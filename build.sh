#!/usr/bin/env bash

: ${PARTICLE_BUILDPACK_VERSION="v0.4.9-rc.3"}
: ${PARTICLE_BUILDPACK_IMAGE="particle/buildpack-particle-firmware:$PARTICLE_BUILDPACK_VERSION"}
: ${PARTICLE_PLATFORM_ID=6}

_start_machine() {
	# ensure the docker machine is running
	docker-machine start default
	eval "$(docker-machine env default)"
}

_init_build() {
	# flatten all the source files in the build directory
	rm -rf build
	mkdir -p build/input
	mkdir -p build/output

	cp *.h *.cpp  build/input
	for f in "$@"; do cp ${f} build/input; done
	echo "========================="
	ls -l build
}

_build() {
	# call the particle buildpack
	#   on osx this assumes that `pwd` results in a directory under /Users which is shared by default with docker-machine
	echo "========================="
	docker run -v `pwd`/build/input:/input -v `pwd`/build/output:/output -e PLATFORM_ID=${PARTICLE_PLATFORM_ID} ${PARTICLE_BUILDPACK_IMAGE}
}

_post_build() {
	# check results and flash if success
	echo "========================="
	if [ -s build/output/firmware.bin ]; then  #if firmware.bin > 0 bytes
		echo "SUCCESS"
		if [ "$PARTICLE_DEVICE" != "" ]; then
			particle flash ${PARTICLE_DEVICE} build/output/firmware.bin
		else
			echo "use: 'particle flash NAME build/output/firmware.bin' to upload"
		fi
	else
		echo "FAILED"
	fi
}

_start_machine
_init_build $@
_build
_post_build

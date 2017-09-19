# xQT from link
	QTSRCN=qt-everywhere-enterprise-src-5.8.0 
	QTTAR=$QTSRCN".tar"
	QTSRC=/z/$QTSRCN
	cd $QTSRC 
	rm  –rf  qtweb*/
	cd $QTSRC/qtbase/mkspecs/devices 
	mkdir fslplat-krogoth
	vim qmake.conf # ex get sample from linux-arm-IMX6-g++
	include(../common/linux_device_pre.conf)
	QMAKE_LIBS_EGL         += -lEGL
	QMAKE_LIBS_OPENGL_ES2  += -lGLESv2 -lEGL -lGAL
	QMAKE_LIBS_OPENVG      += -lOpenVG -lEGL -lGAL
	# IMX6_CFLAGS             = -march=armv7-a -mfpu=neon -DLINUX=1 -DEGL_API_FB=1
	# QMAKE_CFLAGS           += $$IMX6_CFLAGS
	# QMAKE_CXXFLAGS         += $$IMX6_CFLAGS
	DISTRO_OPTS += hard-float
	# Preferred eglfs backend
	# EGLFS_DEVICE_INTEGRATION = eglfs_viv
	v qplatformdefs.h
	include(../common/linux_arm_device_post.conf)
	load(qt_config)
	#===========================================
	cd $QTSRC
QTtarget=fslplat-krogoth
QTCROSS_COMPILE=
QTsysroot=
QTprefix=
QTgen="-device $QTtarget CROSS_COMPILE=$QTCROSS_COMPILE -sysroot $QTsysroot -prefix $QTprefix -hostprefix $QTprefix"
	./configure -qpa eglfs -no-pch -no-xcb -opengl es2 $QTgen -confirm-license -make libs -device-option -nomake examples -no-gtk -v
		two main arguments: CROSS_COMPILE Sysroot
		gcc compiler error: update gcc above to 4.8
		all cmd maybe have permission issue, tried fixed it or just sudo cmd
		# reconfigure: append following argument to ./configure
		v qt-everywhere-enterprise-src-5.8.0/README
	make
		if no wayland-client
		../build/tmp/work/x89_64-linux/wayland-native/1.9.0-r0/build/
		wayland-scanner
		/usr/bin
		configure again
	make install #put files into sysroot
	#get files from installed path to sdcard
	qml –help #test; found missing lib or plugin fold

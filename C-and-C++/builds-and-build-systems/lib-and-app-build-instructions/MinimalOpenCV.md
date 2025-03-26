# Building a minimal build of OpenCV from source


### for more info see config reference
### https://docs.opencv.org/4.x/db/d05/tutorial_config_reference.html


## Install OpenCV

```bash
curl -L -o 4.11.0.zip https://github.com/opencv/opencv/archive/refs/tags/4.11.0.zip

unzip 4.11.0.zip -d ./

git clone https://github.com/opencv/opencv_contrib.git

cd opencv-4.11.0

cmake -S . -B build \
	-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
	-DBUILD_SHARED_LIBS=FALSE -DCMAKE_BUILD_TYPE=Release  \
	-DOPENCV_EXTRA_MODULES_PATH="../opencv_contrib/modules" -DCMAKE_INSTALL_PREFIX="/usr/local" \
	-DBUILD_PERF_TESTS=OFF -DBUILD_TESTS=OFF -DBUILD_DOCS=OFF  -DWITH_CUDA=OFF -DBUILD_EXAMPLES=OFF -DBUILD_opencv_apps=OFF -DINSTALL_CREATE_DISTRIB=ON \
	\
	-DOPENCV_ENABLE_ALLOCATOR_STATS=OFF \
	-DBUILD_OPENEXR=OFF -DWITH_OPENEXR=OFF \
	-DBUILD_JASPER=OFF -DWITH_JASPER=OFF \
	-DBUILD_WEBP=OFF -DWITH_WEBP=OFF \
	-DBUILD_TIFF=OFF -DWITH_TIFF \
	-DBUILD_JPEG=ON -DBUILD_JPEG_TURBO_DISABLE=OFF -DWITH_JPEG=ON \
	-DBUILD_OPENJPEG=OFF -DWITH_OPENJPEG=OFF \
	-DBUILD_SPNG=OFF -DWITH_SPNG=OFF \
	-DWITH_JPEGXL=OFF \
	\
	-DWITH_IMGCODEC_HDR=OFF -DWITH_IMGCODEC_SUNRASTER=OFF -DWITH_IMGCODEC_PXM=OFF -DWITH_IMGCODEC_PFM=OFF \
	\
	-DENABLE_LTO=ON \
	\
	-DWITH_ANDROID_MEDIANDK=OFF \
	\
	-DWITH_AVIF=OFF \
	-DBUILD_JAVA=OFF -DBUILD_opencv_java_bindings_generator=OFF \
	-DBUILD_opencv_js=OFF -DBUILD_opencv_js_bindings_generator=OFF \
	-DWITH_TESSERACT=OFF \
	\
	-DBUILD_opencv_python2=OFF \
	-DCPU_BASELINE=SSE3 -DCPU_DISPATCH=AVX,AVX2 -DENABLE_LTO=ON \
	\
	-DBUILD_opencv_calib3d=OFF \
	-DBUILD_opencv_bgsegm=OFF \
	-DBUILD_opencv_features2d=OFF \
	-DBUILD_opencv_objdetect=OFF \
	-DBUILD_opencv_ml=OFF \
	-DBUILD_opencv_mcc=OFF \
	-DBULD_opencv_flann=OFF \
	-DBUILD_opencv_photo=OFF \
	-DBUILD_opencv_stitching=OFF \
	-DBUILD_opencv_shape=OFF \
	-DBUILD_opencv_superres=OFF \
	-DBUILD_opencv_videostab=OFF \
	-DBUILD_opencv_viz=OFF
	
#========= install eigen from source (optional) : start ==============
# if you have eigen3 already installed yet that eigen library of yours don't have
# 'unsupported' you should install eigen 3.4 from source
# 1. download : https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip
# 2. extract
cd eigen-3.4.0
mkdir build
cmake .. DCMAKE_INSTALL_PREFIX=/usr/local
sudo make install
#========= install eigen from source (optional) : end ================

#========= create symlink (optional) : start ================
# if the previous opencv cmake config command didn't work and it's saying it was unable to find `/usr/local/include/eigen3`
# yet you already have an Eigen library installed in your computer with a different folder name, you can
# create a symlink like the command below so that CMake can find your eigen3 installation then you
# can just re-run the previous config command above.

sudo ln -s /usr/local/include/Eigen /usr/local/include/eigen3
#========= create symlink (optional) : end ================

cmake --build build --config Release

cmake --build build --target install --config Release
```

disable module, example: cmake -DBUILD_opencv_calib3d=OFF ../opencv

some modules: calib3d core features2d flann highgui imgcodecs imgproc ts videoio

eigen can also be enabled or disable : WITH_EIGEN=ON

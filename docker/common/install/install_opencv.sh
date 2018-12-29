#!/usr/bin/env bash
set -e

echo "Install Opencv 3.3.1"
cd /opt
wget -O /opt/opencv.zip https://github.com/opencv/opencv/archive/3.3.1.zip
wget -O /opt/opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/3.3.1.zip 

cd /opt
unzip opencv.zip -d ./ && mv opencv-3.3.1 opencv
unzip opencv_contrib.zip -d ./ && mv opencv_contrib-3.3.1 opencv_contrib

cd opencv
mkdir release
cd release

cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/

make -j4
make install
ldconfig
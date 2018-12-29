#!/usr/bin/env bash
set -e

echo "Install Opencv 3.3.1"

git clone --branch 3.3.1 https://github.com/opencv/opencv.git /opt/opencv
git clone --branch 3.3.1 https://github.com/opencv/opencv_contrib.git /opt/opencv

mkdir /opt/opencv/release

cd /opt/opencv/release

cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/

make -j4
make install
ldconfig
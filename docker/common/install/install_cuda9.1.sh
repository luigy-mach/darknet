#!/usr/bin/env bash
set -e

echo "Install Cuda 9.1"
cd /opt
wget https://developer.nvidia.com/compute/cuda/9.1/Prod/local_installers/cuda-repo-ubuntu1604-9-1-local_9.1.85-1_amd64
chmod +x cuda-repo-ubuntu1604-9-1-local_9.1.85-1_amd64.deb
dpkg -i cuda-repo-ubuntu1604-9-1-local_9.1.85-1_amd64.deb
apt-key add /var/cuda-repo-9-1-local/7fa2af80.pub
apt-get update
apt-get install cuda-9-1
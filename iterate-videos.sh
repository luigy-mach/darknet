#!/bin/bash

for filename in ../video-in/*.*; do
    ./darknet detector demo -prefix "../video-out-images/$filename" cfg/coco.data cfg/yolov3.cfg ../weights/yolov3.weights $filename
done
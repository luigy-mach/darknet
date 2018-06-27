import cv2
import numpy as np
import socket
import sys
import pickle
import struct ### new code
#cap=cv2.VideoCapture(0)
cap = cv2.VideoCapture("rtsp://admin:admin123@192.168.10.213:554/cam/realmonitor?channel=1&subtype=0")
clientsocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
clientsocket.connect(('localhost',8889))
while True:
    ret,frame=cap.read()
    data = pickle.dumps(frame) ### new code
    clientsocket.sendall(struct.pack("H", len(data))+data) ### new code
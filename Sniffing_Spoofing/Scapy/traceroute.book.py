from scapy.all import * 

i = 1
while i <= 30: 
    a = IP()
    a.dst = 'www.amazon.com'
    a.ttl = i 
    b = ICMP()
    reply = sr1(a/b, timeout=5, verbose=1)
    if reply is None:
        print "%2d *" %i 
    elif reply.type == 0:
        print "%2d " %i, reply.src
        break
    else: 
        print "%2d " %i, reply.src
    i = i + 1
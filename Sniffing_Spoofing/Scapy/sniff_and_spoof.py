# reproducing sample lab report code
# reference: https://github.com/Avigdor-Kolonimus/SEED-labs/blob/master/Sniffing%20and%20Spoofing/SnifAndSpoof.py
from scapy.all import * 

def print_pkt(pkt):
    p = copy.deepcopy(pkt[IP])
#    p.src = pkt[IP].dst
    p.src = '1.1.1.1'
    p.dst = pkt[IP].src
    p[ICMP].type = 0
    del p[IP].chksum
    del p[ICMP].chksum
    #p[IP].ttl=255
    p.show2()
    send(p)
    
pkt = sniff(filter='icmp[icmptype]=8', prn=print_pkt)    

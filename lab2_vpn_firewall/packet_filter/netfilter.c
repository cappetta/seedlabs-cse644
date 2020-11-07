#include<linux/skbuff.h>
#include<linux/udp.h>
#include<linux/tcp.h>
#include<linux/ip.h>

// reference :  https://medium.com/@shrutiavinodh/seed-lab-firewall-exploration-554e35dc2ce

static struct nf_hook_ops nfho;
struct sk_buff *sock_buff;
struct udphdr *udp_header;
struct iphdr *ip_header;
struct tcphdr *tcp_header;
static unsigned char *ip_address = “\x5D\xB8\xD8\x22”; //93.184.216.34 for example.com
unsigned int hook_func(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn) (struct sk_buff *))
{
    sock_buff = skb;
    ip_header = ip_hdr(sock_buff);
    if(ip_header->saddr == *(unsigned int*)ip_address)
    {
        printk(“How dare you try to access example.com??? Away with you, data packet.”);
        return NF_DROP;
    }
    return NF_ACCEPT;
}
int init_module()
{
    nfho.hook = hook_func;
    nfho.hooknum = NF_INET_PRE_ROUTING;
    nfho.pf = PF_INET; //ipv4
    nfho.priority = NF_IP_PRI_FIRST;
    nf_register_hook(&nfho); return 0;
}
void cleanup_module()
{
    nf_unregister_hook(&nfho);
}

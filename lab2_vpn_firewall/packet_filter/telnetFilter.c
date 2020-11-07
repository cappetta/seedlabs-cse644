#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>

static struct nf_hook_ops telnetFilterHook;

// print out the dropped packet info
unsigned int dropPacketInfo(const struct iphdr *iph)
{
  // printk(KERN_INFO "Dropping %s packet to %s\n",
      // inet_ntoa(iph->protocol),
      // inet_ntoa(iph->sourceip)
      // );
  printk(KERN_INFO "Dropping packet for restricted traffic between %d.%d.%d.%d  - %d.%d.%d.%d\n",
      ((unsigned char *)&iph->daddr)[0],
      ((unsigned char *)&iph->daddr)[1],
      ((unsigned char *)&iph->daddr)[2],
      ((unsigned char *)&iph->daddr)[3],
      ((unsigned char *)&iph->saddr)[0],
      ((unsigned char *)&iph->saddr)[1],
      ((unsigned char *)&iph->saddr)[2],
      ((unsigned char *)&iph->saddr)[3]);
  return NF_DROP;
}


unsigned int telnetFilter(void *priv, struct sk_buff *skb,
                 const struct nf_hook_state *state)
{
  struct iphdr *iph;
  struct tcphdr *tcph;

  iph = ip_hdr(skb);
  tcph = (void *)iph+iph->ihl*4;
  //drop outgoing telnets
  if (iph->protocol == IPPROTO_TCP && tcph->dest == htons(23)) {
    dropPacketInfo(iph);
    // drop incoming telnets
  } else if (iph->protocol == IPPROTO_TCP && tcph->source == htons(23)) {
    dropPacketInfo(iph);
  } else if (iph->protocol == IPPROTO_TCP && tcph->dest == htons(80)) {
    dropPacketInfo(iph);
  } else if (iph->protocol == IPPROTO_TCP && tcph->dest == htons(443)) {
    dropPacketInfo(iph);
    // drop pings
  } else if (iph->protocol == IPPROTO_ICMP ) {
    dropPacketInfo(iph);
  } else {
    return NF_ACCEPT;
  }
//    return NF_ACCEPT;
}


int setUpFilter(void) {
        printk(KERN_INFO "Registering a Telnet filter.\n");
        telnetFilterHook.hook = telnetFilter; 
        telnetFilterHook.hooknum = NF_INET_POST_ROUTING;
        telnetFilterHook.pf = PF_INET;
        telnetFilterHook.priority = NF_IP_PRI_FIRST;

        // Register the hook.
        nf_register_hook(&telnetFilterHook);
        return 0;
}

void removeFilter(void) {
        printk(KERN_INFO "Telnet filter is being removed.\n");
        nf_unregister_hook(&telnetFilterHook);
}

module_init(setUpFilter);
module_exit(removeFilter);

MODULE_LICENSE("GPL");


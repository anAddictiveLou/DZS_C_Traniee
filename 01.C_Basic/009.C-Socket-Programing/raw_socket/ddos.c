#define __USE_MISC

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define LEN 46

int get_socket()
{
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) 
    {
        perror("Socket creation error");
        return 1;
    }

    int one = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0)
    {
        perror("Error setting IP_HDRINCL option");
    }
    return sockfd;
}

char* create_syn_tcp_pkt(char* attack_ip)
{
    char* packet = (char*) calloc(LEN, sizeof(char));

    struct tcphdr *tcph = (struct tcphdr*) (packet + sizeof(struct ip));
    tcph->source = 0;
    tcph->dest = 0;
    tcph->seq = 0;
    tcph->ack_seq = 0;
    tcph->doff = 5;     
    tcph->fin=0;
    tcph->syn=1;
    tcph->rst=0;
    tcph->psh=0;
    tcph->ack=0;
    tcph->urg=0;
    tcph->window = htons(512); 
    tcph->check = 0;

    struct iphdr* iph = (struct iphdr*) packet;
    iph->version = 4;
    iph->ihl = 5;
    iph->tos = 0;
    iph->tot_len = htons(28);
    iph->id = htons(rand());
    iph->frag_off = 0;
    iph->ttl = 63;
    iph->protocol = IPPROTO_TCP;
    iph->check = 0;
    iph->saddr = INADDR_ANY;
    iph->daddr = inet_addr(attack_ip);
    
    return packet;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <target IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char* attack_ip = argv[1];
    int sockfd = get_socket();
    printf("%s\n", create_syn_tcp_pkt(attack_ip));
    
    exit(EXIT_SUCCESS);
}
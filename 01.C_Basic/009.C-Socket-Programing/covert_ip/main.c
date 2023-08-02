#include <stdio.h>
#include <arpa/inet.h>

int main() {
    // char ip_addr_str[INET6_ADDRSTRLEN];
    // struct in_addr ipv4_addr;
    // struct in6_addr ipv6_addr;

    // const char *ipv4_str = "192.0.2.1";
    // inet_pton(AF_INET, ipv4_str, &ipv4_addr);
    // printf("IPv4 address: %d\n", ipv4_addr.s_addr);
    // char ipv4_str_out[INET_ADDRSTRLEN];
    // inet_ntop(AF_INET, &ipv4_addr, ipv4_str_out, INET_ADDRSTRLEN);
    // printf("IPv4 address: %s\n", ipv4_str_out);

    // const char *ipv6_str = "2001:db8::1";
    // inet_pton(AF_INET6, ipv6_str, &ipv6_addr);
    // char ipv6_str_out[INET6_ADDRSTRLEN];
    // inet_ntop(AF_INET6, &ipv6_addr, ipv6_str_out, INET6_ADDRSTRLEN);
    // printf("IPv6 address: %s\n", ipv6_str_out);

    printf("%d\n", htons(80));
    return 0;
}

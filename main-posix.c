#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

#include "coap.h"

#define PORT 5683

/*int main(int argc, char **argv)
{
    int fd;
    struct sockaddr_in6 servaddr, cliaddr;
    uint8_t buf[4096];
    uint8_t scratch_raw[4096];
    coap_rw_buffer_t scratch_buf = {scratch_raw, sizeof(scratch_raw)};

    fd = socket(AF_INET6,SOCK_DGRAM,0);  //UDP socket

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;
    //servaddr.sin6_addr = in6addr_any;
    servaddr.sin6_port = htons(PORT);  //default port 5683
    bind(fd,(struct sockaddr *)&servaddr, sizeof(servaddr));

    endpoint_setup();

    while(1)
    {
        int n, rc;
        socklen_t len = sizeof(cliaddr);
        coap_packet_t pkt;

        n = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&cliaddr, &len);
#ifdef DEBUG
        printf("Received: ");
        coap_dump(buf, n, true);
        printf("\n");
#endif

        if (0 != (rc = coap_parse(&pkt, buf, n)))
            printf("Bad packet rc=%d\n", rc);
        else
        {
            size_t rsplen = sizeof(buf);
            coap_packet_t rsppkt;
#ifdef DEBUG
            coap_dumpPacket(&pkt);
#endif
            coap_handle_req(&scratch_buf, &pkt, &rsppkt);

            if (0 != (rc = coap_build(buf, &rsplen, &rsppkt)))
                printf("coap_build failed rc=%d\n", rc);
            else
            {
#ifdef DEBUG
                printf("Sending: ");
                coap_dump(buf, rsplen, true);
                printf("\n");
#endif
#ifdef DEBUG
                coap_dumpPacket(&rsppkt);
#endif
		
                sendto(fd, buf, rsplen, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
            }
        }
    }
}*/


#ifndef _TC_SERVER_H_
#define _TC_SERVER_H_

#define __USE_MISC 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/ip.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ogs-core.h>

#include "convert_util.h"


ogs_hash_t *proxy_hash;
ogs_hash_t *conn_hash;

// Proxy structure
typedef struct proxy_s {
    int fd;
    unsigned int from_ip;
    unsigned int to_ip;
    uint16_t from_port;
    uint16_t to_port;
} proxy_t;

// Utility methods
char *gen_proxy_key(unsigned int from_ip, uint16_t from_port, unsigned int to_ip, uint16_t to_port);
proxy_t *get_new_proxy_obj();

// Infrastructure methods
int init_tc_server(void);
int terminate_tc_server(void);

// Proxy methods
int handle_packet(uint8_t *data, int len, char *err, int err_buf_len);

#endif /* _TC_SERVER_H_ */
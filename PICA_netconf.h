#ifndef PICA_NETCONF_H
#define PICA_NETCONF_H

#ifndef WIN32

#include <netinet/in.h>

#else

#define _WIN32_WINNT 0x501
#include <winsock2.h>
#include <ws2tcpip.h>

typedef u_long in_addr_t;
typedef u_short in_port_t;
#endif

int PICA_is_reserved_addr_ipv4(in_addr_t);

#ifdef HAVE_LIBMINIUPNPC
int PICA_upnp_autoconfigure_ipv4(int public_port, int local_port, char *public_ip);
#endif

#endif

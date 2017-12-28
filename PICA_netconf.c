#include "PICA_netconf.h"

#ifdef HAVE_LIBMINIUPNPC
#include <miniupnpc/miniupnpc.h>
#include <miniupnpc/miniwget.h>
#include <miniupnpc/upnpcommands.h>
#include <miniupnpc/upnperrors.h>
#include <stdio.h>
#endif

#define PREFIX4   htonl(0xf0000000U)
#define PREFIX8   htonl(0xff000000U)
#define PREFIX12 htonl(0xfff00000U)
#define PREFIX16 htonl(0xffff0000U)
#define PREFIX24 htonl(0xffffff00U)

#define MAKEIP(a, b, c, d) (htonl( (a&0xFF) << 24 | (b&0xFF) << 16 | (c&0xFF) << 8 | (d&0xFF) ))


int PICA_is_reserved_addr_ipv4(in_addr_t addr)
{
	if ((addr & PREFIX8)  == 0 //0.0.0.0/8
	        ||  (addr & PREFIX8)  == MAKEIP(10, 0, 0, 0) //10.0.0.0/8
	        ||  (addr & PREFIX8)  == MAKEIP(127, 0, 0, 0)//127.0.0.0/8
	        ||  (addr & PREFIX16) == MAKEIP(169, 254, 0, 0) //169.254.0.0/16
	        ||  (addr & PREFIX12) == MAKEIP(172, 16, 0, 0) //172.16.0.0/12
	        ||  (addr & PREFIX16) == MAKEIP(192, 168, 0, 0) //192.168.0.0/16
	        ||  (addr & PREFIX4)  == MAKEIP(224, 0, 0, 0) //224.0.0.0/4
	        ||  (addr & PREFIX4)  == MAKEIP(240, 0, 0, 0) //240.0.0.0/4
	        ||   addr == INADDR_BROADCAST
	   )
		return 1;

	return 0;
}

#ifdef HAVE_LIBMINIUPNPC
int PICA_upnp_autoconfigure_ipv4(int public_port, int local_port, char *public_ip)
{
	struct UPNPDev *devlist = NULL;
	int error = 0;
	struct UPNPUrls urls;
	struct IGDdatas data;
	char lanaddr[64];
	char ppstr[8];
	char lpstr[8];
	int ret;

	devlist = upnpDiscover(2000, 0, 0, 0, 0, 2, &error);

	ret = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));

	if (ret != 1)
	{
		freeUPNPDevlist(devlist);
		return 0;
	}

	ret = UPNP_GetExternalIPAddress(urls.controlURL, data.first.servicetype, public_ip);

	if (ret != UPNPCOMMAND_SUCCESS)
	{
		freeUPNPDevlist(devlist);
	        FreeUPNPUrls(&urls);
		return 0;
	}

	sprintf(ppstr, "%u", public_port);
	sprintf(lpstr, "%u", local_port);

	ret = UPNP_AddPortMapping(urls.controlURL, data.first.servicetype,
					ppstr, lpstr, lanaddr, "Pica Pica", "TCP", 0, "0");


	if (ret != UPNPCOMMAND_SUCCESS)
		ret = 0;
	else
		ret = 1;

	freeUPNPDevlist(devlist);
	FreeUPNPUrls(&urls);
	return ret;
}
#endif


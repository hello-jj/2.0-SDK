#include "ets_sys.h"
#include "osapi.h"
#include "mem.h"
#include "user_interface.h"
#include "c_types.h"
/*
POST /meterweb/handler/meterReadInfoHandlerServlet HTTP/1.1
Host:gziot.zjucolourlife.com
Content-Length: 80

{ "ID":"1744CB", "U":"220.9", "I":"0.0000", "P":"0.0", "W":"0.02", "F":"0.000" }
*/

//char *host = "gziot.zjucolourlife.com";


char *host = "192.168.1.51";

void getHeader(char *p, char *host, int len, u8 mode)
{
	os_memset(p, 0, 256);

	if (mode == 1)
		os_sprintf(p, "POST /meterweb/handler/meterReadInfoHandlerServlet HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n", host, len);
	else if (mode == 2)
		os_sprintf(p, "POST /meterweb/handler/meterReadTest HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n", host, len);
	else if (mode == 3)
		os_sprintf(p, "POST /meterweb/addReadTiming.do HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n", host, len);
	else
		os_sprintf(p, "POST /meterweb/handler/meterReadInfoHandlerServlet HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n", host, len);
}

void getPOST(char *arg, char *pBody, u8 mode)
{
	char *pHeader = (char *)os_zalloc(256);
	if (pHeader == NULL)
	{
		os_printf("malloc failed!!!\r\n");
		return;
	}

	getHeader(pHeader, host, strlen(pBody), mode);

	os_sprintf(arg, "%s%s", pHeader, pBody);

	os_free(pHeader);
}
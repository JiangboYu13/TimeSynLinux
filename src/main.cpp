#include "server.h"
#include "client.h"


int main(int argc, char* argv[])
{

	if (argc < 3)
	{
		printf("Usage: %s [[server|client] listen_port]| server_address server_port send_intervl_in_ms]", argv[0]);
		return -1;
	}
	enum Op_Mode_enum { SERVER, CLIENT };
	typedef enum Op_Mode_enum Op_Mode;
	Op_Mode mode;
	if (strcmp(argv[1], "server")==0)
	{
		printf("server Mode\n");
		mode = SERVER;
	}
	else if (strcmp(argv[1], "client")==0)
	{
		printf("client Mode\n");
		mode = CLIENT;
	}
	else
	{
		printf("Invalid Argument\n");
		printf("Usage: %s [[server|client] listen_port]| server_address server_port send_intervl_in_ms]", argv[0]);		return -1;
	}
	
	if (mode==SERVER)
	{
		return syncResp(atoi(argv[2]));
	}
	else if(mode==CLIENT)
	{
		return syncReq(argv[2], atoi(argv[3]), atoi(argv[4]));
		
	}

	return 0;
}

#include "client.h"

bool syncReq(char* serv_ip, int serv_port, int interval)
{
	int sockfd; 
	struct sockaddr_in serv_addr;
	int recv_len;
	unsigned int slen = sizeof(serv_addr);
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    memset(&serv_addr, 0, sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_pton(AF_INET, serv_ip, &serv_addr.sin_addr);
	char buffer[BUFFER_SIZE];

	while (true)
	{
		double timestamp = NowInSeconds();
		memcpy(buffer, &timestamp, sizeof(timestamp));
		if (sendto(sockfd, buffer, sizeof(timestamp), 0, (struct sockaddr *) &serv_addr, slen) < 0)
		{
			printf("sendto() failed with error");
			return false;
		}

		if ((recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &serv_addr, &slen)) < 0)
		{
			printf("recvfrom() failed with error");
			return false;
		}
		double req_tm = *((double*)buffer);
		printf("Req: %.6f\n", req_tm);
		
		double resp_tm;
		memcpy(&resp_tm, buffer+sizeof(resp_tm), sizeof(resp_tm));
		
		printf("Send: %.6f\n\n\n", resp_tm);
		std::this_thread::sleep_for(std::chrono::milliseconds(interval));
	}
	return true;
}

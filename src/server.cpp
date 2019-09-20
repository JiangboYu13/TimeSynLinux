#include "server.h"

bool syncResp(int serv_port)
{
	int sockfd; 
	struct sockaddr_in serv_addr,clie_addr;
	int recv_len;
	unsigned int slen = sizeof(serv_addr);
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    memset(&serv_addr, 0, sizeof(serv_addr)); 
    memset(&clie_addr, 0, sizeof(clie_addr)); 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(serv_port);

	if (bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("bind failed"); 
        exit(EXIT_FAILURE); 
	}
	printf("listening on port %i",serv_port);
	char buffer[BUFFER_SIZE];


	while (true)
	{
		if ((recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &serv_addr, &slen)) < 0)
		{
			printf("recvfrom() failed with error");
			return false;
		}
		double timestamp = *((double*)buffer);
		printf("Recv: %.6f\n", timestamp);
		
		double tm_now = NowInSeconds();
		memcpy(buffer+sizeof(tm_now), &tm_now, sizeof(tm_now));
		if (sendto(sockfd, buffer, 2*sizeof(tm_now), 0, (struct sockaddr *) &serv_addr, slen) < 0)
		{
			printf("sendto() failed with error");
			return false;
		}
		printf("Send: %.6f\n\n\n", tm_now);
	}
	return true;
}

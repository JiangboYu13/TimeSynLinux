#pragma once 

#include "getTime.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <iostream>
#include <thread>
#define BUFFER_SIZE 16
bool syncReq(char* serv_ip, int serv_port, int interval);
#ifndef SOCKETSERVER_H_H
#define SOCKETSERVER_H

#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread

enum SERVERSTATE { 
    STOP=0,
    RUNNING=1
};

class SocketServer {

	struct ClinetSock
	{
		struct sockaddr * client ;
		int client_sock ;
	};

    private:
    	int socket_desc;
        struct sockaddr_in server ;
        SERVERSTATE server_state ;

    public:
  	    SocketServer();
        int CreateSokcet( int port ) ; 
        void StartListening();
        void StartServer() ;
        void StopServer() ;

    private:
        static void *connection_handler(void *socket_desc);
        
};


#endif
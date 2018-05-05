#include "SocketServer.h"
#include "RequestHandler.h"
#include <string> 

#define BUFSIZE 8096
/*
 * This will handle connection for each client
 * */
void* SocketServer::connection_handler(void* client_sock )
{
    //Get the socket descriptor
    int sock = ((ClinetSock*)client_sock)->client_sock ;
    int read_size;
    char *client_message = new char[BUFSIZE];
     
    puts( "Receive a request!" ) ;

    //Receive a message from client

    read_size = recv(sock , client_message , BUFSIZE , 0);
    //end of string marker
    client_message[read_size] = '\0';
    
    //Send the message back to client
    //write(sock , client_message , strlen(client_message));
    printf( "%s\n", client_message ) ;

    //Get request and give response - STart

    std::string * message = new std::string(); 

    RequestHandler * reqHandler =  new RequestHandler(client_message) ;

    reqHandler->GetResponse(message) ;

    write(sock , message->c_str() , message->size());
    
    //Get request and give response - End
    
    //clear object
    delete reqHandler ;
    delete message ;
    delete client_message;
    

    puts("Client disconnected");
    close(sock) ;
    
} 

int SocketServer::CreateSokcet( int port ) {
	//Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);

    if (socket_desc == -1) {
        printf("Could not create socket");
    }  // if

    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );

        //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 1);

    return 0 ;

}  // CreateSocket


void SocketServer::StartListening() {
    //Accept and incoming connection
    StartServer();
    puts("Waiting for incoming connections...\n");
    int c = sizeof(struct sockaddr_in);

    pthread_t thread_id;

    int i = 1 ;
    ClinetSock *client_sockect = new ClinetSock ;

    while( client_sockect->client_sock = accept(socket_desc, client_sockect->client, (socklen_t*)&c) )
    {
        printf("Connection accepted: %d\n", i); i++;
         
        if( pthread_create( &thread_id , NULL ,  &SocketServer::connection_handler , client_sockect) < 0)
        {
            perror("could not create thread\n");
            return;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        puts("Handler assigned\n");
        
        sleep(0.1);
    }  // while()

    //if (client_sockect->client_sock < 0)
    //{
    //    perror("accept failed");
    //    return 1;
    //}  // if
}
SocketServer::SocketServer() {
	server_state = STOP ;

}  // SocketServer::SocketSocketServer( int port )


void SocketServer::StartServer() { 
    server_state = STOP ; 
}  // SocketServer::StartServer()

void SocketServer::StopServer() { 
    server_state = RUNNING ; 
}   // SocketServer::StopServer()
/*
    C socket server example, handles multiple clients using threads
    Compile
    gcc server.c -lpthread -o server
*/
 
#include "SocketServer.h"
 
//the thread function
void *connection_handler(void *);
 
int main(int argc , char *argv[])
{
     
    SocketServer* socketServer  = new SocketServer()  ;

    if( socketServer->CreateSokcet(8888) == 0 ){
        socketServer->StartListening();    
    }  // if
    
    return 0;
}
 

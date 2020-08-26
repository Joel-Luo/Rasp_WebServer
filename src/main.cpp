#include "SocketServer.h"
 
void *connection_handler(void *);
 
int main(int argc , char *argv[])
{
     
    SocketServer* socketServer  = new SocketServer()  ;

    if( socketServer->CreateSokcet(8888) == 0 ){
        socketServer->StartListening();    
    }  // if
    
    return 0;
}
 

#include "RequestHandler.h"

bool RequestHandler::GetResponse(std::string * Response) {
    

    //std::string * Header = GetResponseHeader() ;
    std::string * Header = new std::string() ;
    std::string * Body = new std::string() ;

    //Send some messages to the client
    Header->append("HTTP/1.1 200 OK\n") ;
    Header->append("Date: Mon, 27 Jul 2009 12:28:53 GMT\n");
    Header->append("Server: Apache/2.2.14 (Win32)\n") ;
    Header->append("Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n") ;
    Header->append("Content-Length: 52\n") ;
    Header->append("Content-Type: text/html\n") ; 
    Header->append("Connection: Closed\n\n") ;

    Body->append("<html>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>") ;


    Response->append( Header->c_str() );
    Response->append( Body->c_str() );

    delete Header ;
    delete Body ;
    return true ;    

}


//std::string * RequestHandler::GetResponseHeader() {
//   return Header ;
//}

RequestHandler::RequestHandler( char* request ){
	RequestContent = request ;
}


//RequestHandler::GetResponseBody( ) {

    //byte* buffer = new byte[4096];
    //byte* buffer = (byte*)"<html>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>") ;
    
    //FileInputStream is = new FileInputStream(path);
    //while (true) {
    //    int len = is.read(buffer);
    //    mWriter.write(buffer, 0, len);
    //    if (len < 4096)
    //        break;
    //} // while
    //is.close();
    //return true;

//} // ReadFile




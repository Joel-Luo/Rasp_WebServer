#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <string> 

typedef unsigned char byte ;


class RequestHandler {
    private:
    	char* RequestContent;
    public: 

    	RequestHandler( char* request );
    	bool GetResponse( std::string* Response) ;

    private:
        void ParseRequest() ;

};


#endif

#include <iostream>
#include <string>
#include "Message.h"
using namespace std;
namespace sict {
		Message::Message():
		user(),
		reply(),
		tweet(){}
		
  Message::Message(const std::string& str){
               size_t  first = str.find(' ',0);
			   size_t  second = str.find('@',first+1);
			   size_t  third = str.find(' ',second+1);
                if(first!= std::string::npos){
                    user = str.substr(0, first);
                    if(second == first+1){
                           reply = str.substr(second + 1,third - second - 1);
                            first = third;
                    }
                        tweet = str.substr(first+1);
		}
        	else *this = Message();
    }
	
    bool Message:: empty()const{
        return (user.empty() || tweet.empty()) ? true : false;
	}
    
    void Message::display(std::ostream& os) const{
        if(!empty()){
            os << ">User  : "<< user << std::endl;
            if(!reply.empty())
                os << " Reply : "<< reply << std::endl;
            os << " Tweet : "<< tweet << "\r\n";
          
        }
    }
}
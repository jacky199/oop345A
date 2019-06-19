/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#include <iostream>
#include <utility>
#include "Message.h"
#include "MessagePack.h"

using namespace std;
namespace sict {
	MessagePack::MessagePack() : message{ nullptr }, num{0}{};

    MessagePack::MessagePack(Message** ms,size_t nu){
        if(nu > 0 && ms != nullptr){
			num = { 0 };
            message = new Message* [nu];
            for(size_t i = 0u;i < nu;i++){
				
                if(!(*ms[i]).empty()){
                    message[num] = new Message(*ms[i]);
                    num++;}
            }
        } 
        else 
			*this = MessagePack();
    }
	
    MessagePack:: ~MessagePack(){
        delete message;
        delete [] message;
    }
	
    MessagePack::MessagePack(const MessagePack& obj){
        *this = obj;
    }
	
    MessagePack::MessagePack(MessagePack&& obj){
        *this = std::move(obj);
    }
	
    MessagePack& MessagePack::operator=(const MessagePack& obj){
        if(this != &obj){
            delete [] message;
            num = obj.num;
            for(size_t i = 0;i < num;i++){
				message[i] = obj.message[i];
			}
        }
        return *this;
    }
		
    MessagePack& MessagePack::operator=(MessagePack&& obj){
        if(this != &obj){   
            num = obj.num; 
			obj.num = 0;
            message = obj.message;     
			obj.message = nullptr;
        }
        return *this;
    }  
	
    void MessagePack::display(std::ostream& os) const{
        for(size_t i = 0u;i < num;i++)
        (*message[i]).display(os);
    }
	
    size_t MessagePack::size() const{
        return num;
    }
	
    std::ostream&operator<<(std::ostream& os,const MessagePack& obj){
        obj.display(os);
        return os;
    }
}
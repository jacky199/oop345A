/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#include <iostream>
#include "Notifications.h"
namespace sict {
	Notifications::Notifications() : address{ nullptr }, max{ 0 }, numOfAdd{ 0 }{}
	
    Notifications::Notifications(int Max){
        if( Max > 0 ){
               address = new const Message*[Max];
               max = Max;
			   numOfAdd = {0};
        } 
        else 
			*this = Notifications();
    }
    
    Notifications:: ~Notifications(){
        delete [] address;
    }
    
    Notifications::Notifications(const Notifications& obj){
		*this = obj;
    }
	
    Notifications::Notifications(Notifications&& obj){
        *this = std::move(obj);
    }
	
    Notifications& Notifications::operator=(const Notifications& obj){
        if(this != &obj){
            delete[] address;
            max = obj.max;
            numOfAdd = obj.numOfAdd;
            address = new const Message* [max];
            for(int i=0;i < max;i++){
                address[i]=obj.address[i];
            }
        }
        return *this;
    }
	
    Notifications& Notifications::operator=(Notifications&& obj){
        if(this != &obj){   
            max = obj.max; 
			obj.max = 0;
            numOfAdd = obj.numOfAdd; 
			obj.numOfAdd = 0;
            address = obj.address;  
			obj.address = nullptr;
        }
        return *this;
    }
    
    Notifications& Notifications::operator+=(const Message& msg){
        if(numOfAdd < max&&!msg.empty())
            address[numOfAdd++] = &msg;
        return *this;
    }
	
    Notifications& Notifications::operator-=(const Message& msg){
        bool found = false;
        int i;
        for ( i = 0;i < numOfAdd&&!found; i++){
            if(address[i]== &msg)
                found = true;
        }
        if(found){
            for(;i < numOfAdd;i++)
                address[i - 1] = address[i];
            if(numOfAdd){
                    address[numOfAdd - 1] = nullptr;
                    numOfAdd--;
            }
        }
        return *this;
    }
	
    void Notifications::display(std::ostream& os)const{
        for(int i=0;i < numOfAdd;i++)
            (*address[i]).display(os);
    }
	
    size_t Notifications::size() const{
        return numOfAdd;
    }
	
    std::ostream& operator<<( std::ostream& os, const Notifications& obj){
        obj.display(os);
        return os;
    }
}
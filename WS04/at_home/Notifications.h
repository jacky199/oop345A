/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include <iostream>
#include "Message.h"
namespace sict {
    class Notifications{
        const Message** address;
        int max;
        int numOfAdd;
		
    public:
        Notifications();
        Notifications(int);
        ~Notifications();
        Notifications(const Notifications&);
        Notifications(Notifications&&);
        Notifications& operator=(const Notifications&);
        Notifications& operator=(Notifications&&);
        Notifications& operator+=(const Message& msg);
        Notifications& operator-=(const Message& msg);
        void display(std::ostream& os)const;
        size_t size() const;
    };
    std::ostream& operator<<( std::ostream& os, const Notifications& obj);
}
#endif 
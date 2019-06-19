/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include "Message.h"
namespace sict {
    class MessagePack{
        Message **message{nullptr};
        size_t num{0};
		
    public:
        MessagePack();
        MessagePack(Message** ms,size_t nu);
        ~MessagePack();
        MessagePack(const MessagePack&);
        MessagePack(MessagePack&&);
        MessagePack& operator=(const MessagePack&);
        MessagePack& operator=(MessagePack&&);
        void display(std::ostream& os) const;
        size_t size() const;
    };
    std::ostream&operator<<(std::ostream& os,const MessagePack& obj);
}
#endif
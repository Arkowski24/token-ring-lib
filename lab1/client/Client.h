//
// Created by USER on 11.03.2019.
//

#ifndef DISTRIBUTED_SYSTEMS_CLIENT_H
#define DISTRIBUTED_SYSTEMS_CLIENT_H

#include <cstdint>
#include <netinet/in.h>
#include "../token/Token.h"

struct TempTokenDTO {
    uint64_t size;
    char data[];
};

class Client {
public:
    virtual ~Client() = default;

    virtual Token *receiveToken() = 0;

    virtual void sendToken(Token *token) = 0;

    virtual void sendNewEmptyToken(Token *token) = 0;

    virtual void discardToken(Token *token) = 0;

    virtual void move(sockaddr_in newNeighbour) = 0;

    virtual const sockaddr_in &getOwnAddress() const = 0;

    virtual const sockaddr_in &getOutputAddress() const = 0;
};


#endif //DISTRIBUTED_SYSTEMS_CLIENT_H

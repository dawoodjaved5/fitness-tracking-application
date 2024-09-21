#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "User.h"
#include <fstream>
//#include "message.h"
#include <sstream>
#include <ctime>
//#include "fileHandling.h"


class Message{
    public:
    string senderName;
    string senderId;
    string message;
    time_t timestamp;
    public:
    Message(){

    }
    Message(string n,string m,string id):senderName(n),message(m),senderId(id){
        timestamp=time(nullptr);
    }
    void setSenderName(string n){
        senderName=n;
    }
    void setMessage(string m){
        message=m;
    }
    
    string getSenderName(){
        return senderName;
    }
    string getMessage(){
        return message;
    }
    time_t getTime(){
        return timestamp;
    }
    string getSenderId(){
        return senderId;
    }

friend istream& operator>>(istream& is,Message &m) {
    getline(is,m.senderName);
    getline(is,m.message);
    is>>m.timestamp;
    
    return is;
}

friend ostream& operator<<(ostream& os, const Message &m) {
    
    os << m.senderName << endl;
    os << m.message << endl;
    os<<m.timestamp;
    return os;
}



    };
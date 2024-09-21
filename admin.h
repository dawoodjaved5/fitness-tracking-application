#pragma once
#include <iostream>
using namespace std;
#include "person.h"
class Admin : public user{
    public:
    Admin(){

    }
    bool authenticate(int pw) const {
    return password == pw;
    }

    void addTrainer(){

    }




};

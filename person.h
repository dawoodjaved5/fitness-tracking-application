#pragma once
#include <iostream>
#include "User.h"
//#include "fileHandling.h"
using namespace std;


class person {
protected:
    string name;
    string id;
    string email;
    int password;
    int age;
    string pq;
    string bio;

public:
    person(){
        
    }
    person(string n, string id, string email, int pass, int age) : name(n), id(id), email(email), password(pass), age(age) {}
    person(string n,string e):name(n),email(e){}

    void setName(string n) {
        name = n;
    }

    void setId(string id) {
        this->id = id;
    }

    void setEmail(string e) {
        email = e;
    }

    void setPassword(int pass) {
        password = pass;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setpq(string ans){
        pq=ans;
    }

    void setBio(string b){
        bio=b;
    }

    string getName() {
        return name;
    }

    string getId() {
        return id;
    }

    string getEmail() {
        return email;
    }

    int getPassword() {
        return password;
    }

    int getAge() {
        return age;
    }

    string getpq(){
        return pq;
    }
    string getBio(){
        return bio;
    }
};
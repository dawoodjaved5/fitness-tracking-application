#pragma once
#include <iostream>
using namespace std;
#include "person.h"
#include <fstream>
#include <sstream>
class trainer : public person{
    private:
    int experience;
    bool approved;
    float height;
    float weight;
    public:
    
    trainer(){
        
    }

    bool isApproved(){
        return approved;
    }

    void approve(){
        approved=true;
    }

    void viewProfile(){

        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"weight: "<<weight<<endl;
        cout<<"height: "<<height<<endl;
        cout<<"experience"<<experience<<" years"<<endl;
        cout<<"Bio: "<<bio<<endl;



    }
    void setExperience(int e){
        experience=e;
    }
    int getExperience(){
        return experience;
    }

    void setHeight(float h){
        height=h;
    }
    void setWeight(float w){
        weight=w;
    }

    




    friend ostream& operator<<(ostream& os, const trainer& t) {
    os << t.name << endl;
    os << t.age<< endl;
    os << t.email << endl;
    os << t.id << endl;
    os << t.bio << endl;
    os << t.password << endl;
    os<<t.experience<<endl;
    os<<t.approved<<endl;
    os<<t.weight<<endl;
    os<<t.height<<endl;
    os<<t.pq<<endl;
    return os;
}

friend istream& operator>>(istream& is, trainer& t) {
    //is.ignore();
    getline(is, t.name);
    
    is >> t.age;
    is>>t.email;
    is>>t.email;
    //is.ignore();
    getline(is, t.bio);
    is>>t.password;
    is>>t.experience;
    is>>t.approved;
    is>>t.weight;
    is>>t.height;
    is>>t.pq;

    return is;
}

};
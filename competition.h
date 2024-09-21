#include <iostream>
using namespace std;
#include <vector>

class Competition{
    public:
    string name;
    vector <string> participants;
    public:
    Competition(){

    }
    Competition(const string &n):name(n){

    }

    void display(){
        cout<<"***************Competition Name: "<<name<<"***************"<<endl<<endl<<endl;
        cout<<"participants: ";
        if (participants.size()==0){
            cout<<"There are no participants for this Competition"<<endl;
        }
        else {
            for (int i=0;i<participants.size();i++){
            cout<<"   "<<i+1<<") "<<participants[i]<<endl;
        }
        }
        
    }



    friend ostream& operator<<(ostream& os, const Competition& c){
        os<<c.name<<endl;
        for (int i = 0; i < c.participants.size(); ++i) {
        os << c.participants[i] << endl;
    }
    return os;


    }

    friend istream& operator>>(istream& is, Competition& c) {
        is>>c.name;
        for (int i=0;i<c.participants.size();i++){
            is>>c.participants[i];
        }
        return is;
    }
};
#include <iostream>
using namespace std;
#include <string>

class locationActivity {
public:
    string name;
    char location; // I for Indoor, O for Outdoor
    string address;
    int duration; // in minutes
    string date;

public:
    locationActivity(){

    }
    locationActivity(const string& n, char l, const string& d, int dur, const string& addr)
        : name(n), location(l), date(d), duration(dur), address(addr) {}

    string getName() const { return name; }
    char getLocationType() const { return location; }
    string getAddress() const { return address; }
    int getDuration() const { return duration; }
    string getDate() const { return date; }



    void display(){
        cout << "Activity Name: " << name << endl;
        cout << "Location Type: " << (location == 'I' || 'i' ? "Indoor" : "Outdoor") << endl;
        cout << "Date: " << date << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Address: " << address << endl;
    }


    friend ostream& operator<<(ostream& os, const locationActivity& l){
        os<<l.name<<endl;
        os<<l.location<<endl;
        os<<l.address<<endl;
        os<<l.date<<endl;
        os<<l.duration<<endl;
        return os;
    }

    friend istream& operator>>(istream& is, locationActivity& l){
        is>>l.name;
        is>>l.location;
        is>>l.address;
        is>>l.date;
        is>>l.duration;
        return is;
    }

};
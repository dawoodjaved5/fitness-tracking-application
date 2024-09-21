#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Post {
    string text;
    static int likes;
    time_t timestamp;

public:
    Post(){

    }
    Post(string t) : text(t) {
        
        timestamp=time(nullptr);
    }

    void setLikes() {
        likes +=1;
    }

    void setText(string t) {
        text = t;
    }

    string getText() const {
        return text;
    }

    int getLikes() const {
        return likes;
    }
    time_t getTimeStamp(){
        return timestamp;
    }

    // Overload insertion operator to display Post details
    friend ostream& operator<<(ostream& os, const Post& post) {
        os << post.text << endl;
        os <<  post.likes << endl;
        os <<  post.timestamp;
        return os;
    }

    // Overload extraction operator to read Post details
    friend istream& operator>>(istream& is, Post& post) {
        getline(is, post.text);
        is>>post.likes;
        is>>post.timestamp;

        return is;
    }
};
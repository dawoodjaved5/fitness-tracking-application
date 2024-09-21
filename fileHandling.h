#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User.h"
#include "trainer.h"
#include "admin.h"
//#include "message.h"
//#include "person.h"
//#include "message.h"
using namespace std;

class FileHandler {
public:
    // Write user profile to file
    static void saveUserProfile(user& u) {
        ofstream fs(u.getId() + ".dat", ios::binary);
        if (fs.is_open()) {
            fs << u;
            // Save goals
            fs << "--- Goals ---" << endl;
            for (size_t i = 0; i < u.goals.size(); ++i) {
                fs << u.goals[i] << endl;
            }
            // Save preferred exercises
            fs << "--- Preferred Exercises ---" << endl;
            for (size_t i = 0; i < u.preferredExercises.size(); ++i) {
                fs << u.preferredExercises[i] << endl;
            }
            
            fs.close();
        } else {
            cout << "Error: Unable to create user file." << endl;
        }
    }

    // Read user profile from file
    static user readUser(const string& uname) {
        string filepath = uname + ".dat";
        ifstream fs(filepath, ios::binary);
        if (fs.is_open()) {
            user u;
            fs >> u;
            string line;
            // Read goals
            while (getline(fs, line)) {
                if (line == "--- Goals ---") {
                    while (getline(fs, line) && line != "--- Preferred Exercises ---") {
                        u.goals.push_back(line);
                    }
                }
                // Read preferred exercises
                if (line == "--- Preferred Exercises ---") {
                    while (getline(fs, line) && line != "--- Workout History ---") {
                        u.preferredExercises.push_back(line);
                    }
                }
                
            }
            
            fs.close();
            return u;
        } else {
            cout << "User file not found for username: " << uname << endl;
            exit(EXIT_FAILURE);
        }
    }

       // Write workout history to file
    static void saveWorkoutHistoryToFile(user& u) {
        ofstream file(u.getId() + "_workouts.dat",ios::binary);
        if (file.is_open()) {
            for (size_t i = 0; i < u.workoutHistory.size(); ++i) {
                file << u.workoutHistory[i] << endl;
            }
            file.close();
        } else {
            cout << "Error: Unable to open workout history file for writing." << endl;
        }
    }

    // Read workout history from file
    static void readWorkoutHistoryFromFile(user& u) {
        ifstream file(u.getId() + "_workouts.dat",ios::binary);
        if (file.is_open()) {
            Workout workout;
            while (file >> workout) {
                file.ignore();
                u.workoutHistory.push_back(workout);
            }
            file.close();
        } else {
            cout << "No workout history found for user: " << u.getId() << endl;
        }
    }



static void saveMessagesToFile(user &u) {
        ofstream file(u.getId() + "_messages.dat",ios::binary);
        if (file.is_open()) {
            for (size_t i = 0; i < u.messages.size(); ++i) {
                file << u.messages[i]<<endl;
            }
            
            file.close();
        } else {
            cout << "Error: Unable to open file for writing messages." << endl;
        }
    }

    // Read messages from file
    static void readMessagesFromFile(user &u) {
        ifstream file(u.getId() + "_messages.dat",ios::binary);
        if (file.is_open()) {
            Message msg;
                
                while(file>>msg){
                    file.ignore();
                    u.messages.push_back(msg); 
            }
            
            file.close();
        } else {
            cout << "No messages found for user: " << u.getId() << endl;
        }
    }

    static void SavePostsToFile(user& u){
        ofstream file(u.getId() + "_posts.dat",ios::binary);
        if (file.is_open()) {
            for (size_t i = 0; i < u.posts.size(); ++i) {
                file << u.posts[i]<<endl;
            }
            
            file.close();
        } else {
            
        }
    }


    static void readPostsFromFile(user &u) {
        ifstream file(u.getId() + "_posts.dat",ios::binary);
        if (file.is_open()) {
            Post p;
                
                while(file>>p){
                    file.ignore();
                    u.posts.push_back(p); 
            }
            
            file.close();
        } else {
            
        }
    }






    static void SaveCompetitionsToFile(user& u){
        ofstream file(u.getId() + "_comp.dat",ios::binary);
        if (file.is_open()) {
            for (int i = 0; i < u.posts.size(); ++i) {
                file << u.competitions[i]<<endl;
            }
            
            file.close();
        } else {
            
        }
    }


    static void readCompetitionsFromFile(user &u) {
        ifstream file(u.getId() + "_comp.dat",ios::binary);
        if (file.is_open()) {
            Competition c;
                
                while(file>>c){
                    file.ignore();
                    u.competitions.push_back(c); 
            }
            
            file.close();
        } else {
            
        }
    }
    

    static void SavelocationBasedToFile(user& u){
        ofstream file(u.getId() + "_location.dat",ios::binary);
        if (file.is_open()) {
            for (int i = 0; i < u.posts.size(); ++i) {
                file << u.locations[i]<<endl;
            }
            
            file.close();
        } else {
            
        }
    }


    static void readlocationBasedFromFile(user &u) {
        ifstream file(u.getId() + "_location.dat",ios::binary);
        if (file.is_open()) {
            locationActivity l;
                
                while(file>>l){
                    file.ignore();
                    u.locations.push_back(l); 
            }
            
            file.close();
        } else {
            
        }
    }


static void SaveTrainerToFile(trainer &t) {
    ofstream file(t.getId() + "_trainer.dat", ios::binary);
    if (file.is_open()) {
        file<<t;
        file.close();
        cout << "Trainer saved to file." << endl;
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

static trainer readTrainer(string &uname) {
    ifstream file(uname + "_trainer.txt", ios::binary);
    if (file.is_open()) {
        trainer t;
        //file.ignore();
        file>>t;
        return t;
        file.close();
        cout << "Trainer loaded from file." << endl;
    } else {
        cout << "Error: Unable to open file for reading." << endl;
        exit(0);
    }
    
}


static void SaveAdminPostsToFile(Admin& a){
        ofstream file(a.getId() + "_adminPosts.dat",ios::binary);
        if (file.is_open()) {
            for (int i = 0; i < a.posts.size(); ++i) {
                file << a.posts[i]<<endl;
            }
            
            file.close();
        } else {
            
        }
    }


    static void readAdminPostsFromFile(Admin &a) {
        ifstream file(a.getId() + "_adminPosts.dat",ios::binary);
        if (file.is_open()) {
            Post p;
                file.ignore();
                while(file>>p){
                    file.ignore();
                    a.posts.push_back(p); 
            }
            
            file.close();
        } else {
            
        }
    }

    





};

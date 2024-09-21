#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "Workout.h"
#include "User.h"
#include "person.h"
#include <sstream>
#include "fileHandling.h"
#include "message.h"
#include "admin.h"
//#include "post.h"
using namespace std;




int Post::likes=0;
int user::badges=0;






bool Userlogin(string& uname, int pass) {  //Function to verify user while logging in
    string filepath = uname + ".dat";

    ifstream fs(filepath, ios::binary);
    if (fs.is_open()) {
        user u;
        fs >> u;
        if (pass == u.getPassword()) {
            cout << "Logged in successfully as user: " << uname << endl;
            
            return true;
        } else {
            cout << "Invalid password." << endl;
        }
    } else {
        cout << "User file not found." << endl;
    }
    return false;
}

bool Trainerlogin(string& uname, int pass) {  //Function to verify trainer while logging in
    string filepath = uname + "_trainer.dat";

    ifstream fs(filepath, ios::binary);
    if (fs.is_open()) {
        trainer t;
        fs >>t;
        if (pass == t.getPassword()) {
            cout << "Logged in successfully as user: " << uname << endl;
            
            return true;
        } else {
            cout << "Invalid password." << endl;
        }
    } else {
        cout << "User file not found." << endl;
    }
    return false;
}





bool Userlogin(string &uname,string pq){  //overloaded function to tell the user his password if he forgot password
    string filepath=uname+".dat";
    ifstream fs(filepath,ios::binary);
    if (fs.is_open()){
        user u;
        fs>>u;
        if (u.getpq()==pq){
            cout<<"Logged in successfully as user: "<<uname<<endl;
            cout<<"your password was: "<<u.getPassword()<<endl;
            return true;
        }
        else {
            cout<<"wrong answer!! login failed!!"<<endl;
        }
    }
    else {
        cout<<"user file not found"<<endl;
    }
    return false;
}

bool Trainerlogin(string &uname,string pq){  //tells the password to trainer if he forgot the password
    string filepath=uname+"_trainer.dat";
    ifstream fs(filepath,ios::binary);
    if (fs.is_open()){
        trainer t;
        fs>>t;
        if (t.getpq()==pq){
            cout<<"Logged in successfully as trainer: "<<uname<<endl;
            cout<<"your password was: "<<t.getPassword()<<endl;
            return true;
        }
        else {
            cout<<"wrong answer!! login failed!!"<<endl;
        }
    }
    else {
        cout<<"user file not found"<<endl;
    }
    return false;
}











bool authenticateUser(const string& uname) {  //authenticate the user while signing up. checks if the user with that user name exists or not
    ifstream file(uname + ".dat",ios::binary);
    if (file.is_open()) {
    
        cout << "User with username " << uname << " already exists." << endl;
        file.close();
        return false;
    } else {
        return true;
    }
}


void updateUserProfile(user& u) {  //update user profile once it is edited
    ifstream file(u.getId() + ".dat");
    if (!file.good()) {
        cout << "Error: User file not found." << endl;
        return;
    }
    file.close();

    FileHandler f;
    f.saveUserProfile(u);
}













void editProfile(user& u) {  //edit the user profile
    cout << "Editing Profile" << endl;
    cout << "1) Edit Name" << endl;
    cout << "2) Edit Age" << endl;
    cout << "3) Edit Password" << endl;
    cout << "4) Edit Email" << endl;
    cout << "5) Edit Height" << endl;
    cout << "6) Edit Weight" << endl;
    cout << "7) Edit Fitness Goals" << endl;
    cout << "8) Edit Exercise Preferences" << endl;
    cout << "9) Edit Workout Log"<<endl;
    cout << "10) Edit Move Goal"<<endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter new name: ";
            string newName;
            cin.ignore();
            getline(cin, newName);
            u.setName(newName);
            
            break;
        }
        case 2: {
            cout << "Enter new age: ";
            int newAge;
            cin >> newAge;
            u.setAge(newAge);
            break;
        }
        case 3: {
            cout << "Enter new password: ";
            int newPassword;
            cin >> newPassword;
            u.setPassword(newPassword);
            break;
        }
        case 4: {
            cout << "Enter new email: ";
            string newEmail;
            cin >> newEmail;
            u.setEmail(newEmail);
            break;
        }
        case 5: {
            cout << "Enter new height: ";
            float newHeight;
            cin >> newHeight;
            u.setHeight(newHeight);
            break;
        }
        case 6: {
            cout << "Enter new weight: ";
            float newWeight;
            cin >> newWeight;
            u.setWeight(newWeight);
            break;
        }
        case 7: {
            u.EditGoals();
            break;
        }
        case 8: {
            u.EditExercisePreferences();
            break;
        }

        case 9: {
            // Edit Workout Log
            u.EditWorkout();
            break;
        }

        case 10: {
            cout<<"enter your new move goal: ";
            float mg;
            cin>>mg;
            u.setMoveGoal(mg);
            cout<<"Move goal updated!";
        }

        case 11: {
            cout<<"enter your new bio: ";
            string bio;
            cin.ignore();
            getline(cin,bio);
            u.setBio(bio);
            cout<<"bio updated!";
        }



        default:
            cout << "Invalid choice" << endl;
    }

    updateUserProfile(u);
}




void userManagement() {
    initializeExerciseList();
    initializeFitnessGoals();
    vector<user> U;
    while (true) {
        cout << "Select your role" << endl;
        cout << "1) USER" << endl;
        cout << "2) Trainer" << endl;
        cout << "3) Admin" << endl;
        cout << "4) Exit" << endl;
        int userChoice;
        cin >> userChoice;

        if (userChoice == 1) {
            cout << "1) Create new account" << endl;
            cout << "2) Login to existing account" << endl;
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Enter your name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                cout << "Enter your age: ";
                int age;
                cin >> age;
                cout<<"Select your gender: (M: Male , F: Female) ";
                char gender;
                do {
                    cout<<"kindly select from F and M"<<endl;
                    cin>>gender;
                    
                }while(gender!='m'&&gender!='M'&&gender!='F'&&gender!='f');
                
                
                cout << "Enter your password (only integers are allowed): ";
                int password;
                cin >> password;
                cout << "Enter your email address: ";
                string email;
                cin >> email;
                cout << "Enter your username (ID): ";
                string id;
                bool a;
                do {
                cin >> id;
                a=authenticateUser(id);
                }while (!a);
                cout<<"do you want to add bio? (Y/N): ";
                char bioch;
                cin>>bioch;
                string bio;
                if (bioch=='y'||bioch=='Y'){
                    cout<<"enter your bio: ";
                    cin.ignore();
                    getline(cin,bio);
                    
                }
                cout<<"what was the name of your first pet: ";
                string q;
                cin>>q;
                

                cout << "Account created successfully" << endl;
                cout << "Setup your profile:" << endl;
                cout << "Enter your height: ";
                float height;
                cin >> height;
                cout << "Enter your weight: ";
                float weight;
                cin >> weight;
                cout<<"enter your move goal i.e the calories you are aiming to burn at every workout: "<<endl;
                cout<<"You can change it anytime in the edit option"<<endl;
                float moveg;
                cin>>moveg;

                user u;
                u.setName(name);
                u.setAge(age);
                u.setEmail(email);
                u.setId(id);
                u.setPassword(password);
                u.setHeight(height);
                u.setWeight(weight);
                u.setpq(q);
                u.setBio(bio);
                if (gender=='m'||gender=='M'){
                    u.setGender('M');
                }
                else if (gender=='f'||gender=='F'){
                    u.setGender('F');
                }
                u.setMoveGoal(moveg);
                
                cout << "You are all set up" << endl;
                FileHandler f;
                user u2;
                cout << "************ Thank you for choosing FitConnect. FitConnect prioritizes its customers in every way ************" << endl << endl;
                while (true){
                    
                    cout << "1)  Start exploring" << endl;
                    cout << "2)  Set goals" << endl;
                    cout << "3)  Set exercise preferences" <<endl;
                    cout << "4)  Workout management"<<endl;
                    cout << "5)  Workout history"<<endl;
                    cout << "6)  View profile" << endl;
                    cout << "7)  Edit profile" <<endl;
                    cout << "8)  View messages"<<endl;
                    cout << "9)  My Dashboard" <<endl;
                    cout << "10) Recommendations"<<endl;
                    cout << "11) Progress Analysis"<<endl;
                    cout << "12) Competitions"<<endl;
                    cout << "13) Location based activities"<<endl;
                    cout << "14) Hire Trainer"<<endl;
                    cout << "15) Logout"<<endl;


                    int choiceInHomePage;
                    cin >> choiceInHomePage;

                    if (choiceInHomePage==1){
                        cout<<"Search (S): "<<endl;
                        
                        char ch;
                        cin>>ch;
                        if (ch=='s'||ch=='S'){
                            cout<<"search by username: ";
                            string uname2;
                            cin>>uname2;
                            
                            
                            u2=f.readUser(uname2);
                            f.readMessagesFromFile(u2);
                            f.readPostsFromFile(u2);
                            
                            
                            
                            u2.viewSocialProfile();cout<<endl<<endl;
                            cout<<"Send Message (M)"<<endl;
                            cout<<"Dashboard (D)"<<endl;
                            char chm;
                            cin>>chm;
                            if (chm=='m'||chm=='M'){
                                u.sendMessage(u2);
                            }

                            else if (chm=='d'||chm=='D'){
                                
                                u.viewDashBoard(u2);
                            }
                            
                        }
                    }


                    else if (choiceInHomePage == 2) {
                        u.setGoals();
                        
                        
                    }
                    else if (choiceInHomePage == 3) {

                        u.setExercisePreferences();
                        
                        
                    }
                    else if (choiceInHomePage==4){
                        
                        u.logWorkout();
                        //f.saveWorkoutHistoryToFile(u);
                        
                        
                    }
                    else if (choiceInHomePage==5){
                        
                        u.displayWorkoutHistory();
                        
                        
                    }
                    else if (choiceInHomePage == 6) {
                        
                        u.viewProfile();
                        
                    }
                    else if (choiceInHomePage == 7) {
                        editProfile(u);
                    }
                    else if (choiceInHomePage==8){
                        string uname3;
                        u.viewMessages();

                        
                        
                    }
                    else if (choiceInHomePage==9){
                        cout<<" Add to dashboard (+)"<<endl;
                        cout<<" Remove from dashboard (-)"<<endl;
                        cout<<" Edit Dashboard (E)"<<endl;
                        cout<<" View Your Dashboard (V) ";
                        char chd;
                        cin>>chd;
                        if (chd=='+'){
                            u.AddPost();
                            
                        }
                        else if (chd=='-'){
                            u.removePost();
                        }
                        else if (chd=='e'||chd=='E'){
                            u.EditPost();
                        }
                        else if (chd=='v'||chd=='V'){

                        }
                        

                    }
                    else if (choiceInHomePage==10){
                        u.generateRecommendations();
                    }
                    
                    else if (choiceInHomePage==11){
                        u.progressAnalysis();
                    }

                    else if (choiceInHomePage==12){
                        cout<<"Personal Competition (P)"<<endl;
                        cout<<"Social Competition (S)"<<endl;
                        char chc;
                        cin>>chc;
                        if (chc=='P'||chc=='p'){
                            u.personalCompetitions();
                        }
                        else if (chc=='s'||chc=='S'){

                            cout<<"1) View all competitions "<<endl;
                            cout<<"2) View joined competitions "<<endl;
                            
                            int chh;
                            cin>>chh;
                            if (chh==1){
                                    u.createCompetition();
                                    cout<<endl;
                                    if (u.competitions.size()!=0){
                                    cout<<"Do you want to join any of these competitions? (Y/N)";
                                    char chj;
                                    cin>>chj;
                                    if (chj=='y'||chj=='Y'){
                                    cout<<"Enter the competition name correctly: "<<endl;
                                    string comp;
                                    cin.ignore();
                                    getline(cin,comp);
                                    u.joinCompetition(comp);
                                    }
                                }
                            }
                            else if (chh==2){
                                u.displayCompetitions();
                            }


                            
                        }
                    }
                    else if (choiceInHomePage==13){
                        cout<<"Add location based activity (+)"<<endl;
                        cout<<"Remove location based activity (-)"<<endl;
                        cout<<"edit location based activity (E)"<<endl;
                        cout<<"View location based activities (V) "<<endl;
                        char chl;
                        cin>>chl;
                        if (chl=='+'){
                            u.addLocation();
                        }
                        else if (chl=='-'){
                            u.removeLocationActivity();
                        }
                        else if (chl=='e'||chl=='E'){
                            u.editLocationActivity();
                        }
                        else if (chl=='v'||chl=='V'){
                            for (int i=0;i<u.locations.size();i++){
                                cout<<"***location "<<i+1<<"***"<<endl;
                                u.locations[i].display();
                                cout<<endl;
                            }
                        }
                    
                    }
                    else if (choiceInHomePage==14){
                        cout<<"search trainer by username: ";
                        string uname;
                        cin>>uname;
                        trainer t;
                        t=f.readTrainer(uname);
                        if (t.isApproved()){
                            cout<<"Trainer profile: "<<endl;
                            t.viewProfile();
                            cout<<endl<<"Add trainer (A)"<<endl<<"Exit (E)"<<endl;
                                char cha;
                                if (cha=='a'||cha=='A'){
                                    cout<<"trainer added"<<endl;
                                }
                            }
                        
                        else {
                            cout<<"this trainer is not approved by the admin!!"<<endl;
                        }
                    }
                    

                    

                    

            
                    else if (choiceInHomePage == 15) {
                    f.saveUserProfile(u);
                    f.saveWorkoutHistoryToFile(u);
                    f.saveMessagesToFile(u2);
                    f.SavePostsToFile(u);
                    f.SaveCompetitionsToFile(u);
                    f.SavelocationBasedToFile(u);
                        
                        break;
                        }
                    }
            } 
                else if (choice == 2) {
                cout << "Enter your username: ";
                string uname;
                cin >> uname;
                cout << "Enter your password: (forgot password? press 0)";
                int pass;
                cin >> pass;
                if (pass==0){
                    cout<<"what was the name of your first pet? ";
                    string qq;
                    cin>>qq;
                    Userlogin(uname,qq);

                }
                if (Userlogin(uname,pass)){
                    FileHandler f;
                    user u=f.readUser(uname);
                    user u2;
                    
                    f.readWorkoutHistoryFromFile(u);
                    f.readMessagesFromFile(u);
                    f.readPostsFromFile(u);
                    f.readCompetitionsFromFile(u);
                    f.readlocationBasedFromFile(u);
                    
                    
                    while (true){
                    
                    cout << "1)  Start exploring" << endl;
                    cout << "2)  Set goals" << endl;
                    cout << "3)  Set exercise preferences" <<endl;
                    cout << "4)  Workout management"<<endl;
                    cout << "5)  Workout history"<<endl;
                    cout << "6)  View profile" << endl;
                    cout << "7)  Edit profile" <<endl;
                    cout << "8)  View messages"<<endl;
                    cout << "9)  My Dashboard" <<endl;
                    cout << "10) Recommendations"<<endl;
                    cout << "11) Progress Analysis"<<endl;
                    cout << "12) Competitions"<<endl;
                    cout << "13) Location based activities"<<endl;
                    cout << "14) Hire Trainer"<<endl;
                    cout << "15) Logout"<<endl;

                    int choiceInHomePage;
                    cin >> choiceInHomePage;

                    if (choiceInHomePage==1){
                        cout<<"Search (S): "<<endl;
                        
                        char ch;
                        cin>>ch;
                        if (ch=='s'||ch=='S'){
                            cout<<"search by username: ";
                            string uname2;
                            cin>>uname2;
                            
                            
                            u2=f.readUser(uname2);
                            f.readMessagesFromFile(u2);
                            f.readPostsFromFile(u2);
                            
                            
                            
                            u2.viewSocialProfile();cout<<endl<<endl;
                            cout<<"Send Message (M)"<<endl;
                            cout<<"Dashboard (D)"<<endl;
                            char chm;
                            cin>>chm;
                            if (chm=='m'||chm=='M'){
                                u.sendMessage(u2);
                            }

                            else if (chm=='d'||chm=='D'){
                                
                                u.viewDashBoard(u2);
                            }
                            
                        }
                    }


                    else if (choiceInHomePage == 2) {
                        u.setGoals();
                        
                        
                    }
                    else if (choiceInHomePage == 3) {

                        u.setExercisePreferences();
                        
                        
                    }
                    else if (choiceInHomePage==4){
                        cout<<"Log Workout (L)"<<endl;
                        cout<<"Edit Workout (E)"<<endl;
                        char chw;
                        cin>>chw;
                        if (chw=='l'||chw=='L'){
                            u.logWorkout();
                        }
                        else if (chw=='e'||chw=='E'){
                            u.EditWorkout();
                        }
                        
                        
                        
                        
                    }
                    else if (choiceInHomePage==5){
                        
                        u.displayWorkoutHistory();
                        
                        
                    }
                    else if (choiceInHomePage == 6) {
                        
                        u.viewProfile();
                        
                    }
                    else if (choiceInHomePage == 7) {
                        editProfile(u);
                    }
                    else if (choiceInHomePage==8){
                        string uname3;
                        u.viewMessages();

                        
                        
                    }
                    else if (choiceInHomePage==9){
                        cout<<" Add to dashboard (+)"<<endl;
                        cout<<" Remove from dashboard (-)"<<endl;
                        cout<<" Edit Dashboard (E)"<<endl;
                        cout<<" View Your Dashboard (V) ";
                        char chd;
                        cin>>chd;
                        if (chd=='+'){
                            u.AddPost();
                            
                        }
                        else if (chd=='-'){
                            u.removePost();
                        }
                        else if (chd=='e'||chd=='E'){
                            u.EditPost();
                        }
                        else if (chd=='v'||chd=='V'){

                        }
                        

                    }
                    else if (choiceInHomePage==10){
                        u.generateRecommendations();
                    }
                    else if (choiceInHomePage==11){
                        u.progressAnalysis();
                    }
                    else if (choiceInHomePage==12){
                        cout<<"Personal Competition (P)"<<endl;
                        cout<<"Social Competition (S)"<<endl;
                        char chc;
                        cin>>chc;
                        if (chc=='P'||chc=='p'){
                            u.personalCompetitions();
                        }
                        else if (chc=='s'||chc=='S'){

                            cout<<"1) View all competitions "<<endl;
                            cout<<"2) View joined competitions "<<endl;
                            
                            int chh;
                            cin>>chh;
                            if (chh==1){
                                    u.createCompetition();
                                    cout<<endl;
                                    if (u.competitions.size()!=0){
                                    cout<<"Do you want to join any of these competitions? (Y/N)";
                                    char chj;
                                    cin>>chj;
                                    if (chj=='y'||chj=='Y'){
                                    cout<<"Enter the competition name correctly: "<<endl;
                                    string comp;
                                    cin.ignore();
                                    getline(cin,comp);
                                    u.joinCompetition(comp);
                                    }
                                }
                            }
                            else if (chh==2){
                                u.displayCompetitions();
                            }


                            
                        }
                    }
                    else if (choiceInHomePage==13){
                        cout<<"Add location based activity (+)"<<endl;
                        cout<<"Remove location based activity (-)"<<endl;
                        cout<<"edit location based activity (E)"<<endl;
                        cout<<"View location based activities (V) "<<endl;
                        char chl;
                        cin>>chl;
                        if (chl=='+'){
                            u.addLocation();
                        }
                        else if (chl=='-'){
                            u.removeLocationActivity();
                        }
                        else if (chl=='e'||chl=='E'){
                            u.editLocationActivity();
                        }
                        else if (chl=='v'||chl=='V'){
                            for (int i=0;i<u.locations.size();i++){
                                cout<<"***location "<<i+1<<"***"<<endl;
                                u.locations[i].display();
                                cout<<endl;
                            }
                        }
                    
                    }
                    else if (choiceInHomePage==14){
                        cout<<"search trainer by username: ";
                        string uname;
                        cin>>uname;
                        trainer t;
                        t=f.readTrainer(uname);
                        if (t.isApproved()){
                            cout<<"Trainer profile: "<<endl;
                            t.viewProfile();
                            cout<<endl<<"Add trainer (A)"<<endl<<"Exit (E)"<<endl;
                                char cha;
                                if (cha=='a'||cha=='A'){
                                    cout<<"trainer added"<<endl;
                                }
                            }
                        
                        else {
                            cout<<"this trainer is not approved by the admin!!"<<endl;
                        }
                    }
                    


                    else if (choiceInHomePage == 15) {
                    f.saveUserProfile(u);
                    f.saveWorkoutHistoryToFile(u);
                    f.saveMessagesToFile(u2);
                    f.SavePostsToFile(u);
                    f.SaveCompetitionsToFile(u);
                    f.SavelocationBasedToFile(u);
                        
                        break;
                        }
                    }
                }
            }
        }

        else if (userChoice==2){
            
            cout << "1) Create new account" << endl;
            cout << "2) Login to existing account" << endl;
            int choice;
            cin >> choice;

            if (choice == 1) {
                
                cout << "Enter your name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                cout << "Enter your age: ";
                int age;
                cin >> age;
                cout<<"Select your gender: (M: Male , F: Female) ";
                char gender;
                do {
                    cout<<"kindly select from F and M"<<endl;
                    cin>>gender;
                    
                }while(gender!='m'&&gender!='M'&&gender!='F'&&gender!='f');
                
                
                cout << "Enter your password (only integers are allowed): ";
                int password;
                cin >> password;
                cout << "Enter your email address: ";
                string email;
                cin >> email;
                cout << "Enter your username (ID): ";
                string id;
                bool a;
                do {
                cin >> id;
                a=authenticateUser(id);
                }while (!a);
                cout<<"do you want to add bio? (Y/N): ";
                char bioch;
                cin>>bioch;
                string bio;
                if (bioch=='y'||bioch=='Y'){
                    cout<<"enter your bio: ";
                    cin.ignore();
                    getline(cin,bio);
                    
                }

                cout<<"what was the name of your first pet: ";
                string q;
                cin>>q;

                cout<<"How many years have you worked in fitness training?: ";
                int exp;
                cin>>exp;

                cout << "Setup your profile:" << endl;
                cout << "Enter your height: ";
                float height;
                cin>>height;
                cout<<"enter your weight: ";
                float weight;
                cin>>weight;


                
                
                

                cout << "Account created successfully" << endl;
                cout<<"You can serve as a trainer once the admin approve your profile!"<<endl;
                

                trainer t;
                t.setName(name);
                t.setAge(age);
                t.setEmail(email);
                t.setId(id);
                t.setPassword(password);
                t.setpq(q);
                t.setBio(bio);
                t.setExperience(exp);
                t.setWeight(weight);
                t.setHeight(height);

                FileHandler f;
                f.SaveTrainerToFile(t);

            }

            else if (choice==2){
                cout<<"enter your username: ";
                string uname;
                cin>>uname;
                cout<<"enter your password (Forgot password? press 0): ";
                int pass;
                cin>>pass;
                if (pass==0){
                    cout<<"what was the name of your first pet: ";
                    string pq;
                    cin>>pq;
                    Trainerlogin(uname,pq);
                }
                FileHandler f;
                if (Trainerlogin(uname,pass)){
                    trainer t;
                    t=f.readTrainer(uname);
                    if (t.isApproved()){
                        cout<<"Approved by admin!!"<<endl;
                    }
                    else {
                        cout<<"you are not approved by the admin!!"<<endl;
                        break;
                    }
                    cout<<"1) My dashboard"<<endl;
                    cout<<"2) Update bio"<<endl;
                    





                }
            }

            


        }
        
        
        else if (userChoice==3){
            
            cout<<"Enter your personal identification number: ";
            int pass;
            cin>>pass;
            Admin a;
            a.setPassword(826698201);
            FileHandler f;
            trainer t;
            
            if (a.authenticate(pass)){
            while (true){
            cout<<endl;
            cout<<"1) Add/remove trainer"<<endl;
            cout<<"2) Make an announcement"<<endl;
            cout<<"3) Make a group chat"<<endl;
            cout<<"4) View user profile"<<endl;
            cout<<"5) View messages"<<endl;
            cout<<"6) Logout"<<endl;
            int choiceInHomePage;
            cin>>choiceInHomePage;
            if (choiceInHomePage==1){
                cout<<"search trainer by username: "<<endl;
                string n;
                cin>>n;
                
                
                t=f.readTrainer(n);
                f.readAdminPostsFromFile(a);

                cout<<"trainer profile: "<<endl;
                t.viewProfile();cout<<endl;


                cout<<"Approve trainer (A)"<<endl;
                cout<<"Reject Trainer (R)"<<endl;
                char cha;
                cin>>cha;
                if (cha=='a'||cha=='A'){
                    cout<<"Trainer "<<t.getName()<<" is approved"<<endl;
                    t.approve();
                }
                else if (cha=='r'||cha=='R'){
                    cout<<"Trainer "<<t.getName()<<" is rejected";
                    continue;
                }
                
            }
            else if (choiceInHomePage==2){
                        cout<<" Add to dashboard (+)"<<endl;
                        cout<<" Remove from dashboard (-)"<<endl;
                        cout<<" Edit Dashboard (E)"<<endl;
                        cout<<" View Your Dashboard (V) ";
                        char chd;
                        cin>>chd;
                        if (chd=='+'){
                            a.AddPost();
                            
                        }
                        else if (chd=='-'){
                            a.removePost();
                        }
                        else if (chd=='e'||chd=='E'){
                            a.EditPost();
                        }
                        else if (chd=='v'||chd=='V'){
                            a.viewDashBoard();
                        }
                        

                    }
                    else if (choiceInHomePage==3){
                        cout<<"Not implemented"<<endl;
                    }
                    else if (choiceInHomePage==4){
                        cout<<"Search by username: ";
                        string uname;
                        cin>>uname;
                        user u;
                        u=f.readUser(uname);
                        u.viewSocialProfile();
                        cout<<"send message (M)"<<endl;
                        cout<<"exit (E)"<<endl;
                        char chm;
                        cin>>chm;
                        if (chm=='m'||chm=='M'){
                            a.sendMessage(u);
                        }
                        else if (chm=='e'||chm=='E'){
                            continue;
                        }
                    }
                    else if (choiceInHomePage==5){
                        a.viewMessages();
                    }
            else if (choiceInHomePage==6){
                f.SaveTrainerToFile(t);
                f.SaveAdminPostsToFile(a);
                break;
            }
            }
            }
            
        }
        else if (userChoice == 4) {
            break;
        }
    }
}

int main() {
    userManagement();
    return 0;
} 
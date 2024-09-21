#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "person.h"
#include "Workout.h"
#include <fstream>
#include <sstream>
#include "message.h"
#include "post.h"
#include "competition.h"
#include "locationBased.h"

vector<string> fitnessGoals;

void initializeFitnessGoals() {  //initializes the available fitness goals from which the user can select
    fitnessGoals.push_back("Lose Weight");
    fitnessGoals.push_back("Build Muscle");
    fitnessGoals.push_back("Improve Flexibility");
    fitnessGoals.push_back("Gain Weight");
}

vector<string> exerciseList;

void initializeExerciseList() {  //initializes the exercise list
    exerciseList.push_back("Running");
    exerciseList.push_back("Weightlifting");
    exerciseList.push_back("Yoga");
    exerciseList.push_back("Cycling");
    exerciseList.push_back("Swimming");
    exerciseList.push_back("Hiking");
    exerciseList.push_back("Dancing");
    exerciseList.push_back("Pilates");
    exerciseList.push_back("Martial Arts");
    exerciseList.push_back("Team Sports");
    // Add more exercises as needed
}












class user : public person {
    
    float height;
    float weight;
    int postn;
    char gender;
    float totalCaloriesConsumed;
    float totalCaloriesBurned;
    static int badges;
    int moveGoal;

    

public:
    vector<string> goals;
    vector<string> preferredExercises;
    vector<Workout> workoutHistory;
    vector<Message> messages;
    vector<Post> posts;
    vector <Competition> competitions;
    vector <locationActivity> locations;
    
    
    user(){
        totalCaloriesBurned=0.0;
        totalCaloriesConsumed=0.0;

    }
    user (string n,string e):person(n,e){}
    user(string n, string id, string email, int pass, int age) : person(n, id, email, pass, age) {
        goals = vector<string>();
        preferredExercises = vector<string>();
        workoutHistory = vector<Workout>();
    }

    friend ostream& operator<<(ostream& os, const user& u);
    friend istream& operator>>(istream& is, user& u);



    void setHeight(float h) {
        height = h;
    }

    void setWeight(float w) {
        weight = w;
    }

    float getHeight(){
        return height;
    }

    float getWeight(){
        return weight;
    }

    void setbadges(){
        badges+=1;
    }
    void setMoveGoal(float m){
        moveGoal=m;
    }
    vector<string> getGoals(){
        return goals;
    }

    void setGender(char g){
        gender=g;
    }
    char GetGender(){
        return gender;
    }
    int getBadges(){
        return badges;
    }
    float getMoveGoal(){
        return moveGoal;
    }

    void setGoals() {  //set user goals based on user preference
        cout << "Choose your fitness goals (enter the numbers separated by spaces):" << endl;
        for (int i = 0; i < fitnessGoals.size(); ++i) {
            cout << i + 1 << ". " << fitnessGoals[i] << endl;
        }

        string goalChoices;
        cin.ignore();
        getline(cin, goalChoices);

        // Parse the input to get the selected goals
        for (int i = 0; i < goalChoices.size(); ++i) {
            char c = goalChoices[i];
            if (isdigit(c)) {
                int index = c - '0' - 1;
                if (index >= 0 && index < fitnessGoals.size()) {
                    goals.push_back(fitnessGoals[index]);
                }
            }
        }
    }


    vector<string> getPreferredExercises() {  
        return preferredExercises;
    }

    void setExercisePreferences() {   //set user preferred exercise
        cout << "Select Preferred Exercises (Enter the numbers separated by spaces):" << endl;
        for (int i = 0; i < exerciseList.size(); ++i) {
            cout << i + 1 << ". " << exerciseList[i] << endl;
        }

        string exerciseChoices;
        cin.ignore();
        getline(cin, exerciseChoices);

        // Parse the input to get the selected exercises
        for (int i = 0; i < exerciseChoices.size(); ++i) {
            char c = exerciseChoices[i];
            if (isdigit(c)) {
                int index = c - '0' - 1;
                if (index >= 0 && index < exerciseList.size()) {
                    preferredExercises.push_back(exerciseList[index]);
                }
            }
        }
    }


void logWorkout() {  //log workout as user provides input
        string type;
        int duration;
        int intensity;
        float nutrition;
        float calories;
        
        // Prompt the user for workout details
        cout << "Enter workout type: ";
        cin.ignore();
        getline(cin,type);
        cout << "Enter duration (minutes): ";
        cin >> duration;
        cout << "Enter intensity (1-10): ";
        cin >> intensity;
        cout<<"enter the nutrition consumed for this workout: ";
        cin>>nutrition;
        cout<<"enter the calories consumed for this workout: ";
        cin>>calories;
        
        

        Workout workout(type, duration, intensity,nutrition,calories);

        workoutHistory.push_back(workout);
        
        cout << "Workout logged successfully." << endl;
    }


    void sendMessage(user &u) {  //sends message to the user which comes in argument
        cout << "Type message: ";
        string message;
        cin.ignore(); 
        getline(cin, message);

        Message msg(name,message,id);
        
        u.messages.push_back(msg);
        cout << "Message sent successfully!" << endl;
    }

    void viewMessages() { //view messages of the current user
        if (messages.empty()) {
            cout << "You have no messages!" << endl;
            
        } else {
            cout << "Sender name" << endl;
            for (int i = 0; i < messages.size(); i++) {
                
                cout << i + 1 << ". " << messages[i].getSenderName() << endl;
            }
            cout << "Open message (Enter message number, 0 to exit): ";
            int choice;
            cin >> choice;
            if (choice >= 1 && choice <= messages.size()) {
                cout << "Message: " << messages[choice - 1].getMessage() << endl;
            } else if (choice != 0) {
                cout << "Invalid choice!" << endl;
                
            }
            
                
        }
    }


    void AddPost(){  //add post to dashboard of the current user
        postn++;
        cout<<"share your experience: ";
        string text;
        cin>>text;
        cin.ignore();
        getline(cin,text);
        Post p(text);
        posts.push_back(p);
        
        cout<<"Post added to your dashboard!"<<endl;
    }

    void removePost(){  //remove post from the dashboard
        postn--;
        cout<<"Following are your posts: "<<endl;
        for (int i=0;i<posts.size();i++){
            cout<<i+1<<") "<<posts[i].getText()<<endl;
        }
        cout<<"select the post number to delete: ";
        int ch;
        cin>>ch;
        posts.erase(posts.begin()+ch-1);
        cout<<"post deleted!"<<endl;

    }

    void EditPost(){  //to edit the post i have written this function
        cout<<"Following are your posts: "<<endl;
        for (int i=0;i<posts.size();i++){
            cout<<i+1<<") "<<posts[i].getText()<<endl;
        }
        cout<<"select the post to edit: ";
        int ch;
        cin>>ch;

        if (ch >= 1 && ch <= posts.size()) {
        cout << "Enter the new text for the post: ";
        string newText;
        cin.ignore(); 
        getline(cin, newText);

        posts.erase(posts.begin() + ch - 1);

        posts.insert(posts.begin() + ch - 1, Post(newText));

        cout << "Post edited successfully!" << endl;
    } else {
        cout << "Invalid post number!" << endl;
    }


    }


    void viewDashBoard(user &u){  //display the dashboard of the user in the argument

        if (u.posts.size()==0){
            cout<<"The user "<<u.getName()<<" have zero posts"<<endl;
        }

        else {
            cout<<"Following are the posts by "<<u.getName()<<endl;
            
        for (int i=0;i<u.posts.size();i++){
            cout<<"**********Post "<<i+1<<"**********"<<endl;
            cout<<i+1<<") "<<u.posts[i].getText()<<endl;
            time_t timestamp=u.posts[i].getTimeStamp();
            cout<<"Time of post: "<<ctime(&timestamp)<<endl;
            cout<<"    Like (L)   Likes: "<<posts[i].getLikes()<<endl;
            cout<<"Next (N)"<<endl;
            cout<<"Exit (E)"<<endl;
            char ch;
            cin>>ch;
            if (ch=='l'||ch=='L'){
                cout<<"Like added"<<endl;
                posts[i].setLikes();
            }
            else if (ch=='N'||ch=='n'){
                continue;
            }
            else if (ch=='E'||ch=='e'){
                break;
            }
            else {
                cout<<"Invalid Choice!"<<endl;
            }
        }
        }
    }

    void viewDashBoard(){  //display the dashboard of the calling instance
        if (posts.size()==0){
            cout<<"You dont have any posts!!"<<endl;
        }
        else {
            for (int i=0;i<posts.size();i++){
            cout<<"**********Post "<<i+1<<"**********"<<endl;
            cout<<i+1<<") "<<posts[i].getText()<<endl;
            time_t timestamp=posts[i].getTimeStamp();
            cout<<"Time of post: "<<ctime(&timestamp)<<endl;
            cout<<" Likes: "<<posts[i].getLikes()<<endl;
            cout<<"Next (N)"<<endl;
            cout<<"Exit (E)"<<endl;
            char ch;
            cin>>ch;
            if (ch=='N'||ch=='n'){
                continue;
            }
            else if (ch=='E'||ch=='e'){
                break;
            }
            else{
                cout<<"Invalid Choice!"<<endl;
            }
            }
        }
    }

    void EditWorkout(){  //edit the workouts which were previously logged
            displayWorkoutHistory();

            cout << "Enter the number of the workout log you want to edit (0 to cancel): ";
            int logNumber;
            cin >> logNumber;

            if (logNumber > 0 && logNumber <= workoutHistory.size()) {
                // Prompt user to edit workout log details
                workoutHistory.erase(workoutHistory.begin() + logNumber - 1); // Remove old log

                cout << "Enter new workout details:" << endl;
                logWorkout(); // Prompt user to log a new workout (can be modified to edit existing log)
            } else if (logNumber != 0) {
                cout << "Invalid workout log number." << endl;
            }
            
    }


    void EditExercisePreferences(){  //edit the preferred exercises
        cout << "1) Add Exercise Preferences" << endl;
            cout << "2) Remove Exercise Preferences" << endl;
            int subChoice;
            cin >> subChoice;

            if (subChoice == 1) {
                setExercisePreferences();
            } else if (subChoice == 2) {
                // Remove Exercise Preferences
                vector<string> currentPreferences = getPreferredExercises();
                if (currentPreferences.empty()) {
                    cout << "You don't have any preferences to remove." << endl;
                    exit (0);
                }
                cout << "Current Exercise Preferences:" << endl;
                for (int i = 0; i < currentPreferences.size(); ++i) {
                    cout << i + 1 << ") " << currentPreferences[i] << endl;
                }

                cout << "Enter the number of the preference you want to remove (0 to finish): ";
                int preferenceToRemove;
                cin >> preferenceToRemove;
                if (preferenceToRemove > 0 && preferenceToRemove <= currentPreferences.size()) {
                    // Remove the selected preference
                    preferredExercises.erase(preferredExercises.begin() + preferenceToRemove - 1);
                    cout << "Preference removed successfully." << endl;
                } else if (preferenceToRemove != 0) {
                    cout << "Invalid preference number." << endl;
                }
            } else {
                cout << "Invalid choice." << endl;
            }
    }

    void EditGoals(){  //edit goals
        cout << "1) Add Goals" << endl;
            cout << "2) Remove Goals" << endl;
            int subChoice;
            cin >> subChoice;

            if (subChoice == 1) {
                // Add Goals
                setGoals();
            } else if (subChoice == 2) {
                // Remove Goals
                vector<string> currentGoals = getGoals();
                if (currentGoals.empty()) {
                    cout << "You don't have any goals to remove." << endl;
                    exit(0);
                }
                cout << "Current Fitness Goals:" << endl;
                for (int i = 0; i < currentGoals.size(); ++i) {
                    cout << i + 1 << ") " << currentGoals[i] << endl;
                }

                cout << "Enter the number of the goal you want to remove (0 to finish): ";
                int goalToRemove;
                cin >> goalToRemove;
                if (goalToRemove > 0 && goalToRemove <= currentGoals.size()) {
                    
                    goals.erase(goals.begin() + goalToRemove - 1);
                    cout << "Goal removed successfully." << endl;
                } else if (goalToRemove != 0) {
                    cout << "Invalid goal number." << endl;
                }
            } else {
                cout << "Invalid choice." << endl;
            }
    }


    void generateRecommendations() {  //generate recommendations on the basis of user preferred goals. i.e the user's goals
    cout << "Generating recommendations based on user's fitness goals..." << endl;
    
    
    
    
    for (int i = 0; i < goals.size(); ++i) {
        if (goals[i] == "Lose Weight") {
            cout << "Recommendation: Focus on a balanced diet with reduced calorie intake and regular aerobic exercises such as running, cycling, or swimming." << endl;
        } else if (goals[i] == "Build Muscle") {
            cout << "Recommendation: Incorporate strength training exercises like weightlifting, bodyweight exercises, and adequate protein intake to support muscle growth." << endl;
        } else if (goals[i] == "Improve Flexibility") {
            cout << "Recommendation: Practice stretching exercises such as yoga or Pilates regularly to improve flexibility and mobility." << endl;
        } else if (goals[i] == "Gain Weight") {
            cout << "Recommendation: Increase calorie intake with nutrient-dense foods and focus on strength training exercises to build muscle mass." << endl;
        } else {
            cout << "Unknown fitness goal: " << goals[i] << endl;
        }
    }

    if (weight < 50.0) {
        cout << "Recommendation: Ensure sufficient calorie intake to support healthy weight gain." << endl;
    } else if (weight > 100.0) {
        cout << "Recommendation: Monitor calorie intake and engage in regular physical activity to maintain a healthy weight." << endl;
    }

}

void progressAnalysis() {  //provides the overall progress analysis of the user based on their workouts
    cout << "Performing progress analysis..." << endl;

    vector<float> caloriesBurnedPerWorkout;
    vector<float> nutritionConsumedPerWorkout;

    // Calculate total calories burned and nutrition consumed per workout
    for (int i = 0; i < workoutHistory.size(); ++i) {
        caloriesBurnedPerWorkout.push_back(workoutHistory[i].getCaloriesBurned());
        nutritionConsumedPerWorkout.push_back(workoutHistory[i].getNutritionConsumed());
    }

    // Calculate total calories burned and nutrition consumed overall
    float totalCaloriesBurned = 0.0;
    float totalNutritionConsumed = 0.0;

    for (int i = 0; i < workoutHistory.size(); ++i) {
        totalCaloriesBurned += caloriesBurnedPerWorkout[i];
        totalNutritionConsumed += nutritionConsumedPerWorkout[i];
    }

    // display total calories burned and nutrition consumed
    cout << "Total calories burned: " << totalCaloriesBurned << endl;
    cout << "Total nutrition consumed: " << totalNutritionConsumed << endl;

    // Generate graphs (using simple text-based representation for demonstration)
    cout << "Graphical representation:" << endl;

    // graph for calories burned per workout
    cout << "Calories burned per workout:" << endl;
    for (int i = 0; i < caloriesBurnedPerWorkout.size(); ++i) {
        cout << "Workout " << i + 1 << ": ";
        for (int j = 0; j < caloriesBurnedPerWorkout[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // graph for nutrition consumed per workout
    cout << "Nutrition consumed per workout:" << endl;
    for (int i = 0; i < nutritionConsumedPerWorkout.size(); ++i) {
        cout << "Workout " << i + 1 << ": ";
        for (int j = 0; j < nutritionConsumedPerWorkout[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    float maxCaloriesBurned = 0.0;
int maxCaloriesBurnedIndex = -1;
for (int i = 0; i < caloriesBurnedPerWorkout.size(); ++i) {
    if (caloriesBurnedPerWorkout[i] > maxCaloriesBurned) {
        maxCaloriesBurned = caloriesBurnedPerWorkout[i];
        maxCaloriesBurnedIndex = i;
    }
}
if (maxCaloriesBurnedIndex != -1) {
    cout << "Most effective workout: Workout " << maxCaloriesBurnedIndex + 1 << " (Calories burned: " << maxCaloriesBurned << ")" << endl;
} else {
    cout << "No workout data available." << endl;
}

// Find the workout with the highest nutrition consumption
float maxNutritionConsumed = 0.0;
int maxNutritionConsumedIndex = -1;
for (int i = 0; i < nutritionConsumedPerWorkout.size(); ++i) {
    if (nutritionConsumedPerWorkout[i] > maxNutritionConsumed) {
        maxNutritionConsumed = nutritionConsumedPerWorkout[i];
        maxNutritionConsumedIndex = i;
    }
}
if (maxNutritionConsumedIndex != -1) {
    cout << "Workout with highest nutrition consumption: Workout " << maxNutritionConsumedIndex + 1 << " (Nutrition consumed: " << maxNutritionConsumed << ")" << endl;
} else {
    cout << "No workout data available." << endl;
}
}



void createCompetition() { //creates competition on the basis of user goals
        for (int i=0;i<goals.size();i++){ 
            string competitionName = "Competition for " + goals[i];
            competitions.push_back(Competition(competitionName));
        }

        cout<<"following are  the competitions for you: "<<endl;
        for (int i=0;i<goals.size();i++){
            competitions[i].display();
        }
        
        
    }

    void joinCompetition(const string& competitionName) {
    // find the competition with the given name
    for (int i = 0; i < competitions.size(); ++i) {
        if (competitions[i].name == competitionName) {
            // Add the user to the participants list
            competitions[i].participants.push_back(name);
            cout << "Joined competition: " << competitionName << endl;
            return;
        }
    }
    // If competition not found
    cout << "Competition not found: " << competitionName << endl;
}

void displayCompetitions(){
    cout << "Competitions you're participating in:" << endl;
    for (int i = 0; i < competitions.size(); ++i) {
        const Competition& comp = competitions[i];
        cout << "- " << comp.name << endl;
        cout << "  Participants: ";
        for (int j = 0; j < comp.participants.size(); ++j) {
            const string& participant = comp.participants[j];
            cout << participant;
            if (j < comp.participants.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void personalCompetitions(){

    cout<<"         **********Burn 150Kcal per day**********"<<endl<<endl;
    cout<<"Hey "<<name<<" Burning "<<moveGoal<<"Kcal "<< "every day is a great way to stay active"<<endl;
    float caloriesBurned=workoutHistory.back().getCaloriesBurned();
    cout<<"The calories Burned in your last workout: "<<caloriesBurned<<endl;
    if (caloriesBurned>=150){
        cout<<"Congratulations!!  You have earned a badge!"<<endl;
        badges++;
    }

    else {
        cout<<"you still have to burn "<<moveGoal-caloriesBurned<<" calories to get a badge"<<endl;
    }

    cout<<"Total Badges: "<<badges<<endl<<endl<<endl;
}




void addLocation() {  //this functions adds the location based activities
    cout << "Enter the name of the activity: ";
    string name;
    cin.ignore();
    getline(cin, name);

    cout << "Location of the activity (I for Indoor, O for Outdoor): ";
    char locationType;
    do {
        cin >> locationType;
        if (locationType != 'I' && locationType != 'i' && locationType != 'O' && locationType != 'o') {
            cout << "Invalid input! Kindly select from I and O." << endl;
        }
    } while (locationType != 'I' && locationType != 'i' && locationType != 'O' && locationType != 'o');

    cout << "Enter address: ";
    string address;
    cin.ignore();
    getline(cin, address);

    cout << "Enter duration (in minutes): ";
    int duration;
    cin >> duration;

    cout << "Enter date (e.g., Sun 12 May): ";
    string date;
    cin.ignore();
    getline(cin, date);

    locationActivity loc(name, locationType, date, duration, address);
    locations.push_back(loc);
    cout << "Location based activity added successfully!" << endl;
}

void displayLocationActivities() {
    cout << "Location based activities:" << endl;
    for (int i = 0; i < locations.size(); ++i) {
        cout << "Activity " << i + 1 << ":" << endl;
        locations[i].display();
        cout << endl;
    }
}

void removeLocationActivity() {
    if (locations.empty()) {
        cout << "No location based activities to remove." << endl;
        return;
    }

    cout << "Select the activity to remove (Enter the number):" << endl;
    for (int i = 0; i < locations.size(); ++i) {
        cout << i + 1 << ". " << locations[i].getName() << endl;
    }

    int choice;
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(locations.size())) {
        cout << "Invalid choice!" << endl;
        return;
    }

    locations.erase(locations.begin() + choice - 1);
    cout << "Location based activity removed successfully!" << endl;
}

void editLocationActivity() {
    if (locations.empty()) {
        cout << "No location based activities to edit." << endl;
        return;
    }

    cout << "Select the activity to edit (Enter the number):" << endl;
    for (int i = 0; i < locations.size(); ++i) {
        cout << i + 1 << ". " << locations[i].getName() << endl;
    }

    int choice;
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(locations.size())) {
        cout << "Invalid choice!" << endl;
        return;
    }

    // Display current details
    cout << "Current details of the selected activity:" << endl;
    locations[choice - 1].display();

    // Modify details
    cout << "Enter new details:" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, locations[choice - 1].name);
    cout << "Location Type (I/O): ";
    cin >> locations[choice - 1].location;
    cout << "Address: ";
    cin.ignore();
    getline(cin, locations[choice - 1].address);
    cout << "Duration (in minutes): ";
    cin >> locations[choice - 1].duration;
    cout << "Date: ";
    cin.ignore();
    getline(cin, locations[choice - 1].date);

    cout << "Location based activity edited successfully!" << endl;
}











void displayWorkoutHistory();
void viewProfile();




friend ostream& operator<<(ostream& os, const user& u) {
    os << u.name << endl;
    os << u.age << endl;
    os << u.email << endl;
    os << u.id << endl;
    os<<u.bio<<endl;
    os << u.password << endl;
    os << u.height << endl;
    os << u.weight << endl;
    os << u.pq<<endl;
    os<<u.postn<<endl;
    os<<u.gender<<endl;
    os<<u.totalCaloriesBurned<<endl;
    os<<badges<<endl;
    os<<u.moveGoal<<endl;


    
    return os;
}


    friend istream& operator>>(istream& is, user& u) {
        getline(is, u.name);
        is >> u.age;
        getline(is, u.email);
        getline(is, u.id);
        getline(is,u.bio);
        is >> u.password;
        is >> u.height;
        is >> u.weight;
        is>>u.pq;
        is>>u.postn;
        is>>u.gender;
        is>>u.totalCaloriesBurned;
        is>>u.badges;
        is>>u.moveGoal;

        

        return is;
    }



    void viewSocialProfile(){
        cout<<"Name: "<<name<<endl;
        cout<<"Username (ID): "<<id<<endl;
        cout<<"bio: "<<bio<<endl;
        cout<<"posts: "<<postn<<endl;
        

    }



};




void user::viewProfile() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Email: " << email << endl;
    cout << "Username (ID): " << id << endl;
    cout<<"bio: "<<bio<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout << "Height: " << height << " ft" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Fitness Goals:" << endl;
    
    // Display fitness goals on a single line
    for (int i = 0; i < goals.size(); ++i) {
        cout << "- " << goals[i];
        if (i < goals.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    
    cout << "Preferred Exercises:" << endl;
    // Display preferred exercises
    for (int i = 0; i < preferredExercises.size(); ++i) {
        cout << "- " << preferredExercises[i] << endl;
    }
}



void user::displayWorkoutHistory() {
    if (workoutHistory.empty()) {
        cout << "No workout history available." << endl;
    } else {
        cout << "Workout History:" << endl;
        for (int i = 0; i < workoutHistory.size(); ++i) {
            cout << i + 1 << ". ";
            cout << "Type: " << workoutHistory[i].getType() << endl;
            cout << "Duration: " << workoutHistory[i].getDuration() << endl;
            cout << "Intensity: " << workoutHistory[i].getIntensity() << endl;
            cout << "Calories Burned: " << workoutHistory[i].getCaloriesBurned()*weight << endl<<endl<<endl;
            cout<<"Nutrition consumed: "<<workoutHistory[i].getNutritionConsumed()<<endl;
            cout<<"Calories consumed: "<<workoutHistory[i].getCaloriesConsumed()<<endl<<endl;
            if (workoutHistory[i].getCaloriesBurned()>workoutHistory[i].getCaloriesConsumed()){
                cout<<"total  calories burned i.e Calories Burned - Calories Consumed = "<<workoutHistory[i].getCaloriesBurned()-workoutHistory[i].getCaloriesConsumed()<<endl;
            }
            else {
                cout<<"You have'nt burned any calories for this workout!! Instead you consumed "<<workoutHistory[i].getCaloriesConsumed()-workoutHistory[i].getCaloriesBurned()<<" extra calories"<<endl;
            }
            
            time_t timestamp = workoutHistory[i].getTimestamp();
            cout << "Timestamp: " << ctime(&timestamp);
            cout << endl;
        }
    }
}

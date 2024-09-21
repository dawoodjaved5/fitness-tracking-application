#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

class Workout {
private:
    string type; 
    int duration;     
    int intensity;  
    int caloriesBurned; 
    time_t timestamp; 
    float nutritionConsumed;
    float caloriesConsumed;

public:
    // Constructor
    Workout() {}

    Workout(string type, int duration, int intensity,float nut,float cal)
        : type(type), duration(duration), intensity(intensity), nutritionConsumed(nut), caloriesConsumed(cal) {
            caloriesBurned=0;
            timestamp = time(nullptr);
        }

    // Getter methods
    string getType() const {
        return type;
    }

    int getDuration() const {
        return duration;
    }

    int getIntensity() const {
        return intensity;
    }

    float getCaloriesBurned() {
        caloriesBurned=(duration)*(intensity);
        return caloriesBurned;
    }

    time_t getTimestamp() const {
        return timestamp;
    }

    float getNutritionConsumed(){
        return nutritionConsumed;
    }
    float getCaloriesConsumed(){
        return caloriesConsumed;
    }

    // Overloaded output stream operator
    friend ostream& operator<<(ostream& os, const Workout& w) {
        os << w.type << endl;
        os << w.nutritionConsumed<<endl;
        os << w.caloriesConsumed<<endl;
        os << w.duration << endl;
        os << w.intensity << endl;
        os << w.caloriesBurned << endl;
        os << w.timestamp;
        return os;
    }

    friend istream& operator>>(istream& is, Workout& w) {
        getline(is, w.type);
        is>>w.nutritionConsumed;
        is>>w.caloriesConsumed;
        is >> w.duration;
        is >> w.intensity;
        is >> w.caloriesBurned;
        is >> w.timestamp;
        return is;
    }
};

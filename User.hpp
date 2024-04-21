#ifndef USER_HPP
#define USER_HPP
#define NOMBRE_ARCHIVO_ACTIVITY "dailyActivity_merged.csv"
#define NOMBRE_ARCHIVO_INTENSITY "minuteIntensitiesNarrow_merged.csv"
#define NOMBRE_ARCHIVO_SLEEPDAY "sleepDay_merged.csv"
#define NOMBRE_ARCHIVO_WEIGHT "weightLogInfo_merged.csv"


#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class User{
    private:
        //dailyActivity_merged
        double id;
        double RestingHeartRate;
        double VeryActiveMinutes;
        double FairlyActiveMinutes;
        double LightlyActiveMinutes;
        double SedentaryMinutes;
        string ActivityDate;
        double LoggedActivitiesDistance;
        double Calories;
        double ActivityMinutes;

        //minuteIntensitiesNarrow_merged
        int Intensity;
        vector <int> personalIntensity;

        //sleepDay_merged
        double TotalMinutesAsleep;
        double TotalTimeInBed;

        //minutesSleep_merged VER COMO ALMACENARLO

        //weightLogInfo_merged
        double WeightKg;

        //heartrates_seconds_merged


    public:
        User();
        User(double id, double RestingHeartRate, double VeryActiveMinutes, double FairlyActiveMinutes, double LightlyActiveMinutes, double SedentaryMinutes, string ActivityDate, double LoggedActivitiesDistance, double Calories, double ActivityMinutes, int Intensity, double TotalMinutesAsleep, double TotalTimeInBed, double WeightKg, std::vector<int>& personalIntensity);


        //GETTERS
        //dailyActivity_merged
        double getId();
        double getRestingHeartRate();
        double getVeryActiveMinutes();
        double getFairlyActiveMinutes();
        double getLightlyActiveMinutes();
        double getSedentaryMinutes();
        string getActivityDate();
        double getLoggedActivitiesDistance();
        double getCalories();
        double getActivityMinutes(); //Se tiene que calcular con los datos, no existe en el excel, sólo hay que sumar todos los minutos
        //minuteIntensitiesNarrow_merged
        int getIntensity();
        //sleepDay_merged
        double getTotalMinutesAsleep();
        double getTotalTimeInBed();
        vector<int> getpersonalIntensity();

        //SETTERS
        //dailyActivity_merged
        void setId(double Id);
        void setRestingHeartRate(double RestingHeartRate);
        void setVeryActiveMinutes(double VeryActiveMinutes);
        void setFairlyActiveMinutes(double FairlyActiveMinutes);
        void setLightlyActiveMinutes(double LightlyActiveMinutes);
        void setSedentaryMinutes(double SedentaryMinutes);
        void setActivityDate(string ActivityDate);
        void setLoggedActivitiesDistance(double LoggedActivitiesDistance);
        void setCalories(double Calories);
        void setActivityMinutes(double ActivityMinutes);
        //minuteIntensitiesNarrow_merged
        void setIntensity(int Intensity);
        //sleepDay_merged
        void setTotalMinutesAsleep(double TotalMinutesAsleep);
        void setTotalTimeInBed(double TotalTimeInBed);

        double userSearch(double Id);
        void loadDataDailyActivity();
        void loadDataIntensity();

};

#endif
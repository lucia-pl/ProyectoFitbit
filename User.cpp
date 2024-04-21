#include "User.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
    User::User(){}
    vector <int> personalIntensity; //para almacenar la intensidad de cada usuario
    vector <User> users(30); //Para almacenar todos los usuarios

    User::User(double id, double RestingHeartRate, double VeryActiveMinutes, double FairlyActiveMinutes, double LightlyActiveMinutes, double SedentaryMinutes, string ActivityDate, double LoggedActivitiesDistance, double Calories, double ActivityMinutes, int Intensity, double TotalMinutesAsleep, double TotalTimeInBed, double WeightKg, std::vector<int>& personalIntensity){
        this-> id = id;
        this-> RestingHeartRate = RestingHeartRate;
        this-> VeryActiveMinutes = VeryActiveMinutes;
        this-> FairlyActiveMinutes =FairlyActiveMinutes;
        this-> LightlyActiveMinutes =LightlyActiveMinutes;
        this-> SedentaryMinutes =SedentaryMinutes;
        this-> ActivityDate =ActivityDate;
        this-> LoggedActivitiesDistance =LoggedActivitiesDistance;
        this-> Calories =Calories;
        this-> ActivityMinutes =ActivityMinutes;
        this-> Intensity =Intensity;
        this-> TotalTimeInBed =TotalTimeInBed;
        this-> TotalMinutesAsleep =TotalMinutesAsleep;
        this-> WeightKg =WeightKg;
        this->personalIntensity=personalIntensity; //comprobar si esta linea es omitible
    }


    //GETTERS
    //dailyActivity_merged
    double User::getId(){
        return id;
    };
    double User::getRestingHeartRate(){
        return RestingHeartRate;
    };
    double User::getVeryActiveMinutes(){
        return VeryActiveMinutes;
    };
    double User::getFairlyActiveMinutes(){
        return FairlyActiveMinutes;
    };
    double User::getLightlyActiveMinutes(){
        return LightlyActiveMinutes;
    };
    double User::getSedentaryMinutes(){
        return SedentaryMinutes;
    };
    string User::getActivityDate(){
        return ActivityDate;
    };
    double User::getLoggedActivitiesDistance(){
        return LoggedActivitiesDistance;
    }
    double User::getCalories(){
        return Calories;
    };
    double User::getActivityMinutes(){
        return ActivityMinutes;
    };
    //minuteIntensitiesNarrow_merged
    int User::getIntensity(){
        return Intensity;
    };
    //sleepDay_merged
    double User::getTotalMinutesAsleep(){
        return TotalMinutesAsleep;
    };
    double User::getTotalTimeInBed(){
        return TotalTimeInBed;
    };
    vector<int> getpersonalIntensity(){
        return personalIntensity;
    }


    //SETTERS
    //dailyActivity_merged
    void User::setId(double id){
        this->id=id;
    };
    void User::setRestingHeartRate(double RestingHeartRate){
        this->RestingHeartRate=RestingHeartRate;
    };
    void User::setVeryActiveMinutes(double VeryActiveMinutes){
        this->VeryActiveMinutes=VeryActiveMinutes;
    };
    void User::setFairlyActiveMinutes(double FairlyActiveMinutes){
        this->FairlyActiveMinutes=FairlyActiveMinutes;
    };
    void User::setLightlyActiveMinutes(double LightlyActiveMinutes){
        this->LightlyActiveMinutes=LightlyActiveMinutes;
    };
    void User::setSedentaryMinutes(double SedentaryMinutes){
        this->SedentaryMinutes=SedentaryMinutes;
    };
    void User::setActivityDate(string ActivityDate){
        this->ActivityDate=ActivityDate;
    };
    void User::setLoggedActivitiesDistance(double LoggedActivitiesDistance){
        this->LoggedActivitiesDistance=LoggedActivitiesDistance;
    };
    void User::setCalories(double Calories){
        this->Calories=Calories;
    };
    void User::setActivityMinutes(double ActivityMinutes){
        this->ActivityMinutes=ActivityMinutes;
    };
    //minuteIntensitiesNarrow_merged
    void User::setIntensity(int Intensity){
        this->Intensity=Intensity;
    };
    //sleepDay_merged
    void User::setTotalMinutesAsleep(double TotalMinutesAsleep){
        this->TotalMinutesAsleep=TotalMinutesAsleep;
    };
    void User::setTotalTimeInBed(double TotalTimeInBed){
        this->TotalTimeInBed=TotalTimeInBed;
    };

    //para encontrar la posición de los usuarios en la lista de usuarios
    int userSearch(double Id){
        for(int i=0; i<sizeof users;i++){
            if(users[i].getId()==Id){
                return i;
            }
        }
        return -1;
    }

    //carga los datos de dailyActivity_merged
    void loadDataDailyActivity(){
            ifstream fileName(NOMBRE_ARCHIVO_ACTIVITY);
            string line;
            char comma = ',';
            //empty se usará para guardar en una variable los datos que no nos interesa guardar pero que hay que pasar por ellos
            double empty, id, VeryActiveMinutes,FairlyActiveMinutes, LightlyActiveMinutes, SendentaryMinutes, LoggedActivitiesDistance, Calories;
            string date;

            if (fileName.is_open()){
                getline(fileName, line);

                while(getline(fileName, line)){
                    stringstream stream(line);
                    for (int i=0; i<941 ;i++){
                        User u;
                        fileName>>id>>date>>empty>>empty>>empty>>LoggedActivitiesDistance>>empty>>empty>>empty>>empty>>VeryActiveMinutes>>FairlyActiveMinutes>>LightlyActiveMinutes>>SendentaryMinutes>>Calories;
                        u.setId(id);
                        u.setActivityDate(date);
                        u.setLoggedActivitiesDistance(LoggedActivitiesDistance);
                        u.setVeryActiveMinutes(VeryActiveMinutes);
                        u.setFairlyActiveMinutes(FairlyActiveMinutes);
                        u.setLightlyActiveMinutes(LightlyActiveMinutes);
                        u.setSedentaryMinutes(SendentaryMinutes);
                        u.setCalories(Calories);
                        users[i]=u;
                    }
                }
                fileName.close();
            } else {
                cout << "Ha habido un fallo al cargar el archivo" << endl;
            }
    }

    void loadDataIntensity(){
         ifstream fileName(NOMBRE_ARCHIVO_INTENSITY);
            string line;
            char comma = ',';
            //empty se usará para guardar en una variable los datos que no nos interesa guardar pero que hay que pasar por ellos
            double empty, Intensity, Id;
            if (fileName.is_open()){
                getline(fileName, line);

                while(getline(fileName, line)){
                    stringstream stream(line);
                    for (int i=0; i<1325581 ;i++){
                        User u;
                        fileName>>Id;
                        while (Id==users[i].getId()){
                            fileName>>empty>>empty>>Intensity;
                            users[i].getpersonalIntensity().push_back(Intensity);
                        }
                    }
                }
                fileName.close();
            } 
            else {
                cout << "Ha habido un fallo al cargar el archivo" << endl;
            }  
    }
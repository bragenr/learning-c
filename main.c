#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char* firstPlaceDriverName;
    char* firstPlaceRaceCarColor;
};

struct RaceCar {
    char* driverName;
    char* raceCarColor;
    int totalLapTime;
};
// Print functions section
int printIntro(){
    printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
    return 0;
}

int printCountDown(){
    printf("Racers Ready! In...\n"
           "5...\n"
           "4...\n"
           "3...\n"
           "2...\n"
           "1...\n"
           "Race!\n\n");
    return 0;
}

int printFirstPlaceAfterLap(struct Race race){
    printf("Lap %d completed! First place is: %s in the %s race car. \n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    return 0;
}

int printCongratulation(struct Race race){
    printf("\n\nLet's all congratulate %s in the %s race car for an amazing performance. It truly was a great race and everybody have a goodnight!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    return 0;
}
// Logic functions section

int calculateTimeToCompleteLap(){
    //implementing random number between 1 and 3
    int lower = 1;
    int upper = 3;

    int speed = lower + rand() % (upper - lower + 1);
    int acceleration = lower + rand() % (upper - lower + 1);
    int nerves = lower + rand() % (upper - lower + 1);

    return (speed + acceleration + nerves);
}

void updateRaceCar(struct RaceCar* raceCarPointer){
    raceCarPointer -> totalLapTime += calculateTimeToCompleteLap();
}

int updateFirstPlace(struct Race* racePointer, struct RaceCar* raceCar1Pointer, struct RaceCar* raceCar2Pointer){
    if (raceCar1Pointer -> totalLapTime < raceCar2Pointer -> totalLapTime ){
        racePointer -> firstPlaceDriverName = raceCar1Pointer -> driverName;
        racePointer -> firstPlaceRaceCarColor = raceCar1Pointer -> raceCarColor;
    }else if (raceCar1Pointer -> totalLapTime > raceCar2Pointer -> totalLapTime){
        racePointer -> firstPlaceDriverName = raceCar2Pointer -> driverName;
        racePointer -> firstPlaceRaceCarColor = raceCar2Pointer -> raceCarColor;
    }else{
        printf("\n\nThe have the same time!!\n");
    }
    return 0;
}

int startRace(struct RaceCar* raceCar1Pointer, struct RaceCar* raceCar2Pointer) {
    int i;
    struct Race race = {
            5,
            0,
            "",
            ""
    };

    for (i = 0; i <= race.numberOfLaps; i++){
        race.currentLap++;
        updateRaceCar( raceCar1Pointer);
        updateRaceCar(raceCar2Pointer);
        updateFirstPlace(&race, raceCar1Pointer, raceCar2Pointer);
        printFirstPlaceAfterLap(race);
    }
    printCongratulation(race);

    return 0;
}


int main() {
    srand(time(0));
    struct RaceCar raceCar1 = {
            "Charlie",
            "Yellow",
            0
    };

    struct RaceCar raceCar2 = {
            "Bob",
            "Green",
            0
    };

    printIntro();
    printCountDown();

    startRace(&raceCar1, &raceCar2);
}
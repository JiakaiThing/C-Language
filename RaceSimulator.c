#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section

struct Race{
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[50];
  char firstPlaceRaceCarColor[30];
};

struct RaceCar{
  char driverName[50];
  char raceCarColor[30];
  int totalLapTime;
};
// Print functions section

void printIntro(){
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown(){
  printf("Racers Ready!\nIn...\n");
  for(int i = 5; i > 0; i--){
    printf("%i\n", i);
  }
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number %d\n", race.currentLap);
  printf("First Place is: %s in the %s race car! \n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race ){
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section

int calculateTimeToCompleteLap(){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar){
  raceCar -> totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  //checks to see who should be first place and allocates to pointers (firstPlaceDriverName and firs[]tPlaceRaceCarColor)
  if (raceCar1 -> totalLapTime <= raceCar2 -> totalLapTime)
  {
    strcpy(race -> firstPlaceDriverName, raceCar1 -> driverName);
    strcpy(race -> firstPlaceRaceCarColor, raceCar1 -> raceCarColor);
  }
  else{
    strcpy(race -> firstPlaceDriverName, raceCar2 -> driverName);
    strcpy(race -> firstPlaceRaceCarColor, raceCar2 -> raceCarColor);
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
    struct Race race = {5, 0, "", ""};
    for(int i = 0; i < race.numberOfLaps; i++){
        race.currentLap++;
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
    }
    printCongratulation(race);
}

int main() {
	srand(time(0));
  struct RaceCar raceCar1 = {"Jay", "Red"};
  struct RaceCar raceCar2 = {"Mike", "Blue"};
  printIntro();  
  printCountDown();
  startRace(&raceCar1, &raceCar2);
};

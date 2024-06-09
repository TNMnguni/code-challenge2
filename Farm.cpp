#include "AdvancedCrop.h"
#include "Farm.h"
#include <iostream>



Farm::Farm()
{ 
	cropCounter = 0;
	farmName = "";
}

Farm::Farm(string farmName)
{
	for (int i = 0; i < 10; ++i) {
		crop[i] = nullptr;
	}
}

string Farm::getName(){

	return farmName;
}
void Farm::addCrop(AdvancedCrop advCrop) {
	if (cropCounter < 10) {
		crop[cropCounter] = new AdvancedCrop(advCrop);
		cropCounter++;
	}
	else {
		std::cout << "Farm is full, cannot add more crops." << std::endl;
	}
}

Farm:: ~Farm(){
	for (int i = 0; i < cropCounter; ++i) {
		delete crop[i];
	}
}

float Farm::getProfit() {
	float totalProfit = 0.0f;
	for (int i = 0; i < cropCounter; ++i) {
		totalProfit += crop[i]->getProduceProfit();
	}
	return totalProfit;
}


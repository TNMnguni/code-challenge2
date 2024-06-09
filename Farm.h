#ifndef FARM_H
#define FARM_H

#include <string>
#include <vector>
#include "AdvancedCrop.h"

class Farm{
public:
	Farm();
	Farm(string farmName);
	string getName();
	//void addCrop(AdvancedCrop& advCrop);
	~Farm();
	float getProfit();
	string farmName;
	void addCrop(AdvancedCrop crop);
	vector<AdvancedCrop> crops;

private:
	AdvancedCrop* crop[10];
	int cropCounter;
	
	

};

#endif
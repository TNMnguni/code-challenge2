
#ifndef CROP_H
#define CROP_H
#include <string>
using namespace std;

class Crop
{
protected:
	string cropName;
	float numberOfUnits;
	float pricePerUnit;
	float cropExpenses;

public:
	Crop();
	Crop(string cropName, float numberOfUnits, float pricePerUnit, float cropExpenses);
	string getName();
	float getUnits();
	float getPrice();
	float getExpenses();
};
#endif 
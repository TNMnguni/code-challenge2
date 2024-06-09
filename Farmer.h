#ifndef FARMER_H
#define FARMER_H

#include <string>
#include "Farm.h"
#include <string>
#include <vector>

class Farmer {
private:

    string fileName;
    Farm* farms[30];
    int farmCounter;
   

public:

    Farmer(string fileName);
    ~Farmer();
    AdvancedCrop extractCropFromLine(string line);
    int getNumberOfFarms();
    Farm& getFarmAt(int index);
    float getTotalProfit();
    int getProfitLessFarms(string farmNames[], float losses[]);
};

#endif 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Farm.h"
#include "Farmer.h"

using namespace std;

    AdvancedCrop Farmer::extractCropFromLine(string line) {
        stringstream ss(line);
        string cropName;
        float numberOfUnits;
        float pricePerUnit, cropExpenses, sizeOfCrop, propertyTax;

        getline(ss, cropName, ',');
        ss >> numberOfUnits;
        ss.ignore();
        ss >> pricePerUnit;
        ss.ignore();
        ss >> cropExpenses;
        ss.ignore();
        ss >> sizeOfCrop;
        ss.ignore();
        ss >> propertyTax;

        return AdvancedCrop(cropName, numberOfUnits, pricePerUnit, cropExpenses, sizeOfCrop, propertyTax);
    }

    Farmer::Farmer(string fileName) : fileName(fileName), farmCounter(0) {
        ifstream file(fileName);
        string line;
        if (!file.is_open()) {
            cout << "File " << fileName << " could not be found" << endl;
            exit(1); 
        }

        Farm* currentFarm = nullptr;

        while (getline(file, line)) {
            if (line.empty()) {
                continue;  
            }

            if (line[0] == '#') {
                
                if (currentFarm != nullptr) {
                    farms[farmCounter++] = currentFarm;
                }
                currentFarm = new Farm(line.substr(1)); 
            }
            else if (currentFarm) {
           
                currentFarm->addCrop(extractCropFromLine(line));
            }
        }

        
        if (currentFarm != nullptr) {
            farms[farmCounter++] = currentFarm;
        }

        file.close();
    }

    int Farmer::getNumberOfFarms(){
        return farmCounter;
    }

    Farm& Farmer::getFarmAt(int index){
        if (index >= 0 && index < farmCounter) {
            return *farms[index];
        }
        throw out_of_range("Index out of range");
    }

    float Farmer::getTotalProfit() {
        float totalProfit = 0.0;
        for (int i = 0; i < farmCounter; ++i) {
            totalProfit += farms[i]->getProfit();
        }
        return totalProfit;
    }

    int Farmer::getProfitLessFarms(string farmNames[], float losses[]){
        int lossCounter = 0;
        for (int i = 0; i < farmCounter; ++i) {
            float profit = farms[i]->getProfit();
            if (profit < 0) {
                farmNames[lossCounter] = farms[i]->farmName;
                losses[lossCounter] = profit;
                ++lossCounter;
            }
        }
        return lossCounter;
    }

    Farmer::~Farmer() {
        for (int i = 0; i < farmCounter; ++i) {
            delete farms[i];
        }
    };



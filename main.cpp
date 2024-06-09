#include "Farmer.h"
#include <iostream>

int main() {
    
    Farmer farmer("Farm.txt");

    
    cout << "Farms and Profits:\n";
    for (int i = 0; i < farmer.getNumberOfFarms(); ++i) {
        Farm& farm = farmer.getFarmAt(i);
        cout << "  - " << farm.getName() << ": $" << farm.getProfit() << endl;
    }
    cout << "Total Profit: $" << farmer.getTotalProfit() << endl << endl;

    
    string farmNames[30]; 
    float losses[30];
    int numLossFarms = farmer.getProfitLessFarms(farmNames, losses);

    if (numLossFarms > 0) {
        cout << "Loss-Making Farms:\n";
        for (int i = 0; i < numLossFarms; ++i) {
            cout << "  - " << farmNames[i] << ": $" << -losses[i] << " loss" << endl;
        }
    }
    else {
        cout << "All farms are profitable!" << endl;
    }

    return 0;
}

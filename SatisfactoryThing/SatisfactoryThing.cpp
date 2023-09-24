
#pragma once
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello World!\n";
}

class item {
private:
    float amountProduced;
    int timeToProduce;
public:
    string name;
    int id;

    item(string name = "placeholder", int id = -1, float amountProduced = 0, int timeTaken = 0) {
        item::name = name;
        item::id = id;
        item::amountProduced = amountProduced;
        item::timeToProduce = timeTaken;
    }

    void setAmountProducedPerMinute(float amountProduced) {
        item::amountProduced = amountProduced;
    }

    void setTimeToProduce(int time) {
        item::timeToProduce = time;
    }

    float getAmountProduced() {
        return item::amountProduced;
    }

    int getTimeToProduce() {
        return item::timeToProduce;
    }

    float getAmountProducedPerMinute() {
        const int minute = 60;
        return (amountProduced * (minute / timeToProduce));
    }
};

class primaryResource :
    public item
{

};

class secondaryResource :
    public item
{
private:
    item itemsNeeded[4];
    float amountsNeeded[4];

public:
    secondaryResource() {

    }

    secondaryResource(int inputAmount, item itemsNeeded[], float amountsNeeded[]) {
        for (int i = 0; i < inputAmount; i++)
        {
            secondaryResource::itemsNeeded[i] = itemsNeeded[i];
            secondaryResource::amountsNeeded[i] = amountsNeeded[i];
        }
    }

    void addResource(item itemNeeded, float amountNeeded) {
        for (int i = 0; i < sizeof(amountsNeeded) / sizeof(float); i++)
        {
            if (amountsNeeded[i] == NULL) {
                itemsNeeded[i] = itemNeeded;
                amountsNeeded[i] = amountNeeded;
            }
        }
    }
};

class building {
public:
    int id;
    string name;
    float energyUse;

    building(int id, string name, float energyUse) {
        building::id = id;
        building::name = name;
        building::energyUse = energyUse;
    }
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

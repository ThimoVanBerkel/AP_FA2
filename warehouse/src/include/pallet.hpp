#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>

class Pallet
{
private:
    std::string itemName;
    int itemCount;
    int itemCapacity;

public:
    Pallet();
    Pallet(std::string itemName, int itemCapacity, int itemCount);
    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();
    bool relocateEmptyPallet(std::string itemName, int itemCapacity);
    bool setItemCapacity(int itemCapacity);
    bool setItemName(std::string itemName);
    bool takeOne();
    bool putOne();
};
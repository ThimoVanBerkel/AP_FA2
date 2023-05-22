#include <iostream>
#include <string>
#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCount, int itemCapacity):  itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount){};

Pallet::Pallet(){
    itemName = "";
    itemCount = 0;
    itemCapacity = -1;
};

std::string Pallet::getItemName(){
    return itemName;
};

int Pallet::getItemCount(){
    return itemCount;
};

// int Pallet::getRemainingSpace(){

// };

// bool Pallet::relocateEmptyPallet(std::string itemName, int itemCapacity){

// };

bool Pallet::setItemCapacity(int itemCapacity){
    this->itemCapacity = itemCapacity;
};

bool Pallet::setItemName(std::string itemName){
    this->itemName = itemName;
};

// bool Pallet::takeOne(){

// };

// bool Pallet::putOne(){

// };
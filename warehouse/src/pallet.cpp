#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount){
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
};

Pallet::Pallet(){
    itemName = "";
    itemCount = 0;
    itemCapacity = 100;
};

std::string Pallet::getItemName(){
    return itemName;
};

int Pallet::getItemCount(){
    return itemCount;
};

int Pallet::getRemainingSpace(){
    return itemCapacity - itemCount;
};

bool Pallet::relocateEmptyPallet(std::string itemName, int itemCapacity){
    // Kijk of de pallet leeg is, anders kan hij niet verplaatsen
    if (itemCount == 0){
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
    else{
        return false;
    }
};

bool Pallet::takeOne(){
    // Kijk of de pallet leeg zit
   if (itemCount == 0){
        return false;
    }
    else{
        // Haal 1 af aan de huidge count
        itemCount = itemCount - 1;
        return true;
    } 
};

bool Pallet::putOne(){
    // Kijk of de pallet vol zit
    if (itemCount == itemCapacity){
        return false;
    }
    else{
        // Voeg 1 toe aan de huidge count
        itemCount = itemCount + 1;
        return true;
    }
};

bool Pallet::isEmpty() const{
    return(itemCount == 0);
}

bool Pallet::isFull() const{
    return(itemCount == itemCapacity);
}
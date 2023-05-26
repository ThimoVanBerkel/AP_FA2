
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "include/shelf.hpp"

Shelf::Shelf() : pallets({Pallet(), Pallet(), Pallet(), Pallet()}) {

}

bool Shelf::swapPallet(int slot1, int slot2) {
    Pallet tijdelijk = pallets[slot1];
    pallets[slot1] = pallets[slot2];
    pallets[slot2] = tijdelijk;
    return true;
};

bool Shelf::isEmpty(){
    // Gaat in alle pallets kijken
    for (Pallet pallet : pallets){
        // Check of elke pallet leeg is
        if (pallet.getItemCount() != 0){
            return false;
        }
    }
    return true;
};

bool Shelf::isFull(){
    // Gaat in alle pallets kijken
    for (Pallet pallet : pallets){
        // Check of elke pallet leeg is
        if (pallet.getRemainingSpace() != 0){
            return false;
        }
    }
    return true;
};
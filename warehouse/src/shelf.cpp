
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "include/shelf.hpp"

Shelf::Shelf() : Pallets({Pallet(), Pallet(), Pallet(), Pallet()}) {

}

bool Shelf::swapPallet(int slot1, int slot2) {
    Pallet tijdelijk = Pallets[slot1];
    Pallets[slot1] = Pallets[slot2];
    Pallets[slot2] = tijdelijk;
    return true;
};

bool Shelf::isEmpty(){
    // Gaat in alle pallets kijken
    for (Pallet pallet : Pallets){
        // Check of elke pallet leeg is
        if (pallet.getItemCount() != 0){
            return false;
        }
    }
    return true;
};

bool Shelf::isFull(){
    // Gaat in alle pallets kijken
    for (Pallet pallet : Pallets){
        // Check of elke pallet leeg is
        if (pallet.getRemainingSpace() != 0){
            return false;
        }
    }
    return true;
};
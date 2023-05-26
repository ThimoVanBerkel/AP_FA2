#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/warehouse.hpp"
#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/pallet.hpp"

Warehouse::Warehouse(){

}

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    Shelves.push_back(shelf);
}   

bool Warehouse::rearrangeShelf(Shelf &Shelf){
    // Kijkt of de employee een certificaat heeft
    if (Employees[0].getForkliftCertificate() == 1){
        bool reset = true;
        while (reset == true){
            reset = false;
            for (int i = 0; i < 3; ++i)
                // Gaat kijken of de pallet geswaped kan worden
                if (Shelf.swapPallet(i, i + 1) == true){
                    reset = true;
                }
        }
        return true; 
    }
    return false;
}

bool Warehouse::pickItems(std::string itemName, int itemCount){
    // Loop door elke shelf heen en daarna door de pallets van die shelf
    for (Shelf Shelf: Shelves){
        for (Pallet pallet : Shelf.pallets){
            if(pallet.getItemName() == itemName){
                while(itemCount > 0 && pallet.takeOne()){
                    itemCount --;
                }
                if(itemCount == 0){
                    return true;
                }
            }
        }
    }
    return false;
}
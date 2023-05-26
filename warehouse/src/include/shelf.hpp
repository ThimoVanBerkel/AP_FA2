#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>

#include "include/pallet.hpp"
#include "include/icontainer.hpp"

class Shelf : public Icountainer
{
public:
    std::array<Pallet, 4> Pallets;
    Shelf();
    bool swapPallet(int slot1, int slot2);
    bool isEmpty() override;
    bool isFull() override;
};  
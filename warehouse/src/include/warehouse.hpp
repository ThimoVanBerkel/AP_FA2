#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "employee.hpp"
#include "shelf.hpp"

class Warehouse
{
public:
    std::vector<Employee> Employees;
    std::vector<Shelf> Shelves;
    Warehouse();
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf &Shelf);
    bool pickItems(std::string itemName, int itemCount);
};
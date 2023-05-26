#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/warehouse.hpp"
#include "include/employee.hpp"

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}   
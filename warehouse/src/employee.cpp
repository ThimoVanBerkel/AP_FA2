#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/employee.hpp"

Employee::Employee(std::string name, bool forkliftCertificate){
    this->name = name;
    this->forkliftCertificate = forkliftCertificate;
    this->busy = 0;
}

std::string Employee::getName(){
    return name;
}

bool Employee::getBusy(){
    return busy;
}

void Employee::setBusy(bool busy){
    this->busy = busy;
}

bool Employee::getForkliftCertificate(){
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate){
    this->forkliftCertificate = forkliftCertificate;
}
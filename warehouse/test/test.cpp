#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "include/pallet.hpp"
#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/warehouse.hpp"

// Find all tests in test*.cpp in test/
// ############################################
//  Test Cases - Pallet.
// ############################################

TEST_CASE("Test of het aanmaken van een pallet lukt"){
    Pallet pallettest("Lego", 60, 15);
    REQUIRE(pallettest.getItemName() == "Lego");
    REQUIRE(pallettest.getRemainingSpace() + pallettest.getItemCount() == 60);
    REQUIRE(pallettest.getItemCount() == 15);
}

TEST_CASE("Testcase voor getItemName"){
    Pallet pallettest("Lego", 60, 15);
    REQUIRE(pallettest.getItemName() == "Lego");
}

TEST_CASE("Testcase voor getRemainingSpace"){
    Pallet pallettest("Lego", 60, 15);
    REQUIRE(pallettest.getRemainingSpace() == 45);
}

TEST_CASE("Testcase voor getItemCount"){
    Pallet pallettest("Lego", 60, 15);
    REQUIRE(pallettest.getItemCount() == 15);
}

TEST_CASE("Testcase voor TakeOne"){
    Pallet pallettest("Lego", 60, 15);
    Pallet pallettest2("Barbie", 60, 0);
    REQUIRE(pallettest.takeOne() == 1);
    REQUIRE(pallettest2.takeOne() == 0);
}

TEST_CASE("Testcase voor PutOne"){
    Pallet pallettest("Lego", 60, 15);
    Pallet pallettest2("Barbie", 60, 60);
    REQUIRE(pallettest.takeOne() == 1);
    REQUIRE(pallettest2.takeOne() == 0);
}

// ############################################
//  Test Cases - Employee.
// ############################################ 

TEST_CASE("Test of het aanmaken van een employee lukt"){
    Employee employeeTest("Kees", true);
    REQUIRE(employeeTest.getName() == "Kees");
    REQUIRE(employeeTest.getForkliftCertificate() == true);
}

TEST_CASE("Testcase voor getName"){
    Employee employeeTest("Kees", true);
    REQUIRE(employeeTest.getName() == "Kees");
}

TEST_CASE("Testcase voor getForkliftCertificate"){
    Employee employeeTest("Kees", true);
    REQUIRE(employeeTest.getForkliftCertificate() == true);
}

TEST_CASE("Testcase voor setBusy"){
    Employee employeeTest("Kees", true);
    employeeTest.setBusy(true);
    REQUIRE(employeeTest.getBusy() == true);
}

// ############################################
//  Test Cases - PickItems.
// ############################################

TEST_CASE("Testcase voor PickItems, één specefiek product"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Lego", 100, 20),
        Pallet("Barbie", 100, 40),
        Pallet("Pokemon", 100, 10),
        Pallet("Lego", 100, 30)};
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.pickItems("Pokemon", 1) == true);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 9);
}

TEST_CASE("Testcase voor PickItems, alle items van een product"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Lego", 100, 20),
        Pallet("Barbie", 100, 40),
        Pallet("Pokemon", 100, 10),
        Pallet("Lego", 100, 30)};
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.pickItems("Lego", 50) == true);
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);
}

TEST_CASE("Testcase voor PickItems, alle items van een product in meerdere shelves"){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Lego", 100, 20),
        Pallet("Barbie", 100, 40),
        Pallet("Pokemon", 100, 10),
        Pallet("Lego", 100, 30)};
    
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Lego", 100, 10),
        Pallet("Barbie", 100, 40),
        Pallet("Pokemon", 100, 10),
        Pallet("Lego", 100, 30)};

    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    REQUIRE(warehouse.pickItems("Lego", 90) == true);
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[1].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[1].pallets[3].getItemCount() == 0);
}
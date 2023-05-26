#include <iostream>
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"
#include "src/include/employee.hpp"
#include "src/include/shelf.hpp"

int main(void)
{
    std::string enter;
    std::cout << "Welkom bij mijn demo van FA2 van adaptive programming." << std::endl;
    std::cout << "Eerst maken we een warenhuis aan en voegen daarna er waardes aan toe." << std::endl;
    std::cout << "Dit doen we om een goede presentatie te maken van de demo." << std::endl;
    std::cout << std::endl;

    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Barbie", 100, 15),
        Pallet("Pokemon", 100, 80),
        Pallet("Pokemon", 100, 2),
        Pallet("Lego", 100, 55)};
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Barbie", 100, 20),
        Pallet("Games", 100, 40),
        Pallet("Pokemon", 100, 30),
        Pallet("Barbie", 100, 10)};

    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addEmployee(Employee("Karel", true));

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {
            std::cout << "- Pallet: " << j << " item = " << warehouse.Shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.Shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "We voegen nu een een medewerker mee met een certificaat" << std::endl;
    std::cout << "Medewerker toegevoegd: " << warehouse.Employees[0].getName() << std::endl;
    std::cout << "Laten we nu een aantal dingen testen | Druk op enter om door te gaan." << std::endl;

    std::getline(std::cin, enter);

    std::cin.clear();

    // std::cout << "Now you may not have seen it but we shall print them out so you can see | Pres enter to continue." << std::endl;
    // std::getline(std::cin, enter);
    // warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // warehouse.rearrangeShelf(warehouse.Shelves[1]);
    
    // std::cin.clear();
    // std::cout << std::endl;

    // for (int i = 0; i < 2; i++)
    // {
    //     // loop
    //     std::cout << "Shelf " << i << std::endl;
    //     for (int j = 0; j < 4; j++)
    //     {

    //         std::cout << "-->Pallet: " << j << " item: " << warehouse.Shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.Shelves[i].pallets[j].getItemCount() << std::endl;
    //     }
    // }

    // std::cout << "Now lets say some one wants to buy 40 books." << std::endl;
    // std::cout << "This would in our case be everyting" << std::endl;
    // std::cout << "Now lets show if all the pallets with books have gone to zero | Pres enter to continue" << std::endl;

    // std::getline(std::cin, enter);
    // std::cin.clear();

    warehouse.pickItems("Books", 40);

    for (int i = 0; i < 2; i++)
    {
        // loop
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {

            std::cout << "- Pallet: " << j << " item: " << warehouse.Shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.Shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << "We kunnen ook de pallets aanvullen zoals we nu gaan laten zien. " << std::endl;
    std::cout << "Druk op enter voor de aanvulling van de producten" << std::endl;
    std::getline(std::cin, enter);
    std::cin.clear();

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {
            warehouse.Shelves[i].pallets[j].putOne();
            std::cout << "- Pallet: " << j << " item: " << warehouse.Shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.Shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << "Nu kunnen we ook er weer producten er van af trekken." << std::endl;
    std::getline(std::cin, enter);
    std::cin.clear();

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {
            warehouse.Shelves[i].pallets[j].takeOne();
            std::cout << "- Pallet: " << j << " item: " << warehouse.Shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.Shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Dit was een korte demo over dat de aplicatie werkt naar behoren." << std::endl;
    std::cout << std::endl;
}

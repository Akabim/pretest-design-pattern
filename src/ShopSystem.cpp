#include "ShopSystem.h"
#include "ModifierFactory.h"
#include <iostream>
#include <string>

IModifier* ShopSystem::OpenShop() {
    std::cout << "\n--- Welcome to the Shop ---" << std::endl;
    std::cout << "Available Modifiers:" << std::endl;
    std::cout << "1. Flat Bonus (+20 Chips)" << std::endl;
    std::cout << "2. Double Score (x2 Mult)" << std::endl;
    std::cout << "0. Skip Shop" << std::endl;
    
    std::cout << "Enter your choice (0-2): ";
    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "1") {
        std::cout << "[Shop] You bought Flat Bonus!\n" << std::endl;
        return ModifierFactory::CreateModifier("FlatBonus");
    } else if (choice == "2") {
        std::cout << "[Shop] You bought Double Score!\n" << std::endl;
        return ModifierFactory::CreateModifier("DoubleScore");
    }

    std::cout << "[Shop] You skipped the shop.\n" << std::endl;
    return nullptr;
}
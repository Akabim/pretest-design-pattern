#include "ScoringSystem.h"
#include <iostream>
#include <string>

void ScoringSystem::CalculateBaseScore(const std::vector<std::string>& cards, int& outChips, int& outMult) {
    int pairsFound = 0;

    for (size_t i = 0; i < cards.size(); i++) {
        for (size_t j = i + 1; j < cards.size(); j++) {
            std::string rank1 = cards[i].substr(1, cards[i].find(" of") - 1);
            std::string rank2 = cards[j].substr(1, cards[j].find(" of") - 1);
            
            if (rank1 == rank2) {
                pairsFound++;
            }
        }
    }

    if (pairsFound == 1) {
        std::cout << "[Scoring] Hand Type: ONE PAIR" << std::endl;
        outChips = 60; 
        outMult = 4;   
    } 
    else if (pairsFound > 1) {
        std::cout << "[Scoring] Hand Type: TWO PAIR / COMBO" << std::endl;
        outChips = 100;
        outMult = 5;   
    } 
    else {
        std::cout << "[Scoring] Hand Type: HIGH CARD" << std::endl;
        outChips = 30;
        outMult = 2;   
    }

    std::cout << "[Scoring] Base Chips: " << outChips << " | Base Mult: " << outMult << std::endl;
}
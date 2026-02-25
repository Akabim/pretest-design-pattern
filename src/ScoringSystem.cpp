#include "ScoringSystem.h"
#include <iostream>

void ScoringSystem::CalculateBaseScore(const std::vector<std::string>& cards, int& outChips, int&outMult) {
    outChips = cards.size() * 10;
    outMult = 2;

    std::cout << "[Scoring] Evaluated " << cards.size() << " cards." << std::endl;
    std::cout << "[Scoring] Base Chips: " << outChips << " | Base Mult: " << outMult << std::endl;
}
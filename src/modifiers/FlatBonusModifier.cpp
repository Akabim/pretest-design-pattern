#include "FlatBonusModifier.h"

std::string FlatBonusModifier::GetName() const {
    return "Flat Bonus (+20 Chips)";
}

void FlatBonusModifier::Apply(int& currentChips, int& currentMult) {
    currentChips += 20; 
}
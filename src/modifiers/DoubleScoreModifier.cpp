#include "DoubleScoreModifier.h"

std::string DoubleScoreModifier::GetName() const {
    return "Double Score (x2 Mult)";
}

void DoubleScoreModifier::Apply(int& currentChips, int& currentMult) {
    currentMult *= 2; 
}
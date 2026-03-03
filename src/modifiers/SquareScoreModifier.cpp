#include "SquareScoreModifier.h"

std::string SquareScoreModifier::GetName() const {
    return "Square Score (Mult ^ 2)";
}

void SquareScoreModifier::Apply(int& currentChips, int& currentMult) {
    currentMult = currentMult * currentMult;
}

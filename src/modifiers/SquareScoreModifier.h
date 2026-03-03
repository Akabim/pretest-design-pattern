#pragma once
#include "IModifier.h"

class SquareScoreModifier : public IModifier {
public:
    std::string GetName() const override;
    void Apply(int& currentChips, int& currentMult) override;
};
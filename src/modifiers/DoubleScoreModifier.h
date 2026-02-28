#pragma once
#include "IModifier.h"

class DoubleScoreModifier : public IModifier {
public:
    std::string GetName() const override;
    void Apply(int& currentChips, int& currentMult) override;
};
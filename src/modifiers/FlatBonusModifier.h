#pragma once
#include "IModifier.h"

class FlatBonusModifier : public IModifier {
public:
    std::string GetName() const override;
    void Apply(int& currentChips, int& currentMult) override;
};
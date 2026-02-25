#pragma once
#include <vector>
#include <string>

class ScoringSystem {
    public : 
    void CalculateBaseScore(const std::vector<std::string>& cards, int& outChips, int& outMult);
};
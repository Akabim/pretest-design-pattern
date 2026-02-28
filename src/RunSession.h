#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "modifiers/IModifier.h"

class RunSession {
    private:
        int currentRound;
        const int MAX_ROUNDS = 3;
        std::vector<std::string> playedCards;
        std::vector<IModifier*> activeModifier;

    public:
        RunSession();
        ~RunSession();
        void Start();

    private:
    void PlayHand();
    int CalculateScore();
    void Shop();
    void EndRun();
};
#pragma once
#include <iostream>
#include <vector>
#include <string>

class RunSession {
    private:
        int currentRound;
        const int MAX_ROUNDS = 3;
        std::vector<std::string> playedCards;

    public:
        RunSession();
        void Start();

    private:
    void PlayHand();
    void CalculateScore();
    void Shop();
    void EndRun();
};
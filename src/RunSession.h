#pragma once
#include <iostream>

class RunSession {
    private:
        int currentRound;
        const int MAX_ROUNDS = 3;

    public:
        RunSession();
        void Start();

    private:
    void PlayHand();
    void CalculateScore();
    void Shop();
    void EndRun();
};
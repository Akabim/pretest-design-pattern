#include "RunSession.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

RunSession::RunSession() : currentRound(1) {}

void RunSession::Start() {
    std::cout << "Start Session" << std::endl;

    while (currentRound <= MAX_ROUNDS) {
        std::cout << "\nRound : " << currentRound << std::endl;
        PlayHand();
        CalculateScore();
        Shop();

        currentRound++;
    }

    EndRun();
}

void RunSession::PlayHand() {
    std::cout << "Play Hand" << std::endl;


    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    std::cout << "Your Hand: ";
    for (int i = 0; i < 5; i++)
    {
        std::string rank = ranks[std::rand() % 13];
        std::string suit = suits[std::rand() % 4];
        std::cout << rank << " of " << suit << ", ";
    }

    std::cout << std::endl;
}

void RunSession::CalculateScore() {
    std::cout << "Calculate Score" << std::endl;
}

void RunSession::Shop() {
    std::cout << "Enter Shop" << std::endl;
}

void RunSession::EndRun() {
    std::cout << "\nEnd Run" << std::endl;
}


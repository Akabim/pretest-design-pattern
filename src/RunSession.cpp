#include "ScoringSystem.h"

#include "RunSession.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>

RunSession::RunSession() : currentRound(1) {
    std::srand(std::time(nullptr));
}

void RunSession::Start() {
    std::cout << "Start run" << std::endl;

    while (currentRound <= MAX_ROUNDS) {
        std::cout << "\nRound : " << currentRound << std::endl;

        int targetScore = 200 * currentRound;
        std::cout << "target : " << targetScore << " Chips" << std::endl;


        PlayHand();
        CalculateScore();
        Shop();

        std::cout << "\nEnd of round " << currentRound << std::endl;

        if (currentRound < MAX_ROUNDS)
        {
           std::string dummy;
           std::cout << "Press Enter to start the next round...";
           std::getline(std::cin, dummy);
        }
        

        currentRound++;
    }

    EndRun();
}


void RunSession::PlayHand() {
    std::cout << "Play Hand" << std::endl;
    
    std::string dummy;
    std::cout << "Press Enter to draw cards...";
    std::getline(std::cin, dummy);

    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::vector<std::string> drawnCards;

    std::cout << "Drawing 8 cards.... " << std::endl;
    for (int i = 0; i < 8; i++) {
        std::string rank = ranks[std::rand() % 13];
        std::string suit = suits[std::rand() % 4];
        drawnCards.push_back("[" + rank + " of " + suit + "]");
    }

    for (int i = 0; i < drawnCards.size(); i++) {
        std::cout << i + 1 << ": " << drawnCards[i] << "  ";
        if (i == 3) std::cout << "\n";
    }
    std::cout << "\n\n";

    playedCards.clear(); // Bersihkan kartu dari ronde sebelumnya
    std::cout << "Select 5 cards to play (enter numbers 1-8 separated by space, e.g., 1 3 4 5 8): ";

    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int cardIndex;
    int count = 0;

    std::cout << "\nYou Played : " << std::endl;

    while (ss >> cardIndex && count < 5) {
        if (cardIndex >= 1 && cardIndex <= 8) {
            playedCards.push_back(drawnCards[cardIndex - 1]);
            std::cout << drawnCards[cardIndex - 1] << " ";
            count++;
        }
    }
    std::cout << "\n" << std::endl;
}

void RunSession::CalculateScore() {
    std::cout << "Calculate Score" << std::endl;
    
    ScoringSystem scorer;
    int currentChips = 0;
    int currentMult = 0;

    scorer.CalculateBaseScore(playedCards, currentChips, currentMult);

    int totalScore = currentChips * currentMult;
    std::cout << "TOTAL SCORE: " << totalScore << "\n" << std::endl;
}

void RunSession::Shop() {
    std::cout << "Enter Shop" << std::endl;
}

void RunSession::EndRun() {
    std::cout << "\nEnd Run" << std::endl;
}


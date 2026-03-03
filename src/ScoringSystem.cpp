#include "ScoringSystem.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int rankToValue(std::string rank) {
    if (rank == "A") return 14;
    if (rank == "K") return 13;
    if (rank == "Q") return 12;
    if (rank == "J") return 11;
    if (rank == "10") return 10;
    return std::stoi(rank); 
}

void ScoringSystem::CalculateBaseScore(const std::vector<std::string>& cards, int& outChips, int& outMult) {
    std::map<std::string, int> rankCounts;
    std::vector<int> values;
    bool isFlush = true;

    for (size_t i = 0; i < cards.size(); i++) {
        std::string rank = cards[i].substr(1, cards[i].find(" of") - 1);
        rankCounts[rank]++;
        values.push_back(rankToValue(rank));

        // check flush
        size_t suitStart = cards[i].find("of ") + 3;
        std::string suit = cards[i].substr(suitStart, cards[i].find("]") - suitStart);
        
        if (i > 0) {
            size_t firstSuitStart = cards[0].find("of ") + 3;
            std::string firstSuit = cards[0].substr(firstSuitStart, cards[0].find("]") - firstSuitStart);
            if (suit != firstSuit) isFlush = false;
        }
    }

    // sort
    std::sort(values.begin(), values.end());
    bool isStraight = true;
    for (size_t i = 1; i < values.size(); i++) {
        if (values[i] != values[i-1] + 1) {
            isStraight = false;
            break;
        }
    }

    // count pairs
    int pairs = 0, triples = 0, quads = 0;
    for (auto const& [rank, count] : rankCounts) {
        if (count == 4) quads++;
        if (count == 3) triples++;
        if (count == 2) pairs++;
    }

    if (isStraight && isFlush) {
        std::cout << "[Scoring] Hand Type: STRAIGHT FLUSH! (GODLIKE)" << std::endl;
        outChips = 250; outMult = 15;
    } else if (quads == 1) {
        std::cout << "[Scoring] Hand Type: FOUR OF A KIND" << std::endl;
        outChips = 200; outMult = 12;
    } else if (triples == 1 && pairs == 1) {
        std::cout << "[Scoring] Hand Type: FULL HOUSE" << std::endl;
        outChips = 160; outMult = 10;
    } else if (isFlush) {
        std::cout << "[Scoring] Hand Type: FLUSH" << std::endl;
        outChips = 120; outMult = 8;
    } else if (isStraight) {
        std::cout << "[Scoring] Hand Type: STRAIGHT" << std::endl;
        outChips = 100; outMult = 8;
    } else if (triples == 1) {
        std::cout << "[Scoring] Hand Type: THREE OF A KIND" << std::endl;
        outChips = 80; outMult = 6;
    } else if (pairs == 2) {
        std::cout << "[Scoring] Hand Type: TWO PAIR" << std::endl;
        outChips = 50; outMult = 4;
    } else if (pairs == 1) {
        std::cout << "[Scoring] Hand Type: ONE PAIR" << std::endl;
        outChips = 30; outMult = 3;
    } else {
        std::cout << "[Scoring] Hand Type: HIGH CARD" << std::endl;
        outChips = 10; outMult = 2;
    }

    std::cout << "[Scoring] Base Chips: " << outChips << " | Base Mult: " << outMult << std::endl;
}
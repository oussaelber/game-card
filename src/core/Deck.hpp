#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include "Card.hpp"

class Deck {
public:
    // Stores all cards in the deck
    std::vector<std::unique_ptr<Card>> cards;

    // Adds a card to the deck
    void addCard(std::unique_ptr<Card> card) {
        cards.push_back(std::move(card));
    }

    // Shuffles the deck randomly
    void shuffle() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::shuffle(cards.begin(), cards.end(), rng);
    }

    // Draws the top card and removes it from the deck
    std::unique_ptr<Card> drawCard() {
        if (cards.empty()) return nullptr;
        std::unique_ptr<Card> top = std::move(cards.back());
        cards.pop_back();
        return top;
    }

    // Returns true if the deck has no cards left
    bool isEmpty() const {
        return cards.empty();
    }

    // Returns the number of remaining cards
    int size() const {
        return static_cast<int>(cards.size());
    }
};
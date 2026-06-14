#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Deck.hpp"

class Player {
public:
    std::string name;
    int hp;
    int actionsLeft;  // Remaining actions this turn
    Deck deck;

    // Cards currently in the player's hand
    std::vector<std::unique_ptr<Card>> hand;

    // Monsters currently on the field
    std::vector<std::unique_ptr<Card>> field;

    // Trap cards placed on the field (max 2)
    std::vector<std::unique_ptr<Card>> traps;

    // Maximum traps allowed on field
    static constexpr int MAX_TRAPS = 2;

    // Number of actions per turn
    static constexpr int ACTIONS_PER_TURN = 3;

    Player(const std::string& name, int hp = 200)
        : name(name), hp(hp), actionsLeft(ACTIONS_PER_TURN){}

    // Draws one card from deck into hand
    void drawCard() {
        if (!deck.isEmpty()) {
            hand.push_back(deck.drawCard());
        }
    }

    // Draws multiple cards at once
    void drawCards(int count) {
        for (int i = 0; i < count; i++) drawCard();
    }

    // Places a trap on the field — returns false if field is full
    bool placeTrap(std::unique_ptr<Card> trap) {
        if (static_cast<int>(traps.size()) >= MAX_TRAPS) return false;
        traps.push_back(std::move(trap));
        return true;
    }

    // Summons a monster onto the field
    void summonMonster(std::unique_ptr<Card> monster) {
        field.push_back(std::move(monster));
    }

    // Reduces player HP by amount — cannot go below 0
    void takeDamage(int amount) {
        hp -= amount;
        if (hp < 0) hp = 0;
    }

    // Called when player's monster dies — loses 10% of monster's HP
    void onMonsterDeath(int monsterHp) {
        takeDamage(monsterHp / 10);
    }

    // Resets actions at the start of a new turn
    void beginTurn() {
        actionsLeft = ACTIONS_PER_TURN;
    }

    // Uses one action — returns false if no actions left
    bool useAction() {
        if (actionsLeft <= 0) return false;
        actionsLeft--;
        return true;
    }

    // Returns true if player has no HP left
    bool isDefeated() const { return hp <= 0; }

    // Returns number of cards in hand
    int handSize()  const { return static_cast<int>(hand.size()); }

    // Returns number of monsters on field
    int fieldSize() const { return static_cast<int>(field.size()); }
};
#pragma once
#include "Card.hpp"

class AttackDefenseCard : public Card{
public:
    int attack;
    int defense;
    bool isTrap;
    std::string specialAbility;

    AttackDefenseCard(int id, const std::string& name, const std::string& description, TerrainType terrainType, int attack, int defense, bool isTrap, const std::string& specialAbility):Card(id,name,description,terrainType), attack(attack), defense(defense), isTrap(isTrap), specialAbility(specialAbility){}

    std::string getType() const override{
        return "AttackDefenseCard";
    }
};


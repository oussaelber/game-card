#pragma once
#include<string>
#include "Card.hpp"

class AttackDefenseCard : public Card{
public:
    int attack;
    int hp;
    int maxHp;// original HP, never changes, used for death penalty
    bool isTrap;
    std::string specialAbility;
    std::string rarity;

    AttackDefenseCard(int id, const std::string& name, const std::string& description, TerrainType terrainType, int attack, int hp, bool isTrap, const std::string& specialAbility,const std::string& rarity):Card(id,name,description,terrainType), attack(attack), hp(hp), maxHp(hp), isTrap(isTrap), specialAbility(specialAbility), rarity(rarity){}

    std::string getType() const override{
        return "AttackDefenseCard";
    }
};


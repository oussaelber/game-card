#pragma once
#include "../core/Player.hpp"
#include "../core/AttackDefenseCard.hpp"
#include "../world/Terrain.hpp"
#include "AbilitySystem.hpp"

class BattleSystem {
public:
    //Executes one monster attacking another monster
    static void attack(Player& attacker, Player& defender, AttackDefenseCard& attackerCard, AttackDefenseCard& defenderCard, const Terrain& terrain){
        //calculate base damage with terrain bonus
        float multiplier=terrain.getMultiplier(attackerCard.terrainType);
        int damage = static_cast<int>(attackerCard.attack*multiplier);

        //chek if defender has an active trap to activate
        if(!defender.traps.empty()){
            auto& trap=defender.traps.front();
            TrapResult result= AbilitySystem::executeTrap(
                trap->specialAbility, defender, attacker, damage
            );

            //traps are single use, remove after activation
            defender.traps.erase(defender.traps.begin());
            
            if(result.blocked){
                if(result.reflected){
                    //damage bounces back to the attacker's monster
                    applyDamageToMonster(attacker,attackerCard,damage);
                }
                return; //stop attack
            }
        }

        //apply damage to the defending monster
        applyDamageToMonster(defender, defenderCard, damage);
    }

private:
    //applies damage to monster's hp, handles death and the 10% penalty
    static void applyDamageToMonster(Player& owner, AttackDefenseCard& monster, int damage){
        monster.hp-=damage;
        if (monster.hp<=0){
            monster.hp=0;
            owner.onMonsterDeath(monster.maxHp);//use original hp
        }
    }
}; 
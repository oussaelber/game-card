#pragma once
#include "../core/Player.hpp"
#include "../core/AttackDefenseCard.hpp"
#include "../world/Terrain.hpp"
#include "AbilitySystem.hpp"

class BattelSystem{
public:
    static void attack(Player& attacker, Player& defender, AttackDefenseCard& attackCard, AttackDefenseCard& defenderCard, const Terrain& terrain){
        // calculate base damage with terrain bonus
        float multiplier =  terrain.getMultiplier(attackCard.terrainType);
        int damge = static_cast<int>(attackCard.attack*multiplier);

        //check if defender has an active trap to activate
        if(!defender.traps.empty()){
            auto& trap=defender.traps.front();
            TrapResult result = AbilitySystem::executeTrap(
                trap-> specialAbility, defender,attacker,damage);
            
            //Remove the trap after use — traps are single-use
            defender.traps.erase(defender.traps.begin());

            if(result.blocked) {
                //Damage was fully blocked
                if (result.reflected){
                    applyDamageToMonster(attacker, attackCard, damge);
                }
                return;
            }
        }

        //apply damage to the defending monster
        applyDamageToMonster(defender, defenderCard, damage);
    }

private:
    //Applies damage to a monster's hp, handles death and the 10% penalty
    static void applyDamageToMonster(Player& owner, AttackDefenseCard& monster, int damage){
        monster.hp-=damage;
        if(monster.hp<=0){
            monster.hp=0;
            owner.onMonsterDeath(monster.hp)
        }
    }
};
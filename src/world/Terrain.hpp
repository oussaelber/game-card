#pragma once
#include<string>
#include<array>
#include<cstdlib>
#include "TerrainType.hpp"

class Terrain{
public:
    TerrainType current;

    Terrain(){
        std::array<TerrainType, 6> all={
            TerrainType::Ocean,
            TerrainType::Jungle,
            TerrainType::Mountain,
            TerrainType::Desert,
            TerrainType::Volcano,
            TerrainType::Ice
        };
        current = all[std::rand() % 6];
    }
    std::string getName() const{
        switch (current){
            case TerrainType::Ocean: return "Ocean";
            case TerrainType::Jungle: return "Jungle";
            case TerrainType::Mountain: return "Mountain";
            case TerrainType::Desert: return "Desert";
            case TerrainType::Volcano: return "Volcano";
            case TerrainType::Ice: return "Ice";
            default: return"None";   
        }
    }
        float getMultiplier(TerrainType cardTerrain) const{
            if (cardTerrain==TerrainType::None) return 1.0f;
            if(cardTerrain==current) return 1.05f;
            if(isOpposite(cardTerrain)) return 0.95f;
            return 1.0f;
        }
private:
        bool isOpposite(TerrainType t) const{
            if(current==TerrainType::Ocean && t==TerrainType::Volcano) return true;
            if(current==TerrainType::Volcano && t==TerrainType::Ocean) return true;
            if(current==TerrainType::Jungle && t==TerrainType::Desert) return true;
            if(current==TerrainType::Desert && t==TerrainType::Jungle) return true;
            if(current==TerrainType::Mountain && t==TerrainType::Ice) return true;
            if(current==TerrainType::Ice && t==TerrainType::Mountain) return true;
            return false;
        }
};
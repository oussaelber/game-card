#pragma once
#include <string>

enum class TerrainType{
    Ocean,
    Jungle,
    Mountain,
    Desert,
    Volcano,
    Ice,
    None
};

inline TerrainType terrainFromString(const std::string& s){
    if(s=="Ocean") return TerrainType::Ocean;
    if(s=="Jungle") return TerrainType::Jungle;
    if(s=="Mountain") return TerrainType::Mountain;
    if(s=="Desert") return TerrainType::Desert;
    if(s=="Volcano") return TerrainType::Volcano;
    if(s=="Ice") return TerrainType::Ice;
    return TerrainType::None;
}
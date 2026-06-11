#pragma once
#include <string>
#include "../world/TerrainType.hpp"

class Card{
public:
    int id;
    std::string name;
    std::string description;
    TerrainType terrainType;

    Card(int id, const std::string& name, const std::string& description, TerrainType terrainType)
    : id(id),name(name),description(description),terrainType(terrainType){}

    virtual ~Card() = default;

    virtual std::string getType() const = 0;
};
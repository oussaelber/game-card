#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "../../include/nlohmann/json.hpp"
#include "AttackDefenseCard.hpp"

class CardLoader {
public:
    // Reads a JSON file and returns a vector of cards
    static std::vector<std::unique_ptr<Card>> loadFromFile(const std::string& path) {
        std::vector<std::unique_ptr<Card>> cards;

        // Open the file
        std::ifstream file(path);
        if (!file.is_open()) return cards;

        // Parse the file content into a JSON object
        nlohmann::json data = nlohmann::json::parse(file);

        // Loop through each card entry in the JSON array
        for (const auto& entry : data) {
            int         id             = entry["id"];
            std::string name           = entry["name"];
            std::string description    = entry["description"];
            std::string terrainStr     = entry["terrain"];
            int         attack         = entry["attack"];
            int         defense        = entry["defense"];
            bool        isTrap         = entry["isTrap"];
            std::string specialAbility = entry["specialAbility"];
            std::string rarity = entry["rarity"];

            // Convert terrain string to enum
            TerrainType terrain = terrainFromString(terrainStr);

            // Create the card and add it to the list
            cards.push_back(std::make_unique<AttackDefenseCard>(id, name, description, terrain, attack, defense, isTrap, specialAbility,rarity));
        }
        return cards;
    }
};
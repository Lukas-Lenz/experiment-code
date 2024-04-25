#include "Field.h"

void Field::soilUpdate(const State &state) {

    // freeze frame state to base calculations on

    // for every tile:
    // moisture spread
    // nutrient spread
    // moisture loss
    // nutrient loss
    // vitality update
    auto tmpTiles = soilTiles;

    for(std::size_t y = 0; y < soilTiles.size(); y++)
        for(std::size_t x = 0; x < soilTiles.at(y).size(); x++) {

            // spread moisture and minerals from base values to neighboring tiles

            Soil &referenceTile = tmpTiles.at(y).at(x);
            auto type = referenceTile.getType();
            
            // TODO: make soil value change depend on progress + change

            float moistureSpread = referenceTile.getMoisture() * type->moisture_spread;
            float mineralSpread = referenceTile.getMinerals() * type->mineral_spread;
            
            if(y != 0) {
                soilTiles.at(y-1).at(x).changeMoisture(moistureSpread);
                soilTiles.at(y-1).at(x).changeMinerals(mineralSpread);
            }

            if(y != soilTypes.size() - 1) {
                soilTiles.at(y+1).at(x).changeMoisture(moistureSpread);
                soilTiles.at(y+1).at(x).changeMinerals(mineralSpread);
            }

            if(x != 0) {
                soilTiles.at(y).at(x-1).changeMoisture(moistureSpread);
                soilTiles.at(y).at(x-1).changeMinerals(mineralSpread);
            }

            if(x != soilTypes.size() - 1) {
                soilTiles.at(y).at(x+1).changeMoisture(moistureSpread);
                soilTiles.at(y).at(x+1).changeMinerals(mineralSpread);
            }

            Soil &actualTile = soilTiles.at(y).at(x);

            auto moistureLoss = 4 * moistureSpread + type->moisture_loss;
            actualTile.changeMoisture(-moistureLoss);

            auto mineralLoss = 4 * mineralSpread + type->mineral_loss;
            actualTile.changeMinerals(-mineralLoss);

            // vitality change depends on growth value
            

        }

}

void Field::plantUpdate(const State &state) {

    for(auto y = 0; y < plants.size(); y++)
        for(auto x = 0; x < plants.at(y).size(); x++) {

            Soil &soil = soilTiles.at(y).at(x);
            Plant &plant = plants.at(y).at(x);

            if(plant.getName() == "none" || plant.isDead())
                continue;

            auto available_moisture = soil.getMoisture();
            auto available_minerals = soil.getMinerals();

            auto used_moisture = plant.consumeMoisture(state, available_moisture);
            auto used_minerals = plant.consumeMinerals(state, available_minerals);

            soil.changeMoisture(-used_moisture);
            soil.changeMinerals(-used_minerals);

            auto ph = soil.getPH();

            plant.grow(state, ph);

        }

}

void Field::update(const State &state) {

    plantUpdate(state);
    soilUpdate(state);

}
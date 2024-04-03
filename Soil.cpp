#include "Actor.cpp"

#include <map>
#include <memory>
#include <vector>

class SoilType {

public:

    SoilType(const std::string name, const float moisture_retention, const float mineral_retention, 
    const float base_nutrients, const float nutrient_availability, const float base_vitality) 
    : name{name}, moisture_retention {moisture_retention}, mineral_retention {mineral_retention},
    base_nutrients {base_nutrients}, nutrient_availability {nutrient_availability}, base_vitality {base_vitality} {}

    const std::string name;

    const float moisture_retention;
    const float mineral_retention;

    const float base_nutrients;
    const float nutrient_availability;

    const float base_vitality;

};

class Soil : public Actor {

public:

    void update(const State &state) override;
    void change_moisture(const float change);
    void change_minerals(const float change);
    void change_vitality(const float change);
    void change_ph(const float change);

    float getVitality() const;
    float getMoisture() const;
    float getMinerals() const;
    float getPh() const;

private:

    std::shared_ptr<SoilType> base_type;
    float vitality;
    float moisture;
    float minerals;
    float ph;

};

void Soil::update(const State &state) {

    auto moisture_retention = base_type->moisture_retention;
    auto mineral_retention = base_type->mineral_retention;

    moisture *= moisture_retention;

}

class Field : public Actor
{
    public:

    void init_soil_types(std::map<std::string, std::shared_ptr<SoilType>> &type_container);

    void make_tile(const std::string name);

    std::shared_ptr<SoilType> getSoilType(const std::string name);

    void update(const State &state);


    private:

    std::map<std::string, std::shared_ptr<SoilType>> soil_types;

    std::vector<std::vector<Soil>> soil_tiles;
    
};

std::shared_ptr<SoilType> Field::getSoilType(const std::string name)
    {
        return soil_types.at(name);
    }

void Field::update(const State &state) {

    for(auto row : soil_tiles)
        for(auto tile : row)
            tile.update(state);

}

void Field::make_tile(const std::string name) {

}

void Field::init_soil_types(std::map<std::string, std::shared_ptr<SoilType>> &type_container)
    {
        type_container.emplace("loamy", std::make_shared<SoilType>("Loamy Soil", 0.5, 0.9, 200, 1, 8));
        type_container.emplace("sandy", std::make_shared<SoilType>("Sandy Soil", 0.1, 0.6, 50, 0.5, 2));
        type_container.emplace("clay", std::make_shared<SoilType>("Clay Soil", 0.8, 0.8, 150, 0.8, 5));
        type_container.emplace("dead", std::make_shared<SoilType>("Dead Soil", 0.4, 0.8, 10, 0.8, 0));
    }
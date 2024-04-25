#ifndef HEADER_H_SOIL
#define HEADER_H_SOIL

#include "UpdateObject.h"

#include <map>
#include <memory>
#include <vector>

class SoilType {

public:

    SoilType(const std::string name, const float moisture_retention, const float mineral_retention, 
    const float base_nutrients, const float nutrient_availability, const float base_vitality);

    const std::string name;

    const float moisture_spread;
    const float mineral_spread;

    const float moisture_loss;
    const float mineral_loss;

    const float base_minerals;
    const float nutrient_availability;

    const float base_vitality;

};

class Soil {

public:

    void changeMoisture(const float change);
    void changeMinerals(const float change);
    void changeVitality(const float change);
    void changePH(const float change);

    float getVitality() const;
    float getMoisture() const;
    float getMinerals() const;
    float getPH() const;

private:

    std::shared_ptr<SoilType> base_type;
    float vitality;
    float moisture;
    float minerals;
    float ph;

};

#endif
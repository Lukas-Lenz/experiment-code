#include "Soil.h"

SoilType::SoilType(const std::string name, const float moisture_retention, const float mineral_retention, 
    const float base_nutrients, const float nutrient_availability, const float base_vitality) 
    : name{name}, moisture_retention {moisture_retention}, mineral_retention {mineral_retention},
    base_nutrients {base_nutrients}, nutrient_availability {nutrient_availability}, base_vitality {base_vitality} {}

void Soil::update(const State &state) {

    auto moisture_retention = base_type->moisture_retention;
    auto mineral_retention = base_type->mineral_retention;

    moisture *= moisture_retention;

}


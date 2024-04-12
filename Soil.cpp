#include "UpdateObject.cpp"

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

class Soil : public UpdateObject {

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


#ifndef HEADER_H_PLANT
#define HEADER_H_PLANT

#include <string>

#include "State.h"

class Plant {

    public:

    // returns amount of minerals/moisture actually consumed!!
    float consumeMinerals(const State &state, const float &minerals_available);
    float consumeMoisture(const State &state, const float &moisture_available);
    void grow(const State &state, const float ph);

    std::string getName() const;
    bool isDead() const;

    private:

    std::string name;

    bool dead;

    float stored_water;
    float stored_minerals;

    float water_cap;
    float mineral_cap;

    float water_required;
    float minerals_required;

    float growth_rate;
    float total_growth;

    float ideal_ph;
    float ph_tolerance;

    float total_health;

};

#endif
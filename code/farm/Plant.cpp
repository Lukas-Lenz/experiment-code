#include <cmath>

#include "Plant.h"
#include "State.h"

//TODO: incorporate growth value in growth processes


float Plant::consumeMinerals(const State &state, const float &minerals_available) {

    auto minerals_used = minerals_required;

    if(minerals_available < minerals_required)
        minerals_used = minerals_available;

    if(stored_minerals + minerals_used > mineral_cap)
        minerals_used = mineral_cap - stored_minerals;

    stored_minerals += minerals_used;

    return minerals_used;

}

float Plant::consumeMoisture(const State &state, const float &moisture_available) {

    auto water_used = water_required;

    if(moisture_available < water_required)
        water_used = moisture_available;

    if(stored_water + water_used > water_cap)
        water_used = water_cap - stored_water;

    stored_water += water_used;

    return water_used;

}

void Plant::grow(const State &state, const float ph) {

    if(dead)
        return;

    // health requirements met?
    if(ph > ideal_ph + ph_tolerance || ph < ideal_ph + ph_tolerance) {
        
        //absolute value of deviation minus 
        float deviation = std::abs(std::abs(ideal_ph - ph) - ph_tolerance);
        total_health -= deviation*2;

    }

    if(stored_water < water_required) {

        float deviation = water_required - stored_water;
        total_health -= deviation;
        stored_water = 0;

    } else {
        stored_water -= water_required;
    }

    if(stored_minerals < minerals_required) {

        float deviation = minerals_required - stored_minerals;
        total_health -= deviation;
        stored_minerals = 0;

    } else {
        stored_minerals -= minerals_required;
    }

    if(total_health <= 0) {
        total_health = 0;
        dead = true;
    }
    
    // grow depending on health

    float growth = rate_factor * 0.01 * total_health;
    total_growth += growth;

}
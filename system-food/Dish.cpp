#include "Dish.h"

bool Dish::check_recipe(const std::string tool, const std::vector<std::string> ingredients) const {

    bool correct_tool = false;
 
    for(const auto &allowed : tools)
        if(tool == allowed)
            correct_tool = true;

    if(!correct_tool)
        return false;        

    //create a tick-down list for ingredient specification


}


Dish Cooker::find_best_match(std::string tool, std::vector<std::string> ingredients, Dish base_dish) const {

    for(auto dish : base_dish.getDerived())
        if(dish->check_recipe(tool, ingredients))
            return find_best_match(tool, ingredients, *dish);

    return base_dish;

}

std::vector<Dish> Cooker::match_recipe(std::string tool, std::vector<std::string> ingredients) const {

    std::vector<Dish> closest_matches;

    for(Dish dish : root_recipes) {
        if(dish.check_recipe(tool, ingredients)) {
            Dish best = find_best_match(tool, ingredients, dish);
            closest_matches.push_back(best);
        }
    }

    return closest_matches;

}

void Cooker::load_dishes(const std::string path){

    // load ingredient dictionary

    // read in recipe

    // save "root" dishes

    // map where each dish saves the dishes that consider it a base
    std::map<std::string, std::vector<std::string>> derived_recipes;


}
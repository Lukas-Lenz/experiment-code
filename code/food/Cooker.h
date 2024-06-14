#ifndef HEADER_H_COOKER
#define HEADER_H_COOKER

#include <string>
#include <vector>
#include <map>

#include "Dish.h"


class Cooker {

public:

    Dish match_recipe(std::string tool, std::vector<std::string> ingredients) const;
    void load_dishes(const std::string path);

    //void add(const std::string name, const Dish dish);
    void add_recipe(const std::string name, const std::vector<std::string> tools, const IngredientList ingredients, const std::string base = "");
    void add_from_data(const std::string name, const std::string tools, const std::string ingredients, const std::string base);

private:

    Dish find_best_match(std::string tool, std::vector<std::string> ingredients, Dish base_dish) const;
    
    std::vector<std::string> root_keys;
    std::map<std::string, Dish> recipes;

};

#endif
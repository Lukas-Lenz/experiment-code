#include <string>
#include <vector>
#include <memory>
#include <map>

class Dish {

public:

    bool check_recipe(const std::string tool, const std::vector<std::string> ingredients) const;
    std::vector<std::shared_ptr<Dish>> getDerived() const;

private:

    using IngredientList = std::vector<std::tuple<std::string, std::string>>;

    const std::string name;
    const std::vector<std::string> tools;
    const IngredientList ingredients;

    std::vector<std::shared_ptr<Dish>> derived_dishes;
    std::shared_ptr<Dish> base_dish;

};

bool Dish::check_recipe(const std::string tool, const std::vector<std::string> ingredients) const {

    bool correct_tool = false;
 
    for(const auto &allowed : tools)
        if(tool == allowed)
            correct_tool = true;

    if(!correct_tool)
        return false;        

    //create a tick-down list for ingredient specification


}





class Cooker {

public:

    std::vector<Dish> match_recipe(std::string tool, std::vector<std::string> ingredients) const;
    void load_dishes(const std::string path);

private:

    Dish find_best_match(std::string tool, std::vector<std::string> ingredients, Dish base_dish) const;
    
    std::vector<Dish> root_recipes;
    std::vector<Dish> recipe_book;
    std::map<std::string, std::vector<std::string>> ingredient_dictionary;

};

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
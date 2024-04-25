#ifndef HEADER_H_DISH
#define HEADER_H_DISH

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

#endif
#include "Dish.h"
#include <algorithm>

bool operator==(const Ingredient &lhs, const Ingredient &rhs) {
    
    return lhs.name == rhs.name;

}

Ingredient::Ingredient(const std::string name, const std::vector<std::string> types)
    : name{name}, types{types} {}

bool Ingredient::isIn(const std::string categories) const {

    std::stringstream catstream (categories);

    while(catstream.good()) {
        std::string substr;
        getline(catstream, substr, '/');
        
        if(substr == this->name) // exact match
            return true;
        
        for(const std::string type : types) // category match
            if(substr == type)
                return true;
    }

    return false;

}

IngredientList::IngredientList() {}
    
IngredientList::IngredientList(std::vector<std::string> ingredient_list) {

    for(std::string ingr : ingredient_list)
        this->add(ingr, 1, false);

}

bool IngredientList::fit(const Ingredient ingredient) {

    for(auto &triple : list) {

        const std::string &categories = std::get<std::string>(triple);
        int &quantity = std::get<int>(triple);
        const bool &exact = std::get<bool>(triple);

        if(ingredient.isIn(categories)) {

            if(!exact || quantity > 0) {
                quantity--;
                return true;
            }
        
        }
    }

    return false;

}

bool IngredientList::is_fulfilled() const {

    for(auto &tuple : this->list) {

        int quantity_required = std::get<int>(tuple);

        if(quantity_required > 0)
            return false;
    }

    return true;

}

Dish::Dish(const std::string name, const std::vector<std::string> tools, const IngredientList ingredients, const std::string base = "") 
: name{name}, tools{tools}, ingredients{ingredients}, base_dish{base}, derived_dishes{} {}

bool Dish::check_recipe(const std::string tool, const std::vector<Ingredient> given_ingredients) const {

    bool correct_tool = false;
 
    for(const auto &allowed : tools)
        if(tool == allowed)
            correct_tool = true;

    if(!correct_tool)
        return false;        

    //create a tick-down list for ingredient specification
    //TODO
    //(name/category, #still needed, more allowed)
    // [(water, 1, false)]
    IngredientList potential_ingredients = this->ingredients;
    
    for(auto ingredient : given_ingredients) {

        bool found = potential_ingredients.fit(ingredient);
        
        if(!found)
            return false;

    }

    return potential_ingredients.is_fulfilled();

}
    
std::vector<std::string> Dish::getDerived() const { return derived_dishes; }

void Dish::addDerived(std::string dish) {

    if(std::find(derived_dishes.begin(), derived_dishes.end(), dish) != derived_dishes.end())
        return; //dish already registered for some reason

    derived_dishes.push_back(dish);

}

std::string Dish::getBase() const { return base_dish; }

std::string Dish::getName() const { return name; }

std::vector<std::string> Dish::getTools() const { return tools; }

IngredientList Dish::getIngedientList() const { return ingredients; }
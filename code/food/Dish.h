#ifndef HEADER_H_DISH
#define HEADER_H_DISH

#include <string>
#include <vector>
#include <memory>
#include <sstream>

struct Ingredient {

    const std::string name;
    const std::vector<std::string> types;

    bool isIn(const std::string type) const;

};

bool operator==(const Ingredient &lhs, const Ingredient &rhs);

class IngredientList {

public:

    void add(const std::string ingredient, const int quantity, const bool exact);

    // define iterator instead?
    IngredientList &get();

    bool fit(const Ingredient ingredient);
    bool is_fulfilled() const;

private:

    std::vector<std::tuple<std::string, int, bool>> list;

};


class Dish {

public:

    Dish(const std::string name, const std::vector<std::string> tools, const IngredientList ingredients, const std::string base = "");

    bool check_recipe(const std::string tool, const std::vector<Ingredient> ingredients) const;
    
    std::vector<std::string> getDerived() const;
    void addDerived(std::string dish);

    std::string getBase() const;
    std::string getName() const;
    std::vector<std::string> getTools() const;
    IngredientList getIngedientList() const;

private:

    const std::string name;
    const std::vector<std::string> tools;
    const IngredientList ingredients;

    std::vector<std::string> derived_dishes;
    const std::string base_dish;

};

#endif
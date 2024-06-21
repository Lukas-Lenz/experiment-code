#ifndef HEADER_H_DISH
#define HEADER_H_DISH

#include <string>
#include <vector>
#include <memory>
#include <sstream>

struct Ingredient {

    const std::string name;
    const std::vector<std::string> types;

    Ingredient(const std::string name, const std::vector<std::string> types);

    bool isIn(const std::string type) const;

};

bool operator==(const Ingredient &lhs, const Ingredient &rhs);

class IngredientList {

public:

    IngredientList();
    IngredientList(std::vector<std::string> ingredient_list);

    void add(const std::string ingredient, const int quantity = 1, const bool exact = false);

    // define iterator instead?
    IngredientList &get();

    bool fit(const Ingredient ingredient);
    bool is_fulfilled() const;

private:

    std::vector<std::tuple<std::string, int, bool>> list;

};


class Dish {

public:

    Dish(std::string name, std::vector<std::string> tools, IngredientList ingredients, Dish *base = nullptr);

    bool check_recipe(const std::string tool, const std::vector<Ingredient> ingredients) const;
    
    std::vector<Dish *> getDerived() const;
    void addDerived(Dish *derived);

    Dish* getBase() const;
    std::string getName() const;
    std::vector<std::string> getTools() const;
    IngredientList getIngedientList() const;

private:

    std::string name;
    std::vector<std::string> tools;
    IngredientList ingredients;

    std::vector<Dish*> derived_dishes;
    Dish* base_dish;

};

#endif
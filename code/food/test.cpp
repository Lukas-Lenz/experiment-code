#include "Cooker.h"

#include <iostream>

int main() {

    Cooker cooker;

    //const std::string recipe_path = "../../data/recipes/";

    //cooker.load_dishes(recipe_path);

    IngredientList tea_ingr;
    tea_ingr.add("herb/fruit/spice", "1+");
    tea_ingr.add("water", "1+");

    IngredientList fac_tea_ingr;
    fac_tea_ingr.add("anise", "1+");
    fac_tea_ingr.add("fennel", "1+");
    fac_tea_ingr.add("caraway", "1+");
    fac_tea_ingr.add("water", "1+");

    cooker.add("tea", {"Tea", {"pot", "teaset"}, tea_ingr, ""});
    cooker.add("fennel anise caraway tea", {"Fennel-Anise-Caraway Tea", {"pot", "teaset"}, fac_tea_ingr, "tea"});

    std::cout << "[1 fennel, caraway, 1 anise, 1 water] makes: " << dish.getName() << std::newline;


    return 0;
}
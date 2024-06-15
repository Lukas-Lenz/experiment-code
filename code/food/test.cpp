#include "Cooker.h"

#include <iostream>

int main() {

    Cooker cooker;

    //const std::string recipe_path = "../../data/recipes/";

    //cooker.load_dishes(recipe_path);

    IngredientList tea_ingr;
    tea_ingr.add("herb/fruit/spice");
    tea_ingr.add("water");

    IngredientList fac_tea_ingr;
    fac_tea_ingr.add("anise");
    fac_tea_ingr.add("fennel");
    fac_tea_ingr.add("caraway");
    fac_tea_ingr.add("water");

    //std::string fac_tea_string = "'fennel anise caraway tea' tools:";

    cooker.add_recipe("Tea", {"pot", "teaset"}, tea_ingr, "");
    cooker.add_recipe("Fennel-Anise-Caraway Tea", {"pot", "teaset"}, fac_tea_ingr, "tea");

    IngredientList fac_tea_list {{"water", "fennel", "water", "anise", "anise", "caraway"}};
    IngredientList herbal_tea_list {{"water", "fennel", "caraway"}}; 

    Dish fac_test = cooker.match_recipe("teaset", {"water", "fennel", "water", "anise", "anise", "caraway"});
    Dish tea_test = cooker.match_recipe("teaset", {"water", "fennel", "water", "anise", "anise", "caraway"});
    Dish herbal_tea_test = cooker.match_recipe("teaset", {"water", "fennel", "water", "anise", "anise", "caraway"});
    Dish fac_test_2 = cooker.match_recipe("teaset", {"water", "fennel", "water", "anise", "anise", "caraway"});


    std::cout << "1 fennel, 1 caraway, 2 anise, 2 water makes: " << fac_test.getName() << std::endl;


    return 0;
}
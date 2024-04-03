#include <string>
#include <vector>



class Dish {


    bool check_recipe(const std::string tool, const std::vector<std::string> ingredients) const;


    using IngredientList = std::vector<std::tuple<std::string, std::string>>;

    const std::string name;
    const std::vector<std::string> tools;
    const IngredientList ingredients;

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

{
    for( : root_recipes){
        check_recipe()
    }
}


void load_dishes(){

    // save "root" dishes for 

    // map where each dish saves the dishes that consider it a base
    std::map<std::string, std::vector<std::string>> derived_recipes;

    for(Dish d : recipes) {

    }

}
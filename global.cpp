    void init_soil_types(std::map<std::string, std::shared_ptr<SoilType>> &type_container);


void Map::init_soil_types(std::map<std::string, std::shared_ptr<SoilType>> &type_container)
    {
        type_container.emplace("loamy", std::make_shared<SoilType>("Loamy Soil", 0.5, 0.9, 200, 1, 8));
        type_container.emplace("sandy", std::make_shared<SoilType>("Sandy Soil", 0.1, 0.6, 50, 0.5, 2));
        type_container.emplace("clay", std::make_shared<SoilType>("Clay Soil", 0.8, 0.8, 150, 0.8, 5));
        type_container.emplace("dead", std::make_shared<SoilType>("Dead Soil", 0.4, 0.8, 10, 0.8, 0));
    }

    std::shared_ptr<SoilType> Map::getSoilType(const std::string name)
    {
        return soil_types.at(name);
    }

std::shared_ptr<SoilType> getSoilType(const std::string name);

    private:

    std::map<std::string, std::shared_ptr<SoilType>> soil_types;
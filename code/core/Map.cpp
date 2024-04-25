
#include <iostream>
#include <fstream>

#include "Map.h";

Map::Map(const std::string name, const size_t width, const size_t height) : name{name}, width{width}, height{height}, tiles{height, {width, TileType::NONE}} {};


void Map::setTile(const int x, const int y, const TileType tileType) {

    if(x < width && y < height)
        tiles.at(y).at(x) = tileType;
}

TileType resolve_tile_type(const std::string symbol) {

    if(symbol == "f")
        return TileType::FOREST;        
    else if(symbol == "g")
        return TileType::GRASS;
    else if(symbol == "s")
        return TileType::SOIL;
    else if(symbol == "w")
        return TileType::WALL;
    else if(symbol == "p")
        return TileType::PATH;

    return TileType::NONE;
}

Map read_map(const std::string path) {

    const std::string full_path = maps_base_path + path;

    std::ifstream file(full_path);

    // first line: name, width, height
    std::string name;
    int width;
    int height;
    
    file >> name;
    file >> width;
    file >> height;

    Map map(name, width, height);

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            
            std::string symbol;
            file >> symbol;

            TileType tileType = resolve_tile_type(symbol);

            map.setTile(x, y, tileType);
        }
    }

    return map;
}




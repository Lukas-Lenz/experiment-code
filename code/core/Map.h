#ifndef HEADER_H_MAP
#define HEADER_H_MAP

#include <string>
#include <vector>

enum class TileType {
    NONE, FOREST, GRASS, SOIL, WALL, PATH 
};


const std::string maps_base_path = "";

class Map
{
    public:

    Map(const std::string name, const size_t width, const size_t height);
    
    void setTile(const int x, const int y, const TileType tileType);

    private:

    std::vector<std::vector<TileType>> tiles;

    std::string name;
    const size_t width;
    const size_t height;

};

#endif
class Tile {


    bool base_passable;
    //texture

}

class Map {

public: 

    Map(const int id) : map_id{id} {

    }

private:

    const int map_id
    std::string map_name;

    Tile* tiles[][];
    Object* objects[][];

    void readMap(const std::string path);

}

void readMap(const std::string path) {

    int x;
    int y;

    //first row: map id, name, x, y
    std::cin >> map_name;
    std::cin >> x;
    std::cin >> y;

    tiles = Array{{}, x, y};

    

    while(!endfile) {

    }

}

Map field {};



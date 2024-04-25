
class Location {

    public:
    void moveBy(int x, int y);

    private:
    int currentMap;
    int x;
    int y;
};

class Agent {


public:


protected:

    Location location;
    void pickGoal();
    void findRoute();

};
#include <string>
#include <memory>

class State {

    int chaosChange;
    int chaosLevel;

    int growthChange;
    int growthLevel;

    int progressChange;
    int progressLevel;

    int orderChange;
    int orderChange;

};

class Actor {

public:

    virtual void update(const State &state) = 0;

    const int getID() const { return actorID; }
    const int getName() const { return actorName; }
    void setName(const std::string &name) { actorName = name; }

protected:

    const int actorID;
    std::string actorName;

};


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
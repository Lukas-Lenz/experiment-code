#include <string>
#include <memory>

#include "State.cpp"

class UpdateObject {

public:

    virtual void update(const State &state, const Time &advanceBy) = 0;

    const int getID() const { return UpdateObjectID; }
    const std::string getName() const { return UpdateObjectName; }
    void setName(const std::string &name) { UpdateObjectName = name; }

protected:

    const int UpdateObjectID;
    std::string UpdateObjectName;

};


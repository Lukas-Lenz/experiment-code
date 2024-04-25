#ifndef HEADER_H_FIELD
#define HEADER_H_FIELD

#include "UpdateObject.cpp"
#include "Soil.cpp"

#include <vector>


class Field : public UpdateObject {


public:

    void update(const State &state) override;

private:

    std::vector<std::vector<Soil>> soilTiles;

    std::vector<std::vector<Plant>> plants;

    void soilUpdate(const State &state);
    void plantUpdate(const State &state);

};

#endif
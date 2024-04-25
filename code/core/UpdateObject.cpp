#include <memory>

#include "UpdateObject.h"


const int UpdateObject::getID() const { return UpdateObjectID; }

const std::string UpdateObject::getName() const { return UpdateObjectName; }

void UpdateObject::setName(const std::string &name) { UpdateObjectName = name; }
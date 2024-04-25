#include <memory>
#include <vector>

#include "UpdateQueue.h";

void UpdateQueue::add(const UpdateObject &UpdateObject) {

}

void UpdateQueue::update(const State &state) {

    //get time difference
    Time advanceBy = state.timeSince(lastUpdate);
    lastUpdate = state;

    for(auto updateObject_ptr : update_objects) {
    
        // check if the object still exists


        updateObject_ptr->update(state, advanceBy);
    }

}

#include "UpdateObject.cpp"

#include <memory>
#include <vector>

{

    const State state = captureState();

    UpdateQueue frame_queue;
    UpdateQueue clock_queue;
    UpdateQueue day_queue;

    while() {

        if(frame_tick) {

        }

        if(clock_tick) {
y
            progress_clock();
            clock_queue.tick();

        }


    }

}


class UpdateQueue {

    public: 

    void add(const UpdateObject &UpdateObject);
    void remove(const UpdateObject &UpdateObject);
    void tick(const State &state);
    void update(const State &state);

    private:

    Time lastUpdate;
    std::vector<std::weak_ptr<UpdateObject>> update_objects;

}


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

clock_update.add()
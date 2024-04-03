#include "Actor.cpp"

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

            progress_clock();
            clock_queue.tick();

        }


    }

}


class UpdateQueue {

    public: 

    void add(const Actor &actor);
    void tick(const State &state);

    private:

    std::vector<std::weak_ptr<Actor>> update_objects;

}


void UpdateQueue::add(const Actor &actor) {

}

void UpdateQueue::tick(const State &state) {


    for(auto actor_ptr : update_objects) {
    
        // check if the object still exists


        actor.update(state);
    }

}

clock_update.add()
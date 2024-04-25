#include "State.cpp"

#include <chrono>

using clock = std::chrono::steady_clock;

using MS_PER_UPDATE = 300;
using UPDATES_PER_CLOCK_TICK = 200;


State captureState() {

    return State{};

}


void update() {

    static int sinceLastTick = 1;

    if(sinceLastTick == UPDATES_PER_CLOCK_TICK) {
        clock.tick();
        sinceLastTick = 0;
    }

    const State tmpState = captureState();

    updateQueue.update(currentState, UpdateTypes::TICK);

    if(sinceLastTick == 0)
        updateQueue.update(currentState, Updates::CLOCK);

    sinceLastTick++;

}


int main() {

    bool end = false;

    Time clock {0, 0, 0};

    UpdateQueue clockQueue;


    auto lastTime = clock::now();
    double lag = 0.0;

    while(!end) {

        auto current = clock::now();

        std::chrono::milliseconds elapsed = current - lastTime;
        lastTime = current;

        lag += elapsed.count();
        

        // Input processing here
        
 
        while(lag >= MS_PER_UPDATE) {

            update();
            lag -= MS_PER_UPDATE;
        }

        // rendering here
        


    }


}

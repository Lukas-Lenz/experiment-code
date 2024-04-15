#include "State.cpp"


using MS_PER_UPDATE = 300;
using UPDATES_PER_CLOCK_TICK = 20;


State captureState() {



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


    double lastTime = getCurrentTime();
    double lag = 0.0;

    while(!end) {

        double current = getCurrentTime();
        double elapsed = current - lastTime;
        lastTime = current;

        lag += elapsed;
        

        // Input processing here
        
 
        while(lag >= MS_PER_UPDATE) {

            update();
            lag -= MS_PER_UPDATE;
        }

        // rendering here
        


    }


}

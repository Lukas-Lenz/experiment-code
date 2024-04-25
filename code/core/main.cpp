Command handleInput() {

}

float MS_PER_FRAME = 1000/30;

int main(){

    bool exit = false;
    float lastTime = ;

    while(!exit) {

        processInput();
        update();
        render();

        float currentTime = ;
        float elapsed = currentTime - lastTime;
        float wait = MS_PER_FRAME - elapsed;

        sleep(wait);

        lastTime = currentTime;

    }

    return 0;

}
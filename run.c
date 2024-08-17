#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include <stdio.h> //standard input/output available to all c code

int main()
{
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine); //turn the engine on in a given configuration (this one is the default)
    if (result != MA_SUCCESS) {
        return -1; //failure code
    }

    ma_engine_play_sound(&engine, "sound.wav", NULL); //plays the sound using the engine

    printf("Press Enter to quit..."); //won't quit if the sound is still playing due to real time processing
    getchar();

    ma_engine_uninit(&engine); //turn the engine off

    return 0;
}
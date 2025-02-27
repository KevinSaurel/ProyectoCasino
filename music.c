#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib") // Enlaza la biblioteca multimedia de Windows

int music() {
    // Reproducir el archivo .wav en segundo plano
    PlaySound("CasinoMusic.wav", NULL, SND_FILENAME | SND_ASYNC);

    // El resto del programa continúa ejecutándose
    int count=10;
    for (size_t i = 0; i < count; i++)
    {
        sleep(1000);
        /* code */
        PlaySound("CasinoMusic.wav", NULL, SND_FILENAME | SND_ASYNC);

    }

    return 0;
}

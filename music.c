#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h> // For _kbhit() and getch()
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time()

#pragma comment(lib, "winmm.lib") // Enlaza la biblioteca multimedia de Windows

void music() {
    const char *songs[] = {"canciones/CasinoMusic.wav", "canciones/Candy.wav"};
    int totalSongs = sizeof(songs) / sizeof(songs[0]);
    int currentSong;

    // Seed the random number generator
    srand(time(NULL));

    // Pick a random song to start with
    currentSong = rand() % totalSongs;

    // Reproducir el archivo .wav en segundo plano
    PlaySound(songs[currentSong], NULL, SND_FILENAME | SND_ASYNC);

    // Continuously check for key presses and song end
 
}
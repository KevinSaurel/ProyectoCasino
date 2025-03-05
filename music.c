#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h> // For _kbhit() and getch()
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time()
#include <string.h> 
#include "music.h"


#pragma comment(lib, "winmm.lib") // Enlaza la biblioteca multimedia de Windows

void music() {
    const char *songs[] = {"canciones/fifthOfBethoven.wav", "canciones/cantina.wav","canciones/Chic.wav"};
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
void playSong(const char *song) {
    PlaySound(song, NULL, SND_FILENAME | SND_ASYNC);
    int i = 0;
    while (i < 4) {
        
        Sleep(1000);
        i++;
        if(i==3){
    music();
        
    }
    
    
}
}
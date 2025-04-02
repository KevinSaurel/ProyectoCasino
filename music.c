#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h> // For _kbhit() and getch()
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time()
#include <string.h> 
#include <process.h>
#include "music.h"


#pragma comment(lib, "winmm.lib") // Enlaza la biblioteca multimedia de Windows

void music() {
    const char *songs[] = {"canciones/fifthOfBethoven.wav", "canciones/Luigi.wav","canciones/Chic.wav"};
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
void playSong(const char *song,int tiempo) {
    PlaySound(song, NULL, SND_FILENAME | SND_ASYNC);
    int i = 0;
    while (i < tiempo) {
        
        Sleep(1000);
        i++;
        if(i==tiempo){
        music();
        break;
    }
    
    
}
}
void playRaceSounds(void *arg) {
    // Play the "dingding.wav" sound asynchronously
    PlaySound("canciones/dingding.wav", NULL, SND_FILENAME | SND_SYNC);

    // Play the "carrera.wav" sound asynchronously
    PlaySound("canciones/carrera.wav", NULL, SND_FILENAME | SND_SYNC);

    // Start background music after the race sounds
    music();
}

void playSongCarrera() {
    // Start a new thread to play the race sounds
    _beginthread(playRaceSounds, 0, NULL);
}
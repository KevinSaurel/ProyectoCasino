@echo off
chcp 65001 >nul
del DeustoCasino.exe
g++ -c Socket/socket.cpp -Iinclude -o Socket/socket.o
gcc -c Menus/main.c Menus/menus.c Model/personas.c Persistencia/fichero.c Juegos/TragaPerras.c Juegos/dado.c Music/music.c Juegos/carrera.c Logger/logger.c Persistencia/config.c Juegos/blackjack.c Persistencia/bd.c Persistencia/sqlite3.c -Iinclude
g++ *.o Socket/socket.o -o DeustoCasino -lwinmm -lws2_32 -mconsole
del *.o
DeustoCasino.exe
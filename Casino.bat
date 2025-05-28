@echo off
chcp 65001 >nul
del DeustoCasino.exe
gcc Socket/server.c -o server.exe -lws2_32

gcc Menus/main.c Menus/menus.c Model/personas.c Persistencia/fichero.c Juegos/TragaPerras.c Juegos/dado.c Music/music.c Juegos/carrera.c Logger/logger.c Persistencia/config.c Juegos/blackjack.c Persistencia/bd.c Persistencia/sqlite3.c -o DeustoCasino -lwinmm -lws2_32
start cmd /k server.exe
DeustoCasino.exe
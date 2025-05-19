@echo off
chcp 65001 >nul
del DeustoCasino.exe
gcc Menus/main.c Menus/menus.c Model/personas.c Persistencia/fichero.c Juegos/TragaPerras.c Juegos/dado.c Music/music.c Juegos/carrera.c Logger/logger.c Persistencia/config.c Juegos/blackjack.c Persistencia/bd.c Persistencia/sqlite3.c -o DeustoCasino -lwinmm -mconsole
DeustoCasino.exe
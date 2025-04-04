@echo off
chcp 65001 >nul
del DeustoCasino.exe
gcc main.c menus.c personas.c fichero.c TragaPerras.c dado.c music.c carrera.c logger.c config.c blackjack.c bd.c sqlite3.c -o DeustoCasino -lwinmm -mconsole
DeustoCasino.exe
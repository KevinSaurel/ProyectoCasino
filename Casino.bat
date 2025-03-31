@echo off
chcp 65001 >nul
gcc main.c menus.c personas.c fichero.c TragaPerras.c dado.c music.c carrera.c logger.c config.c -o DeustoCasino -lwinmm -mconsole
DeustoCasino.exe
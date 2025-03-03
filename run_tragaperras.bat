@echo off
chcp 65001 >nul
gcc main.c menus.c personas.c TragaPerras.c music.c carrera.c -o ProyectoCasino -lwinmm -mconsole
ProyectoCasino.exe
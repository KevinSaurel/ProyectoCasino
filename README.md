PROYECTO_CASINO:

Descripción del Proyecto
El Proyecto Casino es una aplicación en C que simula un casino virtual. Los usuarios pueden participar en diferentes juegos como tragaperras, carrera de caballos, blackjack, y dados. Además, el proyecto incluye funcionalidades para gestionar clientes, almacenar datos en una base de datos SQLite, y cargar información desde ficheros.

Características Principales
Gestión de Clientes:
- Registro de nuevos clientes.
- Carga de datos de clientes desde un fichero o base de datos.
- Verificación de edad para permitir el acceso al casino.

Juegos Disponibles:
- Tragaperras: Simulación de una máquina tragamonedas.
- Carrera de Caballos: Apuesta en carreras con caballos.
- Blackjack: Juego de cartas clásico.
- Dados: Juego de azar con dados.

Base de Datos SQLite:
- Almacenamiento de datos de clientes y carreras.
- Actualización de información en tiempo real.

Ficheros:
- Carga y volcado de datos desde/para ficheros de texto (personas.txt, carreras.txt).

Música:
- Reproducción de música para mejorar la experiencia del usuario.

Estructura del Proyecto
Archivos Principales:
- main.c: Punto de entrada del programa. Gestiona el flujo principal del casino.
- blackjack.c y blackjack.h: Implementación del juego de blackjack.
- carrera.c y carrera.h: Gestión de las carreras de caballos.
- tragaperras.c y tragaperras.h: Implementación del juego de tragaperras.
- dado.c y dado.h: Implementación del juego de dados.
- bd.c y bd.h: Funciones para interactuar con la base de datos SQLite.
- fichero.c y fichero.h: Funciones para leer y escribir datos en ficheros.
- personas.c y personas.h: Gestión de clientes.
- menus.c y menus.h: Menús interactivos para el usuario.
- music.c y music.h: Reproducción de música en el casino.

Ficheros de Datos:
- ficheros/personas.txt: Contiene información de los clientes (nombre, apellido, edad, dinero, deuda).
- ficheros/carreras.txt: Contiene información de las carreras (nombre, distancia, premio, número de caballos).

Requisitos del Sistema
- Compilador C: GCC o cualquier otro compilador compatible con C.
- SQLite: Biblioteca SQLite para la gestión de la base de datos.
- Entorno Windows: Algunas funciones, como Sleep y reproducción de música, están diseñadas para Windows.
- Ficheros de Datos: personas.txt y carreras.txt deben estar en el directorio ficheros.

Instalación y Ejecución
1. Compilar el Proyecto
   En Windows, utiliza el archivo Casino.bat para compilar y ejecutar

Uso del Programa
Inicio:
- Al iniciar, el programa muestra un mensaje de bienvenida y solicita al usuario que seleccione una opción del menú principal.

Menú Principal:
- Registrar un nuevo cliente.
- Cargar datos de un cliente existente.
- Salir del casino.

Juegos Disponibles:
- Selecciona un juego desde el menú de juegos:
  - Tragaperras.
  - Carrera de caballos.
  - Blackjack.
  - Dados.

Gestión de Datos:
- Los datos de los clientes y las carreras se almacenan en la base de datos SQLite y se pueden cargar desde ficheros.


Partes que nos faltan por hacer:
    En el futuro queremos crear una tabla con los resultados de las partidas jugadas por cada cliente,
es decir crear una tabla en la bd que sea el historial de un cliente, pero no nosha  dado tiemplo a implementarlo para esta entrega.
    Ademas, nos falta acabar de implementar bien la tabla carrera para que se puedan añadir y eliminar carreras, asi como 
modificar el visualizarCarreras para que muestre todas las carreras de la bd, por ahora esta manualmente hecho en el main
con un array al que le añadimos dos carreras que creamos en el main. Tambien queremos poner en 2 juegos que nos falta 
, el que te pida cuanto dinero quieres apostar en vez de dejar una apuesta predeterminada como lo tenemos ahora.

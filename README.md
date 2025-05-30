PROYECTO_CASINO:

Descripción del Proyecto
El Proyecto Casino es una aplicación cliente-servidor en C que simula un casino virtual. Los usuarios pueden participar en diferentes juegos como tragaperras, carrera de caballos, blackjack, y dados. El sistema incluye una arquitectura cliente-servidor mediante sockets TCP/IP, gestión de clientes, base de datos SQLite, sistema de logging y efectos de sonido para una experiencia inmersiva.

Características Principales

Sistema Cliente-Servidor:
- Comunicación mediante sockets TCP/IP
- Servidor concurrente para múltiples clientes
- Seguimiento de balance en tiempo real
- Sistema de mensajería entre cliente y servidor

Gestión de Clientes:
- Registro de nuevos clientes
- Sistema de login para clientes existentes
- Verificación de edad
- Control de balance y deudas
- Historial de transacciones

Juegos Disponibles:
- Tragaperras: Simulación de máquina tragamonedas con efectos de sonido
- Carrera de Caballos: Sistema de apuestas en carreras
- Blackjack: Juego de cartas clásico
- Dados: Juegos de azar con dados

Sistema de Persistencia:
- Base de datos SQLite para almacenamiento persistente
- Sistema de archivo para respaldo
- Logging de actividades y transacciones
- Configuración mediante archivos externos

Características Técnicas:
- Efectos de sonido y música ambiental
- Sistema de logging detallado
- Manejo de errores robusto
- Configuración flexible

Estructura del Proyecto

Directorios Principales:
/Juegos           - Implementación de los juegos del casino
/Logger           - Sistema de logging y seguimiento
/Menus            - Interfaz de usuario y navegación
/Model            - Modelos de datos y estructuras
/Music            - Sistema de audio y efectos sonoros
/Persistencia     - Base de datos y gestión de archivos
/Socket           - Implementación cliente-servidor
/readme           - Documentación del proyecto

Archivos Principales:
- main.c: Cliente principal del casino
- server.c: Servidor de gestión del casino
- blackjack.c/h: Implementación del blackjack
- carrera.c/h: Sistema de carreras de caballos
- tragaperras.c/h: Juego de tragaperras
- dado.c/h: Juegos de dados
- bd.c/h: Gestión de base de datos SQLite
- music.c/h: Sistema de audio
- logger.c/h: Sistema de logging
- config.c/h: Gestión de configuración

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

# 						SuDoKu en C 


### Descripción del problema 
El “SuDoKu”, un juego de tablero de 9x9 donde se divide en cuadrantes de 3x3 y el juego consiste en que un jugador debe posicionar números de tal manera que este no se repita vertical ni horizontal y en el cuadrante de 3x3 que este posicionando tal número. El propósito del juego es que el jugador logre completar el tablero que se encuentra con una cantidad de numeros ya establecidos. 

### Estrategia para la resolución 
El procedimiento que se utilizó para la resolución es el siguiente:  
1. **Definir los tableros:** Se utilizaron 3 tableros (matrices) para diferentes usos donde uno se utiliza como tablero base donde se va implementar la carga de los números para el juego, otro donde el jugador pueda interactuar y ver por pantalla y uno ultimo donde se va a utilizar para visualizar una posible solución en el caso que se rinda. 
2. **Carga del tablero base:** Implementa una lógica que permite completar un Sudoku en el tablero base, que se guardará en un tablero solucion (para su posterior uso en caso de rendición) luego solo se dejaran 17 números el resto se reemplazará por puntos y se realizara una copia en otra matriz donde el jugador podra interactuar. 
3. **Verificación de condiciones de victoria:** Después de cada ingreso, se verifica si el tablero está completo de números, en ese caso se verifica que cumpla con que cada fila, columna y cuadrante de 3x3 no tenga números repetidos. 
4. **Interacción con el usuario:** Le solicita al jugador que ingrese la posición donde desea poner el número y luego que ingrese tal número, asegurando que solo seleccione posiciones válidas. 
5. **Reinicio del juego:** Al finalizar una partida, sea por rendición o haber ganado, se muestra el tablero completado y se espera que el jugador presione una tecla para volver al menú principal donde se podrá iniciar el juego nuevamente sin reiniciar el programa. 

### Aproximación a las estructuras para la implementación 
Para implementar este programa, se utilizarán estructuras de datos y funciones que permitan modular el código y facilitar su comprensión: 
1. **Tableros:** 3 matrices de 9x9. Donde las filas se identifican de la A-I y las columnas del 1-9. 
2. **Funciones de control:**
    - ```inicio()```: Muestra el menú principal.
    - ```tablero()```: Inicia el juego.
    - ```carga(m_base, m_show, solucion)```: Realiza la carga de números a los tableros. Inicialmente crea un sudoku completo en la ‘m_base’ lo copia a la matriz ‘solucion’, luego intercambia 64 números en posiciones random dentro de la ‘m_base’ por puntos, de esta manera quedando solo 17 números en la matriz. Así, se crea una copia de matriz_base a ‘m_show’(matriz que interactúa el usuario). 
    - ```graficar(m_show, m_base)```: Muestra el tablero en su estado actual al usuario. 
    - ```input_jugador(m_base, m_show)```: Controla el ingreso de las posiciones y numeros (1-9) que el jugador indica. En el caso que el jugador decida rendirse ingresara la letra ‘R’ y la función retornara un 1 para terminar el juego.  
    - ```verificador(m_base, m_show):```: Evalua si se completo la matriz‘m_show’, en ese caso la función controla si cumple con las condiciones para ganar, si es así el retornara un 0.
3. **Funciones adicionales:** Funciones como ```prints_chars()``` se utiliza para personalizar el diseño del sudoku, y ```rellenar()``` se utiliza para resetear las matrices con un llenado de puntos(‘.’). 

### Explicación breve de cómo debe usarse el programa y los datos de entrada, opciones y resultados, tutorial. 

**Tutorial:**
1. **Inicia el juego:**  Al iniciar el programa, se muestra un menú principal donde el jugador puede decidir comenzar a jugar o salir. 
2. **Ingreso de datos:** Una vez comenzado el juego. El programa solicita al jugador que introduzca la posición (Ej: ‘A1’ o ‘H5’) donde quiere colocar el número. Si la posición ingresada es válida o sea modificable, se pedirá un número del 1 al 9 que quiera ingresar (Se utiliza el ‘0’ para ponerle un punto). 
    - Si la posición está ocupada o es inválida, se le pide al jugador que elija otra posición. 
3. **Condiciones de victoria:** Después de cada turno, el programa verifica si el jugador ha ganado o si se rindió. 
    - **Si hay un ganador:** Se muestra un mensaje indicando al jugador como ganador.
    - **Si se ha rendido:** Se muestra un mensaje indicando que se rindió y una posible solución al sudoku.
4. **Reinicio del juego:** Al finalizar, el programa espera a que el jugador presione una tecla para enviarlo al menú principal, donde el jugador decidirá si jugar nuevamente o salir. 

> Este programa ha sido probado en la consola CMD de Windows 10. No se garantiza su funcionamiento en otras versiones de Windows o en otros entornos de consola (como PowerShell o terminales de Linux).

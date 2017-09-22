#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 20

    typedef struct {
        char nombre[50];
        int edad;
        int estado;
        int dni;
    }EPersona;

    /**
    * Muestra un menu y toma la opcion elegida por el usuario
    *
    *@param char texto[], es el texto que mostrara al usuario el menu de opciones
    *@return int, devuelve un entero con la opcion elegida por el usuario
    */
    int mostrarMenu(char texto[]);

    /**
     * Obtiene el primer indice libre del array.
     * @param lista el array se pasa como parametro.
     * @return el primer indice disponible
     */
    int obtenerEspacioLibre(EPersona personas[], int tam);

    /**
     * Obtiene el indice que coincide con el dni pasado por parametro.
     * @param lista el array se pasa como parametro.
     * @param dni el dni a ser buscado en el array.
     * @param Tamaño del array
     * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
     */
    int buscarPorDni(EPersona personas[], int dni, int tam);

    /**
     * Agrega una persona a la tabla
     * @param lista el array se pasa como parametro.
     * @param Tamaño del array
     */
    void addPersona(EPersona personas[], int tam);

    /**
     * Elimina una persona de la tabla
     * @param lista el array se pasa como parametro.
     * @param Tamaño del array
     */
    void deletePersona(EPersona personas[], int tam);

    /**
     * Ordena las personas alfabeticamente e imprime el resultado
     * @param lista el array se pasa como parametro.
     * @param Tamaño del array
     */
    void sortPrint(EPersona personas[], int tam);

    /**
     * Genera un grafico de barras dividiendo las personas en conjuntos de edades (<18,19-35,>35)
     * @param lista el array se pasa como parametro.
     * @param Tamaño del array
     */
    void graficarEdades(EPersona personas[], int tam);

    /**
     * Inicializa la estructura (Hardcodea) para poder testear el codigo.
     * @param lista el array se pasa como parametro.
     * @param Tamaño del array
     */
    void inicializarEstructura(EPersona personas[], int tam);


    /**
     * Ordena la matriz de conjunto de edades para poder graficar.
     * @param matriz con el conjunto de edades.
     * @param filas de la matriz
     * @param columnas de la matriz
     */
    void sortMatriz(int matriz[][3], int tam,int col);

#endif // FUNCIONES_H_INCLUDED


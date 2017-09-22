#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char texto[200]={};
    char seguir='s';
    int opcion=0;
    EPersona personas[TAM] = {};
    strcpy(texto,
           "1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir\n\n");
    while(seguir =='s')
    {
        system("color 1F");
        opcion = mostrarMenu(texto);
        switch(opcion)
        {
            case 1:
                system("cls");
               // addPersona(personas,TAM);
               inicializarEstructura(personas,TAM);
                system("pause");
                break;
            case 2:
                system("cls");
                deletePersona(personas,TAM);
                system("pause");
                break;
            case 3:
                system("cls");
                sortPrint(personas,TAM);
                system("pause");
                break;
            case 4:
                system("cls");
                graficarEdades(personas,TAM);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
        system("cls");
    }

    return 0;
}


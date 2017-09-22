#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "funciones.h"

int mostrarMenu(char texto[])
{
    int opcion = 0;
    printf("%s\n\n",texto);
    printf("Eleccion del usuario: ");
    scanf("%d",&opcion);
    return opcion;
}

int obtenerEspacioLibre(EPersona personas[], int tam)
{
    int i;
    int espacioLibre;
    for(i = 0; i < tam; i++)
    {
        if(personas[i].estado != 1)
        {
            espacioLibre = i;
            break;
        }
        else
        {
            espacioLibre = tam + 1;
        }
    }
    return espacioLibre;
}

int buscarPorDni(EPersona personas[], int dni, int tam)
{
    int i;
    int espacioDNI;
    for(i = 0; i < tam; i++)
    {
        if(personas[i].dni == dni && personas[i].estado == 1)
        {
            espacioDNI = i;
            break;
        }
        else
        {
            espacioDNI = tam + 1;
        }
    }
    return espacioDNI;

}

void addPersona(EPersona personas[], int tam)
{
    int espacioLibre;
    int dni;
    int validacionDni;
    espacioLibre = obtenerEspacioLibre(personas, TAM);
    if(espacioLibre < (tam + 1))
    {
        printf("Ingrese el DNI de la persona:");
        scanf("%d", &dni/*personas[espacioLibre].dni*/);
        validacionDni = buscarPorDni(personas,dni,tam);
        if(validacionDni == (tam +1) ){
            personas[espacioLibre].dni = dni;
            printf("Ingrese el nombre de la persona: ");
            fflush(stdin);
            scanf("%s", &personas[espacioLibre].nombre);
            printf("Ingrese la edad de la persona:");
            scanf("%d", &personas[espacioLibre].edad);
            personas[espacioLibre].estado = 1;
        }else{
            printf("LA PERSONA YA EXISTE EN EL SISTEMA!\n");
        }
    }
    else
    {
        printf("Memoria llena \n");
    }
}

void deletePersona(EPersona personas[], int tam)
{
    int dni=0;
    int espacioBuscado=0;
    char opcion;
    printf("Ingrese el DNI de la persona a eliminar: ");
    scanf("%d",&dni);
    espacioBuscado = buscarPorDni(personas,dni,TAM);
    system("cls");
    if(espacioBuscado < tam+1){
        printf("¿Está seguro que desea eliminar a %s, DNI: %d? (s/n)\n", personas[espacioBuscado].nombre, dni);
        fflush(stdin);
        opcion = getche();
        if(opcion == 's'){
            personas[espacioBuscado].estado = 0;
            printf("\n ELIMINADO EXITOSAMENTE \n");
        }
    }else{
        printf("La persona no existe en el sistema. \n");
    }
}

void sortPrint(EPersona personas[], int tam)
{
    int i;
    int j;
    int k;
    EPersona aux;
    printf("NOMBRE\t\t\t\tEDAD\t\tDNI\n");
    printf("-------\t\t\t\t-------\t\t-------\n");
    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (strcmp(personas[i].nombre, personas[j].nombre) > 0)
            {
                aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
    for (k = 0; k < tam; k++)
    {
        if(personas[k].estado == 1)
        {
            if(strlen(personas[k].nombre) > 7){
                printf("%s\t\t\t%d\t\t%d\n\n", personas[k].nombre, personas[k].edad, personas[k].dni);
            }else{
                printf("%s\t\t\t\t%d\t\t%d\n\n", personas[k].nombre, personas[k].edad, personas[k].dni);
            }
        }
    }
}


void graficarEdades(EPersona personas[], int tam)
{
    int edades[TAM][3] = {};
    int aux;
    int i;
    int j;
    int cont = 0;
    system("color 1C");
    printf("\n GRAFICO DE EDADES\n");
    printf(" ------------------\n\n");
    for(i=0; i<tam;i++){
        if(personas[i].edad < 18 && personas[i].estado == 1){
            edades[cont][0] = 1;
            cont++;
        }else if(personas[i].edad > 18 && personas[i].edad < 35 && personas[i].estado == 1){
            edades[cont][1] = 1;
            cont++;
        }else if(personas[i].estado == 1){
            edades[cont][2] = 1;
            cont++;
        }
    }
    sortMatriz(edades,cont,0);
    sortMatriz(edades,cont,1);
    sortMatriz(edades,cont,2);

    for(j = 0; j < cont; j++){
       if(edades[j][0] == 1){
            printf(" #");
       }
       if(edades[j][1] == 1){
            printf("  \t#");

       }
       if(edades[j][2] == 1){
            printf(" \t#");
       }
       if(edades[j][0] == 1 || edades[j][1] == 1 || edades[j][2] == 1){
            printf("\n");
       }
       // printf("%d\t%d\t%d\n",edades[j][0],edades[j][1],edades[j][2]);
    }
    printf(" __________________\n");
    printf(" <18\t19-35\t>35\n\n");
}

void inicializarEstructura(EPersona personas[], int tam){

    char nombre[][50] = {"Javier","Roberto","Sabrina","Mario","Zoloda","Anastacia","Javier","Roberto","Sabrina","Mario","Zoloda","Ana","Juan"};
    int edad[] = {25,33,38,38,13,12,25,33,28,18,13,12,30};
    int dni[] = {35863182,36888999,3899599,35862182,36988999,3799599,35863182,36888999,3899599,35862182,36988999,3799599,300000000};
    int estado[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    int i;
    printf("DATOS CARGADOS AUTOMATICAMENTE...\n...\n...\n...\n\n");
    for(i = 0; i < tam; i++){
        strcpy(personas[i].nombre,nombre[i]);
        personas[i].edad = edad[i];
        personas[i].dni = dni[i];
        personas[i].estado = estado[i];
    }


}


void sortMatriz(int matriz[][3], int tam,int col){
    int i;
    int j;
    int aux;
    for(i = 0; i < tam -1; i++){
        for(j = i+1; j<tam; j++){
            if (matriz[i][col] > 0)
            {
                aux = matriz[i][col];
                matriz[i][col] = matriz[j][col];
                matriz[j][col] = aux;
            }

        }
    }
}

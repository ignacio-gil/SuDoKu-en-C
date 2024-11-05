#include "funciones_sudoku.h"

void tablero(){
    int M_base[9][9],M_show[9][9],solucion[9][9], aux;
    int resultado;
    
    carga(M_base,M_show,solucion);

    //Comienza el juego
    do{ 
        system("cls");
        graficar(M_show,M_base);

        aux = input_jugador(M_base,M_show);
        resultado = verificador(M_base,M_show);
        
    } while(aux!=1 && resultado!=0);

    system("cls");
    if(aux==1){
        printf("\nTe rendiste :(\n\nUna posible solucion era:\n");
        graficar(solucion,M_base); 
    } else {
        printf("\n El SuDoKu completo es correcto!\n\n Ganaste!!\n");
        graficar(M_show,M_base); 
    } 
    printf("\n\n\n%s",NORMAL);
    system("pause");
    system("color 70");
}

//Menu 0
void inicio(){
    int aux;
    system("title SuDoKu");
    system("mode con: cols=51 lines=25");
    system("color 70");

    do{
        system("cls");
        printf("%s",FONDO);
        prints_chars(105,32,45,61);
        prints_chars(57,32,18,61);
        printf("%c %sSuDoKu%s %c",16,TITULO,FONDO,17);
        prints_chars(17,61,57,32);
        prints_chars(45,61,173,32);
        printf("(1)   JUGAR");
        prints_chars(90,32,1,32);
        printf("(0)   SALIR");
        prints_chars(328,32,1,32);
        printf("%sIngrese:\n\n%c Opcion: ",NORMAL, 26); scanf("%i", &aux);
        
        if(aux==1){tablero();}

    } while(aux!=0);

}
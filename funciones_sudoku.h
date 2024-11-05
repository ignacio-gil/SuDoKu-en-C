#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   NORMAL         "\x1b[47m\x1b[30m"
#define   TITULO      "\x1b[4m\x1b[40m\x1b[36m"
#define   FONDO           "\x1b[24m\x1b[40m\x1b[96m"
#define   COLOR_TABLERO  "\x1b[47m\x1b[35m"
#define   NUM            "\x1b[34m"
#define   ROJO           "\x1b[31m"

//Rellenar matrices con .
void rellenar(int matriz[9][9], int matriz2[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            matriz[i][j]=matriz2[i][j]='.';
        }
    }
}

//Para el diseño
void prints_chars(int cant_c1, char c1,int cant_c2, char c2){
    for(int i=0;i<cant_c1;i++){printf("%c",c1);}
    for(int i=0;i<cant_c2;i++){printf("%c",c2);}
}

//Carga de matriz
void carga(int M[9][9], int M2[9][9], int solucion[9][9]){
    int aviso, cont, aux, num,i,l, ini_i, fin_i, ini_j, fin_j;
    srand(time(NULL));
    do{
        aviso=0;
        //Rellenar matrices con .
        rellenar(M,M2);

        //Carga numeros al tablero
        for(l=0;l<9;l++){
            for(int k=0;k<9;k++){
                cont=0;
                do{
                    aux=num=0;
                    switch(l){
                        case 0:case 1:case 2:ini_i=0;fin_i=2;break;
                        case 3:case 4:case 5:ini_i=3;fin_i=5;break;
                        case 6:case 7:case 8:ini_i=6;fin_i=8;break;
                    }
                    switch(k){
                        case 0:case 1:case 2:ini_j=0;fin_j=2;break;
                        case 3:case 4:case 5:ini_j=3;fin_j=5;break;
                        case 6:case 7:case 8:ini_j=6;fin_j=8;break;
                    }
                    num = rand()%9+49;

                    //Control fila
                    for(i=0;i<9;i++){if(M[l][i]==num){aux=1;}}
                    //Ctrl columna
                    for(i=0;i<9;i++){if(M[i][k]==num){aux=1;}}
                    //Ctrl cuadrante
                    for(i=ini_i;i<fin_i+1;i++){
                        for(int j=ini_j;j<fin_j+1;j++){
                            if(M[i][j]==num){aux=1;}
                        }
                    }

                    if(M[l][k]=='.' && aux==0){M[l][k]=num;} else {aux=1;}
                    cont++;
                    if(cont==500){break;}

                } while(aux==1);
                if(cont==500){break;}
            }
            if(cont==500){aviso=1;break;}
        }

    } while (aviso==1);

    //Guardo solucion
    for(i=0;i<9;i++){for(l=0;l<9;l++){solucion[i][l]=M[i][l];}}

    //Se dejan 17 numeros en la matriz base
    cont=0;
    while(cont<81-17){
        i=l=0; 
        i = rand()%9; l = rand()%9;
        if(M[i][l]!='.'){M[i][l]='.';cont++;}       
    } 

    //Copio matriz base mod. a M2
    for(i=0;i<9;i++){for(l=0;l<9;l++){M2[i][l]=M[i][l];}}
}

//Muestra de Grafico
void graficar(int matriz[9][9], int matriz_base[9][9]){
    int i,j;
    printf("%s",FONDO);
    prints_chars(60,32,1,32);
    printf("%s +---+",COLOR_TABLERO);
    prints_chars(23,45,1,43);printf(" %s",FONDO);
    prints_chars(19,32,1,32);
    printf("%s |Pos|",COLOR_TABLERO);
    for(i=0;i<9;i++){printf("%2i",i+1);if(i==2 || i==5){printf("  ");}}
    printf(" | %s",FONDO); prints_chars(19,32,1,32);
    printf("%s +---+",COLOR_TABLERO); prints_chars(23,45,1,43);
    printf(" %s",FONDO); prints_chars(9,32,1,32);

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(j!=0 && matriz_base[i][j]=='.'){printf("%s",NUM);}
            if(j==2 || j==5 || j==8){
                printf("%2c%s |",matriz[i][j],COLOR_TABLERO); //Num ult
            } else if(j==0){
                prints_chars(9,32,1,32);
                if(matriz_base[i][j]=='.'){
                    printf("%s |%2c |%s%2c%s",COLOR_TABLERO,i+65,NUM,matriz[i][j],COLOR_TABLERO);
                } else {
                    printf("%s |%2c |%2c",COLOR_TABLERO,i+65,matriz[i][j]);
                }
                
            } else {printf("%2c%s",matriz[i][j],COLOR_TABLERO);} //Num norm.
        }
        if(i==2 || i==5){
            printf(" %s",FONDO); prints_chars(19,32,1,32);
            printf("%s |   +",COLOR_TABLERO);
            prints_chars(23,45,1,43);
        } else if(i==8){
            printf(" %s",FONDO); prints_chars(19,32,1,32);
            printf("%s +---+",COLOR_TABLERO); prints_chars(23,45,1,43);
        }
        printf(" %s",FONDO); prints_chars(9,32,1,32);
    }
    prints_chars(50,32,1,32);
}

//Input jugador
int input_jugador(int M[9][9], int M2[9][9]){
    int num_ing, pos_i, pos_j, aux =0;
    char posicion[3];
    
    printf("%sIngrese:\n\n",NORMAL);
    //Input posicion
    do{
        printf("%c Posicion (Ej: A1 o 'R' p/rendirse): ", 26);
        scanf("%s", posicion);
        pos_i = posicion[0]-'A';
        pos_j = posicion[1]-'1';
        if(posicion[0]=='R'){aux=1;break;
        } else if(M[pos_i][pos_j]!='.'){
            printf("%s-Pos. invalida o no modificable-%s\n",ROJO,NORMAL);posicion[0]=0;
        }
        
    } while(posicion[0]<'A' || posicion[0]>'J' || posicion[1]<'0' || posicion[1]>'9');
    
    //Input numero
    do{
        if(posicion[0]=='R'){break;}
        printf("%c Numero entre 0-9 ('0' p/borrar): ",26);
        scanf("%i", &num_ing);
    } while(num_ing<0 || num_ing>9);

    //Coloca numero
    if(M[pos_i][pos_j]=='.' && posicion[0]!='R'){
        if(num_ing==0){M2[pos_i][pos_j]='.';}else{M2[pos_i][pos_j]=num_ing+48;}
    }

    return aux;
}

//Verificar SuDoKu completo
int verificador(int M[9][9], int M2[9][9]){
    int resultado=0; //False: Ganaste, True:Segui participando
    int i,j,k,l, ini_i, fin_i, ini_j, fin_j, cont, aux,aux2; 

    //Si se completo el tablero empieza a verificar(si no hay mas '.')
    aux2 = 0;
    for(i=0;i<9 && aux2!=1;i++){for(j=0;j<9 && aux2!=1;j++){if(M2[i][j]=='.'){aux2=resultado=1;}}}
    //1ro Chequea punto por punto que no se repita horizontal ni vertical
    for(i=0;i<9 && aux2==0;i++){
        for(j=0;j<9;j++){
            //Ctrl fila
            aux=0;
            for(k=0;k<9;k++){if(M2[i][k]==M2[i][j]){aux++;if(aux==2){resultado=1;}}}
            //Ctrl columna
            aux=0;
            for(k=0;k<9;k++){if(M2[k][j]==M2[i][j]){aux++;if(aux==2){resultado=1;}}}
        }
    }
    //2do Chequea por cuadrante
    for(k=0;k<9 && aux2==0;k++){
        switch(k){
            case 0:case 1:case 2:ini_i=0;fin_i=2;break;
            case 3:case 4:case 5:ini_i=3;fin_i=5;break;
            case 6:case 7:case 8:ini_i=6;fin_i=8;break;
        }
        switch(k){
            case 0:case 3:case 6:ini_j=0;fin_j=2;break;
            case 1:case 4:case 7:ini_j=3;fin_j=5;break;
            case 2:case 5:case 8:ini_j=6;fin_j=8;break;
        }
        for(l=1;l<10;l++){
            cont=0;
            for(i=ini_i;i<fin_i+1;i++){
                for(j=ini_j;j<fin_j+1;j++){
                    if(M[i][j]==l){cont++;}
                }
            }
            if(cont>1){resultado=1;}
        } 
    }

    return resultado;
}
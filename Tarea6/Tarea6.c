#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void e1cad();
void e2cad();
void e1num();
void leerCadena();

char cadena[MAX];
char archivo[11] = "cadenas.txt";
char tabla[]="simbolos.txt";
int i=-1;
int flag=1;
int contPuntos=0;
FILE *tablaSimbolos;

int main(int argc, char** argv){
    leerCadena();
}

//Lee el archivo linea por linea y manda las cadenas al analizador;
void leerCadena(){
  FILE *fp;
  fp = fopen (archivo, "r" );
  tablaSimbolos = fopen(tabla,"w");
  if(fp==NULL){
    printf("Error al leer el archivo");
    exit(1);
  }

  while(1){
    fgets(cadena, MAX, fp);
    if(feof(fp)) break;
    e1cad();
    i=-1;
  }

  fclose(fp);
  fclose(tablaSimbolos);
  memset(cadena, 0, sizeof(cadena));
}

//Estado inicial, verifica que la cadena inicie con "_" o con alguna consonante mayuscula o minuscula
void e1cad(){
  i++;
  if(cadena[i] == 95 || (cadena[i] >=65 && cadena[i] <= 90) || (cadena[i] >=97 && cadena[i] <= 122) ){
    e2cad();
  }else if(cadena[i] >=48 && cadena[i] <= 57){
    e1num();
  }else{
    printf("Error 1 Cadena no valida:  %s",cadena);
  }
}

//Estado final, verifica que la cadena contenga numeros, "_" o con alguna consonante mayuscula o minuscula
void e2cad(){
  i++;
  if(cadena[i] == 95 || (cadena[i] >=65 && cadena[i] <= 90) || (cadena[i] >=97 && cadena[i] <= 122) || (cadena[i] >=48 && cadena[i] <= 57) ){
    e2cad();
  }else if(cadena[i] == '\n'){
    printf("Cadena aceptada:\t%s",cadena);
    fprintf(tablaSimbolos,"%s",cadena);
  }else{
    printf("Error 2 Cadena no valida:\t%s",cadena);
  }
}

void e1num(){
  i++;
  if(cadena[i] >=48 && cadena[i] <= 57){
    e1num();
  }else if(cadena[i] == '\n' && contPuntos == 0){
    printf("Numero entero aceptado:\t%s",cadena);
    contPuntos=0;
  }else if(cadena[i] == '\n' && contPuntos == 1){
    contPuntos=0;
    printf("Numero Real aceptado:\t%s",cadena);
  }else if(cadena[i] == '.' && contPuntos == 0){
    contPuntos++;
    e1num();
  }else{
    contPuntos=0;
    printf("Error 1 cadena no valida como numero Real:\t%s",cadena );
  }
}

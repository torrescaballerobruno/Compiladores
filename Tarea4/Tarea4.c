#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void e1();
void e2();
void leerCadena();

char cadena[MAX];
char archivo[11] = "cadenas.txt";
int i=-1;
int flag=1;

int main(int argc, char** argv){
    leerCadena();
}

//Lee el archivo linea por linea y manda las cadenas al analizador;
void leerCadena(){
  FILE *fp;
  fp = fopen (archivo, "r" );
  if(fp==NULL){
    printf("Error al leer el archivo");
    exit(1);
  }

  while(1){
    fgets(cadena, MAX, fp);
    if(feof(fp)) break;
    e1();
    i=-1;
  }

  fclose(fp);
  memset(cadena, 0, sizeof(cadena));
}

//Estado inicial, verifica que la cadena inicie con "_" o con alguna consonante mayuscula o minuscula
void e1(){
  i++;
  if(cadena[i] == 95 || (cadena[i] >=65 && cadena[i] <= 90) || (cadena[i] >=97 && cadena[i] <= 122) ){
    e2();
  }else{
    printf("Error 1 Cadena no valida:  %s",cadena);
  }
}

//Estado final, verifica que la cadena contenga numeros, "_" o con alguna consonante mayuscula o minuscula
void e2(){
  i++;
  if(cadena[i] == 95 || (cadena[i] >=65 && cadena[i] <= 90) || (cadena[i] >=97 && cadena[i] <= 122) || (cadena[i] >=48 && cadena[i] <= 57) ){
    e2();
  }else if(cadena[i] == '\n'){
    printf("Cadena aceptada:\t%s",cadena);
  }else{
    printf("Error 2 Cadena no valida:\t%s",cadena);
  }
}

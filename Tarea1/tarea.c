#include <stdio.h>
#include <stdlib.h>
#include <regex.h>        
regex_t regex;    /* nuestra estructura regex */
int reti;         /* valor de retorno de las llamadas */
char msgbuf[100]; /* un pequeño buffer para escribir mensajes */
char cadena[100];
char expres[100];

    /* Compilar la expresión regular */
int main(){

    //reti = regcomp(&regex, "([[:digit:]]+)", 0);             /* Compilamos /^a[[:alnum:]]/ */
    
    //reti = regcomp(&regex, "([[:digit:]]+)\.([[:digit:]]*)", 0);
    printf("Expresion: ");scanf("%s",expres);
    reti = regcomp(&regex,expres,0);

    if( reti ){ 
        fprintf(stderr, "No se pudo compilar la expresión\n"); 
        exit(1); 
    }else{
        printf("Cadena: ");scanf("%s", cadena);
    }

    printf("cadena:  %s\n",cadena);

    /* Ejecutamos la expresión regular */
    reti = regexec(&regex, cadena, 0, NULL, 0);              
    
    if( !reti ){
        puts("Cadena Aceptada");  /* Éxito: coincide */
    }else if( reti == REG_NOMATCH ){
        puts("Cadena Denegada");  /* No coincide */
    }else{  /* Se produjo un error; informamos */
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    regfree(&regex);
}

//Hello people of 1974. I come from the future. In 2014 we have laser guns, hover boards and live on the moon!
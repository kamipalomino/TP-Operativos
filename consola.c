#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//std namespace;

typedef enum {PAUSA, CONTINUAR, KILL, BLOQUEAR, STATUS, DEADLOCK,  DESBLOQUEAR, LISTAR} t_tipo; 

int main (){
    
     t_tipo opcion;
        
     printf ("Ingrese opcion deseada:  " );
     scanf ("%s", &opcion);
        
    switch (opcion) {
         case PAUSA:
            printf ("El procesa esta en pausa  ");
            break;     
        case CONTINUAR:
            printf ("El proceso continua  ");
            break;
        case KILL: 
            printf ("Ingrese ID: ");
            break;
        case BLOQUEAR:
             printf ("Ingrese clave y ID: ");
             break;
        case DESBLOQUEAR:
             printf ("Ingrese clave: ");
             break;
        case STATUS:
             printf ("Ingrese clave para ver el estado: ");
             break;
        case DEADLOCK:
             printf ("Lista de procesos en Deadlock: ");
             break;
        case LISTAR:
             printf ("Ingrese recurso:  ");                 
             break;
        default:
            printf("elija algo");
             break;
    }

    
    
    
 
 return 0;
    
}

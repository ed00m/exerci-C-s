#include <stdio.h>

int main()
{
    int i;
    for(i=0; i<256;i++)
    {
        /*
        * Formas para mostrar resultados
        * \n representa salto de linea ==

        * \t representa tabulacion
        * \r representa enter
        * % significa modulo (MOD) dentro de una operación
        *
        */
        printf("\t[%d]==>%c ",i,i);
    }

    return 0; //o return void;
}

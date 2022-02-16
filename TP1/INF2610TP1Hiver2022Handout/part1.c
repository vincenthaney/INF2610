/*
 *  part1.c
 * 
 * ajoutez vos noms, prénoms, matricules et votre section de laboratoire
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

#include "./libprocesslab/libprocesslab.h"

void question1(int choix) {
    // TODO

    if (choix == 1) 
    {
        // 1.1
        printf("75dbcb01f571f1c32e196c3a7d27f62e (printed using printf)");
        write(1,"75dbcb01f571f1c32e196c3a7d27f62e (printed using write)\n", 56);
        printf("\n");
    }else{
        // 1.2
        setvbuf(stdout, NULL, _IONBF, 0);
        printf("75dbcb01f571f1c32e196c3a7d27f62e (printed using printf)");
        write(1,"75dbcb01f571f1c32e196c3a7d27f62e (printed using write)\n", 56);
    }
}

    

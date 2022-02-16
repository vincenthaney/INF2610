/*
 *  part1.c
 * 
 * ajoutez vos noms, prénoms, matricules et votre section de laboratoire
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <string.h>
// -------------------------------------------------

#include "./libprocesslab/libprocesslab.h"

void question1(int choix) {
    // TODO
    char* messageWrite = "75dbcb01f571f1c32e196c3a7d27f62e (printed using write) \n";
    if (choix == 1){
        printf("75dbcb01f571f1c32e196c3a7d27f62e (printed using printf)");
        write(STDOUT_FILENO, messageWrite, strlen(messageWrite));
        printf("\n");
    }
    if (choix == 2){
        setvbuf(stdout, NULL, _IONBF, 0);
        char* messageWrite = "75dbcb01f571f1c32e196c3a7d27f62e (printed using write) \n";
        printf("75dbcb01f571f1c32e196c3a7d27f62e (printed using printf)");
        write(STDOUT_FILENO, messageWrite, strlen(messageWrite));
        printf("\n");
    }
}
    

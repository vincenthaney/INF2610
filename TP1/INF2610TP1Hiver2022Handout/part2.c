/*
 * processlab - part2.c
 * 
 * Ecole polytechnique de Montreal,Hiver  2022
 * vos noms, prénoms et matricules
*/

#include "libprocesslab/libprocesslab.h"


// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// -------------------------------------------------

void question2( )
{
    int nbProcessusEnfants = 0;        
    int status = 0;                                                                                                                                         

    //level 0
    registerProc(0, 0, getpid(), getppid());

    if (fork() == 0) //level 1.1
    {
        registerProc(1, 1, getpid(), getppid());
        if (fork() == 0) //level 2.1
        {
            registerProc(2, 1, getpid(), getppid());
            _exit(1);
        }
        
        if (fork() == 0) //level 2.2
        {
            registerProc(2, 2, getpid(), getppid());
            _exit(1);
        }
        
        if (fork() == 0) //level 2.3
        {
            registerProc(2, 3, getpid(), getppid());
            _exit(1);
        }
        
        if (fork() == 0) //level 2.4
        {
            registerProc(2, 4, getpid(), getppid());
            _exit(1);
        }
        
        while(wait(&status) > 0) {
            nbProcessusEnfants += WEXITSTATUS(status);
        }
        _exit(++nbProcessusEnfants);
    }
    
    
    if (fork() == 0) // level 1.2
    {
        registerProc(1, 2, getpid(), getppid());
        if (fork() == 0) //level 2.5
        {
            registerProc(2, 5, getpid(), getppid());
            _exit(1);
        }
        
        if (fork() == 0) //level 2.6
        {
            registerProc(2, 6, getpid(), getppid());
            _exit(1);
        }
        
        if (fork() == 0) //level 2.7
        {
            registerProc(2, 7, getpid(), getppid());
            _exit(1);
        }

        while(wait(&status) > 0) {
            nbProcessusEnfants += WEXITSTATUS(status);
        }
        _exit(++nbProcessusEnfants);
    }

    while(wait(&status) > 0) {
        nbProcessusEnfants += WEXITSTATUS(status);
    }
    printf("%d\n", nbProcessusEnfants);
    printProcRegistrations();
    execlp("ls", "ls", "-l", NULL);
}


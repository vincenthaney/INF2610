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
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
// -------------------------------------------------

void question2( )
{
pid_t status;
pid_t childCount = 0;

registerProc(0, 0, getpid(), getppid());
    if(fork()==0)
    {
    registerProc(1, 1, getpid(), getppid());
        if(fork()==0)
        {   
            registerProc(2, 1, getpid(), getppid());
            _exit(childCount);
        }
        if(fork()==0)
        {
            registerProc(2, 2, getpid(), getppid());
            _exit(childCount);
        }
        if(fork()==0)
        {   
            registerProc(2, 3, getpid(), getppid());
            _exit(childCount);
        }
        if(fork()==0)
        {   
            registerProc(2, 4, getpid(), getppid());
            _exit(childCount);
        }
        wait(&status);
        childCount += (status >> 8) + 1;
        wait(&status);
        childCount += (status >> 8) + 1;
        wait(&status);
        childCount += (status >> 8) + 1;
        wait(&status);
        childCount += (status >> 8) + 1;
        _exit(childCount);
    }
    
    if(fork()==0){
        registerProc(1, 2, getpid(), getppid());
        
        if(fork()==0)
        {   
            registerProc(2, 5, getpid(), getppid());
            _exit(childCount);
        }
        if(fork()==0)
        {   
            registerProc(2, 6, getpid(), getppid());
            _exit(childCount);
        }
        if(fork()==0)
        {   
            registerProc(2, 7, getpid(), getppid());
            _exit(childCount);
        }
        wait(&status);
        childCount += (status >> 8) + 1;
        wait(&status);
        childCount += (status >> 8) + 1;
        wait(&status);
        childCount += (status >> 8) + 1;
        _exit(childCount);
    }
    
    wait(&status);
    childCount += (status >> 8) + 1;
    wait(&status);
    childCount += (status >> 8) + 1;
    printf("%d\n", childCount);
    printProcRegistrations();
    execlp("/usr/bin/ls", "ls","-l" ,NULL);
    _exit(0);
}

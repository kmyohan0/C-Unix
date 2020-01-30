//
// Created by Yohan on 1/29/2020.
//
#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <wait.h>

using namespace std;

int main() {
    /*
     *execvp() is probably most important function. It will execute the command that user wants to execute
     *
     * execvp() has two parameters:
     *    char* command
     *    char88[] args
     *
     * Note that you MUST put NULL at the end of the array of args (indicates end of argument)
     *
     * from this test code, it will print all the file names.
     */
    char *args[3];
    args[0] = "ls";
    args[1] = "-l";
    args[2] = NULL; //Indicating end of argument;
    execvp(args[0], args);
    return 0;
}


//
// Created by Yohan on 1/29/2020.
//
#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

int main() {
    /* Now, let's combine all functions (execvp(), waitpid(), and fork())
     */
    char *args[3];
    pid_t pid = fork();
    int status = 1;
    if (pid == -1) { //there was an error going in child processor
        cout << "There was an error creating an child processor." << endl;
        exit(-1);
    }
    else if (pid == 0) { // this is child process
        cout << "Child process is processing..." << endl;
        sleep(2);
        args[0] = "mkdir";
        args[1] = "test";
        args[2] = NULL; //Indicating end of argument;
        execvp(args[0], args);
        cout << "created test folder" << endl;
    }
    else { // this is parent process
        if(waitpid(pid, &status, WCONTINUED) < 0) { // there was an error during waitpid();
            perror("waitpid Failed");
            exit(-1);
        }
        else {
            cout << "Now, check to see if test folder has been created from parent class." << endl;
            args[0] = "ls";
            args[1] = "-a";
            execvp(args[0], args);
        }
    }
    return 0;
}


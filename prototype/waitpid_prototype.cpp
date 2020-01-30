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
    /* since waitpid() is a command that wait for child process to finish,
     * we need to make sure to use fork() when using waitpid()
     *
     * Important part is that waitpid() has three parameter variables:
     *    pid_t pid
     *    &int status
     *    int options -> Note that there are pre-made specific types for options so please be careful using options
     *
     * from this code, it should print "Child process is processing" then "waitpid made it"
     */
    pid_t pid = fork();
    int status = 1;
    if (pid == -1) { //there was an error going in child processor
        cout << "There was an error creating an child processor." << endl;
        exit(-1);
    }
    else if (pid == 0) { // this is child process
        cout << "Child process is processing..." << endl;
        sleep(10);
        cout << "done!" << endl;
        exit(0);
    }
    else { // this is parent process
        if(waitpid(pid, &status, WCONTINUED) < 0) { // there was an error during waitpid();
            perror("waitpid Failed");
            exit(-1);
        }
        else {
            cout << "waitpid made it." << endl;
            exit(0);
        }
    }
    return 0;
}


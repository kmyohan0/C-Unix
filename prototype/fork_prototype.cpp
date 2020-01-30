//
// Created by Yohan on 1/29/2020.
//
#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
    pid_t pid = fork();
    /* since fork() already created the child process of the main.cpp, now we have two if loops occurring at the same time.
     * first one is tested from the parent processor, so pid will be positive number.
     * second one is tested from the child processor, so pid will be 0.
     * the expected output will be
     *    <Child process has successfully created.>
     *    <It has returned back to the parent process.>
     */
    if (pid == -1) {
        cout << "There was an error creating an child processor." << endl;
        exit(-1);
    }
    else if (pid == 0) {
        cout << "Child process has successfully created." << endl;
        exit(1);
    }
    else {
        cout << "It has returned back to the parent process." << endl;
        exit(0);
    }
    return 0;
}


//
// Created by Yohan on 2/10/2020.
//

#ifndef RSHELL_TESTINGTOKEN_H
#define RSHELL_TESTINGTOKEN_H

#include "../header/base.h"
#include "iostream"

using namespace std;

class testingToken : public base {
private:
    string command = "";
    bool boolean;
public:
    testingToken   (string command) { this->command = command;};
    testingToken   (bool boolean) { this->boolean = boolean;};
    testingToken   (string command, bool boolean) { this->boolean = boolean; this->command = command;};
    bool execute() {
        if (boolean != NULL) {
            if (boolean) {
                cout << command;
                return boolean;
            }
            else {
                return boolean;
            }
        }
        else {
            return false;
        }
    };
};

#endif //RSHELL_TESTINGTOKEN_H

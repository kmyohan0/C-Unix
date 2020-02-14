//
// Created by Yohan on 2/10/2020.
//

#ifndef RSHELL_TESTTOKEN_H
#define RSHELL_TESTTOKEN_H

#include "../header/base.h"
#include "iostream"

using namespace std;

class testToken : public base {
private:
    string command = "";
    bool boolean;
public:
    testToken   (string command) {this->command = command;};
    testToken   (bool boolean) {this->boolean = boolean;};
    testToken   (string command, bool boolean) {this->boolean = boolean; this->command = command;};
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

#endif //RSHELL_TESTTOKEN_H

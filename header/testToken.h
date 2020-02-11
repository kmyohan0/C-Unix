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
    string command;
public:
    testToken   (string command) {this->command = command;};
    bool execute() {
        cout << command << endl;
        return true;
    };
};

#endif //RSHELL_TESTTOKEN_H

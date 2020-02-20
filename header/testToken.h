//
// Created by Yohan on 2/19/2020.
//

#ifndef RSHELL_TESTTOKEN_H
#define RSHELL_TESTTOKEN_H

#include "../header/base.h"
#include <string>
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include  <stdio.h>
#include  <sys/wait.h>
#include <string.h>

class testToken : public base {
private:
    string command;
public:
    testToken(vector<string> command);
    bool execute();
};

#endif //RSHELL_TESTTOKEN_H

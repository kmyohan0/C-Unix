//
// Created by Yohan on 3/5/2020.
//

#ifndef RSHELL_INPUTTOKEN_HPP
#define RSHELL_INPUTTOKEN_HPP
#include "../header/base.h"
#include <string>
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include  <stdio.h>
#include  <sys/wait.h>
#include <string.h>
#include <sys/fcntl.h>

using namespace std;

class inputToken : public base{

private:
    string filePath;
    base* left;
    base* right;
public:
    inputToken(vector<string> filePath);
    void setLeft(base* left);
    void setRight(base* right);
    bool execute();
};

#endif //RSHELL_INPUTTOKEN_HPP

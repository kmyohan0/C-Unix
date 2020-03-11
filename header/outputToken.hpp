//
// Created by Yohan on 3/5/2020.
//

#ifndef RSHELL_OUTPUTTOKEN_HPP
#define RSHELL_OUTPUTTOKEN_HPP

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

class outputToken : public base{

private:
    string filePath;
    //To determine whether we use append or rewrite, we must have a flag.
    string flag;
    base* left;
    base* right;
public:
    outputToken(vector<string> filePath);
    void setLeft(base* left);
    void setRight(base* right);
    bool execute();
};

#endif //RSHELL_OUTPUTTOKEN_HPP

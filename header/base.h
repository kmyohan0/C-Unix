//
// Created by Yohan on 2/5/2020.
//

#ifndef ASSIGNMENT_COUT_IDEAS_BASE_H
#define ASSIGNMENT_COUT_IDEAS_BASE_H

#include "string"

using namespace std;

class base {
private:
    string command;
public:
    base() {};
    virtual bool execute() = 0;
};

#endif //ASSIGNMENT_COUT_IDEAS_BASE_H

//
// Created by Yohan on 2/5/2020.
//

#ifndef RSHELL_PARSER_H
#define RSHELL_PARSER_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>
#include <sstream>
#include <stack>
#include <typeinfo>
#include <boost/tokenizer.hpp>
#include "../header/base.h"
#include "../header/andToken.h"
#include "../header/nextToken.h"
#include "../header/orToken.h"
#include "../header/quitToken.h"
#include "executeToken.h"
#include "inputToken.hpp"
#include "outputToken.hpp"
#include "pipeToken.hpp"
#include "testToken.h"
using namespace std;

class base;

class parser {
public:
    vector<string> elements;
    void parseString(vector<string>& tokenList);
    int priority(string token);
    vector<vector<string>> toPostFix(vector<string>& tokenList);
    base* postToTree(vector<vector<string>> tokenList);
public:
    void parseCommand(string input);
};

#endif //RSHELL_PARSER_H

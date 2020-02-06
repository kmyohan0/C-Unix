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
//Need to figure out how to install boost
//#include <boost/tokenizer.hpp>
#include "../header/base.h"
#include "base.h"

using namespace std;

class Parser {
private:
    vector<string> elements;
    void parseString(vector<string>& tokenList);
    vector<vector<string>> infixToPostFix(vector<string>& tokenList);
    base* postToTree(vector<vector<string>> tokenList);
public:
    void parseCommand(string input);
};

#endif //RSHELL_PARSER_H

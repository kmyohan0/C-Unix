//
// Created by Yohan on 2/5/2020.
//

#include "iostream"
#include <string>
#include <stdio.h>
#include <vector>

#include "../header/base.h"
#include "../header/parser.h"

using namespace std;

int main() {
    cout << "Running... type \"exit\" to quit" << endl;
    while (true) {
        string input;
        //instantiate parser
        parser* parse = new parser;
        cout << "$ ";
        getline(cin, input);
        if (input == "") {
            continue;
        }
        parse->parseCommand(input);
        delete parse;
        //parse it
        //inside parser class, there will be a execute function that actually runs it.
    }
    return 0;
}
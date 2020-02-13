//
// Created by Yohan on 2/5/2020.
//

#include "iostream"
#include <string>
#include <stdio.h>
#include <vector>

#include "../header/base.h"
#include "../header/Parser.h"

using namespace std;

int main() {
    cout << "Running... type \"exit\" to quit" << endl;
    while (true) {
        string input;
        //instantiate Parser
        Parser* parser = new Parser;
        cout << "$ ";
        getline(cin, input);
        if (input == "") {
            continue;
        }
        parser->parseCommand(input);
        delete parser;
        //parse it
        //inside Parser class, there will be a execute function that actually runs it.
    }
    return 0;
}
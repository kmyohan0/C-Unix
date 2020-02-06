//
// Created by Yohan on 1/29/2020.
//
#include <iostream>
#include "parser_prototype.h"

using namespace std;

int main() {
    string test1 = "ls";
    string test2 = "ls -a";
    string test3 = "cd ..";
    string test4 = "cd this; ls -a";
    parser_prototype parser;
    parser.addCommand(test1);
    cout << "testing test1" << endl;
    parser.parse();
    cout << "testing test2" << endl;
    parser.addCommand(test2);
    parser.parse();
    cout << "testing test3" << endl;
    parser.addCommand(test3);
    parser.parse();
    cout << "testing test4" << endl;
    parser.addCommand(test4);
    parser.parse();
    return 0;
}
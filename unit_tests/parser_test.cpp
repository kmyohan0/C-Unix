//
// Created by Yohan on 2/10/2020.
//
#include "../header/Parser.h"
//#include "gtest/gtest.h"
#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main(int argc, char **argv) {
    //Since most of our functions are private and requires integration
    //to actually show the result, in order to show unit tests,
    //We just decided to use hard-coded cout to actually test how it works
    //Also, for testing only, we changed all functions into public to actually use them in other main
    Parser* parser = new Parser;
    vector<string> geneticTest;
    geneticTest.push_back("ls -a; echo hello && mkdir test || echo world; git status");
    //first, figure out if this can be compilable in Hammer Server
    parser->parseString(geneticTest);
    for (int i = 0; i < geneticTest.size(); i++) {
        cout << geneticTest.at(i) << endl;
    }
    vector<vector<string>> posted = parser->toPostFix(geneticTest);
    for (int i = 0; i < posted.size(); i++) {
        for (int j = 0; j <posted.at(i).size(); j++) {
            cout << posted.at(i).at(j) << endl;
        }
    }
    return 0;
}

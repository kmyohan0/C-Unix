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
    geneticTest.push_back("ls -a");
    cout << geneticTest.back() << endl;
    //first, figure out if this can be compilable in Hammer Server
    //parser->parseCommand("ls -a");

}

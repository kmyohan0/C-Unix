//
// Created by Yohan on 2/19/2020.
//
#include "../header/testToken.h"

testToken::testToken(vector<string> testCommand) {
    for (int i = 0; i < testCommand.size(); i++) {
        testCommand.push_back(const_cast<char *> (testCommand.at(i).c_str()));
    }
    testCommand.push_back(NULL);
}

bool testToken::execute() {
    return false;
}

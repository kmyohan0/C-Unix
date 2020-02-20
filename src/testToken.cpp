//
// Created by Yohan on 2/19/2020.
//
#include "../header/testToken.h"

testToken::testToken(vector<string> testCommand) {
    for (int i = 0; i < testCommand.size(); i++) {
        commands.push_back(const_cast<char *> (testCommand.at(i).c_str()));
    }
    //1st: Remove test or bracket
    commands.erase(commands.begin());
    if (commands.at(commands.size() -1) == "]") {
        commands.pop_back();
    }
    //2nd: flag
    flag = commands.at(0);
    //3rd: filePath
    string temp = commands.at(commands.size()  -1);
    strcpy(filePath, temp.c_str());
}

bool testToken::execute() {
    struct stat stats;
    if (stat(reinterpret_cast<const char *>(&filePath), &stats) < 0) {
        exit(1);
    }
    if (S_ISREG(stats.st_mode) || S_ISDIR(stats.st_mode)) {
        if (flag[1] == 'e') {
            cout << "(True)" << endl;
            return true;
        }
    }
    else {
        if (S_ISREG(stats.st_mode)) {
            if (flag[1] == 'f') {
                cout << "(True)" << endl;
                return true;
            }
            cout << "(False)" << endl;
            return false;
        }
        else if (S_ISDIR(stats.st_mode)) {
            if (flag[1] == 'd') {
                cout << "(True)" << endl;
                return true;
            }
            cout << "(False)" << endl;
            return false;
        }
    }
}

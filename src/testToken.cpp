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
    if (strcmp(commands.at(commands.size() -1),"]") == 0) {
        commands.pop_back();
    }
    //2nd: flag
    flag = commands.at(0);
    //3rd: filePath
    if (commands.size() < 2) {
        filePath = ".";
    }
    else {
        filePath = commands.at(commands.size()  -1);
    }
}

bool testToken::execute() {
    struct stat stats;
    const char* filePathTemp = filePath;
    if (stat(filePathTemp, &stats) < 0) {
        cout << "(False)" << endl;
        return false;
    }
    char switchChar = flag[1];
    switch (switchChar) {
        case 'e' : {
            if (S_ISREG(stats.st_mode) || S_ISDIR(stats.st_mode)) {
                cout << "(True)" << endl;
                return true;
            }
            cout << "(False)" << endl;
            return false;
        }
        case 'f' : {
            if (S_ISREG(stats.st_mode)) {
                cout << "(True)" << endl;
                return true;
            }
            cout << "(False)" << endl;
            return false;
        }
        case 'd' : {
            if (S_ISDIR(stats.st_mode)) {
                cout << "(True)" << endl;
                return true;
            }
            cout << "(False)" << endl;
            return false;
        }
    }
}


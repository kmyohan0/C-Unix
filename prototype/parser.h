//
// Created by Yohan on 1/29/2020.
//

#ifndef ASSIGNMENT_COUT_IDEAS_PARSER_H
#define ASSIGNMENT_COUT_IDEAS_PARSER_H

#include <string>
#include <vector>
//Need to include base and other components, since parser will execute too

using namespace std;

class parser {
private:
    string userInput;
    vector<string> elements;
    void convertIntoPostFix();
    void postFixtoTree();
public:
    parser();
    void addCommand(string input);
    void parse();
};


#endif //ASSIGNMENT_COUT_IDEAS_PARSER_H

//
// Created by Yohan on 1/29/2020.
//

#include <cstring>
#include <iostream>
#include "parser.h"

parser::parser() {
    userInput = "";
}

void parser::addCommand(string input) {
    userInput = input;
}
// We need to convert our commands into postfix.
// The reason is because humans are comfortable
// understanding postfix equations, but computer is not.
// We can use postfix method to easily store our base contents into the tree and run as infix order.
void parser::convertIntoPostFix() {

}
//We use tree to easily access our elements as well as use composite patterns easily.
//i.e. root->execute();
//     left->execute();
//     right->execute();
void parser::postFixtoTree() {

}

void parser::parse() {
    int startPosition = 0;
    for (int i = 0; i < userInput.length(); i++) {
        if (userInput[i] == ' ' || i == userInput.length() -1) {
            if (userInput[i+1] == '-') {
                i += 2;
            }
            string substring = userInput.substr(startPosition, i - startPosition + 1);
            elements.push_back(substring);
            i++;
            startPosition = i;
        }
        else if (i == userInput.length()-2 && elements.size() == 0) {
            elements.push_back(userInput);
        }
    }
    for (int i = 0; i < elements.size(); i++) {
        cout << elements.at(i) << endl;
    }
    elements.clear();
}
//
// Created by Yohan on 3/5/2020.
//

#include "../header/outputToken.hpp"

outputToken::outputToken(vector<string> filePath) {
    this->filePath = filePath.at(0);
    flag = filePath.at(1);
}

void outputToken::setLeft(base *left) {
    this->left = left;
}

void outputToken::setRight(base *right) {
    this->right = right;
}

bool outputToken::execute() {
    return false;
}
//
// Created by Yohan on 2/5/2020.
//
#include "../header/Parser.h"

void Parser::parseCommand(string input) {
    vector<string> tokenList;
    tokenList.push_back(input);
    parseString(tokenList);
    vector<vector<string>>postList = infixToPostFix(tokenList);
    base* root = postToTree(postList);
    root->execute();
}

void Parser::parseString(vector<string> &tokenList) {
/*
 * 1. use Boost separate library to separate space, comma, etc.
 * 2. use Boost tokenizer library to push back each element that was trimmed down.
 * 3. Change compound string into tokens.*/
}

vector<vector<string>> Parser::infixToPostFix(vector<string> &tokenList) {
    return vector<vector<string>>();
}

base *Parser::postToTree(vector<vector<string>> tokenList) {
    return nullptr;
}





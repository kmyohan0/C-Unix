//
// Created by Yohan on 2/5/2020.
//
#include "../header/Parser.h"

void Parser::parseCommand(string input) {
    vector<string> tokenList;
    tokenList.push_back(input);
    parseString(tokenList);
    vector<vector<string>>postList = toPostFix(tokenList);
    base* root = postToTree(postList);
    root->execute();
}

void Parser::parseString(vector<string> &tokenList) {
/*
 * 1. use Boost separate library to separate space, comma, etc.
 * 2. use Boost tokenizer library to push back each element that was trimmed down.
 * 3. Change compound string into tokens.*/
    for (int i = 0; i < tokenList.size(); i++) {
        string token = tokenList.at(i);
        int temp = i;
        boost::char_separator<char> str_separator("","\"\'");
        boost::tokenizer<boost::char_separator<char> > string_token(token, str_separator);
        boost::tokenizer<boost::char_separator<char> >::iterator itr;
        for (itr = string_token.begin(); itr != string_token.end(); itr++) {
            tokenList.push_back(*itr);
            temp++;
        }
        tokenList.erase(tokenList.begin() + i);
        i = temp;
    }

    for (int i = 0; i < tokenList.size(); i++) {
        string token = tokenList.at(i);
        if (token == "\"" || token == "\'") {
            i++;
            if (i != tokenList.size() && tokenList.at(i).compare(token) != 0) {
                string origin = tokenList.at(i);
                int j = i;
                j++;
                for (int j; j < tokenList.size() && tokenList.at(j).compare(token) != 0; j++) {
                    origin += tokenList.at(j);
                    tokenList.erase(tokenList.begin() + j);
                    j = i;
                }
                if (tokenList.begin() + j == tokenList.end()) {
                    tokenList.push_back(token);
                }
                tokenList.at(i) = origin;
                i++;
            }
            else if (tokenList.begin() + i == tokenList.end()) {
                i--;
            }
        }
    }
}

vector<vector<string>> Parser::toPostFix(vector<string> &tokenList) {
    vector<string> string_entry;
    stack<string> lists;
    vector<vector<string> > postFix;

    for (int i = 0; i < tokenList.size(); i++) {
        string token = tokenList.at(i);
        //for every command, check whether they are composite (and, or, next) or leaf (executable commands)
        //if composite, then we need to set that as a branch and add one prev and one next command as leaf.
        //by doing
        /*
         * the input character is an operand, add it to the postFix.
            If the input character is an operator-
                If stack is empty push it to the stack.
                If it’s precedence value is greater than the precedence value of the character on top, push.
                If it’s precedence value is lower then pop from stack and print while precedence of top char is more
                than the precedence value of the input character.
            Repeat steps until input expression is completely read.
            Pop the remaining elements from stack and print them.

            --Reference from GeeksforGeeks
         */

        //else, then just put it in stack
        if (token == ";" || token == "||" || token == "&&") {
            if (string_entry.size() > 0) {
                postFix.push_back(string_entry);
                string_entry.clear();
            }
            while (!lists.empty()) {
                string connector = lists.top();
                vector<string> connector_temp;
                connector_temp.push_back(connector);
                postFix.push_back(connector_temp);
                lists.pop();
            }
            lists.push(token);
        }
        else {
            string_entry.push_back(token);
        }
    }
    //Push back saved string entry
    if (string_entry.size() > 0) {
        postFix.push_back(string_entry);
        string_entry.clear();
    }
    //do same thing that we did for branch
    while (!lists.empty()) {
        string connector = lists.top();
        vector<string> connector_temp;
        connector_temp.push_back(connector);
        postFix.push_back(connector_temp);
        lists.pop();
    }
    return postFix;
}

base *Parser::postToTree(vector<vector<string>> tokenList) {
    vector<base* > command_stack;
    for (int i  = 0; i < tokenList.size(); i++) {
        vector<string> temp = tokenList.at(i);
        //now set every composite command into a tree
        if (temp.at(0) == "&&") {
        }
        else if (temp.at(0) == "||") {
        }
        else if (temp.at(0) == ";") {
        }
        else {
        }
    }
    return command_stack.back();
}





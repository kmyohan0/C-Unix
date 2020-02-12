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
    cout << "Working!" << endl;
    root->execute();
}

void Parser::parseString(vector<string> &tokenList) {
/*
 * Things that I need to think about
 * 0. use string iteration to take out anything that follows with # (comment)
 * 1. use Boost separate library to separate space, comma, etc.
 * 2. use Boost tokenizer library to push back each element that was trimmed down.
 * 3. Change compound string into tokens.*/
    int i = 0;
    string compoundToken = tokenList.at(0);
    boost::char_separator<char> separator(" ", ";");
    boost::tokenizer<boost::char_separator<char>> tokenizer(compoundToken, separator);
    boost::tokenizer<boost::char_separator<char>>::iterator tokenizer_itr;
    for (tokenizer_itr = tokenizer.begin(); tokenizer_itr != tokenizer.end(); tokenizer_itr++) {
        string token = *tokenizer_itr;
        tokenList.insert(tokenList.begin() + i, token);
        if (token[0] == '#') { // if we find comment, then iterate through remaining iterators so that we ignore characters that
            // comes after the comment
            boost::tokenizer< boost::char_separator<char> >::iterator temp = tokenizer_itr;
            ++temp;
            while(temp != tokenizer.end())
            {
                ++temp;
                ++tokenizer_itr;
            }

            tokenList.shrink_to_fit();
        }
        i++;
    }
    tokenList.erase(tokenList.end() - 1);
}


vector<vector<string>> Parser::toPostFix(vector<string> &tokenList) {
    vector<string> string_entry;
    stack<string> lists;
    vector<vector<string> > postFix;
    for (int i = 0; i < tokenList.size(); i++) {
        string token = tokenList.at(i);
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
            andToken* token  = new andToken();
            if(!command_stack.empty()) {
                token->setRight(command_stack.back());
                command_stack.pop_back();
            }
            if(!command_stack.empty()) {
                token->setLeft(command_stack.back());
                command_stack.pop_back();
            }
            command_stack.push_back(token);
        }
        else if (temp.at(0) == "||") {
            orToken* token;
            if(!command_stack.empty()) {
                token->setRight(command_stack.back());
                command_stack.pop_back();
            }
            if(!command_stack.empty()) {
                token->setLeft(command_stack.back());
                command_stack.pop_back();
            }
            command_stack.push_back(token);
        }
        else if (temp.at(0) == ";") {
            nextToken* token;
            if(!command_stack.empty()) {
                token->setRight(command_stack.back());
                command_stack.pop_back();
            }
            if(!command_stack.empty()) {
                token->setLeft(command_stack.back());
                command_stack.pop_back();
            }
            command_stack.push_back(token);
        }
        else if (temp.at(0) == "--q") {
            quitToken* token;
            command_stack.push_back(token);
        }
        else {
            //need to add:
            //Executable executable = new executable(temp);
            //command_stack.push_back(executable);
            int size = temp.size() + 1;
            char *argv[size];
            for (int i = 0; i < size -1; i++) {
                strcpy(argv[i], temp.at(i).c_str());
            }
            argv[size-1] = NULL;
            Executable* executable = new Executable(argv);
            command_stack.push_back(executable);
        }
    }
    return command_stack.back();
}
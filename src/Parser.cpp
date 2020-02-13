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
    //cout << "Workgin" << endl;
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
    // implement \"\' in the separator
    boost::char_separator<char> separator(" ", ";");
    boost::tokenizer<boost::char_separator<char>> tokenizer(compoundToken, separator);
    boost::tokenizer<boost::char_separator<char>>::iterator tokenizer_itr;
    for (tokenizer_itr = tokenizer.begin(); tokenizer_itr != tokenizer.end(); tokenizer_itr++) {
        string token = *tokenizer_itr;
        if (token[0] == '#') {
            /* if we find comment, then iterate through remaining
             * iterators so that we ignore characters that
             * comes after the comment
             * */
            break;
        }
//        else if (token[0] == '\"' || token[0] == '\'') {
//            /*if we find quotation mark, then we should iterate through all
//             * token elements until we find end quotation mark. If we find it,
//             * then consider all strings that are in quotation as one argumentlist
//             */
//
//        }
        tokenList.insert(tokenList.begin() + i, token);
        i++;
    }
    if (tokenList.size() != 0) {
        tokenList.erase(tokenList.end() - 1);
    }
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
            orToken* token = new orToken();
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
            nextToken* token = new nextToken();
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
        else if (temp.at(0) == "exit") {
            quitToken* token = new quitToken();
            command_stack.push_back(token);
        }
        else {
            //need to add:
            //Executable executable = new executable(temp);
            //command_stack.push_back(executable);
//            int size = temp.size() + 1;
//            for (int i = 0; i < size -1; i++) {
//                string string_temp = temp.at(i);
//                strcpy(argv[i], string_temp.c_str());
//            }
//            argv[size-1] = NULL;

//            int size = temp.size() + 1;
//            char* argv[size];
//            for (int i = 0; i < size -1; i++) {
//                string str_temp =  temp.at(i);
//                argv[i] = const_cast<char *>(str_temp.c_str());
//            }
//            argv[size-1] = NULL;

//            for (int i = 0; i < temp.size(); i++) {
//                commands.push_back(temp.at(i));
//            }
//            commands.push_back(NULL);

             Executable* executable = new Executable(temp);
            command_stack.push_back(executable);
        }
    }
    if (command_stack.empty()) {
        vector<string> temp;
        Executable* executable = new Executable(temp);
        command_stack.push_back(executable);
    }
    return command_stack.back();
}
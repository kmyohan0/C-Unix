//
// Created by Yohan on 2/5/2020.
//
#include "../header/parser.h"

void parser::parseCommand(string input) {
    vector<string> tokenList;
    tokenList.push_back(input);
    parseString(tokenList);
    vector<vector<string>>postList = toPostFix(tokenList);
    base* root = postToTree(postList);

    root->execute();
}

void parser::parseString(vector<string> &tokenList) {
/*
 * Things that I need to think about
 * 0. use string iteration to take out anything that follows with # (comment)
 * 1. use Boost separate library to separate space, comma, etc.
 * 2. use Boost tokenizer library to push back each element that was trimmed down.
 * 3. Change compound string into tokens.*/
    int i = 0;
    string compoundToken = tokenList.at(0);
    // implement \"\' in the separator
    boost::char_separator<char> separator(" ", ";[]()");
    boost::tokenizer<boost::char_separator<char>> tokenizer(compoundToken, separator);
    boost::tokenizer<boost::char_separator<char>>::iterator tokenizer_itr;
    bool find = false;
    vector<string> needsToAdd;
    int k = 0;
    int lastPlace = 0;
    for (tokenizer_itr = tokenizer.begin(); tokenizer_itr != tokenizer.end(); tokenizer_itr++) {
        string token = *tokenizer_itr;
        boost::tokenizer<boost::char_separator<char>>::iterator quoStart;
        for (int j = 0; j < token.size(); j++) {
            char character = token.at(j);
            if (character == '"') {
                if (!find) {
                    find = true;
                    k = i;
                }
                else {
                    for (int m = 0; m < (i-k); m++) {
                        token = needsToAdd.back() + " " + token;
                        needsToAdd.pop_back();
                    }
                    token.erase(remove(token.begin(),token.end(),'\"'),token.end());
                    find = false;
                }
            }
        }
        if (token[0] == '#') {
            break;
        }
        if (!find) {
            tokenList.insert(tokenList.begin() + lastPlace, token);
            lastPlace++;
        }
        else {
            needsToAdd.push_back(token);
        }
        i++;
    }
    if (tokenList.size() != 0) {
        tokenList.erase(tokenList.end() - 1);
    }

}

int parser::priority(string token)
{
    if (token == "(")
    {
        return 3;
    }
    else if (token == "<" || token == ">" || token == ">>" || token == "|") {
        return 2;
    }
    else if (token == "&&" || token == "||" || token == ";")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


vector<vector<string>> parser::toPostFix(vector<string> &tokenList) {
    vector<string> string_entry;
    stack<string> lists;
    vector<vector<string> > postFix;
    for (int i = 0; i < tokenList.size(); i++) {
        string token = tokenList.at(i);
        if (token == ";" || token == "||" || token == "&&" || token == "(" || token == ")" || token == "<" || token == ">" || token == ">>" || token == "|") {
            if (token == "(") {
                lists.push(token);
//                postFix.push_back(string_entry);
//                string_entry.clear();
            }
            else if (token == ")") {
                if (string_entry.size() > 0) {
                    postFix.push_back(string_entry);
                    string_entry.clear();
                }
                while (lists.top() != "(") {
                    string temp = lists.top();
                    vector<string> paren_temp;
                    paren_temp.push_back(temp);
                    postFix.push_back(paren_temp);
                    lists.pop();
                }
                lists.pop();
            }
            else {
                if (string_entry.size() > 0) {
                    postFix.push_back(string_entry);
                    string_entry.clear();
                }
                while (!lists.empty() && priority(token) <= priority(lists.top())) {
                    if (lists.top() == "(") {
                        break;
                    }
                    string temp = lists.top();
                    vector<string> paren_temp;
                    paren_temp.push_back(temp);
                    postFix.push_back(paren_temp);
                    lists.pop();
                }
                lists.push(token);
            }
        }
        //for commands
        else {
//            if (string_entry.size() > 0) {
//                postFix.push_back(string_entry);
//                string_entry.clear();
//            }
//            while (!lists.empty()) {
//                string connector = lists.top();
//                vector<string> connector_temp;
//                connector_temp.push_back(connector);
//                postFix.push_back(connector_temp);
//                lists.pop();
//            }
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

base *parser::postToTree(vector<vector<string>> tokenList) {
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
        else if (temp.at(0) == "test" || temp.at(0) == "[") {
            testToken *token = new testToken(temp);
            command_stack.push_back(token);
    }
        //TODO: take out executable and just implement the filename into the input/outputToken
        //i.e. if (typeid(command.stack.back()) == typeid(Executable*()))
        else if (temp.at(0) == ">" || temp.at(0) == ">>") {
            outputToken* token;
            //i.e. cat < testFilePath will give us (cat | testFilePath | <) for postFix. that means, our command_stack
            //will have testFilePath for last element (command_stack.back()), thus check if it is executable, then copy
            // filePath.
            if (typeid(*command_stack.back()).name() == typeid(Executable).name()) {
                Executable* temp_exec = static_cast<Executable* >(command_stack.back());
                vector<string> inputs = {temp_exec->getFileName()};
                inputs.push_back(temp.at(0));
                token = new outputToken(inputs);
                command_stack.pop_back();
            }
                //userInput will be something like: && < filePath
            else {
                cout << "Invalid syntax." << endl;
                exit(1);
            }
            if(!command_stack.empty()) {
                token->setLeft(command_stack.back());
                command_stack.pop_back();
            }
            command_stack.push_back(token);
        }
        else if (temp.at(0) == "<" ) {
            inputToken* token;
            //i.e. cat < testFilePath will give us (cat | testFilePath | <) for postFix. that means, our command_stack
            //will have testFilePath for last element (command_stack.back()), thus check if it is executable, then copy
            // filePath.
            if (typeid(*command_stack.back()).name() == typeid(Executable).name()) {
                Executable* temp_exec = static_cast<Executable* >(command_stack.back());
                vector<string> inputs = {temp_exec->getFileName()};
                token = new inputToken(inputs);
                command_stack.pop_back();
            }
            //userInput will be something like: && < filePath
            else {
                cout << "Invalid syntax." << endl;
                exit(1);
            }
            if(!command_stack.empty()) {
                token->setLeft(command_stack.back());
                command_stack.pop_back();
            }
            command_stack.push_back(token);
        }
        //TODO: work on pipeToken (still having trouble understanding how pipe works)
        else if (temp.at(0) == "|") {
            pipeToken* token = new pipeToken(temp);
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
        else {
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

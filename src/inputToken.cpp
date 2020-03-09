//
// Created by Yohan on 3/5/2020.
//


#include "../header/inputToken.hpp"

inputToken::inputToken(vector<string> filePath) {
    this->filePath = filePath.at(0);
}

void inputToken::setLeft(base *left) {
    this->left = left;
}

void inputToken::setRight(base *right) {
    this->right = right;
}

bool inputToken::execute() {
    //Similar to execute, but instead of using execvp(), we use open()
    int status = 1;
    pid_t pid = fork();
    if (pid == 0)
    {
        //when stdin is open, it doesn't let open() to be executed by left child so we need to close it
        close(0);
        int inputFile = open(filePath.c_str(), O_RDONLY);
        if (left->execute()) {
            close(inputFile);
            exit(0);
        }
        else {
            exit(1);
        }
        // We should assume that there is no right child for input/outputToken
    }
    else if (pid < 0)
    {
        perror("Failed to fork.");
        exit(1);
    }
    else
    {
        if (waitpid(pid, &status, WCONTINUED) < 0)
        {
            perror("Failed to process waitpid");
            exit(1);
        }
        if (status == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

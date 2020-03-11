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
    //Similar to executeToken, but different handling with child process
    int status = 1;
    pid_t pid = fork();
    //child process
    if (pid == 0)
    {
        //1. replace stdout with our file (close stdout (i.e. 1) first)
        close(1);
        //2. Truncate O_TRUNC() or O_WRONLY() based on our flag (> or >>)
        int fd;
        if (this->flag == ">") {
            fd = open(filePath.c_str(), O_CREAT | O_WRONLY | O_TRUNC);
        }
        else {
            fd = open(filePath.c_str(), O_CREAT | O_WRONLY | O_APPEND);
        }
        if (left->execute()) {
            if (right->execute()) {
//                close(fd);
                exit(0);
            }
            exit(1);
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
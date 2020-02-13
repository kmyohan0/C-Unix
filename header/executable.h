
#ifndef __EXECUTABLE_H__ 
#define __EXECUTABLE_H__

#include "../header/base.h"
#include <string> 
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include  <stdio.h>
#include  <sys/wait.h>
#include <string.h>

using namespace std;

class Executable : public base{

        private:
                vector<char *> token_command;
        public:
                Executable(vector<string> command_token);
                bool execute();
};








#endif //__EXECUTABLE_H__


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

using namespace std;

class Executable : public base{

        private:
                char **command;
        public:
                Executable(char **command);
                bool execute();
};








#endif //__EXECUTABLE_H__


#include "../header/executeToken.h"


Executable::Executable(vector<string> command_token)
{
    for (int i = 0; i < command_token.size(); i++) {
        token_command.push_back(const_cast<char *> (command_token.at(i).c_str()));
    }
    token_command.push_back(NULL);
}

bool Executable::execute()
{
	int status = 1;
	pid_t pid = fork();

	if (pid == 0)
	{
	    char** command = &token_command[0];
		if (execvp( command[0], command) < 0)
		{
			perror("command failed.");
			exit(1);
		}
		status = 1;
		exit(1);  
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

string Executable::getFileName() {
    //when using I/O redirection, fileName will be at the first element of the command_stack
    // (in fact, it will only have one element), so  we return token_command.at(0);
    return token_command.at(0);
}

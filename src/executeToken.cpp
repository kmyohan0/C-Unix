
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
	int status = 0;
	pid_t pid;

	if (pid = fork() == 0)
	{
	    char** command = &token_command[0];
		if (execvp( command[0], command) < 0)
		{
			perror("Exec failed.");
			exit(1);
		}
		status = 1;
		exit(1);  
	}
	else if (pid < 0)
	{
		perror("Fork failed.");
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, WCONTINUED) < 0)
		{
			perror("waitPid failed");
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

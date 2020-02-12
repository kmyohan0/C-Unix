
#include "../header/executable.h"


Executable::Executable(char ** command)
{
	this->command = command;
}

bool Executable::execute()
{
	int status = 0;
	pid_t pid;

	if (pid = fork() == 0)
	{
		if (execvp(*command, command) < 0)
		{
			perror("Exec failed.");
			exit(-1);
		}
		status = 1;
		exit(1);  
	}
	else if (pid < 0)
	{
		perror("Fork failed.");
		exit(-1);
	}
	else
	{
		if (waitpid(pid, &status, WCONTINUED) < 0)
		{
			perror("waitPid failed");
			exit(-1);
		}
		if (status == 0)
		{
			return true;
		}
		return false;
	}
	return false;	 
}

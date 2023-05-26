#include "prncpl.h"
/**
* rpdIsr - int func dyalhum hadi saraha
*
* Return: zero fhal shfnja
*/
int rpdIsr(void)
{
	char *rpdIsr = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, rpdIsr, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}
/**
* Isrcheckbuiltins - akhuty bzzf elina had int 
* @av: bla mandwi bayna prm
* @buffer: haheyaa akhra
* @exitstatus: 3awtani
* Return: ila bghete z3ma kuni wahad ula zero
*/
int Isrcheckbuiltins(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_IsrStrcmp(av[0], "env") == 0)
	{
		_envIsr();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_IsrStrcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
* _Isrread - bogossa dyalna char func tane 
*
* Return: finma bghete whenever wherever pointer
*/
char *_Isrread(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
/**
* _IsrFlPTH - hade ghaliban char func
* @av: bla mandwe hihi prm
* @PATH: hta hna 
* @copy:also here
*
* Return: proba pointer
*/
char *_IsrFlPTH(char **av, char *PATH, char *copy)
{
	char *tok, *Isrflpth = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _Isrstrdup(PATH);
	PATHcount = _IsrsplitPATH(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _IsrCnct(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			Isrflpth = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _Isrstrlen(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					Isrflpth = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		Isrflpth = av[0];
	free(copy);
	return (Isrflpth);
}

/**
* _Isrforkproces -everything with this char func
* @av: bla mandwi prm 
* @buffer: prm dyalna
* @Isrflpth: idem hta hna
*
* Return: ghaliban naj7a 0
*/
int _Isrforkproces(char **av, char *buffer, char *Isrflpth)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(Isrflpth, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}

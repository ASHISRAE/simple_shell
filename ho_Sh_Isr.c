#include "prncpl.h"
/**
* main - int func principale
*
* Return: 0 on Golder git
*/
int main(void)
{
	char *Isrflpth = NULL, *copy = NULL, *buffer = NULL;
	char *PATH = NULL;
	char **av;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _Isrgetenv("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		rpdIsr();
		buffer = _Isrread();
		if (*buffer != '\0')
		{
			av = IsrtknSz(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			Isrflpth = _IsrFlPTH(av, PATH, copy);
			if (Isrcheckbuiltins(av, buffer, exitstatus) == 1)
				continue;
			exitstatus = _Isrforkproces(av, buffer, Isrflpth);
		}
		else
			free(buffer);
	}
	return (0);
}

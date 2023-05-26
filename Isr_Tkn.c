#include "prncpl.h"
/**
* IsrtknSz - working char func
* @buffer: their prm parametre
*
* Return: their prm also
*/
char **IsrtknSz(char *buffer)
{
	char *token;
	int i = 0, wordcount = 0;
	char *delimiter = " \n";
	char **av;

	wordcount = _Isrsplitstring(buffer);
	if (!wordcount)
		return (NULL);
	av = malloc((wordcount + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _Isrstrdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}
/**
* _IsrsplitPATH - int maqla fun
* @Isrnstr: hade hta huwa prm dyalhum yallah
*
* Return: number of the PATH MEMBERS
*/
int _IsrsplitPATH(char *Isrnstr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; Isrnstr[i]; i++)
	{
		if (Isrnstr[i] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (Isrnstr[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (wordcount);
}
/**
* _IsrPATHstrcmp - za3za3 int func
* @strIsr1: hade qalek asidi prm parametre
* @strIsr2: idem hna
*
* Return: 0 succesfully connected
*/
int _IsrPATHstrcmp(const char *strIsr1, const char *strIsr2)
{
	int i;

	for (i = 0; strIsr2[i] != '='; i++)
	{
		if (strIsr1[i] != strIsr2[i])
			return (-1);
	}
	return (0);
}
/**
* _IsrCnct - all of them char funcs
* @tmp: blash nqulikum tane shnu hadu PRM
* @av: idem dkl
* @tok: also same
*
* Return: 0 najah inshallah
*/
char *_IsrCnct(char *tmp, char **av, char *tok)
{
	int len = 0;

	_IsrMemset(tmp, 0, 256);
	len = _Isrstrlen(tok) + _Isrstrlen(av[0]) + 2;
	_IsrStrCat(tmp, tok);
	_IsrStrCat(tmp, "/");
	_IsrStrCat(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}

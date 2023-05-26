#include "prncpl.h"
/**
* _Isrstrdup - hade heya l function dyal char
* @Isrnstr: hade heya prmtr dyalha
*
* Return: hade dyal pointer
*/
char *_Isrstrdup(char *Isrnstr)
{
	int c;
	char *dest_str;

	if (Isrnstr == NULL)
		return (NULL);
	for (c = 0; Isrnstr[c] != '\0'; c++)
		;
	dest_str = malloc(sizeof(char) * (c + 1));
	if (dest_str == NULL)
		return (NULL);
	for (c = 0; Isrnstr[c] != '\0'; c++)
	{
		dest_str[c] = Isrnstr[c];
	}
	dest_str[c] = '\0';
	return (dest_str);
}
/**
* _Isrsplitstring - kulhum fihum int function
* @Isrnstr: mafehash prmtr error 404
*
* Return: hade feha prmtr dyalhum
*/
int _Isrsplitstring(char *Isrnstr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; Isrnstr[i]; i++)
	{
		if (Isrnstr[i] != ' ' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (Isrnstr[i + 1] == ' ')
			searchflag = 1;
	}
	return (wordcount);
}
/**
* _IsrStrcmp - had int function twela as hell
* @strIsr1: hade param prmtr
* @strIsr2: hta hade
* Return: der int lshe number
*/
int _IsrStrcmp(const char *strIsr1, const char *strIsr2)
{
	while ((*strIsr1 != '\0' && *strIsr2 != '\0') && *strIsr1 == *strIsr2)
	{
		strIsr1++;
		strIsr2++;
	}
	if (*strIsr1 == *strIsr2)
		return (0);
	else
		return (*strIsr1 - *strIsr2);
}
/**
* _IsrStrCat - hade char function
* @dest: hade param parametre
* @src: idem
* i - new param alala
* j - also
* Return: hada letter char
*/
char *_IsrStrCat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
/**
* _Isrstrlen - lot of int functions
* @s: working param
* i - their parametre
* Return: maybe it`s int
*/
int _Isrstrlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

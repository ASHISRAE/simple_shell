#include "prncpl.h"

/**
* _IsrMemset - function mesmerised
* @s: prmtr dyal S.
* @b: prmtr dyal B.
* @n: prntr dyal N.
* Return: ARR.
*/
char *_IsrMemset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
/**
* _envIsr - printing the env
*
* Return: 0 successful.
*/
int _envIsr(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_Isrputs(environ[i]);
	return (0);
}
/**
* _Isrputs - printing str pro max.
* @Isrnstr: str printf.
*/
void _Isrputs(char *Isrnstr)
{
	int c;

	for (c = 0; Isrnstr[c] != '\0'; c++)
		_Israptch(Isrnstr[c]);
	_Israptch('\n');
}
/**
* _Isrgetenv - char the function the slution pro.
* @name: parammtre the pro.
*
* Return: NULL
*/
char *_Isrgetenv(const char *name)
{
int i, result;

for (i = 0; environ[i]; i++)
{
	result = _IsrPATHstrcmp(name, environ[i]);
	if (result == 0)
	{
		return (environ[i]);
	}
}
return (NULL);
}
/**
* _Israptch - prnt character pro max.
* @c: character prnt pro.
*
* Return: value success.
*/
int _Israptch(char c)
{
	return (write(1, &c, 1));
}

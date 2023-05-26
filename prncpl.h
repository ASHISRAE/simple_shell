#ifndef PRNCPL_H
#define PRNCPL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int _Israptch(char c);
int _IsrStrcmp(const char *strIsr1, const char *strIsr2);
char *_IsrStrCat(char *dest, char *src);
int _Isrstrlen(char *s);

int rpdIsr(void);
char *_Isrread(void);
char *_IsrMemset(char *s, char b, unsigned int n);
int _IsrPATHstrcmp(const char *strIsr1, const char *strIsr2);
char *_Isrgetenv(const char *name);

char *_Isrstrdup(char *Isrnstr);
int _Isrsplitstring(char *Isrnstr);
int Isrcheckbuiltins(char **av, char *buffer, int exitstatus);
int _IsrsplitPATH(char *Isrnstr);
int _envIsr(void);
void _Isrputs(char *Isrnstr);
char *_IsrFlPTH(char **av, char *PATH, char *copy);
char **IsrtknSz(char *buffer);
char *_IsrCnct(char *tmp, char **av, char *tok);
int _Isrforkproces(char **av, char *buffer, char *Isrflpth);

#endif

#include <unistd.h>
int _putchar(char c)                                                                                                                              

{                                                                                                                                                  

	        return (write(1, &c, 1));                                                                                                                  

}

int _islower(int c)                                                                                                                                  

{                                                                                                                                                   
	        if (c >= 97 && c <= 122)
		{                                              
			return (1);
		}                                                                                                                                            
			return (0);
}


int _isalpha(int c)
{
	if ((c >= 65 &&  c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}

	return (0);
}

int _abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return(1);
	else
		return(0);
}

int _strlen(char *s)
{
	int len;

	for (len = 0; *s != '\0';)
	{
		len++;
		s++;
	}

	return (len);
}

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

char *_strcpy(char *dest, char *src)
{
}

int _atoi(char *s)
{
	int i = 0;
	int n = 0;
	int signo = 1;

	while ((s[i] < '0' || s[i] > '9') && s[i] != 0)
	{
		if (s[i] == '-')
			signo *= -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != 0)
	{
		if (n >= 0)
		{
			n = n * 10 - (s[i] - '0');
			i++;
		}
		else
		{
			n = n * 10 - (s[i] - '0');
			i++;
		}
	}
	signo *= -1;
	return (n * signo);
}

char *_strcat(char *dest, char *src)
{

}

char *_strncat(char *dest, char *src, int n)
{

}

char *_strncpy(char *dest, char *src, int n)
{

}

int _strcmp(char *s1, char *s2)
{

}

char *_memset(char *s, char b, unsigned int n)
{

}

char *_memcpy(char *dest, char *src, unsigned int n)
{

}

char *_strchr(char *s, char c)
{

}

unsigned int _strspn(char *s, char *accept)
{

}

char *_strpbrk(char *s, char *accept)
{

}

char *_strstr(char *haystack, char *needle)
{

}


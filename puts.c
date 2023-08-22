#include "main.h"
/**
 * putsss - prints a string
 * @c: string to print
 * Return: number of bytes
 */
int putsss(char *c)
{
	int l = 0;

	if (c)
	{
		for (l = 0; c[l] != '\0'; l++)
		{
			_putchar(c[l]);
		}
	}
	return (l);
}

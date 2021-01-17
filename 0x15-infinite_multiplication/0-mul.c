#include "holberton.h"

/**
 * _calloc - function allocates memory for an array
 * @nmemb: number of elelments of data
 * @size: size of data
 *
 * Description: function allocates memory for an array
 *
 * Return: value
 */
void *_calloc(long int nmemb, long int size)
{
	char *arr;
	long int a;

	arr = malloc(nmemb * size);

	if (arr == NULL)
		exit(98);
	for (a = 0; a < nmemb * size; a++)
		arr[a] = 0;
	return (arr);
}

/**
 * _printstring - function prints a string
 * @str: string
 * Description: uses putchar to print a string
 *
 * Return: value
 */
void _printstring(char *str)
{
	while (*str != '\0')
		_putchar(*str++);
		/*_putchar("/n");*/
}

/**
 * _isDigit - function checks if num or not
 * @s: string
 *
 * Description: function checks for numbers in string
 *
 * Return: 0 for sucess
 */
unsigned int _isDigit(char *s)
{
	unsigned int numbot = 0;


	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		numbot++;
		s++;
	}
	return (numbot);
}

/**
 * main - function multiplies
 * @argcount: number of arguments
 * @argv: arguments
 *
 * Description: function multiplies two ints
 *
 * Return: value
 */

int main(int argcount,  char *argv[])
{
	long int l_argv1, l_argv2, lsum_argv;
	long int x, y;
	char *argprod;

	/* NULL cases */
	if (argcount != 3)
		_printstring("Error\n"), exit(98);
	/**
	*if (argv[1] == '0' || argv[2] == '0')
	*{
	*	_printstring("0\n");
	*	return (0);
	*}
	*/
	l_argv1 = _isDigit(argv[1]);
	l_argv2 = _isDigit(argv[2]);
	if (l_argv1 == 0 || l_argv2 == 0)
		_printstring("Error\n"), exit(98);

	lsum_argv = l_argv1 + l_argv2;
	argprod = _calloc(lsum_argv + 1, sizeof(char));
	/* multiplying the numbers in the string*/
	for (x = lsum_argv - 1, l_argv1--; l_argv1 >= 0; l_argv1--, x += l_argv2 - 1)
		for (y = l_argv2 - 1; y >= 0; y--, x--)
		{
			/* filling the allocated space */
			argprod[x] = (argv[1][l_argv1] * argv[2][y] % 10) + argprod[x];
			argprod[x - 1] = (argv[1][l_argv1] * argv[2][y] / 10) + argprod[x - 1];
			/* what if the result is larger than nine we must regroup */
			if (argprod[x] > '9')
			{
				argprod[x] = argprod[x] - 10;
				argprod[x - 1]++; 
			}
		}
	_printstring(argprod);
	_putchar('\n');
	free(argprod);

	return (0);
}

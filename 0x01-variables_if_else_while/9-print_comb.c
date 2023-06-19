#include <stdio.h>
/**
* main -  persistence and perspiration make an unbeatable
* Return: 0
*/
int main(void)
{
int d;
for (d = 0; d <= 9; d++)
putchar(d);
if (d != '9')
putchar(',');
putchar(' ');
putchar('\n');
return (0);
}

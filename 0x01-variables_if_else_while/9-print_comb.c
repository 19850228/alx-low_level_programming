#include <stdio.h>
/**
* main - Write a program that prints all possible
*
* Return: 0 
*/
int main(void)
{
int digit = 0;
while (digit <= 9)
{
putchar(digit + 48);
if (digit != 9)
{
putchar(',');
putchar(' ');
}
++digit;
}
putchar('\n');
return (0);
}

#include <stdio.h>
/**
* main - You can only use putchar twice in your code
* Return: 0
*/
int main(void)
{
char low, e, q;
e = 'e';
q = 'q';
for (low = 'a'; low <= 'z'; low++)
if (low != e && low != q)
putchar(low);
putchar('\n');
return (0);
}

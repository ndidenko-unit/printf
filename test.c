#include <stdio.h>
#include <wchar.h>
#include "ft_printf.h"

int  ft_2to10(char *bin)
{
	int step;
	int sum;
	int bit;

	if (!bin)
		return(0);
	step = 0;
	sum = 0;
	bit = 1;
	while (*bin++)
		step++;
	bin -= 2;
	while (step != 0)
	{
		if (*bin == '1')
			sum += bit;
		bit *= 2;
		bin--;
		step--;
	}
	return(sum);
}

int main()
{

	printf("%d\n", ft_2to10("0000001010"));


 
	return (0);
}
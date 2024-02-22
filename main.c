#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int val1;
	int val2;
	val1 = ft_printf("|%.X, %.0X|", 0, 0);
	printf("\n");
	val2 = printf("|%.X, %.0X|", 0, 0);
	printf("\n");
	printf("val1: %d || val2: %d ", val1, val2);
}
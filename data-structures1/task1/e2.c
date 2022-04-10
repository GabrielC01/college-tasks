#include <stdio.h>
void main()
{
	short integers[6], i;
	short lenIntegers = sizeof(integers) / sizeof(integers[0]);

	printf("Entre com seis inteiros:\n");
	for (i = 0; i < lenIntegers; i++)
		scanf("%hd", &integers[i]);

	for (i = 0; i < lenIntegers; i++)
		printf("%hd ", integers[i]);
	printf("\n");
}

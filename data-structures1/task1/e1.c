#include <stdio.h>
void main()
{
	short A[] = {1, 0, 5, -2, -5, 7}, i;
	short sum = A[0] + A[1] + A[5];
	printf("Soma A[0], A[1] e A[5]: %hd.\n", sum);
	A[4] = 100;
	for (i = 0; i < sizeof(A) / sizeof(A[0]); i++)
		printf("%hd\n", A[i]);
}

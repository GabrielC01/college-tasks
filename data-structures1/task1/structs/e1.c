#include <stdio.h>
#include <stdlib.h>

typedef struct students {
	char name[32];
	unsigned short regNumber;
	float grades[2];
	float avg;
} Students;

void main()
{
	Students * bcc;
	unsigned short numStudents;

	// Read in number of students to be registered
	printf("Quantos alunos deseja cadastrar?\n");
	scanf("%hu", &numStudents);

	// Allocate the appropriate space in memory for their data
	bcc = calloc(sizeof(bcc), numStudents * sizeof(Students));
	
	// Register their data
	for (unsigned short i = 0; i < numStudents; i++)
	{
		printf("*ALUNO %hu*\n", i+1);
		printf("•Nome:\n");
		scanf("%s", &bcc[i].name);
		printf("•Matricula:\n");
		scanf("%hu", &bcc[i].regNumber);
		printf("•Notas:\n");
		scanf("%f %f", &bcc[i].grades[0], &bcc[i].grades[1]);
		bcc[i].avg = (bcc[i].grades[0] + bcc[i].grades[1]) / 2;
	}

	// Print the name, registration number and average grade of each student
	for (unsigned short i = 0; i < numStudents; i++)
	{
		printf("(Matricula: %hu, Nome: \"%s\", Media: %.1f)\n", bcc[i].regNumber, bcc[i].name, bcc[i].avg);
	}

	free(bcc);
}

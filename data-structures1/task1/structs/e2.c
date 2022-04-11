#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct person {
	char name[32];
	char cpf[11];
	char sex;
	float height;
	float weight;
} Person;

short queryPerson(char *, Person *);

void main()
{
	Person * people;
	unsigned short numPeople;
	
	// Read in number of people to be registered
	printf("Quantos alunos deseja cadastrar?\n");
	scanf("%hu", &numPeople);

	// Allocate the appropriate space in memory for their data
	people = calloc(sizeof(Person), numPeople * sizeof(Person));
	
	// Register their data
	printf("Entre com os dados separados por espaco.\n");
	printf("*(<nome> <CPF> <sexo> <altura> <peso>)*.\n");
	for (unsigned short i = 0; i < numPeople; i++)
	{
		printf("%huª PESSOA:\n", i+1);
		scanf("%s %s %c %f %f", &people[i].name, &people[i].cpf,
				&people[i].sex, &people[i].height, &people[i].weight);
	}	


	// Person query
	char cpf[11];
	do {
		// Get CPF
		printf("Entre com o CPF para consulta, ou 0 para sair.\n");
		scanf("%s", &cpf);

		// Query the individual
		short personIndex = queryPerson(cpf, people);
		printf("%hd\n", personIndex);
		if (personIndex != -1)
		{
			// Compute BMI
			float bmi = people[personIndex].weight / pow(people[personIndex].height, 2);
			// Print name and BMI
			printf("Pessoa encontrada:\n");
			printf("•Nome: %s •IMC: %.2f\n\n", people[personIndex].name, bmi);
		} else {
			printf("Pessoa nao encontrada.\n\n");
		}
		
	} while (cpf[0] != '0');

	// Free dynamically allocated memory
	free(people);
}

// Search for a person in the people array
short queryPerson(char * cpf, Person * people)
{
	for (unsigned short i = 0; i < sizeof(Person) / sizeof(people[0]); i++)
		if (strcmp(cpf, people[i].cpf) == 0)
			return i;
	return -1;
}

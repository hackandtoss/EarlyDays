#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "./cat filename\n");
		return 1;
	}
	
	FILE *infptr = fopen(argv[1], "r");

	if (infptr == NULL)
	{
		fprintf(stderr, "No such file exists\n");
		return 2;
	}

	char fbit;
	while((fbit = fgetc(infptr)) != EOF)
		printf("%c", fbit);

	fclose(infptr);
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void error(void);

void calc(double w, double x, double y, double z);

int main (int argc, char *argv[])
{
	if (argc != 9)
	{
		error();
	}

	double vSorce = 0.0;
	double vMax = 0.0;
	double vMin = 0.0;
	double amps = 0.0;
	size_t count = 0;
	for (int i = 0; i < argc - 1; i++)
	{
		char *temp = argv[i + 1];
		if (strcmp("-s", argv[i]) == 0)
		{
			if (!isdigit(temp[0]) && temp[0] != '.')
				error();
			vSorce = atof(argv[i + 1]);
			count ^= 1;
		}
		if (strcmp("-h", argv[i]) == 0)
		{
			if (!isdigit(temp[0]) && temp[0] != '.')
				error();
			vMax = atof(argv[i + 1]);
			count ^= 2;
		}
		if (strcmp("-l", argv[i]) == 0)
		{
			if (!isdigit(temp[0]) && temp[0] != '.')
				error();
			vMin = atof(argv[i + 1]);
			count ^= 4;
		}
		if (strcmp("-a", argv[i]) == 0)
		{
			if (!isdigit(temp[0]) && temp[0] != '.')
				error();
			amps = atof(argv[i + 1]);
			count ^= 8;
		}
	}

	if (count != 15)
	{
		error();
	}

	calc(vSorce, vMax, vMin, amps);
	return 0;
}

void error(void)
{
	printf("Useage: ./led-calc [options]\n");
	printf("Example: ./led-calc -s 5 -h 3.4 -l 3 -a 0.02\n");
	printf("All options are required:\n");
	printf("-s\tSorce voltage\n");
	printf("-h\tMax voltage the led can handle\n");
	printf("-l\tMinimum voltage required to power led\n");
	printf("-a\tCurrent required by the led in amps\n");
	exit(66);
}

void calc(double w, double x, double y, double z)
{
	double max = (w - y) / z;
	double min = (w - x) / z;
	double avg = (max + min) / 2.0;
	printf("Max ohm resistor is: %.2f ohms\n", max);
	printf("Minimum ohm resistor is: %.2f ohms\n", min);
	printf("Recommended ohm resistor is: %.2f ohms\n", avg);
}

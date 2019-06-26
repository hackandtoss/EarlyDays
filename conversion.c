#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Gives error message
void error(void);

//Converts Temprature 1 = F2C and 2 = C2F 
void convert(double d, char *s);

//Rounds a float to the nearest n places after the decimal
double rounding(double f, int i);

int main (int argc, char *argv[])

//2 Commandline arguments after the program name are required.
{
    if (argc != 3)
    {
        error();
    }

//Error Checking to make sure only -f or -c can be keyed as inputs  
    if (strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-c") != 0)
    {
        error();
    }
    
//Temprature converted
    convert(atof(argv[2]), argv[1]);
    return 0;
}

void error(void)
{
    printf("Usage: ./conversion [-f/c] [temprature]\n");
    printf("-f\t Convert from degrees Fahrenheit to Celsius.\n");
    printf("-c\t Convert for degrees Celsius to Fahrenheit.\n");
    printf("Example: ./conversion -f 32.0\n");
    exit(1);
}

//Converts temprature from -f f2c or -c c2f
void convert(double d, char *s)
{
    if (strcmp(s, "-f") == 0)
    {
        double c = 5.00 / 9.00 * (d - 32.00);
        double t = rounding(c, 2);
        printf("%.2f C\n", t);
    }
    else
    {
        double f = 9.00 / 5.00 * d  + 32.00;
        double t = rounding(f, 2);
        printf("%.2f F\n", t);
    }
}

//Takes a float you wish to round and how many decimal places you would like it to round to.
double rounding(double f, int i)
{
    double n;
    if (i <= 0)
    {
        int r = round(f);
        n = (double) r;
    }
//Don't want to round to more than 6 places after the 0    
    else if (i > 6)
    {
        int r = round(f * 1000000);
        n = (double) r / 1000000.0;
    }
    else
    {
        double d = pow(10.0, (double) i);
        int r = round(f * d);
        n = (double) r / (double) d;
    }
    return n;
}

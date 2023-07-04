#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ERROR 0
double result, num;
int conv;
char ch=0;
int error;
int parenthesis;
void runUnitConverter();
void runCalculator();
int calc(void);
int main(void)
{

    char mstart;
    printf("\tWelcome to Our Calculator & Unit converter System!\n\n\a");
    printf("Press \"C\" to use Calculator.");
    printf("\t\t\tPress \"U\" to use Unit Converter.\n\n\n");
    tryAgain:
    scanf("%c",&mstart);
    if(mstart=='C' || mstart=='c'){
        system("cls");
        runCalculator();
    }else if(mstart=='U' || mstart=='u'){
        system("cls");
        runUnitConverter();
    }else{
        printf("\tFailed! Try again. \n");
        goto tryAgain;
    }
    return 0;

}

void runCalculator(void){
    while(ch!=EOF){  //END OF FILE
		error=0;  //error flag deya hoyese
		parenthesis=0; //initialize the parenthesis counter
		printf("Enter your input : ");
		printf("\nThe result is: %d\n",calc());
	}
}


int GetFactor(void);

//function that calculates simple arithmetic expressions
int calc(void)
{
	int num;
	char operation;
	int result=0;


	if(error) return ERROR; //error case handling kora hoyese

	result=GetFactor(); //first number-factor neya hoyese
	while(ch != '\n' && ch !=')') //loop while
	{
		operation=ch; //operation symbol neya hoyese
		num=GetFactor(); //number-factor abar neya hocche
		if(operation=='+') result+=num; //result er sathe factor add kora hoyese
		else if(operation=='-')result-=num; //result thekefactor subtract kora hoyese
	}

	if(ch==')')
	{
		ch=getchar(); //if we've just exited a parenthesized expression get the next character to know what to do next
		parenthesis--;
	}

	if(ch=='\n' && parenthesis!=0)
	{
		printf("Error: Wrong parenthesis allocation.Try Again;\n");
		error=1;
		return ERROR;
	}

	if(error)
		return ERROR;
	else
		return result;
}

int GetNum(void);
//Funciton that returns the factor that is estimated (either a real factor , a number or even a parenthetic expression)
int GetFactor(void)
{
	int factor,num;
	factor=num=GetNum();

	if(error) return 0; //error case handling

	while(ch=='*')//while we keep getting '*' as an operation character we multiply the result with the next factor
	{
		num=GetNum();
		factor*=num;
	}

	while(ch=='/')//while we keep getting '/' as an operation character we devide the result with the next factor
	{
		num=GetNum();
		factor/=num;
	}

	return factor;
}

int GetNum(void)
{
	int num=0;
	int blank=0;
	//simple loop to build the number from a
	while((((ch=getchar())!=EOF && ch!='\n' && ch>='0' && ch<='9')) || ch==' ' || ch=='\t')
	{
		if(ch==' ' || ch=='\t')
		{
			if(num !=0 && blank==0)
				blank = 1;
			else
				continue;
		}
		else
		{
			//if the number
			num=10*num + (ch - '0');
			if(blank==1) blank=2;
		}

		if(blank == 2)
		{
			printf("Error: No blanks between spaces! Try Again\n");
			int error=1;
			return ERROR;
		}
	}

	if(ch!='+' && ch!='-' && ch!='*' && ch!='(' && ch!=')' && ch!='/' && !error && ch!='\n' && ch!=EOF)
	{
		error=1;
		printf("Error: Unknown character read. Try Again!\n");
		return ERROR;
	}
	if(ch=='(' && num==0)
	{
		ch=0;
		parenthesis++;/*printf("Exiting Parenthesis\n");*/
		num=calc();
	}
	return num;
}
void runUnitConverter(){
    do
    {
        printf("---Unit converter---\n");
        printf("Enter conversion type, or <0> to quit:\n");
        printf("<1>inch-centimetre \t<2>centimetre-inch\n");
        printf("<3>foot-metre \t<4>metre-foot\n");
        printf("<5>mile-kilometre \t<6>kilometre-mile\n");
        printf("<7>pound-kilogram \t<8>kilogram-pound \n");
        printf("<9>ounce-gram \t<10>gram-ounce\n");
        printf("<11>acre-metre square <12>metre square-acre\n");
        printf("<13>pint-litre \t<14>litre-pint\n");
        printf("<15>fahrenheit-celsius \t<16>celsius-fahrenheit\n");
        scanf("%d", &conv);
        if (conv <= 0 || conv > 16)
            return 0;
        printf("Enter unit measure:\n");
        scanf("%lf", &num);
        if (conv == 1)
            result = num * 2.54; // to cent
        if (conv == 2)
            result = num * .393; // to inch
        if (conv == 3)
            result = num * .348; // to met
        if (conv == 4)
            result = num * 3.28; // to foot
        if (conv == 5)
            result = num * 1.6093; // to mile
        if (conv == 6)
            result = num * .625; // to km
        if (conv == 7)
            result = num * .4536; // to pound
        if (conv == 8)
            result = num * 2.2075; // to kgram
        if (conv == 9)
            result = num * 28.3495; // to oz
        if (conv == 10)
            result = num / 28.3495; // to gram
        if (conv == 11)
            result = num * 4046.8; // to acre
        if (conv == 12)
            result = num / 4046.8; // to m2
        if (conv == 13)
            result = num * .568; // to litre
        if (conv == 14)
            result = num / .568; // to pint
        if (conv == 15)
            result = (num - 32) * 5 / 9; // to cel
        if (conv == 16)
            result = (num * 9 / 5) + 32; // to fah
        printf("Result =%lf \n",result);
        printf("Press any key to continue...\n\n");
        getch();
        system("cls");
    } while (conv != 0);
}




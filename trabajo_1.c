#include <stdio.h>
#include <stdlib.h>
#define MAXFILAS 20
#define MAXCOLUMNAS 31

int main(void)
{
	char control;
	int x=0,y=0;
	int i,j;
	char mapa[MAXFILAS][MAXCOLUMNAS]={
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"X           XXXXX           X",
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X                           X",
	"X XXX XX XXXXXXXXXXX XX XXX X",
	"X     XX     XXX     XX     X",
	"X XXX XXXXXX XXX XXXXXX XXX X",
	"X     XX             XX     X",
	"X     XX XXXXXXXXXXX XX     X",
	"X     XX XXXXXXXXXXX XX     X",
	"X     XX             XX     X",
	"X XXX XXXXXX XXX XXXXXX XXX X",
	"X     XX     XXX     XX     X",
	"X XXX XX XXXXXXXXXXX XX XXX X",
	"X                           X",	
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X           XXXXX           X",
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	};
	
	for (i=0;i<MAXFILAS;i++)
	{
		for (j=0;j<MAXCOLUMNAS;j++)
		{
			if (mapa[i][j]=='X')
			printf("X");
			else
			printf(" ");
		}
		printf("\n");
	}
	
	printf("\n");
	printf("introduce:\n");
	printf("      ^\n");
	printf("      |\n");
	printf("      W\n");
	printf(" <--A + D-->         x(salir)\n");
	printf("      S\n");
	printf("      |\n");
	printf("      v\n");
	scanf("%c",&control);
	
	while(control!='x')
	{
	
	if (control=='a')
	x--;
	else
	{
		if (control=='d')
		x++;
		else
		{
			if (control=='w')
			y--;
			else
			{
				if (control=='s')
				y++;
			}
		}
	}
	
	for (i=0;i<MAXFILAS;i++)
	{
		for (j=0;j<MAXCOLUMNAS;j++)
		{
			if (i==y && j==x)
			{
				printf("O");
			}
			else
			{
				if (mapa[i][j]=='X')
				printf("X");
				else
				printf(" ");
			}
		}
		printf("\n");
	}
	
	printf("\n");
	printf("introduce:\n");
	printf("      ^\n");
	printf("      |\n");
	printf("      W\n");
	printf(" <--A + D-->         x(salir)\n");
	printf("      S\n");
	printf("      |\n");
	printf("      v\n");
	scanf("%c",&control);
	
	system("cls");
	
	}
	return 0;
}

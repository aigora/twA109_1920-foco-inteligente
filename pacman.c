#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAXFILAS 20
#define MAXCOLUMNAS 31


int main(void)
{
	char control;
	int x=1,y=1,yy,xx,c=0;
	int i,j;
	char mapa[MAXFILAS][MAXCOLUMNAS]={
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"X           XXXXX           X",
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X                           X",
	"XXXXX XX XXXXXXXXXXX XX XXX X",
	"X     XX     XXX     XX     X",
	"X XXX XXXXXX XXX XXXXXX XXX X",
	"X     XX             XX     X",
	"      XX XXXXXXXXXXX XX      ",
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
			if (i==y&&j==x)
				printf("O");
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
				{
					while(mapa[y][x]==' ')
					{
						system("cls");
						for (i=0;i<MAXFILAS;i++)
						{
							for (j=0;j<MAXCOLUMNAS;j++)
							{
								if (i==y && j==x)
								printf("O");
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
						printf("\n");
						sleep(1);
						y++;
					}
				}
			}
		}
	}
	
	if (mapa[y][x]=='X')
	{
		if (control=='a')
		x++;
		else
		{
			if (control=='d')
			x--;
			else
			{
				if (control=='w')
				y++;
				else
				{
					if (control=='s')
					y--;
				}
			}
		}
	}
	system("cls");
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
	
	
	
	}
	return 0;
}

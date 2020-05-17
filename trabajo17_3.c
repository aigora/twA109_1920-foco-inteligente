#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAXFILAS 20
#define MAXCOLUMNAS 29


int main(void)
{
	char control;
	int x=25,y=9,yy,xx,puntos=0;
	int i,j;
	int estado[MAXFILAS][MAXCOLUMNAS];
	char mapa[MAXFILAS][MAXCOLUMNAS]={
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"X     X     XXXXX           X",
	"X XXX XXXXX XXXXX XXXXX XXX X",
	"X XXXXXXXXX XXXXX XXXXX XXX X",
	"X     X                     X",
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
		for(j=0;j<MAXCOLUMNAS;j++)
		{
			estado[i][j]=1;
		}
	}
	
	estado[9][25]=0;
	estado[9][23]=2;
	
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
				{
					if(estado[i][j]==1)
					printf(".");
					else
					printf("+");
				}
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
	{
		x--;
		while(mapa[y][x]==' ')
		{
			system("cls");
			for (i=0;i<MAXFILAS;i++)
			{
				for (j=0;j<MAXCOLUMNAS;j++)
				{				
					if (i==y && j==x)
					{
						printf("O");
						if (estado[i][j]==1)
						{
							puntos++;
						}
						if (estado[i][j]==2)
						{
							puntos=puntos+100;
						}
						estado[i][j]=0;
					}
					else
					{
						if (mapa[i][j]=='X')
						printf("X");
						else
						{
							if (estado[i][j]==0)
							printf(" ");
							if (estado[i][j]==1)
							printf(".");
							if (estado[i][j]==2)
							printf("+");
						}
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
			if(x==0&&y==9)
			{
				x=29;
			}
			sleep(1);
			x--;
		}
	}
	else
	{
		if (control=='d')
		{
			x++;
			while(mapa[y][x]==' ')
			{
				system("cls");
				for (i=0;i<MAXFILAS;i++)
				{
					for (j=0;j<MAXCOLUMNAS;j++)
					{
						if (i==y && j==x)
						{
							printf("O");
							if (estado[i][j]==1)
							{
								puntos++;
							}
							if (estado[i][j]==2)
							{
								puntos=puntos+100;
							}
							estado[i][j]=0;
						}
						else
						{
							if (mapa[i][j]=='X')
							printf("X");
							else
							{
								if (estado[i][j]==0)
								printf(" ");
								if (estado[i][j]==1)
								printf(".");
								if (estado[i][j]==2)
								printf("+");
							}
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
				if(x==28&&y==9)
				{
					x=-1;
				}
				sleep(1);
				x++;
			}
		}
		else
		{
			if (control=='w')
			{
				y--;
				while(mapa[y][x]==' ')
				{
					system("cls");
					for (i=0;i<MAXFILAS;i++)
					{
						for (j=0;j<MAXCOLUMNAS;j++)
						{
							if (i==y && j==x)
							{
								printf("O");
								if (estado[i][j]==1)
								{
									puntos++;
								}
								if (estado[i][j]==2)
								{
									puntos=puntos+100;
								}
								estado[i][j]=0;
							}
							else
							{
								if (mapa[i][j]=='X')
								printf("X");
								else
								{
									if (estado[i][j]==0)
									printf(" ");
									if (estado[i][j]==1)
									printf(".");
									if (estado[i][j]==2)
									printf("+");
								}
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
					sleep(1);
					y--;
				}
			}
			else
			{
				if (control=='s')
				{
					y++;
					while(mapa[y][x]==' ')
					{
						system("cls");
						for (i=0;i<MAXFILAS;i++)
						{
							for (j=0;j<MAXCOLUMNAS;j++)
							{
								if (i==y && j==x)
								{
								printf("O");
								if (estado[i][j]==1)
								{
									puntos++;
								}
								if (estado[i][j]==2)
								{
									puntos=puntos+100;
								}
								estado[i][j]=0;
								}
								else
								{
									if (mapa[i][j]=='X')
									printf("X");
									else
									{
										if (estado[i][j]==0)
										printf(" ");
										if (estado[i][j]==1)
										printf(".");
										if (estado[i][j]==2)
										printf("+");
									}
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
	scanf("%c",&control);
	
	}
	
	printf("\nTu puntuacion ha sido de: %d puntos\n",puntos);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAXFILAS 20
#define MAXCOLUMNAS 29
#define L 100

int main(void)
{
	FILE *archivo1;
	FILE *archivo2;
	char control,basura[L];
	int control1,control2,control3,control4,control5,control6,estado1=0,esquina=0,muro=0,fantasma=0,final=0,opcion,opcion_aux,cantidad=0,puntos1[L],puntos2[L],auxiliar;
	int x=1,y=1,yy,xx,puntos=0;
	int x1=14,y1=11,x2=23,y2=4,x3=23,y3=15,x4=5,y4=15,x5=14,y5=8,x6=5,y6=4;
	int i,j,pp;
	int estado[MAXFILAS][MAXCOLUMNAS];
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
	"  XXX XX XXXXX XXXXX XX XXX  ",
	"X XXX XX XXXXX XXXXX XX XXX X",
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
	
	estado[1][1]=0;
	
	estado[9][23]=2;
	estado[4][23]=2;
	estado[15][23]=2;
	estado[4][5]=2;
	estado[15][5]=2;
	estado[1][17]=2;
	estado[1][11]=2;
	estado[18][17]=2;
	estado[18][11]=2;
	
	
	printf("***PAC-MAN***\n\n");
	printf("1. Jugar\n");
	printf("2. Instrucciones\n");
	printf("3. Ultimas partidas\n");
	printf("4. Top partidas\n");
	printf("5. Creditos\n");
	printf("6. Salir\n");
	
	scanf("%d",&opcion_aux);
	system("cls");
	
	while (opcion_aux!=6)
	{
		switch (opcion_aux)
		{
			case 1:
			
				for (i=0;i<MAXFILAS;i++)
				{
					for (j=0;j<MAXCOLUMNAS;j++)
					{
						if (i==y&&j==x)
							printf("O");
						else
						{
							if ((i==y1&&j==x1) || (i==y2&&j==x2) || (i==y3&&j==x3) || (i==y4&&j==x4) || (i==y5&&j==x5) || (i==y6&&j==x6))
							printf("8");
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
					}
					printf("\n");
				}
				
				printf("\n");
				printf("introduce:\n");
				printf("      ^\n");
				printf("      |\n");
				printf("      W\n");
				printf(" <--A + D-->      X(rendirse)\n");
				printf("      S\n");
				printf("      |\n");
				printf("      v\n");
				scanf("%c",&control);
				
				
				while(control!='X' && final==0 && puntos<282)
				{
				fantasma=0;
				muro=0;
				esquina=0;
				if (control=='A')	
				{
					x--;
					if (mapa[y][x]=='X')
					{
						x++;
						muro=1;
					}
						
					while(muro==0 && esquina==0 && fantasma==0)
					{
						fantasma=0;
						muro=0;
						esquina=0;
						if ((y==y1&&x==x1) || (y==y2&&x==x2) || (y==y3&&x==x3) || (y==y4&&x==x4) || (y==y5&&x==x5) || (y==y6&&x==x6) || (y==y1&&x+1==x1) || (y==y2&&x+1==x2) || (y==y3&&x+1==x3) || (y==y4&&x+1==x4) || (y==y5&&x+1==x5) || (y==y6&&x+1==x6))
						{
							x++;
							fantasma=1;
							final=1;
						}
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
										puntos=puntos+10;
									}
									estado[i][j]=0;
								}
								else
								{
									if ((i==y1&&j==x1) || (i==y2&&j==x2) || (i==y3&&j==x3) || (i==y4&&j==x4) || (i==y5&&j==x5) || (i==y6&&j==x6))
									printf("8");
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
							}
							printf("\n");							
						}
						printf("\n");
						printf("introduce:\n");
						printf("      ^\n");
						printf("      |\n");
						printf("      W\n");
						printf(" <--A + D-->      X(rendirse)\n");
						printf("      S\n");
						printf("      |\n");
						printf("      v\n");
						if(x==0&&y==9)
						{
							x=29;
						}
						sleep(1);
						
						x--;
						
						if (mapa[y][x]=='X')
						{
							x++;
							muro=1;
						}
						if (mapa[y-1][x+1]==' '|| mapa[y+1][x+1]==' ')
						{
							esquina=1;
							x++;
						}
						
						control1=rand()%4;
						switch (control1)
						{
							case 1:
								x1++;
								if (mapa[y1][x1]=='X')
								{
									x1--;
								}
								break;
							case 2:
								x1--;
								if (mapa[y1][x1]=='X')
								{
									x1++;
								}
								break;
							case 3:
								y1++;
								if (mapa[y1][x1]=='X')
								{
									y1--;
								}
								break;
							case 0:
								y1--;
								if (mapa[y1][x1]=='X')
								{
									y1++;
								}
								break;
							default:
								estado1=1;
								break;
						}
						
						control2=rand()%4;
						switch (control2)
						{
							case 1:
								x2++;
								if (mapa[y2][x2]=='X')
								{
									x2--;
								}
								break;
							case 2:
								x2--;
								if (mapa[y2][x2]=='X')
								{
									x2++;
								}
								break;
							case 3:
								y2++;
								if (mapa[y2][x2]=='X')
								{
									y2--;
								}
								break;
							case 0:
								y2--;
								if (mapa[y2][x2]=='X')
								{
									y2++;
								}
								break;
							default:
								estado1=1;
								break;
						}
						control3=rand()%4;
						switch (control3)
						{
							case 1:
								x3++;
								if (mapa[y3][x3]=='X')
								{
									x3--;
								}
								break;
							case 2:
								x3--;
								if (mapa[y3][x3]=='X')
								{
									x3++;
								}
								break;
							case 3:
								y3++;
								if (mapa[y3][x3]=='X')
								{
									y3--;
								}
								break;
							case 0:
								y3--;
								if (mapa[y3][x3]=='X')
								{
									y3++;
								}
								break;
							default:
								estado1=1;
								break;
						}
						control4=rand()%4;
						switch (control4)
						{
							case 1:
								x4++;
								if (mapa[y4][x4]=='X')
								{
									x4--;
								}
								break;
							case 2:
								x4--;
								if (mapa[y4][x4]=='X')
								{
									x4++;
								}
								break;
							case 3:
								y4++;
								if (mapa[y4][x4]=='X')
								{
									y4--;
								}
								break;
							case 0:
								y4--;
								if (mapa[y4][x4]=='X')
								{
									y4++;
								}
								break;
							default:
								estado1=1;
								break;
						}
						control5=rand()%4;
						switch (control5)
						{
							case 1:
								x5++;
								if (mapa[y5][x5]=='X')
								{
									x5--;
								}
								break;
							case 2:
								x5--;
								if (mapa[y5][x5]=='X')
								{
									x5++;
								}
								break;
							case 3:
								y5++;
								if (mapa[y5][x5]=='X')
								{
									y5--;
								}
								break;
							case 0:
								y5--;
								if (mapa[y5][x5]=='X')
								{
									y5++;
								}
								break;
							default:
								estado1=1;
								break;
						}
						control6=rand()%4;
						switch (control6)
						{
							case 1:
								x6++;
								if (mapa[y6][x6]=='X')
								{
									x6--;
								}
								break;
							case 2:
								x6--;
								if (mapa[y6][x6]=='X')
								{
									x6++;
								}
								break;
							case 3:
								y6++;
								if (mapa[y6][x6]=='X')
								{
									y6--;
								}
								break;
							case 0:
								y6--;
								if (mapa[y6][x6]=='X')
								{
									y6++;
								}
								break;
							default:
								estado1=1;
								break;
						}
					}
				}
				else
				{
					if (control=='D')
					{
						x++;
						if (mapa[y][x]=='X')
						{
							x--;
							muro=1;
						}
						while(muro==0 && esquina==0 && fantasma==0)
						{
							fantasma=0;
							muro=0;
							esquina=0;
							if ((y==y1&&x==x1) || (y==y2&&x==x2) || (y==y3&&x==x3) || (y==y4&&x==x4) || (y==y5&&x==x5) || (y==y6&&x==x6) || (y==y1&&x-1==x1) || (y==y2&&x-1==x2) || (y==y3&&x-1==x3) || (y==y4&&x-1==x4) || (y==y5&&x-1==x5) || (y==y6&&x-1==x6))
							{
								x--;
								fantasma=1;
								final=1;
								
							}
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
											puntos=puntos+10;
										}
										estado[i][j]=0;
									}
									else
									{
										if ((i==y1&&j==x1) || (i==y2&&j==x2) || (i==y3&&j==x3) || (i==y4&&j==x4) || (i==y5&&j==x5) || (i==y6&&j==x6))
										printf("8");
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
								}
								printf("\n");							
							}
							printf("\n");
							printf("introduce:\n");
							printf("      ^\n");
							printf("      |\n");
							printf("      W\n");
							printf(" <--A + D-->      X(rendirse)\n");
							printf("      S\n");
							printf("      |\n");
							printf("      v\n");
							if(x==28&&y==9)
							{
								x=-1;
							}
							sleep(1);
							
							x++;
							
							if (mapa[y][x]=='X')
							{
								x--;
								muro=1;
							}
							if (mapa[y-1][x-1]==' '|| mapa[y+1][x-1]==' ')
							{
								esquina=1;
								x--;
							}
							
							control1=rand()%4;
							switch (control1)
							{
								case 1:
									x1++;
									if (mapa[y1][x1]=='X')
									{
										x1--;
									}
									break;
								case 2:
									x1--;
									if (mapa[y1][x1]=='X')
									{
										x1++;
									}
									break;
								case 3:
									y1++;
									if (mapa[y1][x1]=='X')
									{
										y1--;
									}
									break;
								case 0:
									y1--;
									if (mapa[y1][x1]=='X')
									{
										y1++;
									}
									break;
								default:
									estado1=1;
									break;
							}
							
							control2=rand()%4;
							switch (control2)
							{
								case 1:
									x2++;
									if (mapa[y2][x2]=='X')
									{
										x2--;
									}
									break;
								case 2:
									x2--;
									if (mapa[y2][x2]=='X')
									{
										x2++;
									}
									break;
								case 3:
									y2++;
									if (mapa[y2][x2]=='X')
									{
										y2--;
									}
									break;
								case 0:
									y2--;
									if (mapa[y2][x2]=='X')
									{
										y2++;
									}
									break;
								default:
									estado1=1;
									break;
							}
							control3=rand()%4;
							switch (control3)
							{
								case 1:
									x3++;
									if (mapa[y3][x3]=='X')
									{
										x3--;
									}
									break;
								case 2:
									x3--;
									if (mapa[y3][x3]=='X')
									{
										x3++;
									}
									break;
								case 3:
									y3++;
									if (mapa[y3][x3]=='X')
									{
										y3--;
									}
									break;
								case 0:
									y3--;
									if (mapa[y3][x3]=='X')
									{
										y3++;
									}
									break;
								default:
									estado1=1;
									break;
							}
							control4=rand()%4;
							switch (control4)
							{
								case 1:
									x4++;
									if (mapa[y4][x4]=='X')
									{
										x4--;
									}
									break;
								case 2:
									x4--;
									if (mapa[y4][x4]=='X')
									{
										x4++;
									}
									break;
								case 3:
									y4++;
									if (mapa[y4][x4]=='X')
									{
										y4--;
									}
									break;
								case 0:
									y4--;
									if (mapa[y4][x4]=='X')
									{
										y4++;
									}
									break;
								default:
									estado1=1;
									break;
							}
							control5=rand()%4;
							switch (control5)
							{
								case 1:
									x5++;
									if (mapa[y5][x5]=='X')
									{
										x5--;
									}
									break;
								case 2:
									x5--;
									if (mapa[y5][x5]=='X')
									{
										x5++;
									}
									break;
								case 3:
									y5++;
									if (mapa[y5][x5]=='X')
									{
										y5--;
									}
									break;
								case 0:
									y5--;
									if (mapa[y5][x5]=='X')
									{
										y5++;
									}
									break;
								default:
									estado1=1;
									break;
							}
							control6=rand()%4;
							switch (control6)
							{
								case 1:
									x6++;
									if (mapa[y6][x6]=='X')
									{
										x6--;
									}
									break;
								case 2:
									x6--;
									if (mapa[y6][x6]=='X')
									{
										x6++;
									}
									break;
								case 3:
									y6++;
									if (mapa[y6][x6]=='X')
									{
										y6--;
									}
									break;
								case 0:
									y6--;
									if (mapa[y6][x6]=='X')
									{
										y6++;
									}
									break;
								default:
									estado1=1;
									break;
							}
						}
					}
					else
					{
						if (control=='W')
						{
							y--;
							if (mapa[y][x]=='X')
							{
								y++;
								muro=1;
							}
							while(muro==0 && esquina==0 && fantasma==0)
							{
								fantasma=0;
								muro=0;
								esquina=0;
								if ((y==y1&&x==x1) || (y==y2&&x==x2) || (y==y3&&x==x3) || (y==y4&&x==x4) || (y==y5&&x==x5) || (y==y6&&x==x6) || (y+1==y1&&x==x1) || (y+1==y2&&x==x2) || (y+1==y3&&x==x3) || (y+1==y4&&x==x4) || (y+1==y5&&x==x5) || (y+1==y6&&x==x6))
								{
									y++;
									fantasma=1;
									final=1;
								}
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
												puntos=puntos+10;
											}
											estado[i][j]=0;
										}
										else
										{
											if ((i==y1&&j==x1) || (i==y2&&j==x2) || (i==y3&&j==x3) || (i==y4&&j==x4) || (i==y5&&j==x5) || (i==y6&&j==x6))
											printf("8");
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
									}
								printf("\n");							
								}
								printf("\n");
								printf("introduce:\n");
								printf("      ^\n");
								printf("      |\n");
								printf("      W\n");
								printf(" <--A + D-->      X(rendirse)\n");
								printf("      S\n");
								printf("      |\n");
								printf("      v\n");
								sleep(1);
								
								if ((y==y1&&x==x1) || (y==y2&&x==x2) || (y==y3&&x==x3) || (y==y4&&x==x4) || (y==y5&&x==x5) || (y==y6&&x==x6))
								{
									y++;
									fantasma=1;
									final=1;
									
								}
								
								y--;
								
								if (mapa[y][x]=='X')
								{
									y++;
									muro=1;
								}
								if (mapa[y+1][x+1]==' '|| mapa[y+1][x-1]==' ')
								{
									esquina=1;
									y++;
								}
								
								control1=rand()%4;
								switch (control1)
								{
									case 1:
										x1++;
										if (mapa[y1][x1]=='X')
										{
											x1--;
										}
										break;
									case 2:
										x1--;
										if (mapa[y1][x1]=='X')
										{
											x1++;
										}
										break;
									case 3:
										y1++;
										if (mapa[y1][x1]=='X')
										{
											y1--;
										}
										break;
									case 0:
										y1--;
										if (mapa[y1][x1]=='X')
										{
											y1++;
										}
										break;
									default:
										estado1=1;
										break;
								}
								
								control2=rand()%4;
								switch (control2)
								{
									case 1:
										x2++;
										if (mapa[y2][x2]=='X')
										{
											x2--;
										}
										break;
									case 2:
										x2--;
										if (mapa[y2][x2]=='X')
										{
											x2++;
										}
										break;
									case 3:
										y2++;
										if (mapa[y2][x2]=='X')
										{
											y2--;
										}
										break;
									case 0:
										y2--;
										if (mapa[y2][x2]=='X')
										{
											y2++;
										}
										break;
									default:
										estado1=1;
										break;
								}
								control3=rand()%4;
								switch (control3)
								{
									case 1:
										x3++;
										if (mapa[y3][x3]=='X')
										{
											x3--;
										}
										break;
									case 2:
										x3--;
										if (mapa[y3][x3]=='X')
										{
											x3++;
										}
										break;
									case 3:
										y3++;
										if (mapa[y3][x3]=='X')
										{
											y3--;
										}
										break;
									case 0:
										y3--;
										if (mapa[y3][x3]=='X')
										{
											y3++;
										}
										break;
									default:
										estado1=1;
										break;
								}
								control4=rand()%4;
								switch (control4)
								{
									case 1:
										x4++;
										if (mapa[y4][x4]=='X')
										{
											x4--;
										}
										break;
									case 2:
										x4--;
										if (mapa[y4][x4]=='X')
										{
											x4++;
										}
										break;
									case 3:
										y4++;
										if (mapa[y4][x4]=='X')
										{
											y4--;
										}
										break;
									case 0:
										y4--;
										if (mapa[y4][x4]=='X')
										{
											y4++;
										}
										break;
									default:
										estado1=1;
										break;
								}
								control5=rand()%4;
								switch (control5)
								{
									case 1:
										x5++;
										if (mapa[y5][x5]=='X')
										{
											x5--;
										}
										break;
									case 2:
										x5--;
										if (mapa[y5][x5]=='X')
										{
											x5++;
										}
										break;
									case 3:
										y5++;
										if (mapa[y5][x5]=='X')
										{
											y5--;
										}
										break;
									case 0:
										y5--;
										if (mapa[y5][x5]=='X')
										{
											y5++;
										}
										break;
									default:
										estado1=1;
										break;
								}
								control6=rand()%4;
								switch (control6)
								{
									case 1:
										x6++;
										if (mapa[y6][x6]=='X')
										{
											x6--;
										}
										break;
									case 2:
										x6--;
										if (mapa[y6][x6]=='X')
										{
											x6++;
										}
										break;
									case 3:
										y6++;
										if (mapa[y6][x6]=='X')
										{
											y6--;
										}
										break;
									case 0:
										y6--;
										if (mapa[y6][x6]=='X')
										{
											y6++;
										}
										break;
									default:
										estado1=1;
										break;
								}
							}
						}
						else
						{
							if (control=='S')
							{
								y++;
								if (mapa[y][x]=='X')
								{
									y--;
									muro=1;
								}
								while(muro==0 && esquina==0 && fantasma==0)
								{
									fantasma=0;
									muro=0;
									esquina=0;
									if ((y==y1&&x==x1) || (y==y2&&x==x2) || (y==y3&&x==x3) || (y==y4&&x==x4) || (y==y5&&x==x5) || (y==y6&&x==x6) || (y-1==y1&&x==x1) || (y-1==y2&&x==x2) || (y-1==y3&&x==x3) || (y-1==y4&&x==x4) || (y-1==y5&&x==x5) || (y-1==y6&&x==x6))
									{
										y++;
										fantasma=1;
										final=1;
									}
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
													puntos=puntos+10;
												}
												estado[i][j]=0;
											}
											else
											{
												if ((i==y1&&j==x1) || (i==y2&&j==x2) || (i==y3&&j==x3) || (i==y4&&j==x4) || (i==y5&&j==x5) || (i==y6&&j==x6))
												printf("8");
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
										}
										printf("\n");							
									}
									printf("\n");
									printf("introduce:\n");
									printf("      ^\n");
									printf("      |\n");
									printf("      W\n");
									printf(" <--A + D-->      X(rendirse)\n");
									printf("      S\n");
									printf("      |\n");
									printf("      v\n");
									sleep(1);
									
									if ((y==y1&&x==x1) || (y==y2&&x==x2) || (y==y3&&x==x3) || (y==y4&&x==x4) || (y==y5&&x==x5) || (y==y6&&x==x6))
									{
										y--;
										fantasma=1;
										final=1;
										
									}
									
									y++;
									
									if (mapa[y][x]=='X')
									{
										y--;
										muro=1;
									}
									if (mapa[y-1][x-1]==' '|| mapa[y-1][x+1]==' ')
									{
										esquina=1;
										y--;
									}
									
									control1=rand()%4;
									switch (control1)
									{
										case 1:
											x1++;
											if (mapa[y1][x1]=='X')
											{
												x1--;
											}
											break;
										case 2:
											x1--;
											if (mapa[y1][x1]=='X')
											{
												x1++;
											}
											break;
										case 3:
											y1++;
											if (mapa[y1][x1]=='X')
											{
												y1--;
											}
											break;
										case 0:
											y1--;
											if (mapa[y1][x1]=='X')
											{
												y1++;
											}
											break;
										default:
											estado1=1;
											break;
									}
									
									control2=rand()%4;
									switch (control2)
									{
										case 1:
											x2++;
											if (mapa[y2][x2]=='X')
											{
												x2--;
											}
											break;
										case 2:
											x2--;
											if (mapa[y2][x2]=='X')
											{
												x2++;
											}
											break;
										case 3:
											y2++;
											if (mapa[y2][x2]=='X')
											{
												y2--;
											}
											break;
										case 0:
											y2--;
											if (mapa[y2][x2]=='X')
											{
												y2++;
											}
											break;
										default:
											estado1=1;
											break;
									}
									control3=rand()%4;
									switch (control3)
									{
										case 1:
											x3++;
											if (mapa[y3][x3]=='X')
											{
												x3--;
											}
											break;
										case 2:
											x3--;
											if (mapa[y3][x3]=='X')
											{
												x3++;
											}
											break;
										case 3:
											y3++;
											if (mapa[y3][x3]=='X')
											{
												y3--;
											}
											break;
										case 0:
											y3--;
											if (mapa[y3][x3]=='X')
											{
												y3++;
											}
											break;
										default:
											estado1=1;
											break;
									}
									control4=rand()%4;
									switch (control4)
									{
										case 1:
											x4++;
											if (mapa[y4][x4]=='X')
											{
												x4--;
											}
											break;
										case 2:
											x4--;
											if (mapa[y4][x4]=='X')
											{
												x4++;
											}
											break;
										case 3:
											y4++;
											if (mapa[y4][x4]=='X')
											{
												y4--;
											}
											break;
										case 0:
											y4--;
											if (mapa[y4][x4]=='X')
											{
												y4++;
											}
											break;
										default:
											estado1=1;
											break;
									}
									control5=rand()%4;
									switch (control5)
									{
										case 1:
											x5++;
											if (mapa[y5][x5]=='X')
											{
												x5--;
											}
											break;
										case 2:
											x5--;
											if (mapa[y5][x5]=='X')
											{
												x5++;
											}
											break;
										case 3:
											y5++;
											if (mapa[y5][x5]=='X')
											{
												y5--;
											}
											break;
										case 0:
											y5--;
											if (mapa[y5][x5]=='X')
											{
												y5++;
											}
											break;
										default:
											estado1=1;
											break;
									}
									control6=rand()%4;
									switch (control6)
									{
										case 1:
											x6++;
											if (mapa[y6][x6]=='X')
											{
												x6--;
											}
											break;
										case 2:
											x6--;
											if (mapa[y6][x6]=='X')
											{
												x6++;
											}
											break;
										case 3:
											y6++;
											if (mapa[y6][x6]=='X')
											{
												y6--;
											}
											break;
										case 0:
											y6--;
											if (mapa[y6][x6]=='X')
											{
												y6++;
											}
											break;
										default:
											estado1=1;
											break;
									}
								}
							}
						}
					}
				}
				
				scanf("%c",&control);
				
				}
				
				system("cls");
				printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
				printf("XXXXXXXXXX G A M E XXXXXXXXXX\n");
				printf("XXXXXXXXXX O V E R XXXXXXXXXX\n");
				printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			
				
				printf("\nTu puntuacion ha sido de: %d puntos\n",puntos);
				
				archivo1=fopen("resultados.txt","a");
				if (archivo1==NULL)
				printf("Error al guardar. Revise los ficheros\n");
				else
				{
					fprintf(archivo1,"\n%d",puntos);
					
					fclose(archivo1);
				}
				
				sleep(2);
				system("cls");
				system("pause");
				return 0;
				break;
			
			case 2:
				
				printf("***CONTROLES***\n");
				printf("W + ENTER: Arriba\n");
				printf("S + ENTER: Abajo\n");
				printf("A + ENTER: Izquierda\n");
				printf("D + ENTER: Derecha\n");
				printf("Puedes trazar rutas pulsando distintas direcciones con ENTER entre medias\n\n");
				
				printf("***PARTES DEL MAPA***\n");
				printf("X  Muros\n");
				printf(".  Fruta pequeña\n");
				printf("+  Fruta grande\n");
				printf("O  Pac-Man\n");
				printf("8  Fantasma\n\n");
				
				printf("***OBJETIVOS***\n");
				printf("Comer las maximas frutas posibles\n");
				printf("Evitar a los fantasmas\n\n");
				
				printf("***RECOMENDACIONES***\n");
				printf("Jugar con mayuculas\n");
				printf("Jugar en pantalla completa\n\n\n\n");
				
				printf("\nPulsa cualquier letra para volver al menu principal:");
				scanf("%s",basura);
				system("cls");
				break;
			
			
			
			case 3:
				archivo1=fopen("resultados.txt","r");
				if (archivo1==NULL)
				printf("Error al abrir los resultados. Revise los ficheros\n");
				else
				{
					printf("Introducza cuantas partidas quiere ver: ");
					scanf("%d",&pp);
					system("cls");
					i=0;
					
					while (!feof(archivo1))
					{
						fscanf(archivo1,"%d",&puntos1[i]);
						i++;
						cantidad++;	
					}
					
					j=cantidad-1;
					for (i=0;i<cantidad;i++)
					{
						puntos2[j]=puntos1[i];
						j--;
					}
					
					if (pp>cantidad)
					pp=cantidad;
					
					printf("***ULTIMAS PARTIDAS***\n\n");
					for (i=0;i<pp;i++)
					{
						printf("        - %d\n",puntos2[i]);
					}
					
					fclose(archivo1);
				}
				printf("\n\n\n");
				system("pause");
				return 0;
				break;
				
			case 4:
				archivo2=fopen("resultados.txt","r");
				if (archivo2==NULL)
				printf("Error al abrir los resultados. Revise los ficheros\n");
				else
				{
					printf("Introducza de cuantas partidas quiere el TOP: ");
					scanf("%d",&pp);
					system("cls");
					i=0;
					
					while (!feof(archivo2))
					{
						fscanf(archivo2,"%d",&puntos1[i]);
						i++;
						cantidad++;	
					}
					
					for (i=0;i<cantidad-1;i++)
					{
						for (j=i+1;j<cantidad;j++)
						{
							if (puntos1[j]>puntos1[i])
							{
								auxiliar=puntos1[i];
								puntos1[i]=puntos1[j];
								puntos1[j]=auxiliar;
							}
						}
					}
					
					if (pp>cantidad)
					pp=cantidad;
					printf("***TOP PARTIDAS***\n\n");
					for (i=0;i<pp;i++)
					{
						printf("     - %d\n",puntos1[i]);
					}
					
					fclose(archivo2);
				}
				
				printf("\n\n\n");
				system("pause");
				return 0;
				break;
				
			case 5:
				for (i=10;i>0;i--)
				{
					for (j=i;j>0;j--)
					{
						printf("\n");
					}
					printf("******PROGRAMADORES******\n\n");
					printf("Raul Polvorinos Fernandez\n");
					printf("Carlos Mendoza Carpintero\n");
					sleep(1);
					system("cls");
				}
				break;
			default:
				printf("Opcion incorrecta\n");
				sleep(1);
				system("cls");
				break;	
		}
		printf("***PAC-MAN***\n\n");
		printf("1. Jugar\n");
		printf("2. Instrucciones\n");
		printf("3. Ultimas partidas\n");
		printf("4. Top partidas\n");
		printf("5. Creditos\n");
		printf("6. Salir\n");
		
		scanf("%d",&opcion_aux);
		system("cls");
	}
	return 0;
}

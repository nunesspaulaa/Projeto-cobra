#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>  //getch e kbhit

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char *argv[]) 
{
	
	char tecla;
	char caracter = 205;
	char anterior = 0;
	char Linha  = 1;
	char Coluna = 1;
	char teclaAnterior = 205;
	gotoxy(Coluna,Linha);
	printf("%c", 205);
		
	                                 
	for(;;)
	{
		while ( ! kbhit() ) ;
		tecla=getch();
		if (tecla==27)
        {
        	break;
		}
		if (tecla==-32)
		{
			tecla = getch();
		}
	
	    switch (tecla)
	    {
	    	case 77:Coluna++; //  ->
	    		if(teclaAnterior == 72) 
				{
					Linha--;
					Coluna--;
	    			caracter = 201; // baixo pra ->
				} else if(teclaAnterior == 80)
				{
					Linha++;
					Coluna--;
					caracter = 200; // cima pra -> 
				} else 
				{
					caracter = 205;
				}
				break;
	    	
			case 80:Linha++; // Seta pra baixo
	    		if(teclaAnterior == 77) 
	    		{
					Linha--;
					Coluna++;
					caracter = 187;
				} else if (teclaAnterior == 75) 
				{
					Linha--;
					Coluna--;
					caracter = 201;	
					
				} else
				{
					caracter=186;
				}
			
	    	        break;
	    
			case 75:Coluna--; //  <-
	    		if(teclaAnterior == 72) 
				{
					Linha--;
					Coluna++;
	    			caracter = 187; // cima para <- 
				} else if(teclaAnterior == 80)
				{
					Linha++;
					Coluna++;
					caracter = 188; // baixo pra <-
				} else 
				{
					caracter = 205;
				}
	    	    break;
	       
		   case 72:Linha--;  // Seta pra cima
		   		if (teclaAnterior == 77) // direita pra cima -- FALTANDO
				{
					Linha++;
					Coluna++;
					caracter = 188;
				} else if (teclaAnterior == 75) // esquerda pra cima -- FALTANDO
				{ 
					Linha++;
					Coluna--;
					caracter = 200;	
				}else
				{
				caracter=186;	
				}	
		
	        
	    	
	        
		}
		
		if(Coluna<1)
		{
			Coluna=79;
		}
		
		else if(Coluna>79)
		{
			Coluna=1;
		}
		
		else if(Linha<1)
		{
			Linha=29;
		}
		
		else if(Linha >29)
		{
			Linha=1;
		}
		
		teclaAnterior = tecla;
		
	    gotoxy(Coluna,Linha);
	    printf("%c",caracter);
	  
	}
	return 0;
}


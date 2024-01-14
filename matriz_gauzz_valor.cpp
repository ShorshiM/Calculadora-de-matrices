//Realizar un algoritmo que haga a un sistema de ecuaciones una matriz y aplique el metodo de Gauss y me indique los valores de
// las variables necesarias x y z ... en caso de que no haya solucion o exista infinitas soluciones indicarlo al usuario

#include <conio.h>
#include <stdio.h>
#include <cmath>

void datosVariable(float matriz[][15], int, int);
void dibujarMatriz(float matriz[][15], int, int);
void pintar();


void pintar(){
	//lineas horizontales
	for( int  i = 18 ; i < 104 ; i++){
		gotoxy(i,3) ; printf("%c",205);
		gotoxy(i,26) ; printf("%c",205);	
	}
	//lienas verticales
	for( int i = 4 ; i < 26 ; i++){
		gotoxy(17,i) ; printf("%c",186);
		gotoxy(104,i) ; printf("%c",186);
	}
	//esquinas
	gotoxy(17,3) ; printf("%c",201);
	gotoxy(17,26) ; printf("%c",200);
	gotoxy(104,3) ; printf("%c",187);
	gotoxy(104,26) ; printf("%c",188);
}

void datosVariable(float matriz[][15],int fil, int col){
	char variable[11]={'x','y','z','j','k','l','m','n','o','p','q'};
	int space=0;
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			if(j==col-1){
				gotoxy(22+(4*j),10+i);printf("=");
				space=3;
			}
			gotoxy(21+space+(4*j),10+i);scanf("%f",&matriz[i][j]);
			if(matriz[i][j]==0){
				gotoxy(21+space+(4*j),10+i);printf(" ");
			}else{
				if(matriz[i][j-1]==0 && j!=0 && j!=col-1){
					gotoxy(23+space+(4*j),10+i);printf("%c",variable[j]);
				}else{
					if(j==col-1){
						
					}else{
						if(matriz[i][j]==1){
							gotoxy(21+space+(4*j),10+i);printf(" ");
							if(matriz[i][j]==1 && j!=0){
								gotoxy(20+space+(4*j),10+i);printf("+");
							}
						}else{
							if(matriz[i][j]==-1){
								gotoxy(22+space+(4*j),10+i);printf(" ");
							}
						}
						if(matriz[i][j]>1 && j!=0){
							gotoxy(20+space+(4*j),10+i);printf("+");
						}
						gotoxy(23+space+(4*j),10+i);printf("%c",variable[j]);
					}
				}
				
			}
		}
		space=0;
	}
}

void dibujarMatriz(float matriz[][15],int fil, int col){
	int i,j;
	int space=0;
	int numero=fil;
	char variable[11]={'x','y','z','j','k','l','m','n','o','p','q'};
	float retener;
	float cambio[col];
	bool salir=true;
	bool opcion=false;
	gotoxy(53,8);printf("** Matriz del sistema de ecuaciones **");
	for(i=0;i<fil;i++){
		gotoxy(57,10+i);printf("|");
		for(j=0;j<col;j++){
			if(j== col-1){
				gotoxy(58+(6*j),10+i);printf("|");
				space=3;
			}
			gotoxy(58+space+(6*j),10+i);printf("%.2f",matriz[i][j]);
		}
		gotoxy(59+space+(6*j),10+i);printf("|");
		space=0;
	}
	
	//--------------------------
	
	//metodoGauss(matriz, col, fil);
	for(i=0;i<fil;i++){
		int g=1;
		while(matriz[i][i]==0 && salir){
			if(i<fil-1){
				if((g+i)<fil){
					if(i<fil-1){
						for(j=0;j<col;j++){
							cambio[j]=matriz[i][j];
							matriz[i][j]=matriz[i+g][j];
							matriz[i+g][j]=cambio[j];
						}
					}
				}else{
					salir=false;
					i=fil+5;
				}
			}else{
				if(matriz[i][i]!=matriz[i][i+1]){
					salir=false;
					i=fil+5;
				}else{
					salir=false;
					opcion=true;
					i=fil+5;
				}
				
			}
			
			g++;
		}
		if(matriz[i][i]!=1 && matriz[i][i]!=0){
			retener=(1/matriz[i][i]);
			for(j=0;j<col;j++){
				matriz[i][j]=matriz[i][j]*retener;
			}
		}
		if(salir){
			for(j=1+i;j<fil;j++){
				retener=-matriz[j][i];
				for(int k=0;k<col;k++){
					cambio[k]=retener*matriz[i][k];
				}
				for(int l=0;l<col;l++){
					matriz[j][l]=matriz[j][l]+cambio[l];
					/*if(i==fil-1 && l==col-1 && matriz[j][l-1]==0 && matriz[j][l]!=matriz[j][l-1]){
						salir=false;
						i=fil+5;
					}
					if(i==fil-1 && l==col-1 && matriz[j][l-1]==0 && matriz[j][l]==matriz[j][l-1]){
						salir=false;
						opcion=true;
						i=fil+5;	
					}*/
				}
			}
		}
	}
	
	//--------------------------
	
	if(salir){
		//-------------------------------
		gotoxy(34,11+fil);printf("** Metodo de Gauss **");
		for(i=0;i<fil;i++){
			gotoxy(30,12+fil+i);printf("|");
			for(j=0;j<col;j++){
				if(j==col-1){
					gotoxy(31+(6*j),12+fil+i);printf("|");
					space=3;
				}
				gotoxy(31+space+(6*j),12+fil+i);printf("%.2f",matriz[i][j]);
			}
			gotoxy(33+space+(j*6),12+fil+i);printf("|");
			space=0;
		}
		//-------------------------------
		// Metodo Gauss Jordan
		for(int k=1;k<fil;k++){
			for(int i=k;i>0;i--){
				//for(int t=0;t<col;t++){
				retener=-matriz[i-1][k];
				for(int j=0;j<col;j++){
					cambio[j]=matriz[k][j]*retener;
				}
				for(int l=0;l<col;l++){
					matriz[i-1][l]=matriz[i-1][l]+cambio[l];
				}
				//}
			}
		}
		
		//-------------------------------
			
		gotoxy(20,16+fil);printf("** Solucion de variables con metodo Gauss-Jordan **");
			for(i=0;i<fil;i++){
				gotoxy(28,17+fil+i);printf("%c = %.3f",variable[i],matriz[i][col-1]);
			}
	}else{
		if(opcion){
			gotoxy(28,17+fil);printf("** El sistema de ecuaciones tiene infinitas soluciones **");
		}else{
			gotoxy(28,17+fil);printf("** El sistema de ecuaciones no tiene solucion **");
		}
	}


	
	/*
	if(fil==3){
		resultado[2]=matriz[2][3];
		resultado[1]=matriz[1][3]-(matriz[1][2]*resultado[2]);
		resultado[0]=matriz[0][3]-(matriz[0][2]*resultado[2])-(matriz[0][1]*resultado[1]);
		for(int i=0;i<3;i++){
			gotoxy(28,19+fil+i);printf("%c = %.3f",variable[i],resultado[i]);
		}
	}if(fil==2){
		resultado[1]=matriz[1][2];
		resultado[0]=matriz[0][2]-(matriz[0][1]*resultado[1]);
		for(int i=0;i<2;i++){
			gotoxy(28,19+fil+i);printf("%c = %.3f",variable[i],resultado[i]);
		}
	}
	*/
}

int main(){
	textcolor(LIGHTBLUE);
	textbackground(WHITE);
	window(1,1,140,50);
	int fil,col;
	int variable;
	float matriz[15][15];
	pintar();
	do{
		gotoxy(30,5);printf("** Numero de variables **");
		gotoxy(38,7);scanf("%i",&variable);
		if(variable>1){
			fil=variable;
			col=variable+1;
		}else{
			gotoxy(35,9);printf("** Debe tener como minimo 2 variables **");
			getch();
			gotoxy(35,9);printf("                                         ");
			gotoxy(38,7);printf("                  ");
		}
	}while(variable<2);
	
	datosVariable(matriz, fil, col);
	dibujarMatriz(matriz, fil, col);
	
	gotoxy(30,25);printf("\n");
	return 0;
}

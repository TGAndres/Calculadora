#include<stdio.h>

int main(){
	double primero,segundo,suma,resta,mult,div;
	printf("Introduce un n%cmero real (y presiona enter): ", 163);
	scanf("%lf",&primero);
	printf("Introduce otro n%cmero real (y presiona enter): ", 163);
	scanf("%lf",&segundo);
	
	suma = primero + segundo;
	resta = primero - segundo;
	mult = primero * segundo;
	
	printf("Los n%cmeros ingresados fueron: %.4lf y %.4lf\n", 163,primero,segundo);
	
	puts("=====================================");
	puts("|    OPERACION    |    RESULTADO    |");
	puts("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
	printf("|SUMA             |");
	printf("%17.4lf|\n",suma);
	printf("|RESTA            |");
	printf("%17.4lf|\n",resta);
	printf("|MULTIPLICACION   |");
	printf("%17.4lf|\n",mult);
	printf("|DIVISION         |");
	if(segundo < 0.0001 && segundo > -0.0001) puts(" ERROR MATEMATICO|");
	else{
		div = primero / segundo;
		printf("%17.4lf|\n",div);
	} 
	puts("=====================================");
	return 0;
}

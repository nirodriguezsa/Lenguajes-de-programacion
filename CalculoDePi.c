#include <stdio.h>
#include <math.h>

double factorial(double n) {
   if(n < 0) return 0;
   else if(n > 1) return n*factorial(n-1);
   return 1;
};

double ramanujan(n){ //n es el numero de iteraciones
	double coeficiente = (2*sqrt(2)/9801);
	double sumatoria = 0;
	
	if(n < 0) return sumatoria; // Si no, se aplica la formula
	while(n >= 0){
		sumatoria = sumatoria + (factorial(4*n)*(1103+(26390*n))) / (pow(factorial(n),4)*pow(396,(4*n)) );
		n= n-1;	
	};
	return 1/(sumatoria*coeficiente);//Ya que el resultado es 1/pi
};

double wallis(n){
	
	double multiplicatoria	= 1;
	
	if(n <= 0) return multiplicatoria; // Si no, se aplica la formula
	while(n > 0){
		multiplicatoria = multiplicatoria * (4*pow(n,2)) / (((2*n)-1)*((2*n)+1))  ;
		n= n-1;	
	};
	return multiplicatoria*2;//Ya que el resultado es pi/2
};


main(){
	printf("\nResultado con metodo de Ramanujan (con 6 iteraciones):\n %.17f", ramanujan(6),"\n\n\n"); //Con solo 6 iteraciones ya nos da mas cifras exactas de pi que el metodo de Wallis con 23170 iteraciones
	printf("\nResultado con metodo de Wallis (con 23170 iteraciones):\n %.17f", wallis(23170),"\n\n\n\n");	//Máximo de iteraciones posibles antes de que empiece a dar valores incoherentes en mi maquina
}

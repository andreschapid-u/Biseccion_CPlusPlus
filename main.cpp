#include<iostream>
#include "biseccion.h"

using namespace std;
	
void buscarRaiz(biseccion b1, double a, 
				double b, double tolerancia, 
				int max_iter){
	double raiz = 0.0;
	
	if(b1.encontrarRaiz(a, b, tolerancia, max_iter, raiz)){
		cout << "Raiz encontrada para la funcion " << b1.str() << ": " << raiz << " con un er: " << tolerancia << endl;
	}else{
		cout << "No se encontro una raiz para la funcion " 
			<< b1.str()
			<< " en el intervalo ["<< a << ", "<< b << "]" << endl;
	}
}

int main (int argc, char *argv[]) {
	
	biseccion b1(
				 [](double x){
					 double f1 = x * x * x;
					 double f2 = 2 * x * x;
					 return (f1 - f2 - x + 1);
				 },
					"x^3 - 2x^2 - x + 1"
					);
	
	char opcion = '0';
	double a = 0.1;
	double b = 2.0;
	double tolerancia = 0.0001;
	double max_iter = 100;
	do{
		cout << "\t\tMetodo de Biseccion" << endl;
		cout << "\tFuncion a evaluar: " << b1.str() << endl;
		cout << "\nIngrese el valor de a: ";
		cin >> a;
		cout << "\nIngrese el valor de b: ";
		cin >> b;
		cout << "\nIngrese el valor de la tolerancia (0.0...): ";
		cin >> tolerancia;
		cout << "\nIngrese el numero de iteraciones: ";
		cin >> max_iter;
		buscarRaiz(b1, a, b, tolerancia, max_iter);
		cout << "\nDesea ejecutar otra vez?" << endl;
		cout << "1. SI" << endl;
		cout << "2. No" << endl;
		cout << "\nIngrese 1 o 2: ";
		cin >> opcion;		
	}while(opcion != '2');
	
	return 0;
}




#ifndef BISECCION_H
#define BISECCION_H
#include <cmath>
#include <functional>
#include <stdlib.h>
#include <string>

using std::function;
using std::string;

class biseccion{
public:
	biseccion(
			  function<double(double)> p_func,
			  string p_str): func(p_func), str_func(p_str){
	};
	
	double f(double x){
		return func(x);
	}
	string str(){
		return str_func;
	}
		
	bool encontrarIntervalo(
							double a,
							double b,
							double &inicio,
							double &fin,
							int intervalos){
		double paso = (b - a) / intervalos;
		int iter = 1;
		for( double x = a; x <= b; x+= paso){
			double valor = f(x);
			double valorSiguiente = f(x + paso);
			if( valor *valorSiguiente < 0.0){
				inicio = x;
				fin = x + paso;
				return true;
			}
			iter++;
		}
		return false;
	}
		
	bool encontrarRaiz(double a,
					   double b,
					   double & tolerancia,
					   int max_iter,
					   double & raiz){
		double inicio;
		double fin;
		double intervalos = 10;
		if(!encontrarIntervalo(a, b, inicio, fin, intervalos)){
			return false;
		}

		//Metodo de Biseccion
		double xanterior =  (inicio + fin) / 2.0;
		int i = 1;
		
		if(f(xanterior) == 0.0){
			raiz = xanterior;
			tolerancia = 0.0;
			return true;
		}
		
		double resultado = f(inicio) * f(xanterior); 
		if(resultado > 0.0){
			inicio = xanterior;
		}else {
			fin = xanterior;
		}
		
		while(i <= max_iter){
			double xnueva = (inicio + fin) / 2.0;
			double er = abs((xnueva - xanterior)/xnueva);
			
			if( (f(xnueva) == 0) || (er < tolerancia) ){
				raiz = xnueva;
				tolerancia = er;
				return true;
			}
			i++;
			
			resultado = f(inicio) * f(xnueva); 
			if(resultado > 0.0){
				inicio = xnueva;
			}else {
				fin = xnueva;
			}
			xanterior = xnueva;
		}
		return false;
	}
	
private:
	function<double(double)> func;
	string str_func;
};

#endif

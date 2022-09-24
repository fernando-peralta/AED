#include <iostream>
using namespace std;

void print_sopa(char(*matriz)[10], int b) {
	for (char(*i)[10] = matriz; i < matriz + b; i++)
	{
		for (char* j = *i; j < *(i + 1); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}

class avanzar {
	public:
		char* avanzar_arriba(char*& p, int n) {
			p = p - n;
			return p;
		}

		char* avanzar_abajo(char*& p, int n) {
			p = p + n;
			return p;
		}

		char* avanzar_derecha(char*& p, int n) {
			p++;
			return p;
		}

		char* avanzar_izquierda(char*& p, int n) {
			p--;
			return p;
		}
};



typedef char* (avanzar::* PF)(char*&, int);

int contar_palabra(char(*matriz)[10], int b, char  *objetivo, int len) {
	int contador = 0;
	PF arr[4] = { &avanzar::avanzar_abajo,&avanzar::avanzar_arriba,&avanzar::avanzar_derecha,&avanzar::avanzar_izquierda };
	PF *puntero_avanzar = arr;
	avanzar a;

	for (char(*i)[10] = matriz; i < matriz + b; i++)
	{
		for (char* j = *i; j < *(i + 1); j++)
		{
			if (*j == *objetivo)
			{
				for (int i = 0; i < 4; i++)
				{
					int aux_cuenta = 0;
					char *aux_recorrido = j;
					for (char* aux1 = objetivo+1; *aux1; aux1++)
					{
						if (*(a.*arr[i])(aux_recorrido, b) == *aux1)
						{
							aux_cuenta++;
						};
					}

					if (aux_cuenta==len-1)
					{
						contador++;
					}
					puntero_avanzar++;
				}
				
			}
		}
	}
	return contador;
}

int main() {
	char matriz[10][10] = {{'G','T','P','A','L','T','A','J','W','R'},{'P','L','T','R','A','E','I','J','K','L'},{'A','I','E','O','J','R','H','Q','T','R'},{'L', 'T','J','U','Z','W','B','C','T','J'},{'T','J','J','Z','W','U','Y','P','M','N'},{'A','T','L','A','P','J','T','T','H','U'},{'W','A','F','F','E','R','J','J','P','P'},{'O','O','U','Z','W','T','T','H','I','A'},{'P','B','D','E','F','K','N','M','O','P'},{'D','O','R','S','T','T','V','X','Y','Z'} };

	char objetivo[10] = { 'P','A','L','T','A' };
	int len = 0;
	for (char *aux=objetivo; *aux; aux++)
	{
		len++;
	}

	print_sopa(matriz, 10);

	cout<<contar_palabra(matriz, 10, objetivo, len);
	
}
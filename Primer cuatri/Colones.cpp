/**************************************************************/
/* Programa que devuelve el número de elementos desordenados  */
/*  de una lista supuestamente ordenada.                      */
/**************************************************************/
#include <iostream>
using namespace std;
 //Compiler version g++ 4.9

int colones(int vector [], int n);
const int MAX_SIZE = 100000;

 int main()
 {
 	int vector [MAX_SIZE];
 	int cases, n;

 	cin >> cases;
 	while (cases > 0) {
 		cin >> n;
 		while (n < 0) {
 			cout << "Error, n must be >= 0. Try again." << endl;
 			cin >> n;
 		}

 		for (int i = 0; i < n; i++) {
 			cin >> vector[i];
 		}

 		cout << colones(vector, n) << endl;

 		cases--;
 	}

 	return 0;
 }

int colones(int vector[], int n) {
	int colones = 0, min = vector [n - 1];

	for (int i = n - 1; i > 0; i--){
		if (vector[i-1] > vector[i]) {
			colones++;
		}
		else if(vector[i-1] > min) {
				colones++;
			}
		else {
			min = vector[i-1];
		}
	}

	return colones;
}

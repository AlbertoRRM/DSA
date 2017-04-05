/***********************************************************************/
/* Programa que devuelve el tamaño de una secuencia de números pares en*/
/* un vector y el comienzo y el final de esta secuencia, o vacio si no */
/* existe tal secuencia. En caso de dos secuencias de igual longitud   */
/* devolverá la posicionada más hacia la derecha.                      */
/***********************************************************************/
#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;
int longestPares(int vector[], int n, int &start, int &end);

int main() {
    int vector[MAX_SIZE];
    int result, cases, n, start, end;

    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> n;
        while(n < 0 && n > 100000) {
            cout << "Error! n must be >= 0. Try again." << endl;
            cin >> n;
        }

        for (int i = 0; i < n; i++) {
            cin >> vector[i];
        }
		start = -1;
		end = -1;
		result = longestPares(vector, n, start, end);
		if (result != 0)
			cout << result << " -> " << "[" << start << "," << end << ")" << endl;
		else
			cout << "Vacio" << endl;
    }

    return 0;
}

int longestPares(int vector[], int n, int &start, int &end) {
    int length = 0, auxLength = 0, auxStart = -1, auxEnd = -1;
    bool init = false; // Indica si se ha iniciado una secuencia de pares

    for (int i = n - 1; i >= 0; i--) {
        // Mientras sea par, se incrementa auxLength
        while(vector[i] % 2 == 0 && i >= 0) {
            auxLength++;
            if(!init) {
                init = true;
                auxEnd = i + 1;
            }
            i--;
        }
        // Se establece la posición del inicio de la secuencia par
        if(init) {
            init = false;
            auxStart = i + 1;
        }

        //Se actualizan los datos si es necesario
        if(length < auxLength) {
            length = auxLength;
            start = auxStart;
            end = auxEnd;
        }

		auxLength = 0;
    }

    return length;
}

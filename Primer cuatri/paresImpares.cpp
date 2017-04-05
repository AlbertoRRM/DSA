/***********************************************************************/
/* Programa que devuelve Si si una lista es divisible en números pares */
/* e impares y nos devuelve en qué posición.                           */
/***********************************************************************/
#include <iostream>
using namespace std;

const int MAX_SIZE = 10000;
void paresImpares(int vector[], int n, bool &existe, int &p);

int main() {
    int vector[MAX_SIZE];
    int cases, n, p;
    bool existe;

    cin >> cases;
    while(cases > 0) {
        cin >> n;
        while(n < 0) {
            cout << "Error! n must be >= 0. Try again." << endl;
            cin >> n;
        }

        for (int i = 0; i < n; i++) {
            cin >> vector[i];
        }

		existe = false;
		p = 0;
        paresImpares(vector, n, existe, p);

        if(existe) {
            cout << "Si " << p << endl;
        }
        else {
            cout << "No" << endl;
        }

        cases--;
    }

    return 0;
}

void paresImpares(int vector[], int n, bool &existe, int &p) {
    int i = n - 1;
    bool ok = true;

	if (vector[i] % 2 != 0) {
		while (i >= 0 && ok) {
			if (vector[i] % 2 == 0 && !existe) {
				existe = true;
				p = i + 1;
			}
			else if (vector[i] % 2 != 0 && existe) {
				ok = false;
				existe = false;
				p = 0;
			}
			i--;
		}
	}
}

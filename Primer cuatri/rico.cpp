#include <iostream>
using namespace std;

int diasRestantes(int cents);

int main() {
    int cases, cents;

    cin >> cases; 
    for (int i = 0; i < cases; i++) {
        cin >> cents;
        cout << diasRestantes(cents) << endl;
    }

    return 0;
}

int diasRestantes(int cents) {
    int dias = 2, dinero = 2, i_2 = 1, i_1 = 1, i_aux;

	if (cents == 0) return 0;
	else if (cents == 1) return 1;
	else {
		while (dinero < cents) {
			dinero += (i_2 * 2 + i_1);
			i_aux = i_1;
			i_1 = i_2 * 2 + i_1;
			i_2 = i_aux;
			dias++;
		}
	}

    return dias;
}

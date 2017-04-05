/*Dado el valor de una base entera x(1 ≤ x ≤ 100) y el valor de un exponenten (0 ≤ n ≤ 1.000.000),
el programa calcula el valor de la siguiente serie: x0 + x1 + ... + xn */
#include <iostream>
using namespace std;

int MAX_SIZE = 1000000;
int seriePotencias(int x, int n);
int power(int b, int e);

int main() {
    int x, n;

    cin >> x;
	while (x != 0 && cin) {
		while (x < 0 && x > 100) {
			cout << "Error. x must be >= 1 and <= 100, try again!" << endl;
			cin >> x;
		}

		cin >> n;
		while (n < 0 && n > 1000000) {
			cout << "Error. n must be >= 0 and <= 1000000" << endl;
			cin >> n;
		}
		cout << seriePotencias(x, n) << endl;
		cin >> x;
	}

    return 0;
}

int seriePotencias(int x, int n) {
    int suma = 0;

    for (int i = 0; i <= n; i++) {
		suma = (suma * x + 1)  % 1000007;
    }

	return suma;
}

#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;
int numeroMaximo(int vector[], int n, int &repeticiones);

int main() {
    int vector[MAX_SIZE];
    int cases, n, repeticiones;

    cin >> cases;
    while(cases > 0) {
        cin >> n;
        while(n < 0 && n > MAX_SIZE) {
            cout << "Error! n must be >= 0. Try again." << endl;
            cin >> n;
        }

        for(int i = 0; i < n; i++) {
            cin >> vector[i];
        }
        repeticiones = 1;

		cout << numeroMaximo(vector, n, repeticiones);
		cout << " " << repeticiones << endl;
        cases--;
    }

    return 0;
}

int numeroMaximo(int vector[], int n, int &repeticiones) {
    int posicionMax = 0;
    for (int i = 1; i < n; i++) {
        if(vector[posicionMax] < vector[i]) {
            posicionMax = i;
            repeticiones = 1;
        }
        else if (vector[posicionMax] == vector[i])
            repeticiones++;
    }

    return vector[posicionMax];
}

/***********************************************************************/
/* Programa que devuelve Si si una lista es divisible en números pares */
/* e impares y nos devuelve en qué posición.                           */
/***********************************************************************/
#include <iostream>
using namespace std;

const int MAX_SIZE = 10000;
void paresImpares(int vector[], int n, bool &existe, int &p);
bool pares(int vector[], int s, int t);
bool impares(int vector[], int s, int t);

int main() {
    int vector[MAX_SIZE];
    int cases, n, p;
    bool existe;


    cin >> cases;

    for (int i = 0; i < cases; i++) {
      cin >> n;

      if (n < MAX_SIZE + 1) {
        for (int j = 0; j < n; j++) {
          cin >> vector[j];
        }

        int p = 0;
        bool existe = false;

        paresImpares(vector, n, existe, p);

        if (existe) {
          cout << "Si " << p << endl;
        }
        else {
          cout << "No" << endl;
        }
      }
    }

    // cin >> cases;
    // while(cases > 0) {
    //     cin >> n;
    //     while(n < 0) {
    //         cout << "Error! n must be >= 0. Try again." << endl;
    //         cin >> n;
    //     }
    //     if(n < MAX_SIZE) {
    //         for (int i = 0; i < n; i++) {
    //             cin >> vector[i];
    //         }
    //
    // 		existe = false;
    // 		p = 0;
    //         paresImpares(vector, n, existe, p);
    //
    //         if(existe) {
    //             cout << "Si " << p << endl;
    //         }
    //         else {
    //             cout << "No" << endl;
    //         }
    //
    //         cases--;
    //     }
    // }

    return 0;
}


void paresImpares (int vector[], int n, bool &existe, int &p) {
  int q = 0;

  while (q < n && vector[q] % 2 == 0) {
    q++;
  }

  bool esPar = pares(vector, 0, q);
  bool esImpar = impares(vector, q, n);

  if (esPar && esImpar) {
    existe = true;
    p = q;
  }
  else {
    existe = false;
  }
}
// void paresImpares(int vector[], int n, bool &existe, int &p) {
//     int q = 0;
//     bool ok = false;
//
// 	if (vector[n - 1] % 2 != 0) {
//         while(q < n && !ok) {
//             if(vector[q] % 2 == 0) {
//                 q++;
//             }
//             else
//                 ok = true;
//
//         }
// 		existe = impares(vector, q , n) && pares(vector, 0, q);
//         if(existe)
//             p = q;
// 	}
// }

bool pares(int vector[], int s, int t) {
    bool pares = true;
    int i = s;

    while (i < t && pares) {
        if(vector[i] % 2 != 0) {
            pares = false;
        }
        i++;
    }
    return pares;
}

bool impares(int vector[], int s, int t) {
    bool impares = true;
    int i = s;

    while (i < t && impares) {
        if(vector[i] % 2 == 0) {
            impares = false;
        }
        i++;
    }
    return impares;
}

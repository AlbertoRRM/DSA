#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;

int esVidente(int vector[], int n);

int main()
{
  int vector[MAX_SIZE];
  int cases, n, result;

  cin >> cases;
  while(cases > 0)
  {
    cin >> n;
    while(n < 0)
    {
        cout << "Error, n must be greater or equal to zero! Try again." << endl;
        cin >> n;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> vector[i];
    }

	result = esVidente(vector, n);
    if(result != -1)
      cout << "Si " << result << endl;
    else
      cout << "No" << endl;

    cases--;
  }

  return 0;
}

int esVidente(int vector[], int n)
{
	bool ok = false;
    int i = n - 1, suma = 0;

    while(i >= 0 && !ok)
    {
        if(suma == vector[i])
            ok = true;
        else {
            suma += vector[i];
			i--;
        }
    }

	if (!ok)
		suma = -1;

    return i;
}

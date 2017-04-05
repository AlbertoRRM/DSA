/* fob 0(x, y) = x
   fob1(x, y) = y
   fobn(x, y) = fobn − 1(x, y) + fobn − 2 (x,y) si n ≥2 */
#include <iostream>
using namespace std;

int fob(int n, int x, int y);

int main() {
    int n, x, y;

    cin >> n;
    while(n >= 0) {
        cin >> x;
        cin >> y;
        cout << fob(n, x, y) << endl;
        cin >> n;
    }

    return 0;
}

int fob(int n, int x, int y) {
    if(n == 0) return x;
    else if(n == 1) return y;
    else {
        return fob(n - 1, x, y) + fob(n - 2, x, y);
    }
}

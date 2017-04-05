/* Ascending by a hairbreadth: 0 <= v[i + 1] - v[i] <= 1
 D-entertaining:

 Specification
 P = n >= 0 && d >= 0 && length() >= n
 Q = {r = ascending(v, n) && entertaining(v, n, d)}
 ascending(v, n):= Vk : 0 <= k < n - 1 : v[k + 1] - v[k] <= 1
 entertaining(v, n, d):= Vk : 0 <= k < n : frec(v, n, v[k]) <= d
 frec(v, n, a):= #k : 0 <= k < n : v[k] = a

 Invariant
 I:= {1 <= i <= n ∧ ascending(v, i) ∧ entertaining(v, i, d)}
*/
bool exercise1(int v[], int n, int d) {
    int i = 1;
    bool ascending = true, entertaining = true;

    if (n == 0) {
        while(i < n && ascending && entertaining) {
            ascending = (v[i] >= v[i - 1]) && (v[i] - v[i - 1] <= 1);
            entertaining = (((i - d) >= 0) && (v[i] > v[i - d]));
        }
    }
    return ascending && entertaining;
}

//Exercise 2
for (int k = e; k < e + n; k++) {
        k = v[i - 1];
        if (k <= v[i - 1] - 1)
            k++;
}

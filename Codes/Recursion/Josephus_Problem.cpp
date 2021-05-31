#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Josephus(int n, int k)
{
    if (n == 1)
        return 0;
    return ((Josephus(n - 1, k) + k) % n);
}
int main()
{
    int n = 7, k = 3;
    cout << Josephus(n, k);
    return 0;
}
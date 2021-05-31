// given a rope of length n , you need to find maximum no of pieces you can make such that the length of every pieces is in set {a,b,c}, where a,b,c are variable given
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int rope(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    else if (n < 0)
        return -1;

    int ans = max(rope(n - a, a, b, c), max(rope(n - b, a, b, c), rope(n - c, a, b, c)));
    if (ans == -1)
        return -1;
    return ans + 1;
}

int main()
{
    int n = 23;
    int a = 12, b = 9, c = 11;
    cout << rope(n, a, b, c);
    return 0;
}
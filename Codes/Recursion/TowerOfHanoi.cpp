#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void towerofhanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        cout << "Move 1 from " << A << " to " << C << endl;
        return;
    }
    towerofhanoi(n - 1, A, B, C);
    cout << "Move " << n << " from " << A << " to " << C << endl;
    towerofhanoi(n - 1, B, C, A);
}
int main()
{
    int n = 3;
    char A = 'a', B = 'b', C = 'c';
    towerofhanoi(n, A, C, B);
    return 0;
}
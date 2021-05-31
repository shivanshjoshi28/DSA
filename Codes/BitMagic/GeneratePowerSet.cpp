#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string s = "ABC";
    int n = s.length();
    int powerlen = (1 << n); // here 2to the power 3=8  so , we loop from 0 to 7
    for (int i = 0; i < powerlen; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                cout << s[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// print that index element for which the bit is set
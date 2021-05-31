// wap to find that element in an array that occur odd time          assumption: there is only one element in the array that occur odd times

// wap to find whether the k th bit is set or not

// wap to check if the no. is the power of 2
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    if (n && (n & (n - 1) == 0))
        cout << "Given no. is power of 2";
    else
        cout << "Not a power of 2";
    return 0;
}
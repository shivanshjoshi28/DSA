// this question also had an efficient solution that can be done through DP

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int CountSubset(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    return CountSubset(arr, n - 1, sum) + CountSubset(arr, n - 1, sum - arr[n - 1]);
}
int main()
{
    int arr[6] = {0, 2, -2, 4, 5, -4};
    int sum = 0;
    int n = 6;
    CountSubset(arr, n, sum);
    return 0;
}
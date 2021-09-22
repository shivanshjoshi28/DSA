// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find
// rightmost index
// which satisfies the condition
// arr[j] - arr[i] <= k
int findInd(int key, int i,
			int n, int k, int arr[])
{
	int start, end, mid, ind = -1;
	
	// Initialising start to i + 1
	start = i + 1;
	
	// Initialising end to n - 1
	end = n - 1;
	
	// Binary search implementation
	// to find the rightmost element
	// that satisfy the condition
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		
		// Check if the condition satisfies
		if (arr[mid] - key <= k)
		{
			
			// Store the position
			ind = mid;
			
			// Make start = mid + 1
			start = mid + 1;
		}
		else
		{
			// Make end = mid-1
			end = mid-1;
		}
	}
	
	// Return the rightmost position
	return ind;
}

// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k)
{
	int i, j, ans = n - 1;
	
	// Sort the given array
	sort(arr, arr + n);
	
	// Iterate from 0 to n-1
	for (i = 0; i < n; i++)
	{
		
		// Find j such that
		// arr[j] - arr[i] <= k
		j = findInd(arr[i], i, n, k, arr);
		
		// If there exist such j
		// that satisfies the condition
		if (j != -1)
		{
			// Number of elements
			// to be removed for this
			// particular case is
			// (j - i + 1)
			ans = min(ans, n - (j - i + 1));
		}
	}
	
	// Return answer
	return ans;
}

// Driver Code
int main()
{
	int a[] = {0,3,5};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 2;
	cout << removals(a, n, k);
	return 0;
}

// // Backtracking based CPP program to print all
// // permutations of a string that follow given
// // constraint
// #include <bits/stdc++.h>
// using namespace std;

// bool isSafe(string& str, int l, int i, int r)
// {
// 	// If previous character was 'A' and character
// 	// is 'B', then do not proceed and cut down
// 	// the recursion tree.
// 	if (l != 0 && str[l - 1] == 'A' && str[i] == 'B')
// 		return false;

// 	// This condition is explicitly required for
// 	// cases when last two characters are "BA". We
// 	// do not want them to swapped and become "AB"
// 	if (r == l + 1 && str[i] == 'A' && str[l] == 'B'
// 		|| r == l + 1 && l == i && str[r] == 'B'
// 			&& str[l] == 'A')
// 		return false;

// 	return true;
// }

// void permute(string& str, int l, int r)
// {
// 	// We reach here only when permutation
// 	// is valid
// 	if (l == r) {
// 		cout<<endl;
// 		cout << str << endl;
// 		return;
// 	}

// 	// Fix all characters one by one
// 	for (int i = l; i <= r; i++) {
//         // cout<<"i= "<<i<<"      "<<"l= "<<l<<endl;
//         // cout<<" Original str= "<<str<<endl;

// 		// Fix str[i] only if it is a
// 		// valid move.
// 		cout<<"checking "<<str<<"l= "<<l<<" i= "<<i<<" r= "<<r<<endl;
// 		if (isSafe(str, l, i, r)) {
// 			cout<<"passed"<<endl;
//             // cout<<"passed "<<endl;
// 			swap(str[l], str[i]);
//             // cout<<"First swap at i= "<<i<<" "<<str<<endl;
// 			permute(str, l + 1, r);
// 			swap(str[l], str[i]);
//             // cout<<"Second swap at i= "<<i<<" "<<str<<endl;
// 		}
// 	}
// }

// // Driver Code
// int main()
// {
// 	string str = "CBAD";

// 	// Function call
// 	permute(str, 0, str.length() - 1);
// 	return 0;
// }




#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#include<vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
const int inf =(int) 1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

bool isSafe(int i,int l,int r,string str)
{
	if(l!=0 && str[l-1]=='A' && str[i]=='B' ) 
		return false;
	if((l+1==r) && str[l]=='B'&& str[i]=='A') return false;
	if((l+1==r )&& l==i && str[r]=='B' && str[l]=='A') return false;
	return true;
}


void solve(string str,int l,int h)
{
	if(l==h) 
	{
		cout<<str<<endl;
		return;
	}
	for(int i=l;i<=h;i++)
	{
		if(isSafe(i,l,h,str))
		{
			swap(str[i],str[l]);
			solve(str,l+1,h);
			swap(str[i],str[l]);
		}
	}
}

int main()
{
	boost;
	string str="ABC";
	solve(str,0,str.length()-1);
	return 0;
}
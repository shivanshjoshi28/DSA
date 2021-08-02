// https://leetcode.com/problems/valid-parenthesis-string/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include <vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define F first
#define S second
const int inf = (int)1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

// bool Valid(string s, int index, stack<char> sch)
// {
//     if (index == s.length() && sch.empty())
//     {
//         return true;
//     }
//     else if (index == s.length() && !sch.empty())
//     {
//         return false;
//         // stack<char> newsch = sch;
//         // while (!newsch.empty())
//         // {
//         //     char top = newsch.top();
//         //     if (top != '*')
//         //         return false;
//         //     newsch.pop();
//         // }
//         // return true;
//     }
//     cout << " at index = " << index << endl;
//     if (s[index] == '(')
//     {
//         sch.push(s[index]);
//         bool b = Valid(s, index + 1, sch);
//         sch.pop(); // backtrack
//         return b;
//     }
//     else if (s[index] == ')')
//     {
//         if (sch.empty())
//         {
//             return false;
//         }
//         else
//         {
//             char top = sch.top();
//             sch.pop();
//             bool dd = Valid(s, index + 1, sch);
//             if (dd == false)
//             {
//                 sch.push('(');
//                 return false;
//             }
//             else
//                 return true;
//         }
//     }
//     else
//     {

//         // let * = (
//         sch.push('(');
//         bool b = Valid(s, index + 1, sch);
//         sch.pop(); // backtrack

//         // Let * = )
//         bool c;
//         if (sch.empty())
//         {
//             c = false;
//         }
//         else
//         {
//             char top = sch.top();
//             sch.pop();
//             c = Valid(s, index + 1, sch);
//         }

//         // Let * =""
//         bool d = Valid(s, index + 1, sch);
//         cout << "Bool b= " << b << " bool c= " << c << " bool d= " << d << endl;
//         return (b or c or d);
//     }
// }
bool isValid(string s, int index, vector<char> &v)
{
    cout << " At index = " << index << "    vector      ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    if (index == s.length() && v.empty())
    {
        return true;
        cout << "Returned true" << endl;
    }
    else if (index == s.length() && !v.empty())
    {
        cout << "Returned false" << endl;
        return false;
    }

    if (s[index] == '(')
    {
        v.push_back(s[index]);
        bool b = isValid(s, index + 1, v);
        v.pop_back(); // backtrack
        return b;
    }
    else if (s[index] == ')')
    {
        if (v.empty())
        {
            return false;
        }
        else
        {
            char top = v.back();
            v.pop_back();
            bool dd = isValid(s, index + 1, v);
            if (dd == false)
            {
                v.push_back('(');
                return false;
            }
            else
            {
                cout << "Return ** true" << endl;
                return true;
            }
        }
    }
    else
    {

        // let * = (
        v.push_back('(');
        bool b = isValid(s, index + 1, v);
        v.pop_back(); // backtrack
        if (b == true)
            return true;

        // Let * = )
        bool c;
        if (v.empty())
        {
            cout << " Yes c= false" << endl;
            c = false;
        }
        else
        {
            char top = v.back();
            v.pop_back();
            c = isValid(s, index + 1, v);
            if (c == false)
            {
                cout << "pushed ( ****" << endl;
                v.push_back('(');
            }
        }
        if (c == true)
            return true;

        // Let * =""
        bool d = isValid(s, index + 1, v);
        cout << "Bool b= " << b << " bool c= " << c << " bool d= " << d << endl;
        return (b or c or d);
    }
}

int main()
{
    boost;
    string s;
    cin >> s;
    vector<char> v;
    cout << isValid(s, 0, v);
    return 0;
}
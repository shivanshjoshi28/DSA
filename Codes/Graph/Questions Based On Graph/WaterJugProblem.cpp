// // #include <bits/stdc++.h>
// // #include <iostream>
// // using namespace std;

// // #include <vector>
// // typedef pair<int, int> pii;
// // typedef vector<int> vi;
// // #define pb push_back
// // #define MP make_pair
// // #define endl "\n"
// // #define boost                         \
// //     ios_base::sync_with_stdio(false); \
// //     cin.tie(NULL)
// // #define F first
// // #define S second
// // const int inf = (int)1e18;
// // const int ninf = (int)-1e17;
// // #define rep(a, b) for (int a = 0; a < b; a++)
// // #define per(a, b) for (int a = b - 1; a >= 0; a--)
// // #define FOR(it, start, end) for (auto it = start; it != end; it++)

// // void BFS(int m, int n, int sum, set<pair<int, int>> &path)
// // {
// //     queue<pair<int, int>> q;
// //     q.push({0, 0});
// //     path.insert({0, 0});
// //     while (!q.empty())
// //     {
// //         auto top = q.front();
// //         cout << top.first << " " << top.second << endl;
// //         q.pop();
// //         if (top.first < m)
// //         {
// //             pair<int, int> temp = {m, top.second};

// //             if (path.find(temp) == path.end())
// //             {
// //                 cout << "inserting1" << temp.first << " " << temp.second << endl;
// //                 path.insert(temp);
// //                 q.push(temp);
// //             }
// //             if (temp.first + temp.second == sum)
// //             {
// //                 cout << "breaked" << endl;

// //                 break;
// //             }
// //         }
// //         if (top.first != 0)
// //         {
// //             pair<int, int> temp = {0, top.second};

// //             if (path.find(temp) == path.end())
// //             {
// //                 cout << "inserting2" << temp.first << " " << temp.second << endl;
// //                 path.insert(temp);
// //                 q.push(temp);
// //             }
// //             if (temp.first + temp.second == sum)
// //             {
// //                 cout << "breaked" << endl;
// //                 break;
// //             }
// //         }
// //         if (top.second < n)
// //         {
// //             pair<int, int> temp = {top.first, n};
// //             if (path.find(temp) == path.end())
// //             {
// //                 cout << "inserting3" << temp.first << " " << temp.second << endl;

// //                 path.insert(temp);
// //                 q.push(temp);
// //             }
// //             if (temp.first + temp.second == sum)
// //             {
// //                 cout << "breaked" << endl;

// //                 break;
// //             }
// //         }
// //         if (top.second != 0)
// //         {
// //             pair<int, int> temp = {top.first, 0};
// //             if (path.find(temp) == path.end())
// //             {
// //                 cout << "inserting4" << temp.first << " " << temp.second << endl;

// //                 path.insert(temp);
// //                 q.push(temp);
// //             }
// //             if (temp.first + temp.second == sum)
// //             {
// //                 cout << "breaked" << endl;

// //                 break;
// //             }
// //         }
// //         if ((m - top.first) > 0)
// //         {
// //             pair<int, int> temp;
// //             if (top.second > (m - top.first))
// //             {
// //                 temp = make_pair(m, top.second - (m - top.first));
// //             }
// //             else
// //             {
// //                 temp = make_pair(top.first + top.second, 0);
// //             }
// //             if (path.find(temp) == path.end())
// //             {
// //                 cout << "inserting5" << temp.first << " " << temp.second << endl;

// //                 path.insert(temp);
// //                 q.push(temp);
// //             }
// //             if (temp.first + temp.second == sum)
// //             {
// //                 cout << "breaked" << endl;
// //                 break;
// //             }
// //         }
// //         if ((n - top.second) > 0)
// //         {
// //             pair<int, int> temp;
// //             if (top.first > (n - top.second))
// //             {
// //                 temp = make_pair(top.first - (n - top.second), n);
// //             }
// //             else
// //             {
// //                 temp = make_pair(0, top.second + top.first);
// //             }
// //             if (path.find(temp) == path.end())
// //             {
// //                 cout << "inserting6" << temp.first << " " << temp.second << endl;

// //                 path.insert(temp);
// //                 q.push(temp);
// //             }
// //             if (temp.first + temp.second == sum)
// //             {
// //                 cout << "breaked" << endl;
// //                 break;
// //             }
// //         }
// //     }
// // }
// // int main()
// // {
// //     // boost;
// //     int m, n, sum;
// //     cin >> m >> n >> sum;
// //     set<pair<int, int>> v;
// //     // v.push_back({0,0});
// //     BFS(m, n, sum, v);
// //     for (auto it : v)
// //         cout << it.first << " " << it.second << endl;

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// void printpath(map<pii, pii> mp, pii u)
// {
//     if (u.first == 0 && u.second == 0)
//     {
//         cout << 0 << " " << 0 << endl;
//         return;
//     }
//     printpath(mp, mp[u]);
//     cout << u.first << " " << u.second << endl;
// }
// void BFS(int a, int b, int target)
// {
//     map<pii, int> m;
//     bool isSolvable = false;
//     vector<tuple<int, int, int>> path;
//     map<pii, pii> mp;

//     queue<pii> q;

//     q.push(make_pair(0, 0));
//     while (!q.empty())
//     {

//         auto u = q.front();
//         // cout << u.first << " " << u.second << endl;
//         q.pop();
//         if (m[u] == 1)
//             continue;

//         if ((u.first > a || u.second > b || u.first < 0 || u.second < 0))
//             continue;
//         // cout << u.first << " " << u.second << endl;

//         m[{u.first, u.second}] = 1;

//         if (u.first == target || u.second == target)
//         {
//             isSolvable = true;

//             printpath(mp, u);
//             if (u.first == target)
//             {
//                 if (u.second != 0)
//                     cout << u.first << " " << 0 << endl;
//             }
//             else
//             {
//                 if (u.first != 0)
//                     cout << 0 << " " << u.second << endl;
//             }
//             return;
//         }

//         // completely fill the jug 1
//         if (m[{a, u.second}] != 1)
//         {
//             q.push({a, u.second});
//             // cout << "Pushed " << a << " " << u.second << endl;
//             mp[{a, u.second}] = u;
//         }

//         // empty the jug 1
//         if (m[{0, u.second}] != 1)
//         {
//             q.push({0, u.second});
//             // cout << "Pushed " << 0 << " " << u.second << endl;

//             mp[{0, u.second}] = u;
//         }
//         // completely fill the jug 2
//         if (m[{u.first, b}] != 1)
//         {
//             q.push({u.first, b});
//             // cout << "Pushed " << u.first << " " << b << endl;

//             mp[{u.first, b}] = u;
//         }

//         // empty the jug 2
//         if (m[{u.first, 0}] != 1)
//         {
//             q.push({u.first, 0});
//             // cout << "Pushed " << u.first << " " << 0 << endl;
//             mp[{u.first, 0}] = u;
//         }

//         //transfer jug 2 -> jug 1
//         int d = a - u.first;
//         if (u.second >= d)
//         {
//             int c = u.second - d;
//             if (m[{a, c}] != 1)
//             {
//                 q.push({a, c});
//                 // cout << "Pushed " << a << " " << c << endl;
//                 mp[{a, c}] = u;
//             }
//         }
//         else
//         {
//             int c = u.first + u.second;
//             if (m[{c, 0}] != 1)
//             {
//                 q.push({c, 0});
//                 // cout << "Pushed " << c << " " << 0 << endl;
//                 mp[{c, 0}] = u;
//             }
//         }
//         //transfer jug 1 -> jug 2
//         d = b - u.second;
//         if (u.first >= d)
//         {
//             int c = u.first - d;
//             if (m[{c, b}] != 1)
//             {
//                 q.push({c, b});
//                 // cout << "Pushed " << c << " " << b << endl;

//                 mp[{c, b}] = u;
//             }
//         }
//         else
//         {
//             int c = u.first + u.second;
//             if (m[{0, c}] != 1)
//             {
//                 q.push({0, c});
//                 // cout << "Pushed " << 0 << " " << c << endl;

//                 mp[{0, c}] = u;
//             }
//         }
//     }
//     if (!isSolvable)
//         cout << "No solution";
// }

// int main()
// {
//     int Jug1 = 4, Jug2 = 3, target = 2;
//     cout << "Path from initial state "
//             "to solution state ::\n";
//     BFS(Jug1, Jug2, target);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void printpath(map<pii, pii> mp, pii u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(mp, mp[u]);
    cout << u.first << " " << u.second << endl;
}
void BFS(int a, int b, int target)
{
    map<pii, int> m;
    bool isSolvable = false;
    vector<tuple<int, int, int>> path;
    map<pii, pii> mp;

    queue<pii> q;

    q.push(make_pair(0, 0));
    while (!q.empty())
    {

        auto u = q.front();
        // cout<<u.first<<" "<<u.second<<endl;
        q.pop();
        if (m[u] == 1)
            continue;

        if ((u.first > a || u.second > b || u.first < 0 || u.second < 0))
            continue;
        // cout<<u.first<<" "<<u.second<<endl;

        m[{u.first, u.second}] = 1;

        if (u.first == target || u.second == target)
        {
            isSolvable = true;

            printpath(mp, u);
            if (u.first == target)
            {
                if (u.second != 0)
                    cout << u.first << " " << 0 << endl;
            }
            else
            {
                if (u.first != 0)
                    cout << 0 << " " << u.second << endl;
            }
            return;
        }
        // completely fill the jug 2
        if (m[{u.first, b}] != 1)
        {
            q.push({u.first, b});
            mp[{u.first, b}] = u;
        }

        // completely fill the jug 1
        if (m[{a, u.second}] != 1)
        {
            q.push({a, u.second});
            mp[{a, u.second}] = u;
        }

        //transfer jug 1 -> jug 2
        int d = b - u.second;
        if (u.first >= d)
        {
            int c = u.first - d;
            if (m[{c, b}] != 1)
            {
                q.push({c, b});
                mp[{c, b}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{0, c}] != 1)
            {
                q.push({0, c});
                mp[{0, c}] = u;
            }
        }
        //transfer jug 2 -> jug 1
        d = a - u.first;
        if (u.second >= d)
        {
            int c = u.second - d;
            if (m[{a, c}] != 1)
            {
                q.push({a, c});
                mp[{a, c}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{c, 0}] != 1)
            {
                q.push({c, 0});
                mp[{c, 0}] = u;
            }
        }

        // empty the jug 2
        if (m[{u.first, 0}] != 1)
        {
            q.push({u.first, 0});
            mp[{u.first, 0}] = u;
        }

        // empty the jug 1
        if (m[{0, u.second}] != 1)
        {
            q.push({0, u.second});
            mp[{0, u.second}] = u;
        }
    }
    if (!isSolvable)
        cout << "No solution";
}

int main()
{
    int Jug1 = 4, Jug2 = 3, target = 2;
    cout << "Path from initial state "
            "to solution state ::\n";
    BFS(Jug1, Jug2, target);
    return 0;
}
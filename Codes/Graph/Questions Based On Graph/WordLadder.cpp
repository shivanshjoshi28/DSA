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

int WordLadder(string start, string end, set<string> &wordlist)
{
    queue<string> q;

    q.push(start);
    if (wordlist.find(end) == wordlist.end())
        return 0;
    else
    {
        int level = 0;
        q.push(start);
        while (!q.empty())
        {
            level++;
            int no_of_node_at_sameLevel = q.size();
            while (no_of_node_at_sameLevel != 0)
            {
                string topstring = q.front();
                q.pop();
                for (int i = 0; i < topstring.size(); i++) //O(n)             -->totally inside it take O(n*26*n)
                {
                    string temp = topstring;
                    for (int j = 'a'; j <= 'z'; j++) // O(26)
                    {
                        temp[i] = j;

                        if (temp.compare(topstring) == 0) // O(n)
                            continue;
                        else if (temp.compare(end) == 0) //O(n)
                            return level + 1;
                        else if (wordlist.find(temp) != wordlist.end()) //O(log n)
                        {
                            wordlist.erase(temp);
                            q.push(temp);
                        }
                    }
                }
                no_of_node_at_sameLevel--;
            }
        }
    }
    return 0;
}

int main()
{
    boost;
    string start, end;
    set<string> wordlist;
    cin >> start >> end;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        wordlist.insert(str);
    }
    cout << WordLadder(start, end, wordlist);
    return 0;
}

// Using the logic of BFS traversal
// TC: O(M *n*n*26)   M- size of input worlist ,    n= size of each word(here n= max length)
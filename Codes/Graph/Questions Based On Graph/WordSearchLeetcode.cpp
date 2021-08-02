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

class Solution
{
public:
    bool check(vector<vector<char>> board, int index, int i, int j, string word)
    {
        if (index == word.length())
        {
            return true;
        }
        cout << i << " " << j << endl;
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or board[i][j] == '0' or board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '0';
        if (check(board, index + 1, i + 1, j, word))
            return true;
        if (check(board, index + 1, i, j + 1, word))
            return true;
        if (check(board, index + 1, i - 1, j, word))
            return true;
        if (check(board, index + 1, i, j - 1, word))
            return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && check(board, 0, i, j, word))
                    return true;
            }
        }
        return false;
    }
};
class OnlineSolution
{
public:
    bool helper(int i, int j, int index, vector<vector<char>> &board, string word, vector<vector<bool>> &visited)
    {

        //successfully reached the end
        if (index == word.size())
        {
            return true;
        }
        // cout << i << " " << j << endl;

        //out of bounds
        //if the current cell has already been visited
        //the cell in board doesn't match with the current char in word
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() ||
            visited[i][j] || board[i][j] != word[index])
        {
            return false;
        }

        //marking the current cell in board as visited
        visited[i][j] = true;

        //checking resursively if the next adjacent cell contains the next character in the word
        if (helper(i + 1, j, index + 1, board, word, visited) || helper(i - 1, j, index + 1, board, word, visited) ||
            helper(i, j + 1, index + 1, board, word, visited) || helper(i, j - 1, index + 1, board, word, visited))
        {
            return true;
        }

        //backtracking
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        int rows = board.size();
        int cols = board[0].size();

        //to keep a check that we don't visit a same cell multiple times
        //to avoid infinte loop
        //initalizing the visited array to false
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        //checking if the word exists in board
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (word[0] == board[i][j] && helper(i, j, 0, board, word, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    boost;
    vector<vector<char>> board;
    vector<char> v;
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    string word = "AAAAAAAAAAAAAAB";
    OnlineSolution obj;
    cout << obj.exist(board, word);
    return 0;
}
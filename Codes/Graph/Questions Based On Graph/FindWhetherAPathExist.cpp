// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/
class Solution
{
public:
    //Function to find whether a path exists from the source to destination.
    bool DFS(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 5 || grid[x][y] == 0)
            return false;

        if (grid[x][y] == 2)
        {
            return true;
        }

        grid[x][y] = 5; // set it as 5-means visited

        if (DFS(grid, x + 1, y, m, n))
            return true;
        if (DFS(grid, x, y + 1, m, n))
            return true;
        if (DFS(grid, x - 1, y, m, n))
            return true;
        if (DFS(grid, x, y - 1, m, n))
            return true;
        return false;
    }
    bool is_Possible(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid.size();
        // bool visited(grid.size(),false);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    if (DFS(grid, i, j, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};

TC(O(n *n))
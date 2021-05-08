 // this is the algorithm that is better that naive algorithm O(m*n)............ It have reduced the complexity to O(m+n).
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void lpsArray(string pat, int *lps, int m)
{
    int i = 1;
    int len = 0;
    lps[0] = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void search(string pat, string text)
{
    int m = pat.length(), n = text.length();
    int lps[m];
    lpsArray(pat, lps, m);
    cout << "The content of the LPS array of the pattern array is :   ";
    for (auto element : lps)
        cout << element << " ";
    cout << endl;
    int i = 0, j = 0; // here i is the variable that will contain the index of text string and j variable contain the index of pattern.
    while (i < n)
    {
        if (pat[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    string text;
    cout << "Enter the text in which you wanna do search : ";
    cin >> text;
    string pat;
    cout << "Enter the pattern you want to search : ";
    cin >> pat;
    search(pat, text);

    return 0;
}
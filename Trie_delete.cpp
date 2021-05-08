#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct trie
{
    bool isend;
    struct trie *child[26];
};
struct trie *getroot()
{
    struct trie *root = new trie;
    root->isend = false;
    for (int i = 0; i < 26; i++)
    {
        root->child[i] = NULL;
    }
    return root;
}
void insert(struct trie *root, string word)
{
    struct trie *mover = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index_in_trie = word[i] - 'a';
        if (mover->child[index_in_trie] == NULL)
        {
            mover->child[index_in_trie] = getroot();
        }
        mover = mover->child[index_in_trie];
    }
    mover->isend = true;
}
bool search(struct trie *root, string tosearch)
{
    struct trie *mover = root;
    for (int i = 0; i < tosearch.length(); i++)
    {
        int index_in_trie = tosearch[i] - 'a';
        if (mover->child[index_in_trie] == NULL)
        {
            return false;
        }
        mover = mover->child[index_in_trie];
    }
    return (mover != NULL && mover->isend);
}
bool isempty(struct trie *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
            return false;
    }
    return true;
}
struct trie *remove(struct trie *root, string todelete, int depth = 0)
{
    if (!root)
        return NULL;

    if (depth == todelete.size())
    {
        if (root->isend)
            root->isend = false;
        if (isempty(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }
    int index = todelete[depth] - 'a';
    root->child[index] = remove(root->child[index], todelete, depth + 1);

    if (isempty(root) && root->isend == false)
    {
        delete root;
        root = NULL;
    }
    return root;
}
int main()
{
    int n;
    cout << "How many words you wanna insert in dictionary : ";
    cin >> n;
    string words[n];
    cout << "Enter the content of dictionary : \n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    struct trie *root = getroot();
    for (int i = 0; i < n; i++)
    {
        insert(root, words[i]);
    }
    int queries;
    cout << "Enter the no. of queries of search :: ";
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        string tosearch;
        cout << "Enter the word you want to search in the dictionary :: ";
        cin >> tosearch;
        if (search(root, tosearch))
            cout << tosearch << " is present in dictionary" << endl;
        else
        {
            cout << tosearch << " is not present in dictionary" << endl;
        }
    }
    int queriess;
    cout << "Enter the no. of queries of delete :: ";
    cin >> queriess;
    for (int i = 0; i < queriess; i++)
    {
        string todelete;
        cout << "Enter the word you want to delete from the dictionary :: ";
        cin >> todelete;
        remove(root, todelete);
    }
    return 0;
}
// Q1 .  Diff utility -- its something like git version control system . 
// s1 = "dsfdsasdgssf"
// s2= "sdfabfdsbtryrerwrewg"
// then we first find LCS and then we can check how many character are deleted in first and inserted in second . 
// m= length of first string 
// n= lenght of second string 
// then no. of deleted   m-ans;
// then no. of added    n-ans 




// Q2. Minimum insertion and deletion to convert s1 into s2;

// we get answer of this question by finding the LCS and then using that we 
// final an s= m-ans+ n-ans;


// Q3. Shortest common supersequence 
// it is basically the shortest string that contain both s1 and s2 as subsequence in in
// we can find this easily by LCS 
// first find LCS , then loop through both string , and keep concatinating the character that is not present in LCS. respectively



// Q4 . Longest Palindromic subsequence
// first find the LCS by using the string s and string ( rev of s )
// the LCS is the answer 

// Q5. Longest Repeating subsequence
// ex - s1= "aabb", so here ans is "ab", as it is repeating in the string 


// int TabulationDP(string s1,string s2,int m,int n)
// {
//     vector<vector<int>>table(m+1,vector<int>(n+1,-1));
//     for(int i=0;i<=m;i++) table[i][0]=0;
//     for(int j=0;j<=n;j++) table [0][j]=0;
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(s1[i-1]==s2[j-1] and i!=j)
//             {
//                 table[i][j]=table[i-1][j-1]+1;
//             }
//             else
//             {
//                 table[i][j]=max(table[i-1][j],table[i][j-1]);
//             }
//         }
//     }
//     return table[m][n];
// }



// Q6. space optimised solution for LCS 



// Q7 . printing LCS 
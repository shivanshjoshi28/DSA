// Q1. Building bridge
// ex - [(6,2),(4,3),(2,6),(1,5)]

// o/p - 2
// no bridge cross each other
// ->sort the array in increasing order of first value of pair
// if the first value are same like (2,6) and (2,3),then sort according to first _INLINE_VARIABLES_SUPPORTED
//  -> find the LIS of the sorted array according to second values



// Q2. Longest chain of pairs 
// i/p - (5,24),(39,60),(15,28),(27,40),(50,90)
// o/p - 3

// -> sort the array of pair according to first value
// -> find the lcs of the array with condition that arr[i].first> arr[j].second
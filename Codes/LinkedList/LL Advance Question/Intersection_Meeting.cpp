// wap to find the  node where the linked list meeet

// solution 1 : Using hashset of Node * type and insert all the Node of LL 1 and then iterate throught the node of LL2 ,
// find  the first node that is already present in hashset

// Solution 2 : LL1 size = n1 , LL2 size= n2     find abs(n1-n2)       , now move the iterator from starting of long LL to abs(n1-n2) step forward
// and then use the two pointer and move through both the LL at same time and check for their equality

// wap to segregate even and odd in the LL
#include<iostream>

using namespace std;

#include "BinarySearchTree.h"

int main()
{
    auto bst = new BinarySearchTree<int>;

    bst->Insert(10);
    bst->Insert(5);
    bst->Insert(20);
    bst->Insert(30);
    bst->Insert(8);
    bst->Insert(2);
    bst->Search(2);
    bst->Search(8);
    bst->Search(30);
    bst->Search(99999);
    return 0;
}

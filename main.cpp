#include<iostream>

using namespace std;

#include "BinarySearchTree.h"

int main()
{
    Node<int>* n = nullptr;
    auto bst = new BinarySearchTree<int>;

    n = bst->Insert(n, 10);
    n = bst->Insert(n, 20);
    n = bst->Insert(n, 5);
    n = bst->Insert(n, 30);
    n = bst->Insert(n, 8);
    bst->Search(n, 30);
    bst->Search(n, 8);
    bst->Search(n, 99);

    n = bst->Delete(n, 20);
    n = bst->Delete(n, 5);

    return 0;
}

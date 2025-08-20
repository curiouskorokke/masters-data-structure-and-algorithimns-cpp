#include<iostream>

using namespace std;

#include "BinarySearchTree.h"
#include "TreeNode.h"

int main()
{
    TreeNode<int>* n = nullptr;
    auto bst = new BinarySearchTree<int>;

    // n = bst->Insert(n, 10);
    // n = bst->Insert(n, 20);
    // n = bst->Insert(n, 5);
    // n = bst->Insert(n, 30);
    // n = bst->Insert(n, 8);
    // bst->Search(n, 30);
    // bst->Search(n, 8);
    // bst->Search(n, 99);
    //
    // n = bst->Delete(n, 20);
    // n = bst->Delete(n, 5);


    auto newTree = new TreeNode<int>;
    newTree = nullptr;
    int preorderArr[] = {
        30, 20, 10, 15, 25, 40, 50, 45
    };


    newTree = bst->GenerateFromPreorder(newTree, preorderArr, 8);
    delete newTree;
    return 0;
}

#include<iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree<int>* t = new Tree<int>;
    t->Create(t);

    cout<<"Preorder: ";
    t->Preorder(t);
    cout<<endl;
    cout<<"Inorder: ";
    t->Inorder(t);
    cout<<endl;
    cout<<"Postorder: ";
    t->Postorder(t);
    cout<<endl;

    delete t;

    return 0;
}

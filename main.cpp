#include<iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<int>* t = new Tree<int>;
    t->Create(t);

    Stack<Tree<int>*>* st = new Stack<Tree<int>*>;
    cout << "Preorder: ";
    t->Preorder(t, st);
    cout << endl;

    cout << "Inorder: ";
    t->Inorder(t, st);
    cout << endl;

    cout << "Postorder: ";
    t->Postorder(t, st);
    cout << endl;

    Queue<Tree<int>*>* q = new Queue<Tree<int>*>;

    cout <<"Level Order: ";
    t->LevelOrder(t,q);
    cout<<endl;


    delete t;
    delete st;

    return 0;
}

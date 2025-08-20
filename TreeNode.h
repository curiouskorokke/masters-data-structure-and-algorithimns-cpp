//
// Created by Nicholas  Ng on 19/08/2025.
//

#ifndef NODE_H
#define NODE_H
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode();
    ~TreeNode();
};

template <typename T>
TreeNode<T>::TreeNode()
{
    lChild = nullptr;
    rChild = nullptr;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
    delete lChild;
    delete rChild;
}
#endif //NODE_H

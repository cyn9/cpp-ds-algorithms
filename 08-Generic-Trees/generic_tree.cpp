#include <iostream>
#include <vector>

template<typename T>
struct TreeNode {
    T data;
    std::vector<TreeNode<T> *> children;

    TreeNode() : TreeNode(0) {}
    TreeNode(T data) : data {data} {}


};

int main() {
    TreeNode<int>* root  = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    delete[] root;
    delete[] node1;
    delete[] node2;

    return 0;
}
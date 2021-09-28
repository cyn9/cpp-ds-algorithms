#include <iostream>
#include <vector>

template<typename T>
struct TreeNode {
    T data;
    std::vector<TreeNode<T> *> children;

    TreeNode() : TreeNode(0) {}
    TreeNode(T data) : data {data} {}
};

template<typename T>
void printTree(const TreeNode<T> *root) {
    // Check if tree is empty (root is nullptr?)
    if (!root) {
        std::cout << "Tree is empty.\n";
        return;
    }

    std::cout << root->data << ": ";
    for (std::size_t i = 0; i < root->children.size(); ++i) {
        std::cout << root->children[i]->data << ' ';
    }

    std::cout << '\n';

    for (std::size_t i = 0; i < root->children.size(); ++i) {
        printTree(root->children.at(i));
    }
}

/* Tree example 1:
      1
    /   \
   2     3

   Tree example 2:
      10
       \
        20
         \
          30

   Tree example 3:
       root = nullptr
*/ 
int main() {
    // Tree example 1:
    std::cout << "Tree example 1: \n";
    TreeNode<int>* root1 = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root1->children.push_back(node1);
    root1->children.push_back(node2);
    printTree(root1);

    // Tree example 2:
    std::cout << "\nTree example 2: \n";
    TreeNode<float>* root2 = new TreeNode<float>(10.0f);
    TreeNode<float>* n1 = new TreeNode<float>(20.0f);
    TreeNode<float>* n2 = new TreeNode<float>(30.0f);

    root2->children.push_back(n1);
    n1->children.push_back(n2);
    printTree(root2);

    // Tree example 3:
    std::cout << "\nTree example 3: \n";
    TreeNode<double>* root3 = nullptr;
    printTree(root3);

    // Memory cleanup:
    delete root1;
    delete root2;
    delete root3;

    delete node1;
    delete node2;
    delete n1;
    delete n2;

    return 0;
}

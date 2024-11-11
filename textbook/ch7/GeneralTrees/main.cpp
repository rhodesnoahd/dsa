#include "GeneralTree.h"

int main() {
  /** build the following tree:
   *                 0
   *               /   \
   *             [1,    2]
   *             /     /|\
   *           [5]   [7,9,3]
   *                   / \
   *                 [6,  4]
   */
  Tree<int> tree(0);

  tree.root->addChild(1);
  tree.root->addChild(2);

  tree.root->children.at(0)->addChild(5);
  tree.root->children.at(1)->addChild(7);
  tree.root->children.at(1)->addChild(9);
  tree.root->children.at(1)->addChild(3);

  tree.root->children.at(1)->children.at(1)->addChild(6);
  tree.root->children.at(1)->children.at(1)->addChild(4);

  // print
  cout << "Depth of root: " << tree.depth(tree.root.get()) << std::endl; // 0
  cout << "Depth of node 7: " << tree.depth(tree.root->children.at(1)->children.at(0).get()) << std::endl; // 2
  cout << "Height of root: " << tree.height(tree.root) << std::endl; // 3
  tree.preorderTraversal(); // 0 1 5 2 7 9 6 4 3 
  tree.postorderTraversal(); // 5 1 7 6 4 9 3 2 0
};
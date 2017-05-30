/**
* Definition for a binary tree node.
*/

#include "iostream"
#include <queue>
#include <stack>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BinTreeSolution {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> v;
    std::stack<const TreeNode *> s;
    const TreeNode *p = root;
    while (!s.empty() || p != NULL) {
      if (p != NULL) {
        s.push(p);
        p = p->left;
      } else {
        p = s.top();
        s.pop();
        v.push_back(p->val);
        p = p->right;
      }
    }
    return v;
  }
  std::vector<int> preorderTraversal(TreeNode *head) {
    std::vector<int> result;
    const TreeNode *p = head;
    std::stack<const TreeNode *> s;
    while (p != NULL || !s.empty()) {
      if (p != NULL) {
        result.push_back(p->val);
        s.push(p);
        p = p->left;
      } else {
        p = s.top();
        s.pop();
        p = p->right;
      }
    }
    return result;
  }
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> result;
    std::stack<const TreeNode *> s;
    const TreeNode *p = root;
    const TreeNode *q = NULL;
    do {
      while (p != NULL) {
        s.push(p);
        p = p->left;
      }
      q = NULL;
      while (!s.empty()) {
        p = s.top();
        if (p->right == q) {
          s.pop();
          result.push_back(p->val);
          q = p;
        } else {
          p = p->right;
          break;
        }
      }
    } while (!s.empty());

    return result;
  }
  TreeNode *getRightLeafNode(TreeNode *root) {
    if (root->right) {
      getRightLeafNode(root->right);
    } else {
      return root;
    }
  }
  std::vector<std::vector<int> > levelOrderTraversal2(TreeNode *root) {
    const TreeNode *p = root;
    std::vector<std::vector<int> > result;
    std::queue<const TreeNode *> current, next;
    if (p != NULL) {
      current.push(p);
    }
    while (!current.empty()) {
      std::vector<int> level;
      while (!current.empty()) {
        p = current.front();
        current.pop();
        level.push_back(p->val);
        if (p->left) {
          next.push(p->left);
        }
        if (p->right) {
          next.push(p->right);
        }
      }
      result.push_back(level);
      swap(current, next);
    }
    return result;
  }

  std::vector<int> levelOrderTraversal(TreeNode *head) {
    const TreeNode *p = head;
    std::vector<int> result;
    std::queue<const TreeNode *> q;
    if (p != NULL) {
      q.push(p);
    }
    while (!q.empty()) {
      p = q.front();
      q.pop();
      result.push_back(p->val);
      if (p->left) {
        q.push(p->left);
      }
      if (p->right) {
        q.push(p->right);
      }
    }
    return result;
  }
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    if (root->left) {
      if (root->right) {
        flatten(root->right);
      }
      getRightLeafNode(root->left)->right = root->right;
      root->right = root->left;
      flatten(root->left);
      root->left = NULL;
    }
  }

  void travelTree(TreeNode *root) {
    /*TreeNode *pnode, *lnode, *rnode;*/
    if (root) {
      std::cout << root->val << std::endl;
      travelTree(root->left);
      travelTree(root->right);
    }
  }

  void destoryTree(TreeNode *node) {

    if (node) {
      destoryTree(node->left);
      destoryTree(node->right);
      delete node;
    }
  }
};
int main(int argc, char **argv) {
  TreeNode *root = new TreeNode(0);
  TreeNode *pNode = root;
  const int length = 4;
  int acc = 0;
  for (size_t i = 0; i < length; i++) {
    acc++;
    TreeNode *ln = new TreeNode(acc);
    acc++;
    TreeNode *rn = new TreeNode(acc);
    pNode->left = ln;
    pNode->right = rn;

    pNode = ln;
  }
  BinTreeSolution BTS;
  std::cout << "pre order Traversal" << std::endl;
  std::vector<int> vp = BTS.preorderTraversal(root);
  for (size_t i = 0; i < vp.size(); i++) {
    std::cout << vp[i] << std::endl;
  }
  std::cout << "recurrent pre order traversal" << std::endl;
  BTS.travelTree(root);
  std::cout << "in order Traversal " << std::endl;
  std::vector<int> v = BTS.inorderTraversal(root);
  std::cout << "level order traversal" << std::endl;
  std::vector<int> vl = BTS.levelOrderTraversal(root);
  for (size_t i = 0; i < vl.size(); i++) {
    std::cout << vl[i] << std::endl;
  }
  std::cout << "post order Traversal" << std::endl;
  std::vector<int> vpost = BTS.postorderTraversal(root);
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }
  BTS.flatten(NULL);
  BTS.destoryTree(root);

  return 0;
}

#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void inorder_recursive(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_recursive(root->left);
    cout << root->data << " ";
    inorder_recursive(root->right);
}
void inorder_iterative(node *root)
{
    stack<node *> s;
    node *cur = root;
    while (!s.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            s.pop();
            cout << cur->data << " ";
            cur = cur->right;
        }
    }
}
int main()
{
    /*
        1
      /  \
      2   3
     / \   \
    4   5   6 
     */
    node *a = new node(1);
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;
    cout << "from iterative method" << endl;
    inorder_iterative(a);
    cout << endl;
    cout << "from recursive method" << endl;
    inorder_recursive(a);
    return 0;
}
/*
Problem: Return an array of the values of all nodes that have
a distance k from the target node.
*/

/*-------------------------
Recursive Solution
Time Complexity: O(n)
---------------------*/

#include <iostream>
#include <vector>
using namespace std;

// Basic Structure of a tree
class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    void insert(Node *&root, int data)
    {

        if (root == NULL)
            root = new Node(data);
        else if (root->data > data)
            insert(root->left, data);
        else
            insert(root->right, data);
    }
    vector<int> v;
    void kdown(Node *root, Node *block, int k)
    {
        if (root == NULL or root == block or k < 0)
        {
            return;
        }
        if (k == 0)
        {
            v.push_back(root->data);
            return;
        }
        kdown(root->left, block, k - 1);
        kdown(root->right, block, k - 1);
    }
    int k_help(Node *root, Node *target, int k)
    {
        if (root == NULL)
            return -1;
        if (root == target)
        {
            kdown(root, NULL, k);
            return 1;
        }
        int ld = k_help(root->left, target, k);
        if (ld != -1)
        {
            kdown(root, root->left, k - ld);
            return 1 + ld;
        }
        int rd = k_help(root->right, target, k);
        if (rd != -1)
        {
            kdown(root, root->right, k - rd);
            return 1 + rd;
        }
        return -1;
    }
    vector<int> distanceK(Node *root, Node *target, int k)
    {
        k_help(root, target, k);
        return v;
    }
};

int main()
{
    // User Input
    Node *root = NULL;
    Node *tar;
    int n, num, tar, k;
    cout << "Enter the Number of nodes :";
    cin >> n;
    cout << "\nEnter the value of the nodes :";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        root->insert(root, num);
    }
    cout << "\nEnter the target value :" << tar;
    cout << "Enter the distance you to search :" << k;
    vector<int> v = root->distanceK(root, tar, k);
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}

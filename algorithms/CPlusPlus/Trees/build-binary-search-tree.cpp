#include<iostream>
using namespace std;

struct BSTNode
{
  int data;
  BSTNode* left;
  BSTNode* right;
};

BSTNode* GetNewNode(int data)
{
  BSTNode* newNode = new BSTNode();
  newNode -> data = data;
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}

BSTNode* Insert(BSTNode* root, int data)  
{
  if(root == NULL)  
  {
    root = GetNewNode(data); 
  }
  else if(data <= root -> data)
  {
    root -> left = Insert(root -> left, data);  
  }
  else
  {
    root -> right = Insert(root -> right, data);
  }
  return root;
}

bool Search(BSTNode* root, int data)
{
  if(root == NUL)
    return false;
  else if(root -> data == data)
    return true;
  else if(data <= root -> data)
    return Search(root -> left, data);
  else
    return Search(root -> right, data);
}

int main()
{
  BSTNode* root = NULL;
  root = Insert(root, 15);  
  root = Insert(root, 10); 
  root = Insert(root, 20);  
  root = Insert(root, 25);  
  root = Insert(root, 8);  
  root = Insert(root, 12);  
  
  int number;
  cout << "Enter number be searched\n";
  cin >> number;
  
  if(Search(root, number) == true)
    cout << "Found" << endl;
  else
    cout << "Not found" << endl;
}

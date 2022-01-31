//Credits to my peer, Nicolas, for his AVL tree implementation, and 
//Professor Aman for his main function. I simply made the wrapper 
//class for the ordered map. See my implementation of the AVL tree.

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>
#include <cctype>
using namespace std;

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    int height = 0;
    string name = "";
};

class AVLTree {
    Node* root;
    int getHeight(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* leftRightRotate(Node* node);
    Node* rightLeftRotate(Node* node);
    Node* insertHelper(Node* root, string _name, int idNum, bool& insertSuccessful);
    Node* removeHelper(Node* root, long id, bool& removeSuccessful);
    vector<Node*> inOrderR(Node* root, vector<Node*>& nodes);
    Node* removeInorderHelper(Node* root, int N, vector<Node*>& nodes);
public:
    AVLTree() {
        root = NULL;
    }
    ~AVLTree() {
        delete root;
    }
    //Getters
    Node* getRoot() {
        return root;
    }
    //Other Functions
    bool insert(string _name, string id);
    bool remove(string id);
    //void search(long id);
    Node* searchIDHelper(Node* root, string id);
    int preOrder(Node* root, string _name, int& on);
    void search(Node* root, string _name, int& on);
    void printInorder(Node* root);
    void printPostorder(Node* root);
    string printPreorder(Node* root, string& output3);
    void printLevelCount(Node* root);
    void removeInorder(int N, vector<Node*>& nodes);
};


//function get height implemented from an idea from Geeks for geeks to get the height of a BST
int AVLTree::getHeight(Node* node) {
    int height = 0;
    if (node == NULL) {
        height = 0;
        return height;
    }
    else {
        return node->height;
    }
}

//Function to calculate the maximum value between two values
int maxVal(int uno, int dos) {
    if (uno > dos) {
        return uno;
    }
    else {
        return dos;
    }
}

//Rotations, idea used from Geeks for Geeks implemented to be used for AVL Trees for all rotations
Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    Node* rightNewRoot = newRoot->right;
    //Rotation
    newRoot->right = node;
    node->left = rightNewRoot;

    //Update Height of node and newRoot
    node->height = maxVal(getHeight(node->left), getHeight(node->right) + 1);
    newRoot->height = maxVal(getHeight(newRoot->left), getHeight(newRoot->right) + 1);

    return newRoot;
}
//Rotations, idea used from Geeks for Geeks implemented to be used for AVL Trees for all rotations
Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    Node* leftNewRoot = newRoot->left;
    //Rotation
    newRoot->left = node;
    node->right = leftNewRoot;

    //Update Height
    node->height = maxVal(getHeight(node->left), getHeight(node->right) + 1);
    newRoot->height = maxVal(getHeight(newRoot->left), getHeight(newRoot->right) + 1);

    return newRoot;
}

Node* AVLTree::leftRightRotate(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* AVLTree::rightLeftRotate(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Insert node containing name and id (and maybe more) into tree
// Cited from Geeks for Geeks, ideas used from AVL trees
Node* AVLTree::insertHelper(Node* root, string _name, int idNum, bool& insertSuccessful) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->val = idNum;
        newNode->name = _name;
        newNode->left, newNode->right = NULL;
        newNode->height = 1;
        //Print out successful
        insertSuccessful = true;
        //This count keeps track of how many commas we will need for printing
        return newNode;
    }

    if (idNum < root->val) {
        root->left = insertHelper(root->left, _name, idNum, insertSuccessful);
        //balance?
    }
    else if (idNum > root->val) {
        root->right = insertHelper(root->right, _name, idNum, insertSuccessful);
        //balance?
    }
    else {
        //Means the root repeated
        insertSuccessful = false;
        return root;
    }

    //Update the overall Height
    int maxValLocal = maxVal(getHeight(root->left), getHeight(root->right));
    root->height = maxValLocal + 1;

    //Check to ensure balance
    int factor = 0;
    if (root == NULL) {
        //factor
        factor = 0;
    }
    else {
        //factor
        factor = getHeight(root->left) - getHeight(root->right);
    }

    if (root->left != nullptr) {
        //Left Left = right rotation
        if (idNum < root->left->val && factor > 1) {
            return rotateRight(root);
        }
        //Left right = left right rotate
        //factor
        if (idNum > root->left->val && factor > 1) {
            return leftRightRotate(root);
        }
    }
    if (root->right != nullptr) {
        //Right Right = left rotation
        //factor
        if (idNum > root->right->val && factor < -1) {
            return rotateLeft(root);
        }
        //Right left = right left rotate
        //factor
        if (idNum < root->right->val && factor < -1 && root->right != nullptr) {
            return rightLeftRotate(root);
        }
    }

    //Then we can return the root
    return root;
}

bool AVLTree::insert(string _name, string id) {
    bool insertSuccessful = false;
    int idNum = stoi(id);
    root = insertHelper(root, _name, idNum, insertSuccessful);
    return insertSuccessful;
}

//Code cited and used from Geeks for Geeks, ideas used to implement remove function for AVL tree
//The tree is already balanced, so using the BST tree delete is fine here. Ideas such as "free" were used, as well as the algorithm for removing objects from the tree.
Node* AVLTree::removeHelper(Node* root, long id, bool& removeSuccessful) {
    if (root == NULL) {
        /*if (root->height == 1) {
            cout << "successful" << endl;
        }*/
        removeSuccessful = false;
        return root;
    }
    if (id < root->val) {
        root->left = removeHelper(root->left, id, removeSuccessful);
    }
    else if (id > root->val) {
        root->right = removeHelper(root->right, id, removeSuccessful);
    }
    else if (id == root->val) {
        //No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            removeSuccessful = true;
        }
        //Uno Chil'ren
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
            removeSuccessful = true;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
            removeSuccessful = true;
        }
        //Two Children
        else {
            Node* newTemp = root->right;
            while (newTemp != NULL && newTemp->left != NULL) {
                //traverse left to find the smallest in order value
                newTemp = newTemp->left;
            }
            Node* found = newTemp;
            root->val = found->val;
            root->name = found->name;
            root->right = removeHelper(root->right, found->val, removeSuccessful);
        }
    }
    else {
        removeSuccessful = false;
    }
    return root;
}

bool AVLTree::remove(string idString) {
    int id = stoi(idString);
    bool removeSuccessful = false;
    root = removeHelper(root, id, removeSuccessful);
    return removeSuccessful;
}

Node* AVLTree::searchIDHelper(Node* root, string id) {
    int idNumerical = stoi(id);
    Node* temp = root;
    while (temp != NULL) {
        if (idNumerical == temp->val) {
            return temp;
        }
        else if (idNumerical < temp->val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    //We get here if we cant find anything
    return root;
}

//***Changed to inorder instead of preorder
int AVLTree::preOrder(Node* root, string _name, int& on) {
    if (root != NULL) {
        preOrder(root->left, _name, on);
        if (root->name == _name) {
            on = 1;
            cout << root->val << endl;
        }
        preOrder(root->right, _name, on);
    }
    return on;
}

void AVLTree::search(Node* root, string _name, int& on) {
    if (root == NULL) {
        cout << "unsuccessful" << endl;
        return;
    }
    on = preOrder(root, _name, on);
    if (on == 0) {
        cout << "unsuccessful" << endl;
    }
}
//Print outs
void AVLTree::printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        printInorder(root->left);
        if (root->left != NULL) {
            cout << ", ";
        }
        cout << root->name;
        if (root->right != NULL) {
            cout << ", ";
        }
        printInorder(root->right);
    }
}

void AVLTree::printPostorder(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        printPostorder(root->left);
        if (root->left != NULL) {
            cout << ", ";
        }
        printPostorder(root->right);
        if (root->right != NULL) {
            cout << ", ";
        }
        cout << root->name;
    }
}

string AVLTree::printPreorder(Node* root, string& output3) {
    
    if (root == NULL) {
        return output3;
    }
    else {
        output3 += root->name;
        if (root->left != NULL || root->right != NULL) {
            output3 += ", ";
        }
        printPreorder(root->left, output3);
        if (root->left != NULL && root->right != NULL) {
            output3 += ", ";
        }
        printPreorder(root->right, output3);
    }
    return output3;
}

void AVLTree::printLevelCount(Node* root) {
    if (root == NULL) {
        cout << "0" << endl;
    }
    else {
        //had root->height - 1 here ori
        cout << root->height;
    }
}

//Helper function for removeInorder
vector<Node*> AVLTree::inOrderR(Node* root, vector<Node*>& nodes) {
    if (root != NULL) {
        inOrderR(root->left, nodes);
        nodes.push_back(root);
        inOrderR(root->right, nodes);
    }
    return nodes;
}

//Function that utilizes the remove function to remove nodes in the tree in an IN ORDER function
Node* AVLTree::removeInorderHelper(Node* root, int N, vector<Node*>& nodes) {
    bool found = false;
    long foundID;
    Node* result;
    nodes = inOrderR(root, nodes);
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (i == N) {
            found = true;
            foundID = nodes.at(i)->val;
        }
    }
    if (found) {
        bool noIdea = false;
        result = removeHelper(root, foundID, noIdea);
        return result;
    }
    else {
        cout << "unsuccessful" << endl;
    }
}

void AVLTree::removeInorder(int N, vector<Node*>& nodes) {
    root = removeInorderHelper(root, N, nodes);
}

//---------------------------------------------------------------------------------------

class OrderedMap
{
private:
    //create an object of the AVL Tree which your peer implemented 
    AVLTree newTree;

public:
    OrderedMap();
    ~OrderedMap();
    bool insert(const std::string ID, const std::string NAME);
    std::string search(const std::string ID);
    std::string traverse();
    bool remove(const std::string ID);
};


OrderedMap::OrderedMap()
{
    //code here
}

OrderedMap::~OrderedMap()
{
    //code here
}

bool OrderedMap::insert(const std::string ID, const std::string NAME)
{
    return newTree.insert(NAME, ID);
}

std::string OrderedMap::search(const std::string ID)
{
    string outputSearch = "";
    int idAsNum = stoi(ID);

    Node* result = newTree.searchIDHelper(newTree.getRoot(), ID);

    if (result == NULL) {
        outputSearch = "";
    }
    else if (result == result && result->val != idAsNum) {
        outputSearch = "";
    }
    else {
        outputSearch = result->name;
    }

    return outputSearch;
}

std::string OrderedMap::traverse()
{
    string output3 = "";
    output3 = newTree.printPreorder(newTree.getRoot(), output3);
    return output3;
}

bool OrderedMap::remove(const std::string ID)
{
    //code here
    return newTree.remove(ID);
}

//Do not change main() 
int main()
{
    OrderedMap myMap;
    int lines = 0;
    std::string command = "", ufid = "", name = "";
    std::cin >> lines;
    while (lines--)
    {
        std::cin >> command;
        if (command == "insert")
        {
            std::cin >> ufid >> name;
            std::cout << myMap.insert(ufid, name) << "\n";
        }
        else if (command == "search")
        {
            std::cin >> ufid;
            std::cout << myMap.search(ufid) << "\n";
        }
        else if (command == "traverse")
        {
            std::cout << myMap.traverse() << "\n";
        }
        else if (command == "remove")
        {
            std::cin >> ufid;
            std::cout << myMap.remove(ufid) << "\n";
        }
    }

    return 0;
}
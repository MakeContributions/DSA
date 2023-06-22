#include <iostream>
#include <vector>
#include <cmath>

/**
 * Heap operation are defined with node pointer to allow
 * decrease key to be called with the given node.
 */


struct Node
{
    int key;
    int degree;
    bool mark;
    int data; // an extra field, not required for implementation
    Node* left;
    Node* right;
    Node* parent;
    Node* child;

    Node(int key): key(key){};
    Node(int key, int data): key(key), data(data){};

    friend std::ostream& operator<<(std::ostream& os, const Node &n){
        os << "{ " 
           << "key: " << n.key << " ; "
           << "degree: " << n.degree << "; "
           << "mark: " << n.mark << "; "
           << "data: " << n.data << "; "
           << "left: " << (n.left == nullptr? -1: n.left->data) << "; "
           << "right: " << (n.right == nullptr? -1: n.right->data) << "; "
           << "parent: " << (n.parent == nullptr? -1: n.parent->data) << "; "
           << "child: " << (n.child == nullptr? -1: n.child->data) << "; "
           << " }";

        return os;
    }
};

class FibonacciHeap
{
private:
    Node* _mn;
    int _length;

    /**
     * @brief inserts a node to rootlist after given node
     * 
     * @param after 
     * @param toInsert 
     */
    void _insertTORootListAfterNode(Node *after, Node *toInsert){
        if(after->right == after){
            //after ----> after toInsert
            toInsert->right = toInsert->left = after;
            after->right = after->left = toInsert;
            return ;
        }
        // after next
        // after toInsert next
        toInsert->left = after;
        toInsert->right = after->right;

        toInsert->left->right = toInsert;
        toInsert->right->left = toInsert;
    }

    /**
     * @brief removes the given node from rootlist
     * but it still contains reference to its neighbours
     * 
     * @param toDelete 
     * @return Node* 
     */
    Node* _removeNodeFromRootList(Node *toDelete){
        auto left = toDelete->left;

        if(toDelete == left) // only one child left
            left = nullptr;
        else if(toDelete->right == toDelete->left){ // only two child left
            // cld left ---> left
            left->left = left;
            left->right = left;
        }
        else{ // if at least three child is there
            // left cld right
            // left right
            toDelete->left->right = toDelete->right;
            toDelete->right->left  = toDelete->left;
        }

        toDelete->parent = nullptr;
        return left;
    }

    /**
     * @brief inserts all child node of parent node to same rootlist
     * the parent exists
     * 
     * @param parent 
     */
    void _insertChildOfNodeToRootList(Node* parent){
        for(auto cld = parent->child; cld != nullptr;){
            auto left = _removeNodeFromRootList(cld);
            _insertTORootListAfterNode(parent, cld);
            cld = left;
        }
    }

    /**
     * @brief inserts a new child at root list after insertAt
     * 
     * @param insertAt 
     * @param toInsert 
     * @return Node* insertAt node is changed in the function call
     * so it is recommanded to assign to the return value;
     */
    Node* _insertNewChildAtRootList(Node* insertAt, Node* toInsert){
        if(insertAt == nullptr){
            insertAt = toInsert;
            insertAt->right = toInsert;
            insertAt->left  = toInsert;
        }
        else{
            _insertTORootListAfterNode(insertAt, toInsert);
        }

        return insertAt;
    }
    
    /**
     * @brief links child a children of parent and performs
     * associated links
     * 
     * @param parent 
     * @param child 
     * @return Node* 
     */
    Node* _fibHeapLink(Node* parent, Node* child){
        _removeNodeFromRootList(child);

        child->parent = parent;
        parent->child = _insertNewChildAtRootList(parent->child, child);

        child->mark = false;
        parent->degree ++;

        return parent;
    }

    /**
     * @brief consolidates the fibonacchi heap
     * 
     */
    void _consolidate(){
        std::vector<Node *> roots;
        roots.push_back(_mn);
        for(auto cur = _mn->right; cur != _mn ;cur = cur->right){
            roots.push_back(cur);
        }

        int upper_bound = log2(_length) + 2;
        std::vector<Node *> array(upper_bound, nullptr);
        for(auto cur : roots){
            auto z = cur;
            int d = cur->degree;
            while(array[d] != nullptr){
                auto y = array[d];

                if(z->key <= y->key) z = _fibHeapLink(z, y);
                else z = _fibHeapLink(y, z);

                array[d] = nullptr;

                d++;
            }

            array[d] = z;
        }

        _mn = nullptr;
        for(auto node: array){
            if(node == nullptr) continue;

            _mn = _insertNewChildAtRootList(_mn, node);
            if(_mn->key > node->key){
                _mn = node;
            }
        }
        
    }

    void _cut(Node* parent, Node* node){
        parent->child = _removeNodeFromRootList(node);
        if(parent->child)
            parent->child->parent = parent;
        parent->degree--;

        _insertTORootListAfterNode(_mn, node);
        node->parent = nullptr;
        node->mark = false;
    }

    void _cascadingCut(Node* parent){
        auto grandP = parent->parent;
        if(grandP != nullptr){
            if(parent->mark == false) parent->mark = true;
            else {
                _cut(grandP, parent);
                _cascadingCut(grandP);
            }
        }
    }

    void _printHelper(std::ostream& os, Node *n, int tab){
        if(n == nullptr) return ;

        for(int i = 0; i < tab; i++) os << "\t";
        os << *n << std::endl;
        _printHelper(os, n->child, tab+1);
        
        for(auto cur = n->right; cur != n; cur = cur->right){
            for(int i = 0; i < tab; i++) os << "\t";
            os << *cur << std::endl;
            _printHelper(os, cur->child, tab+1);
        }
    }

public:
    FibonacciHeap(/* args */);
    ~FibonacciHeap();

    void insert(Node *toInsert){
        toInsert->degree = 0;
        toInsert->mark = false;
        toInsert->parent = nullptr;
        toInsert->child = nullptr;

        _mn = _insertNewChildAtRootList(_mn, toInsert);
        if(_mn->key > toInsert->key){
            _mn = toInsert;
        }
        
        _length++;
    }

    void pop(){
        if(_mn != nullptr){
            _insertChildOfNodeToRootList(_mn);
            _removeNodeFromRootList(_mn);
            
            if(_mn->left == _mn){
                _mn = nullptr;
            }else{
                _mn = _mn->right;
                _consolidate();
            }

            _length--;
        }
    }

    Node* top(){
        return _mn;
    }

    int length(){
        return _length;
    }

    void decreaseKey(Node* node, int k){
        if(node->key <= k) {
            std::cerr << "node->key <= k" << std::endl;;
            return ;
        }

        node->key = k;
        auto parent = node->parent;
        if(parent != nullptr && node->key < parent->key){
            _cut(parent, node);
            _cascadingCut(parent);
        }

        if(node->key < _mn->key){
            _mn = node;
        }
    }

    

    friend std::ostream& operator<<(std::ostream& os, FibonacciHeap &f){
        os << "====================================================" << std::endl;

        if(f._mn == nullptr) os << "null" << std::endl;
        os << "length : " << f._length << std::endl;

        f._printHelper(os, f._mn, 0);

        os << "====================================================" << std::endl;
        return os;
    }
};

FibonacciHeap::FibonacciHeap(/* args */)
{
    _mn = nullptr;
    _length = 0;
}

FibonacciHeap::~FibonacciHeap()
{
}


int main(int argc, char const *argv[])
{
    FibonacciHeap fh;
    Node *node1 = new Node(10, 5);
    Node *node2 = new Node(20, 5);
    Node *node3 = new Node(30, 5);

    fh.insert(node1);
    fh.insert(node2);
    fh.insert(node3);

    std::cout << fh << std::endl;
    std::cout << "Top : " << *fh.top() << std::endl;

    fh.decreaseKey(node3, 5);
    std::cout << fh << std::endl;
    std::cout << "Top : " << *fh.top() << std::endl;

    fh.pop();
    std::cout << fh << std::endl;
    std::cout << "Top : " << *fh.top() << std::endl;

    fh.pop(); fh.pop();
    std::cout << fh << std::endl;

    delete node1;
    delete node2;
    delete node3;
}
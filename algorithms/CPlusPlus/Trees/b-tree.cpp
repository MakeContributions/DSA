#include<iostream>
using namespace std;

template <class T>
class BTreeNode
{
    T* keys;
    int Min_Child;
    int order;
    BTreeNode** children;
    int num_keys;
    bool leaf;
public:
    BTreeNode(bool _leaf, int m)
    {
        Min_Child = roundUp(m);
        leaf = _leaf;
        order = m;
        keys = new T[order - 1];
        children = new BTreeNode * [order];
        num_keys = 0;
    }

    void insertNonFull(int v)
    {
        int index = num_keys - 1;

        if (leaf)
        {
            while (index >= 0)
            {
                if (keys[index] < v) break;
                keys[index + 1] = keys[index];
                index--;
            }
            keys[index + 1] = v;
            num_keys = num_keys + 1;
        }

        else
        {
            while (index >= 0)
            {
                if (keys[index] < v) break;
                index--;
            }
            children[index + 1]->insertNonFull(v);

            if (children[index + 1]->num_keys == 2 * Min_Child - 1)
            {
                split(index + 1, children[index + 1]);
            }
        }





    }

    static int roundUp(int num)
    {
        int iNum;
        if (num % 2 == 0)
        {
            iNum = num / 2;
            return iNum;
        }

        else
        {
            iNum = (num / 2) + 1;
            return iNum;
        }
    }

    void split(int index, BTreeNode* x)
    {
        BTreeNode* t = new BTreeNode(x->leaf, x->order);
        t->num_keys = Min_Child - 1;

        for (int i = 0; i < Min_Child - 1; i++)
            t->keys[i] = x->keys[i + Min_Child];

        if (x->leaf == false)
        {
            for (int i = 0; i < Min_Child; i++)
                t->children[i] = x->children[i + Min_Child];
        }

        x->num_keys = Min_Child - 1;

        for (int i = num_keys; i >= index + 1; i--)
            children[i + 1] = children[i];

        children[index + 1] = t;

        for (int i = num_keys - 1; i >= index; i--)
            keys[i + 1] = keys[i];

        keys[index] = x->keys[Min_Child - 1];

        num_keys = num_keys + 1;
    }

    void Print()
    {
        if(this->leaf){

            cout<<" ";
        }
        getKeys();
        cout<<" ";
        int i;

        for (i = 0; i < num_keys; i++)
        {

            if (!leaf) {

                children[i]->Print();
            }


        }
        if (!leaf)

            children[i]->Print();




    }


    void getKeys() {

        for (int i = 0; i < num_keys; i++)
        {
            cout << keys[i];

            if (i < num_keys - 1)
            {
                cout << ",";
            }
        }

        cout << endl;

    }

    template<class, int m> friend class BTree;
};

template <class T, int m>
class BTree
{
    BTreeNode<T>* root;
    int Min_Child;
    int order;

public:
    BTree()
    {
        root = nullptr;
        Min_Child = BTreeNode<T>::roundUp(m);
        order = m;
    }

    void Print()
    {
        if (root != nullptr) root->Print();
    }

    void insert(int v)
    {


        if (root == nullptr)
        {
            root = new BTreeNode<T>(true, order);
            root->keys[0] = v;
            root->num_keys = 1;
        }

        else
        {

            root->insertNonFull(v);

            if (root->num_keys == 2 * Min_Child - 1)
            {
                BTreeNode<T>* r = new BTreeNode<T>(false, order);

                r->children[0] = root;

                r->split(0, root);
                root = r;
            }
        }

    }
};

int main()
{
    BTree<int, 5> t;

    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(12);
    t.insert(13);
    t.insert(14);
    t.insert(15);
    t.insert(16);
    t.insert(17);




    t.Print();

    return 0;
}
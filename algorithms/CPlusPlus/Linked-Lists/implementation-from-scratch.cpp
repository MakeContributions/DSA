/*
 * linked_list.cpp
 *
 * Create a linked list using arrays and
 * structures. Emulates std::list in C++ STL
 */

#include <iostream>
#include <string>
#include <exception>

using dType = char;//int;//std::string;

template<typename T>
struct Node
{
    T val;
    Node *next;
};

template <class T>
class List
{
private:
    Node<dType> *head = nullptr;
public:
    List() {}

    void push_back(const T& val)
    {
        Node<T> *currNode = head;
        // std::cout << currNode << "\n";

        Node<T> *newNode { new Node<T>[sizeof(Node<T>)] };
        newNode->val = val;
        newNode->next = nullptr;

        if (currNode == nullptr)
        {
            currNode = newNode;
            // std::cout << currNode << "\n";
            head = currNode;
            return;
        }
        //Node<T> *initialNode = head;
        Node<T> *nextNode { currNode->next };

        while (nextNode != nullptr)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }

        nextNode = newNode;
        currNode->next = nextNode;
    }

    void push_front(const T& val)
    {
        Node<T> *newNode { new Node<T>[sizeof(Node<T>)] };
        newNode->val = val;
        newNode->next = head;

        head = newNode;
    }

    void pop_front()
    {
        if (empty())
            throw std::runtime_error("Empty list");

        head = head->next;
        std::cout << "Popped front!\n";
    }

    const bool empty() { return head == nullptr; }

    const T& front()
    {
        if (empty())
            throw std::runtime_error("Empty list");
        return head->val;
    }

    void pop_back()
    {
        if (empty())
            throw std::runtime_error("Empty list");

        Node<T> *prevNode = head;
        Node<T> *currNode = prevNode->next;
        if (currNode == nullptr)
        {
            head = nullptr;
            return;
        }

        while (currNode->next != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = nullptr;

        std::cout << "Popped back!\n";
    }

    const T& back()
    {
        if (empty())
            throw std::runtime_error("Empty list");

        Node<T> *currNode = head;
        Node<T> *nextNode = currNode->next;

        while (nextNode != nullptr)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }

        return currNode->val;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list)
    {
        Node<T> *node = list.head;
        while (node != nullptr)
        {
            os << node->val << " -> ";
            node = node->next;
        }
        os << "NULL";
        return os;
    }
};

template <typename T>
void insert_element(List<T>& list, bool front)
{
    T val {};
    std::cout << "Enter value to be inserted: ";
    std::cin >> val;

    if (front) list.push_front(val);
    else list.push_back(val);
    return;
}

void menu()
{
    List<dType> list {};
    while (true)
    {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Push (B)ack an element\n";
        std::cout << "2. Push (F)ront an element\n";
        std::cout << "3. (D)isplay the linked list\n";
        std::cout << "4. Get (f)ront\n";
        std::cout << "5. Get (b)ack\n";
        std::cout << "6. Pop f(R)ont\n";
        std::cout << "7. Pop b(A)ck\n";
        std::cout << "8. (q)uit\n";
        char ch {};
        std::cin >> ch;

        try
        {
            switch (ch)
            {
                case 'B': insert_element(list, false);
                          break;
                case 'F': insert_element(list, true);
                          break;
                case 'D': std::cout << list << "\n";
                          break;
                case 'f': std::cout << list.front() << "\n";
                          break;
                case 'b': std::cout << list.back() << "\n";
                          break;
                case 'R': list.pop_front();
                          break;
                case 'A': list.pop_back();
                          break;
                case 'q': return;
                default: std::cout << "That's an invalid option. Please try again.\n";
            }
        }
        catch (const std::runtime_error& re)
        {
            std::cerr << re.what() << "\n";
        }
    }
}

int main()
{
    menu();
}

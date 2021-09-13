#include <iostream>
#include <exception>

using dType = int;

template <typename T>
class Node {
    public:
        T data;
        Node *next;

        Node(T data)
            : data(data) , next(nullptr) {};
        Node(){}
};

template <typename T>
class SinglyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        SinglyLinkedList()
            : head(nullptr),tail(nullptr){}

        void insertAtHead(T data) {
            Node<T> *temp = new Node<T>(data);

            // if head is not pointing to anything then simply point to new node
            if(this->head == nullptr) {
                this->head = temp;
                return;
            }

            // if head is already point at some node
            // first make new node points to head address
            temp->next = this->head;
            // change head point to new node
            this->head = temp;
        }

        void insertAtEnd(T data){

            Node<T> *newNode = new Node<T>(data);

            // if head is not pointing to anything then simply point to new node
            if(this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                return;
            }

            // if list is not empty, then put the address of the new node in the tail->next
            // and finally, make the next of newNode = NULL and tail will be pointing the the newNode as now it is in the last position.
            tail->next = newNode;
            newNode->next= NULL;
            tail=newNode;
        }

        T removeAtHead() {
            // if list is empty we can't remove node
            if(this->head == nullptr)
                throw std::runtime_error("List is Empty.");

            // save data of node where head is pointed
            T data = this->head->data;
            // save temp pointer to free the memory
            Node<T>* temp_ptr = this->head;
            this->head = this->head->next;

            // free memory
            delete temp_ptr;
            return data;
        }

        T removeAtEnd() {
            // if list is empty we can't remove node
            if (this->head == nullptr)
                throw std::runtime_error("List is Empty.");
            // if list is singleton it just becomes nullptr
            if (this->head->next == nullptr)
            {
                T data = this->tail->data;

                Node<T>* temp_ptr = this->tail;
                this->head = nullptr;
                this->tail = nullptr;

                delete temp_ptr;
                return data;
            }

            // save data of node where tail is pointed
            T data = this->tail->data;

            // now iterate to one before last pointer
            Node<T>* currNode = this->head;
            Node<T>* nextNode = currNode->next;

            while (nextNode && nextNode->next)
            {
                currNode = nextNode;
                nextNode = nextNode->next;
            }

            // save temp pointer to free the memory
            Node<T>* temp_ptr = this->tail;
            currNode->next = nullptr;
            this->tail = currNode;

            delete temp_ptr;
            return data;
        }

        T front() {
            return this->head->data;
        }

        T back() {
            return this->tail->data;
        }

        void printList() const {
            if(this->head == nullptr) {
                std::cout<<"List is Empty."<<std::endl;
            } else {
                Node<T> *itr = this->head;
                // iterate through list until itr reach to nullptr and print data
                while(itr != nullptr) {
                    std::cout<<itr->data<<" ";
                    itr = itr->next;
                }
                std::cout<<std::endl;
            }
        }
};

template <typename T>
void insert_element(SinglyLinkedList<T>& list, bool front) {
    T val {};
    std::cout << "Enter value to be inserted: ";
    std::cin >> val;

    if (front) list.insertAtHead(val);
    else list.insertAtEnd(val);
}

void menu() {
    SinglyLinkedList<dType> list {};
    while (true) {
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

        try {
            switch (ch) {
                case 'B': insert_element(list, false);
                          break;
                case 'F': insert_element(list, true);
                          break;
                case 'D': list.printList();
                          break;
                case 'f': std::cout << list.front() << "\n";
                          break;
                case 'b': std::cout << list.back() << "\n";
                          break;
                case 'R': list.removeAtHead();
                          break;
                case 'A': list.removeAtEnd();
                          break;
                case 'q': return;
                default: std::cout << "That's an invalid option. Please try again.\n";
            }
        }
        catch (const std::runtime_error& re) {
            std::cerr << re.what() << "\n";
        }
    }
}

int main() {
    menu();
}

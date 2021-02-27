#include <iostream>
#include <unistd.h>

template <typename T>
class Node {
    public:
        T data;
        Node<T>* next;

        public:
            // this create node with data
            Node(int data)
                : data(data) , next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        // initially head and tail must be null
        CircularLinkedList()
            : head(nullptr) , tail(nullptr) {}

        void insertAtHead(T data) {
            Node<T> *newNode = new Node<T>(data);

            // if list is empty add new node
            if(this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                newNode->next = this->head;
                return;
            }

            newNode->next = this->head;
            this->head = newNode;
            this->tail->next = newNode;
        }

        void insertAtEnd(T data) {
            Node<T>* newNode = new Node<T>(data);

            // if list is empty add new node
            if(this->tail == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                newNode->next = this->head;
                return;
            }

            this->tail->next = newNode;
            newNode->next = this->head;
            this->tail = newNode;
        }

        T deleteAtHead() {
            if(this->head == nullptr) {
                std::cout<<"Stack Underflow"<<std::endl;
                exit(1);
            }

            Node<T>* temp = this->head;
            T data = this->head->data;
            if(this->head == this->head->next) {
                this->head = nullptr;
                this->tail = nullptr;
                delete temp;
                return data;
            }

            this->head = this->head->next;
            tail->next = this->head;
            delete temp;
            return data;
        }

        void printList() const {
            Node<T>* itr = this->head;
            if(itr == nullptr) {
                std::cout<<"List is Empty";
            } else {
                // print every element after 1s since it's circular
                while(itr != nullptr) {
                    std::cout<<itr->data<<" "<<std::flush;
                    itr = itr->next;
                    sleep(1);
                }
            }
            std::cout<<std::endl;
        }
};

int main() {
    CircularLinkedList<int> c;
    c.insertAtHead(1);
    c.insertAtEnd(2);
    c.insertAtEnd(3);
    c.insertAtHead(0);
    c.insertAtHead(-1);
    c.deleteAtHead();
    c.printList();
    return 0;
}

#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node *next;

        Node(T data)
            : data(data) , next(nullptr) {};
};

template <typename T>
class SinglyLinkedList {
    private:
        Node<T>* head;

    public:
        SinglyLinkedList()
            : head(nullptr){}

        void push(T data) {
            Node<T> *temp = new Node<T>(data);
            if(this->head == nullptr) {
                this->head = temp;
                return;
            }

            temp->next = this->head;
            this->head = temp;
        }

        T pop() {
            if(this->head == nullptr) {
                std::cout<<"List is Empty"<<std::endl;
                exit(1);
            }
            T data = this->head->data;
            this->head = this->head->next;
            return data;
        }

        void printList() const {
            if(this->head == nullptr) {
                std::cout<<"List is Empty"<<std::endl;
            } else {
                Node<T> *itr = this->head;
                while(itr != nullptr) {
                    std::cout<<itr->data<<" ";
                    itr = itr->next;
                }
                std::cout<<std::endl;
            }
        }
};

int main() {
    SinglyLinkedList<int> l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.pop();
    l.printList();
    return 0;
}

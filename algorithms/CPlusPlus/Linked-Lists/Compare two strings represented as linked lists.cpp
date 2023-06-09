#include<bits/stdc++.h>
using namespace std;

// Defining struct for creating Node
struct Node
{
    char data;
    Node *next;
};
Node *head;

// creates Node for individual character for a string and returns the address of the first Node
Node *insert(string &str)
{
    head = NULL;
    Node *current = NULL;
    for (auto ch : str)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        (*temp).data = ch;
        (*temp).next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            (*current).next = temp;
            current = temp;
        }
        
    }

    return head;
    
}

// compares the strings, returns true if the strings are same and returns false if they are differnt
bool compare(Node *s1, Node *s2)
{
    while ((s1 && s1) && ((*s1).data == (*s2).data))
    {
        s1 = (*s1).next;
        s2 = (*s2).next;
    }

    if (s1 == NULL && s2 == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
     
}


int main()
{
    /*
        creates two linked list
        
        if hello & world are two strings

        1st head -> h -> e -> l -> l -> o -> NULL
        2nd head -> w -> o -> r -> l -> d -> NULL

    */
    string str1, str2;
    cout    <<  "enter first string :   ";
    cin >>  str1;
    cout    <<  "enter second string    :   ";
    cin >>  str2;

    Node *s1 = insert(str1);
    Node *s2 = insert(str2);

    bool comp = compare(s1, s2);
    cout    <<  (comp ? "the strings are same" : "the strings are not same")    <<  endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
/*This function takes the two lists as arguments and if they are not null it will compare them until the last node*/
bool areIdentical(struct Node* a, struct Node* b)
{
	while (a != NULL && b != NULL) {
		if (a->data != b->data)
			return false;
		a = a->next;
		b = b->next;
	}
	return (a == NULL && b == NULL);
}
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
int main()
{
	struct Node* a = NULL;
	struct Node* b = NULL;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&b, 1);
	push(&b, 2);
	push(&b, 3);
	areIdentical(a, b) ? cout<<"Identical":cout<<"Not Identical";
	return 0;
}
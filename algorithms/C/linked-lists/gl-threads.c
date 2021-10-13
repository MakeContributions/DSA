/**
 * @file gl-threads.c
 * @brief Glue based doubly linked-list
 * @details
 * In traditional a doubly linked-list each node will have a left and right
 * pointer and a pointer to the data, so the structure of the node will contain
 * 3 data members(next, prev, data). In Glue based doubly linked-list there will
 * only be 2 data members left and right pointers. As for the data, it will be 
 * glued on top of the node.
 *
 * Illustration
 * -------------
 * Traditional doubly linked-list:
 *                       _____________                    _____________
 *                  ___ | application |               ___| application |
 *                 |    |   data      |              |   |    data     |
 *                 |    |_____________|              |   |_____________|
 *       __________|_________              __________|_________
 *      | prev | data | next |____________| prev | data | next |
 *      |______|______|______|            |______|______|______|
 *
 *
 * Glue based doubly linked-list:
 *       _____________             _____________
 *      | application |           | application |
 *      |    data     |           |    data     |
 *      |_____________|           |_____________|
 *      | prev | next |___________| prev | next |
 *      |______|______|           |______|______|
 *
 * @author [Ashborn-SM](https://github.com/Ashborn-SM)
 */

#include <stdlib.h> // for dynamic memory allocation 
#include <stdio.h> // for IO operations
#include <string.h> // for string manipulation

#define HEAD(list) (list->head)
#define OFFSETOF(structure, field) (long)&((structure*)0)->field

/**
 * @struct glthread_node
 * @brief node for the glue based doubly linked list
 */
typedef struct glthread_node_{
    struct glthread_node_* next;
    struct glthread_node_* prev;
}glthread_node;

/**
 * @struct gldll
 * @brief the doubly linked-list
 */
typedef struct{
    glthread_node* head;
    size_t size;
    // store the addresses of all the nodes in linked-list
    char** addresses;
    unsigned int offset;
}gldll;

/**
 * @brief initialise the node
 * @details set the node members to NULL
 * @param node linked-list node
 * @returns void
 */
void init_glthread_node(glthread_node* node){
    node->next = NULL;
    node->prev = NULL;
}

/**
 * @brief initialise the linked-list
 * @details set the head and offset
 * @param list linked-list
 * @param offset offset of the data member
 * @returns void
 */
void init_glthread_list(gldll* list, unsigned int offset){
    list->head = NULL;
    list->size = 0;
    list->addresses = NULL;
    list->offset = offset;
}

/**
 * @brief insertion of node
 * @details insert the node at the front of the list
 * @param list linked-list
 * @param node node to be inserted
 * @returns void
 */
void glthread_pushfront(gldll* list, glthread_node* node){
    glthread_node* cur = HEAD(list);
    list->size++;
    if(cur == NULL){
        HEAD(list) = node;
        return;
    }
    cur->prev = node;
    node->next = cur;
    HEAD(list) = node;
}

/**
 * @brief delete the node at front
 * @details delete the head node and point the head to the next node
 * @param list based doubly linked-list
 * @returns void
 */
void glthread_popfront(gldll* list){
    if(list == NULL || HEAD(list) == NULL ){ return; }
    glthread_node* temp = HEAD(list)->next;
    free((char*)HEAD(list) - list->offset); 
    HEAD(list) = temp;
    if(HEAD(list) != NULL){
        temp->prev = NULL;
    }
    list->size--;
}

/**
 * @brief return the addresses of all nodes in the linked-list
 * @param list based doubly linked-list
 * @return addresses of all nodes in the linked-list starting from head
 */
char** get_addresses(gldll* list){
    if(list->addresses != NULL){ 
        // free the memory in order to avoid memory leak
        free(list->addresses);
    }
    list->addresses = malloc(list->size*sizeof(char*));
	if(list->addresses == NULL){
		printf("Allocation Failure");
		exit(0);
	}
    glthread_node* cur = HEAD(list);
    for(int i=0; cur != NULL; i++){
        list->addresses[i] = (char*)cur - list->offset; 
        cur = cur->next;
    }

    return list->addresses;
}

/**
 * @struct person 
 * @brief a structure with attributes of a person
 */
typedef struct{
    char name[30];
    int age, weight, height;
    glthread_node glnode;
}person;

/**
 * @brief print the details of the person
 * @param per person structure
 * @returns void
 */
void print(person* per){
    printf("Name: %s\n", per->name);
    printf("Height: %i\n", per->height);
    printf("Age: %i\n", per->age);
    printf("Weight: %i\n", per->weight);
	printf("------------\n");
}

/**
 * @brief allocate memory
 * @returns memory with type person
 */
person* allocate(){
	person* new = malloc(sizeof(*new));
	if(new == NULL){
		printf("Allocation Failure");
		exit(0);
	}
	return new;
}

/**
 * @brief Self-test the implementation
 * @param list linked-list
 * @returns void
 */
static void test(gldll* list){
	if(HEAD(list) == NULL){
		return;
	}
	char passed[10] = "[PASSED]:\0";
	char failed[10] = "[FAILED]:\0";
	char expected[9] = "EXPECTED\0";
	char returned[9] = "RETURNED\0";
	person* per = (person*)((char*)HEAD(list)- list->offset);
	if(strcmp(per->name, "rohit") == 0){
		printf("%s: %s -> %s, %s -> %s\n", passed, expected, "rohit",
		returned, per->name);
	}
	else{
		printf("%s: %s -> %s, %s -> %s\n", failed, expected, "rohit",
		returned, per->name);
	}
	if(per->age == 23){
		printf("%s: %s -> %i, %s -> %i\n", passed, expected, 23,
		returned, per->age);
	}
	else{
		printf("%s: %s -> %i, %s -> %i\n", failed, expected, 23,
		returned, per->age);
	}
	if(per->height == 174){
		printf("%s: %s -> %i, %s -> %i\n", passed, expected, 174,
		returned, per->height);
	}
	else{
		printf("%s: %s -> %i, %s -> %i\n", failed, expected, 174,
		returned, per->height);
	}
	if(per->weight == 67){
		printf("%s: %s -> %i, %s -> %i\n", passed, expected, 67,
		returned, per->weight);
	}
	else{
		printf("%s: %s -> %i, %s -> %i\n", failed, expected, 67,
		returned, per->weight);
	}
}

/**
 * @brief free all the memory allocated for the doubly linked-list
 * @param list doubly linked-list
 * @returns void
 */
void destructor(gldll** list){
    while(HEAD((*list))!= NULL){
        glthread_popfront((*list));
    }
    free(*list);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(){
	gldll* list = malloc(sizeof(*list));
	if(list == NULL){
		printf("Allocation Failure");
		exit(0);
	}

	person* rahul = allocate();
	person* rohit = allocate();

	strcpy(rahul->name, "rahul");
	strcpy(rohit->name, "rohit");

	rahul->age = 19;
	rohit->age = 23;

	rahul->height = 170;
	rohit->height = 174;

	rahul->weight = 60;
	rohit->weight = 67;

	init_glthread_list(list, OFFSETOF(person, glnode));

	init_glthread_node(&(rahul->glnode));
	init_glthread_node(&(rohit->glnode));

	glthread_pushfront(list, &(rohit->glnode));
	glthread_pushfront(list, &(rahul->glnode));

	char** addresses = get_addresses(list);
	for(int i=0; i<list->size; i++){
		print((person*)addresses[i]);
	}

	glthread_popfront(list);

	test(list);

	destructor(&list);
	return 0;
}

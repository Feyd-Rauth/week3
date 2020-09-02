
// C program for generic linked list 
#include<stdio.h> 
#include<stdlib.h> 
  
/* A linked list node */
struct Node 
{ 
    // Any data type can be stored in this node 
    int data; 
    
    struct Node *next; 
    
}; 
struct LinkedList{
    struct Node* head;
    int size;
};
  
/* Function that pushes node before the head */
void push(struct Node** head, int new_data, int* size) 
{ 
    // Allocate memory for node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    new_node->data  = new_data; 
    new_node->next = (*head);
    
    
  
    (*head) = new_node; 
    (*size)++;
} 
/* Function that pushes node at existing position (Works only if there is a head)*/
void insert_node(struct Node** head, int pos, int new_data, int* size){
    if(pos >= *size){
        printf("No such position!");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data;

    struct Node* temp = malloc(sizeof(struct Node));
    temp = (*head);

    for(int i = 1; i < pos; i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    (*size)++;
}

void delete_node(struct Node** head, int pos, int* size){
    if(pos >= *size){
        printf("No such position!");
        return;
    }
    if(pos == 0){
        (*head) = (*head)->next;
    }
    struct Node* temp = malloc(sizeof(struct Node));
    temp = (*head);

    for(int i = 1; i < pos; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    (*size)--;
}

void printList(struct Node *node){
    while (node != NULL) 
    { 
        printf("%d\n", node->data);
        node = node->next; 
    } 

}
/* Driver program to test above function */
int main() 
{ 
    struct LinkedList list;
    list.head = NULL;
    list.size = 0;
  
    // Create and print an int linked list 
    
    int arr[] = {10, 20, 30, 40, 50}, i; 
    for (i=4; i>=0; i--) 
       push(&list.head, arr[i], &list.size); 
    printf("Created integer linked list is \n");
    printList(list.head); 
    insert_node(&list.head, 1, 15, &list.size);
    insert_node(&list.head, 3, 25, &list.size);

    delete_node(&list.head, 6, &list.size);
    delete_node(&list.head, 0, &list.size);
    
    insert_node(&list.head, 4, 100, &list.size);
    printf("Linked list after changing\n");
    printList(list.head); 
    
    

    return 0; 
} 

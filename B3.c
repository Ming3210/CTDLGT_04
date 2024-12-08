#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next; 
} Node;

Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void insertLast(Node** head, int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d-->",temp->data );
		temp = temp->next;		
	}
	printf("NULL\n");
}

Node* createLinkedList(int n) {
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
    	int value;
       
    	printf("Phan tu %d: ", i + 1);
        scanf("%d", &value);
        
        insertLast(&head, value);
    }
    return head;
}

void deleteLast(Node** head){

    Node* temp = *head;
	if (temp == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if (temp->next == NULL) {
        temp = NULL;
        return;
    }
	Node* prev = NULL;
	while (temp->next != NULL) {
    	prev = temp;
    	temp = temp->next;
	}
	prev->next = NULL;
}

int main(){
	int n;
	Node* head = NULL;
	printf("Nhap n: ");
	scanf("%d", &n);
	head = createLinkedList(n); 
	deleteLast(&head);
    printList(head);
	return 0;
}

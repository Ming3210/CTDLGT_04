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

int searchElement(Node* head, int num) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == num) {
            return index; 
        }
        temp = temp->next;
        index++;
    }
    return -1; 
}

int main(){
	int n, num;
	Node* head = NULL;
	printf("Nhap n: ");
	scanf("%d", &n);
	head = createLinkedList(n); 
	printf("Nhap gia tri can tim: ");
	scanf("%d", &num);
	int result;
    printList(head);
	result = searchElement(head, num);
   	printf("\nChi so: %d ",result);
	return 0;
}

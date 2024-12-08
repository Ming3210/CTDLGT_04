#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next; 
} Node;

Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next=NULL;
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

void insertHead(Node** head,int value){
	Node* newNode = createNode(value);
	// Gan con tro nut moi cho head
	newNode->next = *head;
	// cap nhat head tro den node moi
	*head = newNode;
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

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    if (position == 0) {
        *head = temp->next;  
        return;
    }
    int index = 0;
    while (temp != NULL && index < position) {
        prev = temp;  
        temp = temp->next;  
        index++;
    }

    if (temp == NULL) {
        printf("Vi tri nam ngoai pham vi danh sach.\n");
        return;
    }
    prev->next = temp->next;
   
}


int main(){
  int n, position;
	Node* head = NULL;
	printf("Nhap n: ");
	scanf("%d", &n);
	head = createLinkedList(n);

    printf("Nhap vi tri can chen : ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);
    printList(head);     
	return 0;
}

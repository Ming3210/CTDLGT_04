#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertLast(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int findMax(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return -1; 
    }

    int maxValue = head->data; 
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data > maxValue) {
            maxValue = temp->data;
        }
        temp = temp->next;
    }
    return maxValue;
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &value);
        insertLast(&head, value);
    }

    printf("Danh sach lien ket: ");
    printList(head);

    int maxValue = findMax(head);
    if (maxValue != -1) {
        printf("Phan tu lon nhat trong danh sach: %d\n", maxValue);
    }

    return 0;
}

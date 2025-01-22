#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void Insert_End(int num){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    if (head == NULL && tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void Delete_End(){
    if (head == NULL) {
        printf("\nThe list is already empty!\n");
        return;
    }
    
    struct node *ptr = tail;
    struct node *p = head;

    if (head == tail) {
        head = tail = NULL;
        free(ptr);
        return;
    }

    while (p->next != tail) {
        p = p->next;
    }
    p->next = NULL;
    tail = p;
    free(ptr);
}

void Insert_Front(int num) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = head;

    if (head == NULL) {
        tail = temp;
    }
    head = temp;
}

void Delete_Front() {
    if (head == NULL) {
        printf("\nThe list is already empty!\n");
        return;
    }

    struct node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
    }
    free(temp);
}

void Insert_mid(int num, int pos) {
    struct node *ptr = head;
    struct node *p = NULL;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    while (ptr != NULL && ptr->data != pos) {
        p = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position not found!\n");
        free(temp);
        return;
    }

    temp->next = ptr;
    if (p != NULL) {
        p->next = temp;
    } else {
        head = temp;
    }
}

void Delete_mid(int pos) {
    struct node *ptr = head;
    struct node *p = NULL;

    while (ptr != NULL && ptr->data != pos) {
        p = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position not found!\n");
        return;
    }

    if (p != NULL) {
        p->next = ptr->next;
    } else {
        head = ptr->next;
    }
    free(ptr);
}

void display() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice, num, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Delete from the end\n");
        printf("3. Insert at the front\n");
        printf("4. Delete from the front\n");
        printf("5. Insert in the middle\n");
        printf("6. Delete from the middle\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert at the end: ");
                scanf("%d", &num);
                Insert_End(num);
                break;
            case 2:
                Delete_End();
                break;
            case 3:
                printf("Enter the number to insert at the front: ");
                scanf("%d", &num);
                Insert_Front(num);
                break;
            case 4:
                Delete_Front();
                break;
            case 5:
                printf("Enter the number to insert in the middle: ");
                scanf("%d", &num);
                printf("Enter the position (node value) to insert after: ");
                scanf("%d", &pos);
                Insert_mid(num, pos);
                break;
            case 6:
                printf("Enter the position (node value) to delete from the middle: ");
                scanf("%d", &pos);
                Delete_mid(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

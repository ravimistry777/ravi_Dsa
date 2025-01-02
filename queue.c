#include<stdio.h>
#define n 100
int queue[n];
int front = -1;
int rear = -1;
void enqueue(int x) {
    if (rear == n - 1) {
        printf("Queue is full");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = x;
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty");
        return -1;
    }
    int x = queue[front];
    front++;
    return x;
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    return 0;
}
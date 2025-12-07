// restaurant_order_system.c
// Simple Restaurant Order Management using Priority Queues in C
// Author: Sameer Kumar

#include <stdio.h>
#include <string.h>

#define MAX_ORDERS 50
#define NAME_LEN   50
#define ITEM_LEN   100

typedef struct {
    int  orderId;
    char customerName[NAME_LEN];
    char item[ITEM_LEN];
    int  isVIP;
} Order;

typedef struct {
    Order data[MAX_ORDERS];
    int front;
    int rear;
} Queue;

Queue vipQueue;
Queue normalQueue;
int lastOrderId = 0;

void initQueue(Queue *q);
int  isEmpty(Queue *q);
int  isFull(Queue *q);
void enqueue(Queue *q, Order o);
int  dequeue(Queue *q, Order *o);
void placeOrder();
void serveNextOrder();
void displayPendingOrders();
void searchOrderById();
void clearInputBuffer();

int main() {
    int choice;

    initQueue(&vipQueue);
    initQueue(&normalQueue);

    printf("=============================================\n");
    printf("     RESTAURANT ORDER MANAGEMENT SYSTEM      \n");
    printf("         (VIP & NORMAL PRIORITY)             \n");
    printf("=============================================\n");

    do {
        printf("\n-------------- MAIN MENU --------------\n");
        printf("1. Place New Order\n");
        printf("2. Serve Next Order\n");
        printf("3. Show All Pending Orders\n");
        printf("4. Search Order by ID\n");
        printf("5. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: placeOrder(); break;
            case 2: serveNextOrder(); break;
            case 3: displayPendingOrders(); break;
            case 4: searchOrderById(); break;
            case 5: printf("\nExiting... Thank you!\n"); break;
            default: printf("\nInvalid choice! Please enter 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}

void initQueue(Queue *q) { q->front = q->rear = -1; }
int isEmpty(Queue *q) { return (q->front == -1 || q->front > q->rear); }
int isFull(Queue *q) { return (q->rear == MAX_ORDERS - 1); }

void enqueue(Queue *q, Order o) {
    if (isFull(q)) { printf("\nQueue FULL! Cannot accept more orders.\n"); return; }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear] = o;
}

int dequeue(Queue *q, Order *o) {
    if (isEmpty(q)) return 0;
    *o = q->data[q->front];
    q->front++;
    if (q->front > q->rear) initQueue(q);
    return 1;
}

void placeOrder() {
    Order o;
    int choice;

    lastOrderId++;
    o.orderId = lastOrderId;

    printf("\n--- Place New Order ---\n");
    printf("Customer Name: ");
    fgets(o.customerName, NAME_LEN, stdin);
    o.customerName[strcspn(o.customerName, "\n")] = '\0';

    printf("Order Item: ");
    fgets(o.item, ITEM_LEN, stdin);
    o.item[strcspn(o.item, "\n")] = '\0';

    printf("Priority Type (1 = VIP, 0 = Normal): ");
    scanf("%d", &choice);
    clearInputBuffer();

    o.isVIP = (choice == 1);

    if (o.isVIP) {
        enqueue(&vipQueue, o);
        printf("\n[VIP ORDER PLACED]\n");
    } else {
        enqueue(&normalQueue, o);
        printf("\n[Normal Order Placed]\n");
    }

    printf("Generated Order ID: %d\n", o.orderId);
}

void serveNextOrder() {
    Order o;
    printf("\n--- Serve Next Order ---\n");

    if (!isEmpty(&vipQueue)) {
        dequeue(&vipQueue, &o);
        printf("Serving VIP Order ID: %d\nCustomer: %s\nItem: %s\n", o.orderId, o.customerName, o.item);
    } else if (!isEmpty(&normalQueue)) {
        dequeue(&normalQueue, &o);
        printf("Serving Normal Order ID: %d\nCustomer: %s\nItem: %s\n", o.orderId, o.customerName, o.item);
    } else {
        printf("No pending orders.\n");
    }
}

void displayPendingOrders() {
    printf("\n--- Pending Orders ---\n");

    if (isEmpty(&vipQueue) && isEmpty(&normalQueue)) {
        printf("No pending orders.\n");
        return;
    }

    if (!isEmpty(&vipQueue)) {
        printf("\nVIP Orders:\n");
        for (int i = vipQueue.front; i <= vipQueue.rear; i++) {
            printf("ID: %d | Customer: %s | Item: %s\n",
                   vipQueue.data[i].orderId,
                   vipQueue.data[i].customerName,
                   vipQueue.data[i].item);
        }
    }

    if (!isEmpty(&normalQueue)) {
        printf("\nNormal Orders:\n");
        for (int i = normalQueue.front; i <= normalQueue.rear; i++) {
            printf("ID: %d | Customer: %s | Item: %s\n",
                   normalQueue.data[i].orderId,
                   normalQueue.data[i].customerName,
                   normalQueue.data[i].item);
        }
    }
}

void searchOrderById() {
    int id;
    printf("\nEnter Order ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = vipQueue.front; i <= vipQueue.rear; i++) {
        if (!isEmpty(&vipQueue) && vipQueue.data[i].orderId == id) {
            printf("\nOrder Found (VIP)\nID: %d | Customer: %s | Item: %s\n",
                   vipQueue.data[i].orderId,
                   vipQueue.data[i].customerName,
                   vipQueue.data[i].item);
            return;
        }
    }

    for (int i = normalQueue.front; i <= normalQueue.rear; i++) {
        if (!isEmpty(&normalQueue) && normalQueue.data[i].orderId == id) {
            printf("\nOrder Found (Normal)\nID: %d | Customer: %s | Item: %s\n",
                   normalQueue.data[i].orderId,
                   normalQueue.data[i].customerName,
                   normalQueue.data[i].item);
            return;
        }
    }

    printf("\nOrder ID %d not found.\n", id);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

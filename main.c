#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

struct node* creationandinsertion(struct node* head, int* count) {
    struct node* newnode, *temp = NULL;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        (*count)++;
        printf("Press 0 to exit and 1 to continue: ");
        scanf("%d", &choice);
    }
    return head;
}

void display(struct node* head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* deletefrombeginning(struct node* head, int* count) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    head = head->next;
    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
    (*count)--;
    return head;
}

struct node* deletefromend(struct node* head, int* count) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (head->next == NULL) {
        printf("Deleted node with value: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
    }
    (*count)--;
    return head;
}

struct node* deleteatposition(struct node* head, int* count) {
    struct node *temp = head, *prev = NULL;
    int position, i;

    printf("Enter position to delete (0-based index): ");
    scanf("%d", &position);

    if (position < 0 || position >= (*count)) {
        printf("Invalid position\n");
        return head;
    }

    if (position == 0) {
        head = head->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
    } else {
        for (i = 0; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
    }
    (*count)--;
    return head;
}

struct node* deletebyvalue(struct node* head, int* count) {
    struct node *temp = head, *prev = NULL;
    int value;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
    (*count)--;
    return head;
}

int main() {
    int choice = 1, option;

    while (choice) {
        printf("\n******* Select an operation ********\n");
        printf("1. Create a linked list\n");
        printf("2. Display list\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete from the end\n");
        printf("5. Delete at a specific position\n");
        printf("6. Delete by specific value\n");
        printf("7. Display count of nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            head = creationandinsertion(head, &count);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = deletefrombeginning(head, &count);
            break;
        case 4:
            head = deletefromend(head, &count);
            break;
        case 5:
            head = deleteatposition(head, &count);
            break;
        case 6:
            head = deletebyvalue(head, &count);
            break;
        case 7:
            printf("The current count of nodes is: %d\n", count);
            break;
        case 8:
            printf("Exiting\n");
            exit(0);
        default:
            printf("Invalid choice, try again\n");
        }
    }
    return 0;
}

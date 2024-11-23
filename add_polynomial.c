#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int pow;
    int coeff;
    struct Node *next;
} Node;

Node* createNode(int pow, int coeff) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->pow = pow;
    newNode->coeff = coeff;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtTail(Node *tail, int pow, int coeff) {
    Node *temp = createNode(pow, coeff);
    if (tail != NULL) {
        tail->next = temp;
    }
    return temp;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->pow);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node* addPolynomial(Node *head1, Node *head2) {
    Node *resultHead = NULL, *resultTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        Node *temp = NULL;
        if (head1->pow == head2->pow) {
            temp = createNode(head1->pow, head1->coeff + head2->coeff);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->pow > head2->pow) {
            temp = createNode(head1->pow, head1->coeff);
            head1 = head1->next;
        } else {
            temp = createNode(head2->pow, head2->coeff);
            head2 = head2->next;
        }

        if (resultHead == NULL) {
            resultHead = temp;
            resultTail = temp;
        } else {
            resultTail->next = temp;
            resultTail = temp;
        }
    }

    while (head1 != NULL) {
        Node *temp = createNode(head1->pow, head1->coeff);
        resultTail->next = temp;
        resultTail = temp;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        Node *temp = createNode(head2->pow, head2->coeff);
        resultTail->next = temp;
        resultTail = temp;
        head2 = head2->next;
    }

    return resultHead;
}

int main() {
    Node *n = createNode(4, 1000);
    Node *n1 = createNode(4, 500);
    Node *head = n;
    Node *tail = n;
    Node *head1 = n1;
    Node *tail1 = n1;

    int s;

    printf("Enter the number of terms in each polynomial: ");
    scanf("%d", &s);

    int pow[s], coeff[s], pow1[s], coeff1[s];

    printf("Enter the terms (power and coefficient) of the first polynomial:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d %d", &pow[i], &coeff[i]);
        tail = insertAtTail(tail, pow[i], coeff[i]);
    }

    printf("Enter the terms (power and coefficient) of the second polynomial:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d %d", &pow1[i], &coeff1[i]);
        tail1 = insertAtTail(tail1, pow1[i], coeff1[i]);
    }

    printf("First polynomial: ");
    print(head);

    printf("Second polynomial: ");
    print(head1);

    Node *head3 = addPolynomial(head, head1);

    printf("Result polynomial after addition: ");
    print(head3);

    return 0;
}

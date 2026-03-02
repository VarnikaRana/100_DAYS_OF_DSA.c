#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end
void insertTerm(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } 
        else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } 
        else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insertTerm(&result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, c, e;

    printf("Enter number of terms for Polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        insertTerm(&poly1, c, e);
    }

    printf("Enter number of terms for Polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        insertTerm(&poly2, c, e);
    }

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    display(sum);

    return 0;
}

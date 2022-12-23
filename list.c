#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
    int val;
    struct nodes *next;
} node;

node *head;
int count;

void print() {
    node* ptr = head;
    printf("%d :", count);
    while (ptr) {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(int num) {
    if (head) {
        node *new = (node *) malloc(sizeof(node));
        new->val = num;
        if (num < head->val) {
            new->next = head;
            head = new;
            ++count;
            print();
            return;
        }
        else if (num == head->val) {
            print();
            free(new);
            return;
        }
        node *ptr = head;
        while (ptr->next) {
            if (num == ptr->next->val) {
                print();
                free(new);
                return;
            }
            else if (num < ptr->next->val) {
                new->next = ptr->next;
                break;
            }
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
        ++count;
    }
    else {
        head = (node *) malloc(sizeof(node));
        head->val = num;
        head->next = NULL;
        ++count;
    }
    print();
}

void delete(int num) {
    if (head) {
        if (num == head->val) {
            node *temp = head;
            head = head->next;
            --count;
            print();
            free(temp);
            return;
        }
        for (node *ptr = head; ptr->next; ptr = ptr->next) {
            if (num == ptr->next->val) {
                node *temp = ptr->next;
                ptr->next = ptr->next->next;
                --count;
                print();
                free(temp);
                return;
            }
        }
    }
    print();
}

void freeall() {
    while (head) {
        node *ptr = head;
        head = head->next;
        free(ptr);
    }
}

int main(int argc, char **argv) {
    char op;
    int num;
    while (scanf("%c %d", &op, &num) != EOF) {
        if (op == 'i')
            insert(num);
        else if (op == 'd')
            delete(num);
    }
    freeall();
    return EXIT_SUCCESS;
}
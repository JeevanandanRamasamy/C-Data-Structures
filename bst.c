#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes {
    int val;
    struct nodes* left;
    struct nodes* right;
} node;

node *root;

void insert(int num) {
    if (root) {
        node *n = root;
        while (n) {
            if (num < n->val) {
                if (!n->left) {
                    node *new = (node *) malloc(sizeof(node));
                    new->val = num;
                    new->left = NULL;
                    new->right = NULL;
                    n->left = new;
                    printf("inserted\n");
                    return;
                }
                n = n->left;
            }
            else if (num > n->val) {
                if (!n->right) {
                    node *new = (node *) malloc(sizeof(node));
                    new->val = num;
                    new->left = NULL;
                    new->right = NULL;
                    n->right = new;
                    printf("inserted\n");
                    return;
                }
                n = n->right;
            }
            else {
                printf("not inserted\n");
                return;
            }
        }
    }
    else {
        root = (node *) malloc(sizeof(node));
        root->val = num;
        root->left = NULL;
        root->right = NULL;
        printf("inserted\n");
    }
}

void search(int num) {
    node *n = root;
    while (n) {
        if (num < n->val)
            n = n->left;
        else if (num > n->val)
            n = n->right;
        else {
            printf("present\n");
            return;
        }
    }
    printf("absent\n");
}

void delete(int num) {
    if (root && num == root->val) {
        node *temp = root;
        if (!root->left)
            root = root->right;
        else if (!root->right)
            root = root->left;
        else {
            node *ptr = root->left;
            if (ptr->right) {
                while (ptr->right->right)
                    ptr = ptr->right;
                node *t = ptr->right->left;
                ptr->right->left = root->left;
                ptr->right->right = root->right;
                root = ptr->right;
                ptr->right = t;
            }
            else {
                root->left->right = root->right;
                root = root->left;
            }
        }
        printf("deleted\n");
        free(temp);
        return;
    }
    node *n = root;
    while (n) {
        if (num < n->val) {
            if (!n->left) {
                printf("absent\n");
                return;
            }
            else if (num == n->left->val) {
                node *temp = n->left;
                if (!n->left->left)
                    n->left = n->left->right;
                else if (!n->left->right)
                    n->left = n->left->left;
                else {
                    node *ptr = n->left->left;
                    while (ptr->right->right)
                        ptr = ptr->right;
                    node *t = ptr->right->left;
                    ptr->right->left = n->left->left;
                    n->left = ptr->right;
                    ptr->right = t;
                }
                printf("deleted\n");
                free(temp);
                return;
            }
            n = n->left;
        }
        else if (num > n->val) {
            if (!n->right) {
                printf("absent\n");
                return;
            }
            else if (num == n->right->val) {
                node *temp = n->right;
                if (!n->right->right)
                    n->right = n->right->left;
                else if (!n->right->left)
                    n->right = n->right->right;
                else {
                    node *ptr = n->right->left;
                    while (ptr->right->right)
                        ptr = ptr->right;
                    node *t = ptr->right->left;
                    ptr->right->left = n->right->left;
                    n->right = ptr->right;
                    ptr->right = t;
                }
                printf("deleted\n");
                free(temp);
                return;
            }
            n = n->right;
        }
    }
    printf("absent\n");
}

void print(node *n) {
    if (n) {
        printf("(");
        print(n->left);
        printf("%d", n->val);
        print(n->right);
        printf(")");
    }
}

void freeall(node *n) {
    if (n) {
        freeall(n->left);
        freeall(n->right);
        free(n);
    }
}

int main(int argc, char **argv) {
    char op;
    int num;
    while (scanf("%c", &op) != EOF) {
        if (op == 'i') {
            scanf("%d", &num);
            insert(num);
        }
        else if (op == 's') {
            scanf("%d", &num);
            search(num);
        }
        else if (op == 'd') {
            scanf("%d", &num);
            delete(num);
        }
        else if (op == 'p') {
            print(root);
            printf("\n");
        }
    }
    freeall(root);
    return EXIT_SUCCESS;
}
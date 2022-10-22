#include <stdio.h>
#include <stdlib.h>
#include "./encadeada.h"

typedef struct _node {
    int key;
    struct _node * next;
} Node;

typedef struct _list {
    Node * first;
    Node * last;
} List;

Node * newNode() {
    /* Creates a new node (you're not supposed to use that) */
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}

void setKey(Node *n, int x) {
    n->key = x;
}

List * newList() {
    /* Creates a new list */
    List *newList = (List *) malloc(sizeof(List));
    return newList;
}

int getLength(List *l) {
    /* Return the length of the list l */
    int i = 1;
    Node *n = l->first;
    if (n == NULL) {
        return 0;
    }
    while (n->next != NULL) {
        n = n->next;
        i++;
    }
    return i;
}

int isInside(List *l, int x) {
    /* Returns if x is on the list l (boolean) */
    Node *n = l->first;
    int i, r = 0, s = getLength(l);
    if (s != 0) {
        for (i = 0; i < getLength(l); i++) {
            if (n->key == x) {
                r = 1;
            }
            n = n->next;
        }
    }
    return r;
}

int getPosition(List *l, int x) {
    /* Returns the position of x on the list l (-1 if the list doesn't have a element of value x) */
    int i = 0, s = getLength(l);
    Node *n = l->first;
    if (s != 0) {
        if (isInside(l, x)) {
            while ((n->key != x) && (i < getLength(l))) {
                n = n->next;
                i++;
            }
            return i;
        }
        return -1;
    }
    return -1;
}

void includeElement(List *l, int x) {
    /* Includes an element of value x to the final of the list l */
    Node *pt = newNode();
    setKey(pt, x);
    if (getLength(l) == 0) {
        l->first = pt;
        l->last = pt;
    }
    l->last->next = pt;
    l->last = pt;
    l->last->next = NULL;
}

void removeElement(List *l, int x) {
    /* Removes an element of value x from the list l, if l contains it */
    Node *n = l->first;
    Node *m = n->next;
    if (isInside(l, x)) {
        if (n->key == x) {
            l->first = l->first->next;
        } else {
            while (m->key != x) {
                n = n->next;
                m = m->next;
            }
            n->next = m->next;
            free(m);
        }
    } else {
        printf("Element is not on the list.\n");
    }
}

int getElement(List *l, int p) {
    /* Returns the element of the list l with index p, if it exists */
    int i = 0, s = getLength(l);
    Node *n = l->first;
    if (p+1 <= s) {
        while (i != p) {
            n = n->next;
            i++;
        }
        return n->key;
    } else {
        printf("Out of bounds\n");
        return -1;
    }
}

void changeValue(List *l, int p, int v) {
    /* Change the value of the element of value p from the list l to a new value v */
    int i;
    Node *n = l->first;
    if (getLength(l) - 1 >= p) {
        for (i = 0; i < p; i++) {
            n = n->next;
        }
        n->key = v;
    }
}

void printList(List *l) {
    /* Prints the list l in the format [a, b, c, d] */
    int i, s = getLength(l);
    Node *n = l->first;
    if (s == 0) {
        printf("[]\n");
    } else {
        printf("[");
        for (i = 0; i < s; i++) {
            if (i != s-1) {
                printf("%d, ", n->key);
            } else {
                printf("%d", n->key);
            }
            n = n->next;
        }
        printf("]\n");
    }
}

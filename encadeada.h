#ifndef encadeada_h
#define encadeada_h

typedef struct _node Node;
typedef struct _list List;
Node * newNode();
void setKey(Node *n, int x);
List * newList();
int getLength(List *l);
int isInside(List *l, int x);
int getPosition(List *l, int x);
void includeElement(List *l, int x);
void removeElement(List *l, int x);
int getElement(List *l, int p);
void changeValue(List *l, int p, int v);
void printList(List *l);

#endif
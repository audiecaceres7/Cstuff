#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
  int value;
  struct node *prev;
  struct node *next;
}
node;

// removing node
int remove_node(node **head, node **tail, int *length, node **n);

// adding to the head 
int prepend(node **head, node **tail, int *length, int item);

// adding to the tail
int append(node **head, node **tail, int *length, int item);

// removing element by value
int remove_item(node **head, node **tail, int *length, int item);

// print linked list
void print_linked_list(node **head, node **tail, int *length);

// free nodes
void free_linked_list(node **head);

int main(void)
{
  int length = 0;
  node *head = NULL;
  node *tail = NULL;

  for (int i = 0; i < 10; i++)
  {
    append(&head, &tail, &length, i);
  }

  remove_item(&head, &tail, &length, 7);
  remove_item(&head, &tail, &length, 3);

  print_linked_list(&head, &tail, &length);

  free_linked_list(&head);
  return 0;
}

int append(node **head, node **tail, int *length, int item) 
{
  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }

  (*length)++;
  n->value = item;
  n->next = NULL;
  n->prev = NULL;
  
  if ((*tail) == NULL && (*head) == NULL) 
  {
    (*tail) = n;
    (*head) = n;
    return 0;
  } 

  n->prev = (*tail);
  (*tail)->next = n;
  (*tail) = n;
  
  return 0;
}

int prepend(node **head, node **tail, int *length, int item) 
{
  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }

  (*length)++;
  n->value = item;
  n->next = NULL;
  n->prev = NULL;
  
  if ((*tail) == NULL && (*head) == NULL) 
  {
    (*tail) = n;
    (*head) = n;
    return 0;
  } 

  n->next = (*head);
  (*head)->prev = n;
  (*head) = n;

  return 0;
}

void print_linked_list(node **head, node **tail, int *length) 
{
  node *ptr = (*head);
  for (int i = 0; i < (*length); i++) 
  {
    if (ptr == (*tail))
    {
      printf("%i ", ptr->value);
      break;
    }
    printf("%i -> ", ptr->value);
    ptr = ptr->next;
  }
  printf("\n");
}

void free_linked_list(node **head) {
  while ((*head) != NULL) {
    node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
  }
}

int remove_node(node **head, node **tail, int *length, node **n)
{ 
  if ((*length) == 0) 
  {
    int out = (*head)->value;
    (*head) = NULL;
    (*tail) = NULL;
    return out;
  }
  
  (*n)->prev->next = (*n)->next;
  (*n)->next->prev = (*n)->prev;

  if ((*n) == (*head))
  {
    (*head) = (*n)->next;
  }

  if ((*n) == (*tail))
  {
    (*head) = (*n)->next;
  }

  (*n)->prev = NULL;
  (*n)->next = NULL;

  return (*n)->value;
}

int remove_item(node **head, node **tail, int *length, int item) {
  node *ptr = (*head);
  while (ptr != NULL)
  {
    if (ptr->value == item)
    {
      break;
    }
    ptr = ptr->next;
  }

  return remove_node(head, tail, length, &ptr);
}

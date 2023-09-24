#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node 
{
  int value;
  struct node *next;
}
node;

int print_linked_list(node **head);
int deque(node **head, int *length);
int enqueue(int value, node **head, node **tail, int *length);
int find_value(node **head, int value);

// Linked list using the Queue adt
int main(int argc, char *argv[]) 
{
  while (argc != 2)
  {
    printf("Missing command line argument! \n");
    return 1;
  }

  node *head = NULL;
  node *tail = NULL;
  int length = 0;

  for (int i = 1; i <= 10; i++)
  {
    enqueue(i, &head, &tail, &length);
  }

  printf("Head is %i\n", head->value);
  printf("Tail is %i\n", tail->value);

  print_linked_list(&head);

  int value = deque(&head, &length);
  int other = deque(&head, &length);
  printf("The value eliminated was %i\n", value);
  printf("The value eliminated was %i\n", other);

  print_linked_list(&head);

  int item = atoi(argv[1]);

  find_value(&head, item);

  printf("Length is %i\n", length);

  return 0;
}

int find_value(node **head, int item)
{
  node *ptr = *head;
  while (ptr != NULL)
  {
    if (ptr->value == item)
    {
      printf("Value exists! \n");
      return 0; 
    }
    ptr = ptr->next;
  }

  printf("value wasn't found! \n");
  free(ptr);
  return 1;
}

int print_linked_list(node **head)
{
  node *ptr = *head;
  while (ptr != NULL)
  {
    printf("%i ", ptr->value);
    ptr = ptr->next;
  }
  
  printf("\n");
  return 0;
}

int deque(node **head, int *length)
{
  if (*head == NULL)
  {
    return 1;
  }

  node *h = *head;
  (*head) = (*head)->next;

  (*length)--;
  return h->value;

  free(h);
}

int enqueue(int value, node **head, node **tail, int *length)
{
  (*length)++;
  node *n = malloc(sizeof(node));

  if (n == NULL)
  {
    return 1;
  }

  n->value = value;
  n->next = NULL;

  if (*tail == NULL)
  {
    *tail = n;
    *head = n;
  } 

  else
  {
    (*tail)->next = n;
    *tail = n;
  }

  return 0;
}

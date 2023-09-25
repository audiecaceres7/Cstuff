#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// check if list is empty
int check_array(int *length);

// insert element front/back or any other position
int insert(int *array[], int index, int item, int *length);

// Remove element from any position
int remove_element(int *array[], int index, int *length);

// Read and Modify an element at a position
int modify(int *array[], int index, int value);

// Search list for and element
int search(int *array[], int value, int *length);

// print array
int print_array(int *array[], int *length);

int main(void)
{
  int length = 5;
  int *array = malloc(sizeof(int) * length);

  for (int i = 0; i < 5; i++)
  {
    array[i] = i + 1;
  }

  // printing all
  print_array(&array, &length);
  check_array(&length);

  int val = insert(&array, 2, 31, &length);
  if (val == -1)
  {
    printf("Index not found. \n");
    return 1;
  }

  // printing all
  print_array(&array, &length);
  check_array(&length);

  int removed_element = remove_element(&array, 1, &length);
  if (removed_element == -1) 
  {
    printf("Index not found. \n");
    return 1;
  }

  print_array(&array, &length);
  check_array(&length);

  modify(&array, 3, 9);

  print_array(&array, &length);
  check_array(&length);

  search(&array, 31, &length);

  return 0;
}


int print_array(int *array[], int *length)
{
  for (int i = 0; i < *length; i++)
  {
    printf("%i ", (*array)[i]);
  }

  printf("\n");
  return 0;
}

int check_array(int *length)
{ 
  if (*length == 0)
  {
    printf("Array is empty. \n");
    printf("\n");
    return 1;
  }

  printf("Length is %i\n", *length);
  printf("\n");
  return 0;
}

int insert(int *array[], int index, int item, int *length)
{
  if (index > (*length) - 1)
  {
    return -1; 
  }

  (*length)++;

  if (index == (*length) - 1) 
  {
    (*array)[(*length) - 1] = item;
    return 0; 
  } 

  for (int j = *length - 1; j > index; j--)
  {
    int tmp = (*array)[j];
    (*array)[j] = (*array)[j - 1];
    (*array)[j - 1] = tmp;
  }
  
  (*array)[index] = item;
  return 0;
}

int remove_element(int *array[], int index, int *length)
{
  if (index > (*length) - 1)
  {
    return -1;
  }

  if (index == (*length) - 1)
  {
    (*array)[(*length) - 1] = 0;
    (*length)--;
    return 0;
  }


  (*array)[index] = 0;
  for (int j = index; j < (*length); j++)
  {
    int tmp = (*array)[j];
    (*array)[j] = (*array)[j + 1];
    (*array)[j + 1] = tmp;
  }

  (*length)--;

  return 0;
}

int modify(int *array[], int index, int value)
{
  int old_value = (*array)[index];
  (*array)[index] = value;

  printf("Value from ( index %i ) value %i was modified to %i\n", index, old_value, value);
  return 0;
}

int search(int *array[], int item, int *length)
{
  for (int i = 0; i < (*length); i++)
  {
    if ((*array)[i] == item)
    {
      printf("Value %i found. \n", item);
      return 0;
    } 
  }
  printf("Value not found. \n");
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../models/models.h "

Node *addPatient(char *name, int day, char *month, int year, long long int old)
{
  Node *temp = (Node *)(malloc(sizeof(Node)));
  strcpy(temp->p.name, name);
  temp->p.day = day;
  strcpy(temp->p.month, month);
  temp->p.year = year;
  temp->p.old = old;
  temp->next = temp->prev = NULL;
  return temp;
}

void pushPQ(char *name, int day, char *month, int year, long long int old)
{
  Node *temp = addPatient(name, day, month, year, old);
  if (!head)
  {
    head = tail = temp;
  }
  else if (old < head->p.old)
  {
    temp->next = head;
    head->prev;
    head = temp;
  }
  else if (old > head->p.old)
  {
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
  else
  {
    Node *curr = head;
    while (curr && curr->next->p.old < temp->p.old)
    {
      curr = curr->next;
    }
    curr->next->prev = temp;
    temp->next = curr->next;
    curr->next = temp;
    temp->prev = curr;
  }
}

void removePQ()
{
  if (head && head == tail)
  {
    head = tail = NULL;
    free(head);
  }
  else
  {
    Node *newTail = tail->prev;
    tail->prev = newTail->next = NULL;
    free(tail);
    tail = newTail;
  }
}

void printPatient(int cure)
{
  int need = 0;

  Node *curr = head;
  while (curr)
  {
    need++;
    curr = curr->prev;
  }

  if (cure >= need)
  {
    printf("All patients get the cure, %d cure left\n", cure - need);
  }
  else if (cure < need)
  {

    Node *curr = head;
    printf("Need %d more cure\n", need - cure);
    while (curr)
    {
      printf("%d %s %d - %s\n", curr->p.day, curr->p.month, curr->p.year, curr->p.name);
    }
  }
}
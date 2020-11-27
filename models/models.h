struct patient
{
  char name[255];
  int day;
  char month[20];
  int year;
  long long int old;
};

struct Node
{
  patient p;
  Node *prev, *next;
} * head, *tail;

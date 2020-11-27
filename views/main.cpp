#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../models/models.h"
#include "../controllers/controllers.h"

int main()
{
  int patient_count, totalcure_count;
  scanf("%d %d", patient_count, totalcure_count);
  getchar();

  char month[20], name[255];
  int day, year;

  for (int i = 0; i < patient_count; i++)
  {
    scanf("%d %s %d - %[^\n]", day, month, year, name);
    getchar();
    long long int old;
    if (strcmp(month, "january") == 0)
    {
      old = 1;
    }
    else if (strcmp(month, "february") == 0)
    {
      old = 2;
    }
    else if (strcmp(month, "march") == 0)
    {
      old = 3;
    }
    else if (strcmp(month, "april") == 0)
    {
      old = 4;
    }
    else if (strcmp(month, "may") == 0)
    {
      old = 5;
    }
    else if (strcmp(month, "june") == 0)
    {
      old = 6;
    }
    else if (strcmp(month, "july") == 0)
    {
      old = 7;
    }
    else if (strcmp(month, "august") == 0)
    {
      old = 8;
    }
    else if (strcmp(month, "september") == 0)
    {
      old = 9;
    }
    else if (strcmp(month, "oktober") == 0)
    {
      old = 10;
    }
    else if (strcmp(month, "november") == 0)
    {
      old = 11;
    }
    else if (strcmp(month, "desember") == 0)
    {
      old = 12;
    }

    old = (30 * old) + (365 * year) + day;
    pushPQ(name, day, month, year, old);
  }

  for (int i = 0; i < totalcure_count; i++)
  {
    removePQ();
  }

  printPatient(totalcure_count);

  return 0;
}
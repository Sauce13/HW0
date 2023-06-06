
#include "GenericTraits.h"
#include <string.h>

#define MAX_TYPES 256
static char *type_names[MAX_TYPES];
static void *(*constructors[MAX_TYPES])(char *);
static void (*destructors[MAX_TYPES])(void *);
static int num_types = 0;

Constructor get_constructor(char *type_name)
{
  /* Your code here to get the constructor of the struct' */
  for (int i = 0; i < num_types; i++)
  {
    if (strcmp(type_names[i], type_name) == 0)
    {
      return constructors[i];
    }
  }
  return NULL;
}
Destructor get_destructor(char *type_name)
{
  /* Your code here to get the destructor of the struct' */
  for (int i = 0; i < num_types; i++)
  {
    if (strcmp(type_names[i], type_name) == 0)
    {
      return destructors[i];
    }
  }
  return NULL;
}

void add_ctor_dtor(char *type_name, Constructor ctor, Destructor dtor)
{
  /* Your code here to register the struct */

  type_names[num_types] = strdup(type_name);
  constructors[num_types] = ctor;
  destructors[num_types] = dtor;
  num_types++;
}

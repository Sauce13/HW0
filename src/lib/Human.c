
#include "Human.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Your code here to define the struct */

#include "Human.h"
#include <string.h>

void *new_Human(char *input)
{
    Human *new_human = malloc(sizeof(Human));
    new_human->impl = malloc(sizeof(GenericTraits));

    new_human->impl->new = new_Human;
    new_human->impl->dump = dump_Human;
    new_human->impl->cmp = cmp_Human;
    new_human->impl->drop = drop_Human;

    if (input != NULL)
    {
        char *end_of_name = strpbrk(input, " \n");
        if (end_of_name != NULL)
        {
            *end_of_name = '\0';
        }

        strncpy(new_human->name, input, 256 - 1);
        new_human->name[256 - 1] = '\0';
    }
    else
    {
        memset(new_human->name, '\0', 256);
    }

    return new_human;
}

void dump_Human(void *self, FILE *fp)
{
    Human *this_human = (Human *)self;
    fprintf(fp, "%s\n", this_human->name);
}

int cmp_Human(void *self, void *other)
{
    Human *human1 = (Human *)self;
    Human *human2 = (Human *)other;

    return strcmp(human1->name, human2->name);
}

void drop_Human(void *self)
{
    free(self);
}

void __attribute__((constructor)) register_Human()
{
    add_ctor_dtor("Human", new_Human, drop_Human);
}

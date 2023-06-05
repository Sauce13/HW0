#include "Int.h"
#include <stdint.h>

/* Your code here to define the struct */

void *new_Int(char *string)
{
    Int *i = malloc(sizeof(Int));
    i->impl = malloc(sizeof(GenericTraits));

    i->impl->new = new_Int;
    i->impl->dump = dump_Int;
    i->impl->cmp = cmp_Int;
    i->impl->drop = drop_Int;

    printf("In new_Int: new=%p, dump=%p, cmp=%p, at address %p\n",
           i->impl->new, i->impl->dump, i->impl->cmp, i->impl->drop, i->impl);

    i->i = atoi(string);

    return i;
}

void dump_Int(void *self, FILE *fp)
{
    Int *i = (Int *)self;
    fprintf(fp, "0x%X", i->i);
}

int cmp_Int(void *self, void *other)
{
    Int *i1 = (Int *)self;
    Int *i2 = (Int *)other;

    if (i1->i < i2->i)
    {
        return -1;
    }
    else if (i1->i > i2->i)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void drop_Int(void *self)
{
    Int *i = (Int *)self;
    free(i->impl);
    free(i);
}

void __attribute__((constructor)) register_Int()
{
    add_ctor_dtor("Int", new_Int, drop_Int);
}
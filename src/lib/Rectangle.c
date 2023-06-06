
#include "Rectangle.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

/* Your code here to define the struct */

void *new_Rectangle(char *input)
{
    Rectangle *new_rectangle = malloc(sizeof(Rectangle));
    new_rectangle->impl = malloc(sizeof(GenericTraits));

    new_rectangle->impl->new = new_Rectangle;
    new_rectangle->impl->dump = dump_Rectangle;
    new_rectangle->impl->cmp = cmp_Rectangle;
    new_rectangle->impl->drop = drop_Rectangle;

    if (input != NULL)
    {
        char *height = strtok(input, " ");
        char *width = strtok(NULL, " ");
        if (height != NULL && width != NULL)
        {
            new_rectangle->height = atoi(height);
            new_rectangle->width = atoi(width);
        }
    }

    return new_rectangle;
}

void dump_Rectangle(void *self, FILE *fp)
{
    Rectangle *this_rectangle = (Rectangle *)self;
fprintf(fp, "%" PRIu64 " %" PRIu64 "\n", this_rectangle->height, this_rectangle->width);
}

int cmp_Rectangle(void *self, void *other)
{
    Rectangle *rect1 = (Rectangle *)self;
    Rectangle *rect2 = (Rectangle *)other;

    uint64_t area1 = rect1->height * rect1->width;
    uint64_t area2 = rect2->height * rect2->width;

    if (area1 > area2)
    {
        return 1; 
    }
    else if (area1 < area2)
    {
        return -1; 
    }
    else
    {
        if (rect1->height != rect2->height)
        {
            return rect1->height - rect2->height;
        }
        else
        {
            return rect1->width - rect2->width;
        }
    }
}

DEFINE_STRUCT(Rectangle)

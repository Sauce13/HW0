#include "Student.h"
#include "Human.h"
#include "stdint.h"
#include "string.h"

/* Your code here to define the struct */

void *new_Student(char *input)
{
    Student *new_student = (Student *)malloc(sizeof(Student));
    new_student->base.impl = (GenericTraits *)malloc(sizeof(GenericTraits));

    new_student->base.impl->new = new_Student;
    new_student->base.impl->dump = dump_Student;
    new_student->base.impl->cmp = cmp_Student;
    new_student->base.impl->drop = drop_Student;

    char *name = strtok(input, " ");
    char *grade = strtok(NULL, " ");

    if (name != NULL && grade != NULL)
    {
        strncpy(new_student->base.name, name, sizeof(new_student->base.name) - 1);
        new_student->grade = atoi(grade);
    }

    return new_student;
}

void dump_Student(void *self, FILE *fp)
{
    Student *this_student = (Student *)self;
    fprintf(fp, "%s %d\n", this_student->base.name, this_student->grade);
}

int cmp_Student(void *self, void *other)
{
    Student *student1 = (Student *)self;
    Student *student2 = (Student *)other;

    int grade_diff = student1->grade - student2->grade;

    if (grade_diff != 0)
    {
        return grade_diff;
    }
    else
    {
        return cmp_Human(&student1->base, &student2->base);
    }
}

void drop_Student(void *self)
{
    Student *s = (Student *)self;
    drop_Human(&s->base);
}

void __attribute__((constructor)) register_Student()
{
    add_ctor_dtor("Student", new_Student, drop_Student);
}
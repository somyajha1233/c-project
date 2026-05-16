#include <stdio.h>

struct Student
{
    char name[50];
    int marks[3];
    int total;
    float average;
    char grade;
};

int main()
{
    struct Student s[5];
    int i, j;

    FILE *fp;

    // Input student details
    for(i = 0; i < 5; i++)
    {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);

        s[i].total = 0;

        for(j = 0; j < 3; j++)
        {
            printf("Enter marks of subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);

            s[i].total += s[i].marks[j];
        }

        s[i].average = s[i].total / 3.0;

        // Grade calculation
        if(s[i].average >= 80)
            s[i].grade = 'A';
        else if(s[i].average >= 60)
            s[i].grade = 'B';
        else if(s[i].average >= 40)
            s[i].grade = 'C';
        else
            s[i].grade = 'F';
    }

    // File handling
    fp = fopen("student.txt", "w");

    fprintf(fp, "Name\tTotal\tAverage\tGrade\n");

    for(i = 0; i < 5; i++)
    {
        fprintf(fp, "%s\t%d\t%.2f\t%c\n",
                s[i].name,
                s[i].total,
                s[i].average,
                s[i].grade);
    }

    fclose(fp);

    printf("\nStudent data saved in file successfully.\n");

    return 0;
}
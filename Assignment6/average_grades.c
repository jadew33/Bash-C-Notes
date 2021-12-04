#include <stdio.h>
#include <stdlib.h>
 #include <math.h>

void countStudentsAndAssignments(const char *filename, int *numAssignments, int *numStudents);
int countCommas(char line[]);

int main(void)
{
    const char *filename = "grades2.txt";
    int *numStudents = 0, *numAssignments =0;
    // int loops = numStudents(filename);
    countStudentsAndAssignments(filename, numAssignments,numStudents);
    printf("A: %d, S: %d", (int)numAssignments, (int)numStudents);

    // FILE *f = fopen(filename, "r");
    // if (!f)
    // {
    //     fprintf(stderr, "Could not open /etc/passwd for reading");
    //     exit(1);
    // }
    // char buf[100];
    // while (fgets(buf, 100, f))
    // {
    //     printf("%s\n", buf);
    //     countCommas(buf);
    //     numStudents++;
    // }
    // fclose(f);
}

void countStudentsAndAssignments(const char *filename, int *numAssignments, int *numStudents)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Could not read file ");
        printf("%s\n", filename);
        exit(1);
    }
    char buf[100];
    while (fgets(buf, 100, f))
    {
        *numStudents++;
    }
    fclose(f);
}

// int countCommas(char line[])
// {
//     // char str1[100];
//     // char str2[100];
//     // int a1, a2, a3, a4, result, i;
//     // result = sscanf(line, "%[^','],%[^','],%[^','],%s", o, s, t, f);
// char s1[100],s2[100],s3[100],s4[100],s5[100],s6[100];
//     //  printf("in function %s\n", line);
//     // int n = sscanf(line, "%s,%s", str1, str2);
//     // printf("line = %d, str1 = %s, str2 = %s\n", n, str1, str2);
// int n = sscanf(line, "%*[^,],%[^,],%lu,%lu,%lu,%lu", s1,s2,s3,s4,s5,s6);
// printf("%s %s %s %s %s %s", s1,s2,s3,s4,s5,s6);
//     //    result = sscanf(tokenstring, "%[^','],%[^','],%[^','],%s", o, s, t, f);

// }

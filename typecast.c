#include<stdio.h>
int main()
{
    int salary;
    float sal;
    printf("enter salary:");
    scanf("%d",&salary);
    sal=(float)salary;
    printf("The floating point variable of %d is %f",salary,sal);
}
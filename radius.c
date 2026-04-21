#include<stdio.h>
int main()
{
    float radius;
    float area;
    printf("Area of circle calculator\n");
    printf("Enter the radius of the circle:");
    scanf("%f",&radius);
    area=3.14*radius*radius;
    printf("The area of the circle is %f",area);
    
}
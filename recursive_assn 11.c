#include <stdio.h> 
int factorial(int n) { 
    if (n == 0 || n == 1) { 
        return 1; 
    } 
    return n * factorial(n - 1); 
} 
int fibonacci(int n) { 
    if (n == 0) { 
        return 0; 
    } 
    if (n == 1) { 
        return 1; 
    } 
    return fibonacci(n - 1) + fibonacci(n - 2); 
} 
int main() { 
    int choice, num, i; 
    do { 
        printf("\n--- Recursion Menu ---\n"); 
        printf("1. Factorial\n"); 
        printf("2. Fibonacci Series\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch(choice) { 
            case 1: 
                printf("Enter a positive number: "); 
                scanf("%d", &num); 
 
                if (num < 0) { 
                    printf("Factorial is not defined for negative numbers.\n"); 
                } else { 
                    printf("Factorial of %d is: %d\n", num, factorial(num)); 
                } 
               break; 
       case 2: 
                printf("Enter the number of terms: "); 
                scanf("%d", &num); 
                if (num <= 0) { 
                    printf("Please enter a number greater than 0.\n"); 
                } else { 
                    printf("Fibonacci Series: "); 
                    for (i = 0; i < num; i++) { 
                        printf("%d ", fibonacci(i)); 
                    } 
                    printf("\n"); 
                } 
                break; 
            case 3: 
                printf("Exiting program...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while(choice != 3); 
    return 0; 
} 
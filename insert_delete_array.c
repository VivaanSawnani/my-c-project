#include<stdio.h>

int main()
{
    int n, a[30];
    int c = 0, p, v, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &a[i]);
    }

    while(c != 4)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("Insert has been selected\n");
                printf("Enter position (0 to %d) and value: ", n);
                scanf("%d %d", &p, &v);

                if(p < 0 || p > n){
                    printf("Invalid position\n");
                    break;
                }

                for(i = n; i > p; i--)
                {
                    a[i] = a[i-1];
                }
                a[p] = v;
                n++;
                break;

            case 2:
                printf("Delete has been selected\n");
                printf("Enter the position to be deleted: ");
                scanf("%d", &p);

                if(p < 0 || p >= n){
                    printf("Invalid position\n");
                    break;
                }

                for(i = p; i < n-1; i++)
                {
                    a[i] = a[i+1];
                }
                n--;
                break;

            case 3:
                printf("Display has been selected\n");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                break;

            case 4:
                printf("Exit has been selected\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

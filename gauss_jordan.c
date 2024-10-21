// Gauss Jordan Method

#include <stdio.h>
#include <math.h>

#define SIZE 10

void printMatrix(float a[SIZE][SIZE], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of Augmented Matrix:\n");
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nInitial Augmented Matrix:\n");
    printMatrix(a, n);

    for (i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == i)
                    continue;
                if (a[j][i] != 0.0)
                {
                    for (int k = 1; k <= n; k++)
                    {
                        int temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                }
            }
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }

                printf("Matrix after making a[%d][%d] zero:\n", j, i);
                printMatrix(a, n);
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return 0;
}

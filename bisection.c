#include <stdio.h>
#include <math.h>
#define N 30
#define f(x) (x * x * x + 3 * x - 10)
int main()
{
    float a, b, c, fa, fb, fc, e;

    int step = 1;

    printf("Enter the interval [a, b]:\n");
    scanf("%f%f", &a, &b);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);

    fa = f(a);
    fb = f(b);

    if (fa * fb == 0)
    {

        printf("Guessed interval is the root %d %d", a, b);
        return 0;
    }

    if (fa * fb > 0)
    {

        printf("Incorrect initial guesses. f(a) and f(b) must have different signs.\n");
        return 0;
    }

    printf("\nStep\t\ta\t\tb\t\tc\t\tf(c)\n");

    do
    {

        c = (a + b) / 2;
        fc = f(c);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, a, b, c, fc);

        if (fabs(fc) < e || step >= N)
        {
            break;
        }

        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        step++;

    } while (1);

    printf("\nRoot is: %f\n", c);
    return 0;
}

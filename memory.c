#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72;
    x[2] = 73;
    x[3] = 74;
}
/**there are two (main) mistake (not syntax error) in the program above,
 * and use a command 'valgrind ./memory' can help me figure them out. and the correct is below.
#include <stdlib.c>
#include <stdio.c>
int main(void)
{
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)  //not must
    {
        return 1;
    }
    x[0] = 72;
    x[1] = 73;
    x[2] = 74;
    free(x);
    return 0;
}
*/

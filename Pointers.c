#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 10;
    int* numberP = &number;
    int** numberPP = &numberP;

    printf("\nValor da variavel number: %d", number);
    printf("\nEndereço da variavel number: %p", &number);

    printf("\nValor da variavel numberP: %p", numberP);
    printf("\nValor apontado por numberP: %d", *numberP);
    printf("\nEndereço da variavel numberP: %p", &numberP);
//    printf("\nValor da variavel numberP++: %p", ++numberP);

    printf("\nValor da variavel numberPP: %p", numberPP);
    printf("\nValor apontado no primeiro nivel por numberPP: %p", *numberPP);
     printf("\nValor apontado no segundo nivel por numberPP: %d", **numberPP);
    printf("\nEndereço da variavel numberPP: %p", &numberPP);

    printf("\n\n");
/*
    float *pi = (float*)malloc(sizeof(float));
    *pi = 3.1415;
    printf("\nValor apontado por pi: %f", *pi);
    printf("\nEndereço de pi: %p", pi);
    free(pi);
    printf("\nValor apontado por pi apos free: %f", *pi);
    printf("\nEndereço de pi apos free: %p", pi);
    *pi = 0;
    printf("\nValor apontado por pi apos atribuir 0: %f", *pi);
    pi = NULL;
    printf("\nEndereço de pi apos atribuir NULL: %p", pi);

    printf("\n\n");
*/
    return EXIT_SUCCESS;
}

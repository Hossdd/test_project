#include<stdio.h>
#include<conio.h>
void main()
{
    int A, B, codeA[8], codeB[8], As[8], Bs[8], Cs[8], i, a = 0, b = 0;
    clrscr();
    printf("Enter Data A : ");
    scanf("%d", &A);
    if(A == 0)
    {
        A = -1;
    }
    printf("Enter Data B : ");
    scanf("%d", &B);
    if(B == 0)
    {
        B = -1;
    }
    printf("\nEnter codeA : ");
    for(i = 0; i < 8; i++)
    {
        scanf("%d", &codeA[i]);
        if(codeA[i] == 0)
        {
            codeA[i] = -1;
        }
    }
    printf("Enter codeB : ");
    for(i = 0; i < 8; i++)
    {
        scanf("%d", &codeB[i]);
        if(codeB[i] == 0)
        {
            codeB[i] = -1;
        }
    }
    printf("\ncodeA : ");
    for(i = 0; i < 8; i++)
    {
        printf("%d ", codeA[i]);
    }

    printf("\ncodeB : ");
    for(i = 0; i < 8; i++)
    {
        printf("%d ", codeB[i]);
    }

    for(i = 0; i < 8; i++)
    {
        As[i] = A * codeA[i];
        Bs[i] = B * codeB[i];
        Cs[i] = As[i] + Bs[i];
    }

    printf("\nAs : ");
    for(i = 0; i < 8; i++)
    {
        printf(" %d", As[i]);
    }

    printf("\nBs : ");
    for(i = 0; i < 8; i++)
    {
        printf(" %d", Bs[i]);
    }

    printf("\n\nCs : ");
    for(i = 0; i < 8; i++)
    {
        printf(" %d", Cs[i]);
    }

    for(i = 0; i < 8; i++)
    {
        a = a + codeA[i] * Cs[i];
        b = b + codeB[i] * Cs[i];
    }

    if(a > 0) {
        printf("\nA : 1");
    } else {
        printf("\nA : 0");
    }

    if(b > 0) {
        printf("\nB : 1");
    } else {
        printf("\nB : 0");
    }
    getch();
} 
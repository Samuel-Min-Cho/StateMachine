#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct state
{
    char n;
    struct state *zero;
    struct state *one;
};

void printList(struct state *array[])
{
    struct state *p;
    for (int i = 0; i < 8; i++)
    {
        p = array[i];
        if (p != NULL)
        {
            printf("%c %c %c\n", p->n, p->zero->n, p->one->n);
        }
    }
}

void search(struct state *cs, struct state *nextCs, char array[])
{
    while (cs != nextCs)
    {
        for (int i = 0; i < 8; i++)
        {
            if (array[i] == nextCs->n)
            {
                return;
            }
        }
        sortArr(nextCs->n, array);
        search(nextCs, nextCs->one, array);
        search(nextCs, nextCs->zero, array);
    }
}

void sortArr(char c, char array[])
{
    if (c == 'A')
    {
        array[0] = 'A';
    }
    else if (c == 'B')
    {
        array[1] = 'B';
    }
    else if (c == 'C')
    {
        array[2] = 'C';
    }
    else if (c == 'D')
    {
        array[3] = 'D';
    }
    else if (c == 'E')
    {
        array[4] = 'E';
    }
    else if (c == 'F')
    {
        array[5] = 'F';
    }
    else if (c == 'G')
    {
        array[6] = 'G';
    }
    else if (c == 'H')
    {
        array[7] = 'H';
    }
}

int main(int argc, char *argv[])
{
    struct state *A = (struct state *)malloc(sizeof(struct state));
    struct state *B = (struct state *)malloc(sizeof(struct state));
    struct state *C = (struct state *)malloc(sizeof(struct state));
    struct state *D = (struct state *)malloc(sizeof(struct state));
    struct state *E = (struct state *)malloc(sizeof(struct state));
    struct state *F = (struct state *)malloc(sizeof(struct state));
    struct state *G = (struct state *)malloc(sizeof(struct state));
    struct state *H = (struct state *)malloc(sizeof(struct state));

    A->n = 'A';
    A->zero = H;
    A->one = C;

    B->n = 'B';
    B->zero = C;
    B->one = A;

    C->n = 'C';
    C->zero = E;
    C->one = F;

    D->n = 'D';
    D->zero = F;
    D->one = H;

    E->n = 'E';
    E->zero = A;
    E->one = D;

    F->n = 'F';
    F->zero = G;
    F->one = E;

    G->n = 'G';
    G->zero = B;
    G->one = G;

    H->n = 'H';
    H->zero = D;
    H->one = G;
    struct state *array[] = {A, B, C, D, E, F, G, H};
    struct state *cs = B;

    printf("%c\n", cs->n);
    char input[10];
    do
    {
        fgets(input, 20, stdin);
        if (input[0] == '0')
        {
            cs = cs->zero;
            printf("%c\n", cs->n);
        }

        else if (input[0] == '1')
        {
            cs = cs->one;
            printf("%c\n", cs->n);
        }

        else if ('c' == input[0])
        {
            for (int i = 0; i < 8; i++)
            {
                if (input[4] == array[i]->n)
                {
                    if (input[2] == '0')
                    {
                        cs->zero = array[i];
                        break;
                    }
                    else if (input[2] == '1')
                    {
                        cs->one = array[i];
                        break;
                    }
                }
            }
        }

        else if (input[0] == 'q')
        {
            printf("%c", cs->n);
        }

        else if (input[0] == 'p')
        {
            printList(array);
        }

        else if (input[0] == 'g')
        {
            char arr[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
            char listG[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
            sortArr(cs->n, arr);
            search(cs, cs->one, arr);
            search(cs, cs->zero, arr);
            int k = 0;
            for (int i = 0; i < 8; i++)
            {
                if (arr[i] == '0')
                {
                    k++;
                    listG[i] = array[i]->n;
		       printf("%c ", listG[i]);
                }
            }
            if (k == 0)
            {
                printf("No garbage");
            }
            printf("\n");
        }

        else if (input[0] == 'd')
        {
            char arr[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
            char listG[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
            sortArr(cs->n, arr);
            search(cs, cs->one, arr);
            search(cs, cs->zero, arr);
            for (int i = 0; i < 8; i++)
            {
                if (arr[i] == '0')
                {
                    listG[i] = array[i]->n;
                }
            }

            if (input[2] == NULL)
            {
                int j = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (listG[i] == array[i]->n)
                    {
                        array[i] = NULL;
                        j++;
                    }
                }
                if (j == 0)
                {
                    printf("No states deleted.\n");
                }
                else if (j > 0)
                {
                    printf("Deleted: ");
                    for (int i = 0; i <= j; i++)
                    {
                        if (listG[i] != '0')
                        {
			       printf("%c", listG[i]);
                        }
                    }
                    printf("\n");
                }
            }
            else if (input[2] != NULL)
            {
                int p = 0;
                for (int i = 0; i < 8; i++)
                {
		  //   printf("%c",listG[i]);
                    if (input[2] == listG[i])
                    {
                        if (input[2] == 'A')
                        {
                            p++;
                            array[0] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'B')
                        {
                            p++;
                            array[1] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'C')
                        {
                            p++;
                            array[2] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'D')
                        {
                            p++;
                            array[3] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'E')
                        {
                            p++;
                            array[4] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'F')
                        {
                            p++;
                            array[5] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'G')
                        {
                            p++;
                            array[6] = NULL;
                            printf("Deleted\n");
                        }
                        else if (input[2] == 'H')
                        {
                            p++;
                            array[7] = NULL;
                            printf("Deleted\n");
                        }
                    }
                }
                if (p == 0){
                    printf("Not Deleted.\n");
                }
            }
        }
    } while ('z' != input[0]);
    exit(0);
}

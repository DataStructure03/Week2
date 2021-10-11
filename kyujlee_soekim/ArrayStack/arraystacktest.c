#include "arraystack.h"

void	displayStack(ArrayStack *pStack)
{
    int i = pStack->currentElementCount;
    if (isArrayStackEmpty(pStack)) printf("\nempty stack\n\n");
    if (isArrayStackFull(pStack)) printf("\nfull stack\n\n");
	while (--i >= 0)
		printf("|%d's data| [%d]\n",i, pStack->pElement[i].data);
	printf("\n");
}

int main()
{
	ArrayStack *AS = NULL;

	AS = createArrayStack(7);
	if (AS != NULL)
	{
		ArrayStackNode node;

		printf("---------------- push ----------------\n");
        
        node.data = 1;
		pushAS(AS, node);

		node.data = 2;
		pushAS(AS, node);

		node.data = 3;
		pushAS(AS, node);

		node.data = 4;
		pushAS(AS, node);

		node.data = 5;
		pushAS(AS, node);

		node.data = 6;
		pushAS(AS, node);

		node.data = 7;
		pushAS(AS, node);

		displayStack(AS);

        printf("---------------- pop ----------------\n");

        printf ("pop element is : %d \n",popAS(AS).data);
        printf ("pop element is : %d \n",popAS(AS).data);
        printf ("pop element is : %d \n",popAS(AS).data);
        printf ("pop element is : %d \n",popAS(AS).data);
        printf ("pop element is : %d \n",popAS(AS).data);
        printf ("pop element is : %d \n",popAS(AS).data);
        printf ("pop element is : %d \n",popAS(AS).data);
        //clearArrayStack(AS);
   		displayStack(AS);
	}
	deleteArrayStack(AS);
}

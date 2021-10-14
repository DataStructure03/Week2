#include "liststack.h"

static void	displayStack(LinkedStack *pStack)
{
	StackNode *tmp;
	int i = pStack->currentElementCount;
	tmp = pStack->pTopElement->preElement;

    if (isLinkedStackEmpty(pStack)) printf("\nempty stack\n\n");

	while (tmp)
	{
		printf("|%d's data| [%d]\n", --i, tmp->data);
		tmp = tmp->preElement;
	}
	printf("\n");
}

int main()
{
	// LinkedStack *LS = NULL;

	// LS = createLinkedStack();
	// if (LS != NULL)
	// {
	// 	StackNode node;

	// 	printf("---------------- push ----------------\n");
        
    //     node.data = 1;
	// 	pushLS(LS, node);

	// 	node.data = 2;
	// 	pushLS(LS, node);

	// 	node.data = 3;
	// 	pushLS(LS, node);

	// 	node.data = 4;
	// 	pushLS(LS, node);

	// 	node.data = 5;
	// 	pushLS(LS, node);

	// 	node.data = 6;
	// 	pushLS(LS, node);

	// 	node.data = 7;
	// 	pushLS(LS, node);

	// 	displayStack(LS);

    //     printf("---------------- pop ----------------\n");
        
    //     //there's memory leaks
    //     printf ("pop element is : %d \n",popLS(LS)->data);
    //     printf ("pop element is : %d \n",popLS(LS)->data);
    //     printf ("pop element is : %d \n",popLS(LS)->data);
    //     printf ("pop element is : %d \n",popLS(LS)->data);
    //     printf ("pop element is : %d \n",popLS(LS)->data);
    //     printf ("pop element is : %d \n",popLS(LS)->data);
    //     printf ("pop element is : %d \n\n",popLS(LS)->data);

    //     //there's no memory leaks
    //     // free(popLS(LS));
    //     // free(popLS(LS));
    //     // free(popLS(LS));
    //     // free(popLS(LS));
    //     // free(popLS(LS));
    //     // free(popLS(LS));
    //     // free(popLS(LS));

   	// 	displayStack(LS);
	// }
    // deleteLinkedStack(LS);


	// test for checkBracketMatching
	char *str_true[4] = { "hi a * ( a + b / {a - b} * ( a * (a + (c+d))) )/ {a b } [ a c b d]",
						"   ",
						 " ( [ {{{}}} ] )"};
	char *str_false[4] =  {"hi a * (( a + b / {a - b} * ( a * (a + (c+d))) )/ {a b } [ a c b d]",
						" [ ( { ) ] }",
						" ((( )"};

	for (int i = 0;str_true[i]; ++i)
		printf("result :%d of string :%s \n",checkBracketMatching(str_true[i]), str_true[i]);

	for (int i = 0;str_false[i]; ++i)
		printf("result :%d of string :%s \n",checkBracketMatching(str_false[i]), str_false[i]);
}

#include "liststack.h"


LinkedStack* createLinkedStack(){
    LinkedStack* ret = NULL;
    

    ret = (LinkedStack *)malloc(sizeof(LinkedStack));

    if (ret != NULL){
        ret->currentElementCount = 0;

        ret->pTopElement = (StackNode *)malloc(sizeof(StackNode));
        if (ret->pTopElement != NULL){
            ret->pTopElement->data.x = 0;
            ret->pTopElement->data.y = 0;
            ret->pTopElement->preElement = NULL;
        }
    }

    return ret;
}

void deleteLinkedStack(LinkedStack* pStack){
    int i = pStack->currentElementCount;
    while (--i >= 0)
        free(popLS(pStack));
    
    free(pStack->pTopElement);

    free(pStack);
}


int pushLS(LinkedStack* pStack, StackNode element){
    StackNode *New = NULL;

    if (pStack != NULL){
        New = (StackNode *)malloc(sizeof(StackNode));
        New->data = element.data;

        New->preElement = pStack->pTopElement->preElement;
        pStack->pTopElement->preElement = New;

        pStack->currentElementCount++;
        return true;
    }
    return false;
}
StackNode* popLS(LinkedStack* pStack){
    StackNode *ret = NULL;
    if (pStack != NULL){
        if (isLinkedStackEmpty(pStack) == false){
            // store return node(poped node)
            ret = pStack->pTopElement->preElement;
            // header node is pointing second node(next of ret)
            pStack->pTopElement->preElement = ret->preElement;
            ret->preElement = NULL;
            pStack->currentElementCount--;
        }
    }
    return (ret);
}


StackNode* peekLS(LinkedStack* pStack){
    if (pStack != NULL)
        return (pStack->pTopElement->preElement);
    else
        return NULL;
}


int isLinkedStackEmpty(LinkedStack* pStack){
    if (pStack->currentElementCount == 0)
        return true;
    else
        return false;
}

int deleteAndReturn(LinkedStack *stack, int result){
    deleteLinkedStack(stack);
    return result;
}

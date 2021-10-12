#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount){
    ArrayStack* ret;
    int i = -1;
    ret = (ArrayStack *)malloc(sizeof(ArrayStack));

    if (ret == NULL || maxElementCount <= 0)
        return NULL;
    
    //set initial data
    ret->maxElementCount = maxElementCount;
    ret->currentElementCount = 0;
    ret->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);

    if (ret->pElement == NULL)
        return NULL;

    //init the array in which the data will be stored.
    while (++i < maxElementCount)
        (ret->pElement + i)->data = 0;
    
    return ret;
}

void deleteArrayStack(ArrayStack* pStack){
    //free the array
    free(pStack->pElement);
    
    //free the whole stack
    free(pStack);
}

int isArrayStackFull(ArrayStack* pStack){
    //if max data and current data are same then stack is full
    if (pStack->maxElementCount == pStack->currentElementCount)
        return true;
    else
        return false;
}

int pushAS(ArrayStack* pStack, ArrayStackNode element){
    if (pStack != NULL){
        if (isArrayStackFull(pStack) == 0){
            //push data
            pStack->pElement[pStack->currentElementCount] = element;
            
            pStack->currentElementCount++;
            return true;
        }
    }
    return false;
}

ArrayStackNode popAS(ArrayStack* pStack){
    //create return variable and init by zero
    ArrayStackNode ret;
    memset (&ret, 0, sizeof(ret));

    if (pStack != NULL){
        if (isArrayStackEmpty(pStack) == 0){
            pStack->currentElementCount--;
            // store the latest data to ret
            ret = pStack->pElement[pStack->currentElementCount];
            // set zero the latest data
            pStack->pElement[pStack->currentElementCount].data = 0;
        }
    }
    return ret;
}

ArrayStackNode* peekAS(ArrayStack* pStack){
    if (pStack != NULL){
        return (pStack->pElement + (pStack->currentElementCount));
    }
    else return NULL;
}

void clearArrayStack(ArrayStack* pStack){
    int i = pStack->currentElementCount;
    while (--i >= 0){
        popAS(pStack);
    }
}

int isArrayStackEmpty(ArrayStack* pStack){
    if (pStack->currentElementCount == 0)
        return true;
    else
        return false;
}
#include "liststack.h"


LinkedStack* createLinkedStack(){
    LinkedStack* ret = NULL;
    
    //         LinkedStack         
    // assign |___________|
    ret = (LinkedStack *)malloc(sizeof(LinkedStack));

    if (ret != NULL){
        //set initial data
        ret->currentElementCount = 0;

        //create header node(dummy node)
        ret->pTopElement = (StackNode *)malloc(sizeof(StackNode));
        if (ret->pTopElement != NULL){
            ret->pTopElement->data = 0;
            //first data
            ret->pTopElement->preElement = NULL;
        }
    }

    return ret;
}

void deleteLinkedStack(LinkedStack* pStack){
    //pop every Node and free poped Node
    int i = pStack->currentElementCount;
    while (--i >= 0)
        free(popLS(pStack));
    
    //free header node(dummy node)
    free(pStack->pTopElement);

    //free stack
    free(pStack);
}


int pushLS(LinkedStack* pStack, StackNode element){
    StackNode *New = NULL;//new node to put at stack

    if (pStack != NULL){
        New = (StackNode *)malloc(sizeof(StackNode));
        New->data = element.data;

        //New node is pointing the first node
        New->preElement = pStack->pTopElement->preElement;
        //header node is pointing the new node
        pStack->pTopElement->preElement = New;

        pStack->currentElementCount++;
        return true;
    }
    return false;
}

// free 어디서 시켜줘야??? 밖에서 해야하는데 굳이 반환형을 포인터로 할 필요??
//StackNode popLS(LinkedStack* pStack)이렇게 하고 함수 안에서 free시켜주는게 효율적으로 보임
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
    //return the first node(node pointed by header node)
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

int checkBracketMatching(char *pSource){
    LinkedStack *brackets;
    StackNode node;
    StackNode *top;

    if (!pSource || pSource[0] == '\0')
        return false;

    node.preElement = NULL;
    brackets = createLinkedStack();
    for (char *symbol = pSource; *symbol; ++symbol){
        switch (*symbol){
            case '(': case '{': case '[':
                node.data = *symbol;
                pushLS(brackets, node);
                break;
        }
        if ( ! isLinkedStackEmpty(brackets)){
            switch (*symbol){
                case ')': 
                    if (peekLS(brackets)->data != '(') 
                        return deleteAndReturn(brackets, false);
                    else
                        free(popLS(brackets));
                    break;
                case '}': 
                    if (peekLS(brackets)->data != '{') 
                        return deleteAndReturn(brackets, false);
                    else
                        free(popLS(brackets));
                    break;
                case ']': 
                    if (peekLS(brackets)->data != '[')
                        return deleteAndReturn(brackets, false);
                    else
                        free(popLS(brackets));
                    break;
            }
        }
    }

    if (isLinkedStackEmpty(brackets))
        return deleteAndReturn(brackets, true);
    else
        return deleteAndReturn(brackets, false);
}

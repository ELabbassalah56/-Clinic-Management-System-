#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

/*global static variable*/
//static sNode *Prev;



//function to creat node for linkedlist
sNode *gGetNode(pVoid Data)
{

        sNode *NewNode = (sNode *)malloc(sizeof(sNode));

        NewNode->data =Data;
        NewNode->pNext = NullPtr;

        return (NewNode);
}
//print char*
void gPrintpChar(pVoid Data){


 printf("%s",Data);

}
//print char 
void gPrintChar(pVoid Data){

  printf("%c",*(char *)Data);
}
//print  int *
void gPrintpInt(pVoid Data){

  printf("%d",Data);
}
//print float *
void gPrintpFloat(pVoid Data){

        printf("%f",Data);
}

//function to insert  node  in certain position
void gInsertNode(sNode **gCurrent, pVoid Data, int Pos, int Size)
{

        if (Pos < 1 || Pos > (Size + 1))
        {
                printf("/************************************/\n");
                printf("/*        Invalid Position          */\n");
                printf("/************************************/\n");
        }
        else
        {
                while (Pos--)
                {

                        if (Pos == 0)
                        {
                                //adding node at requiered position
                                sNode *temp = gGetNode(&Data);
                                temp->data = malloc(Size);

                                //point created node to gCurrentnode
                                temp->pNext = (*gCurrent);

                                for (int i = 0; i < Size; i++)
                                        *(char *)(temp->data + i) = *(char *)(Data + i);
                                //change the pointer of the previous node (old node) to newNode
                                *gCurrent = temp;
                        }
                        else
                        {
                                //point to pointer pointing to the address of next Node
                                gCurrent = &(*gCurrent)->pNext;
                        }
                }
                Size++;
        }
}

//search to certain node
_uint8 gSearchOnNode(sNode *gCurrent, pVoid Key)
{

        _uint8 iRetValue = 1;
        sNode *temp = gCurrent;
        sNode *Prev;

        while (temp != NullPtr)
        {
                Prev = temp;
                //finding the certain data
                if (*(char *)temp->data == *(char *)Key)
                {

                        return iRetValue;
                }

                temp = temp->pNext;
        }

        return (iRetValue - 1);
}

void gDisplayNode(sNode *gCurrent, int Pos)
{
        sNode *temp = gCurrent;
        _uint8 Count = 1;

        if (gCurrent == NullPtr)
        {

                printf("/************************************/\n");
                printf("/*       The LinkedList Empty!      */\n");
                printf("/************************************/\n");
        }
        else
        {

                while (gCurrent != NullPtr)
                {
                        if (Pos == Count)
                        {
                                gPrintInt(gCurrent->data);
                        }
                        Count++;
                        gCurrent = gCurrent->pNext;
                }
        }
}
void gPrintList(sNode *node, void (*fptr)(void *))
{
        while (node != NullPtr)
        {
                (*fptr)(node->data);
                node = node->pNext;
        }
}

// Function to print an integer
void gPrintInt(void *n)
{
        printf("%d\t", *(int *)n);
}

// Function to print a float
void gPrintFloat(void *f)
{
        printf("%f\t\t", *(float *)f);
}

void gDeleteList(sNode **gHead)
{
        /* deref gHead to get the real gCurrent */
        sNode *current = *gHead;
        sNode *next;

        while (current != NULL)
        {
                next = current->pNext;
                free(current);
                current = next;
        }

        *gHead = NullPtr;
}

void gDeleteNode(sNode **gCurrent, pVoid Key)
{
        sNode *currP, *prevP;

        /* For 1st node, indicate there is no previous. */
        prevP = NullPtr;

        /*
   * Visit each node, maintaining a pointer to
   * the previous node we just visited.
   */
        for (currP = *gCurrent; currP != NullPtr; prevP = currP, currP = currP->pNext)
        {

                if (*(char *)currP->data == *(char *)Key)
                { /* Found it. */
                        if (prevP == NullPtr)
                        {
                                /* Fix beginning pointer. */
                                *gCurrent = currP->pNext;
                        }
                        else
                        {
                                /*
         * Fix previous node's next to
         * skip over the removed node.
         */
                                prevP->pNext = currP->pNext;
                        }

                        /* Deallocate the node. */
                        free(currP);
                        currP = NullPtr;
                        /* Done searching. */
                        return;
                }
        }
}
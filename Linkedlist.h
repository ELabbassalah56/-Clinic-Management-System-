/*
*                   Author : elabbas salah hatata
*                   DATE : 22/07/2020
*
*/
#ifndef __Linkedlist__
#define __Linkedlist__

#include "../embeddedSw/Std_Types.h"

#define NullPtr ((void *)0)
//creating new type
typedef void *pVoid;



void gPrintpChar(pVoid Data);
void gPrintChar(pVoid Data);
void gPrintpInt(pVoid Data);
void gPrintpFloat(pVoid Data);
void gPrintpChar(pVoid Data);



typedef struct Node
{
        //pointer to void to generle data of container
        pVoid data;
        //Pointer  to  Next  Container
        struct Node *pNext;

} sNode;

//creat node
sNode *gGetNode(pVoid Data);

//insert node in certain position
void gInsertNode(sNode **gCurrent, pVoid Data, int Pos, int Size);

//search on data inlinked list
_uint8 gSearchOnNode(sNode *gCurrent, pVoid Key);

//delete certain Node with Key
void gDeleteNode(sNode **Current, pVoid Key);

//Display certain Node with Key
void gDisplayNode(sNode *gCurrent, int Pos);

//print all Linked List
void gPrintList(struct Node *node, void (*fptr)(void *));
//print integer data
void gPrintInt(pVoid n);
//print float data
void gPrintFloat(pVoid f);

//delete all Linked List

void gDeleteList(sNode **gHead);

#endif
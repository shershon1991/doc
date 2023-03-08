#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Insert(SeqList* list, SeqList* node, int pos);

SeqListNode* SeqList_Delete(SeqList* list, int pos);

SeqListNode* SeqList_Get(SeqList* list, int pos);

int SeqList_Length(SeqList* list);

int SeqList_Capacity(SeqList* list);

#endif;	//__MY_SEQLIST_H__


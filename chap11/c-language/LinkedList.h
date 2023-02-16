typedef struct LinkedListNodeType {
    int data;
    struct LinkedListNodeType *pLink;
} LinkedListNode;

typedef struct LinkedListType {
    int currentCount;
    LinkedListNode headerNode;
} LinkedList;

LinkedList *createLinkedList();
int getLinkedListData(LinkedList *pList, int position);
int addLinkedListData(LinkedList *pList, int position, int data);
int removeLinkedListData(LinkedList *pList, int position);
void deleteLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);

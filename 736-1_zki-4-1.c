#include <stdio.h> 
#include <stdlib.h> 
typedef struct queue 
{
	struct queue* front;
	struct queue* rear;
	int value;
} q;

typedef struct HeadAndTail 
{
	struct queue* head;
	struct queue* tail;
	int size;
} ht;

_Bool IsEmpty(ht* queue) 
{
	if (queue == NULL || queue->size == 0) return 1;
	return 0;
}

ht* CreateQueue() 
{
	ht* creation = malloc(sizeof(ht));
	creation->head = creation->tail = NULL;
	creation->size = 0;
	return creation;
}

int DestroyQueue(ht** list)
{
	q* first = (*list)->head;
	q* buffer = NULL;
	while (first)
	{
		buffer = first->front;
		free(first);
		first = buffer;
	};
	free(*list);
	(*list) = NULL;
}

int Write(ht* queue, int newvalue) 
{
	q* element = malloc(sizeof(q));
	if (queue->size == 0) 
	{
		queue->tail = queue->head = element;
		element->value = newvalue;
		element->rear = element->front = NULL;
		queue->size++;
	}
	else
	{
		element->rear = queue->tail;
		element->front= NULL;
		element->value = newvalue;
		queue->tail->front = element;
		queue->tail = element;
		queue->size++;
	}	
	return 0;
}

int Read(ht* queue) {
	if (IsEmpty(queue)) exit(1);
	return queue->head->value;
}

int DeleteElem(ht* queue) 
{
	if (!IsEmpty(queue));
	if (queue->size == 1) 
	{
		free(queue->head);
		queue->head = queue->tail = NULL;
		queue->size = 0;
	}
	else
	{
		queue->head = queue->head->front;
		free(queue->head->rear);
		queue->head->rear ==NULL;
		queue->size--;
	}
		return 0;
}

int ShowList(ht* list)
{
	if (!IsEmpty(list));
	q* first = list->head;
	do
	{
		printf("%d", first->value);
		printf(" ");
		first = first->front;
	}
	while (first);
	printf("\n");
	return 0;
}

int main() 
{
	int n = 0;
	ht* queue = CreateQueue();
	scanf("%i", &n);
	for (int i = 1; i<=n; ++i) {
		Write(queue, i);
	}
	ShowList(queue);
	do
	{
		printf("<%d %d> ", Read(queue), queue->size);
		DeleteElem(queue);
	} 
	while (!IsEmpty(queue));
	printf("\n");
	return 0;
}

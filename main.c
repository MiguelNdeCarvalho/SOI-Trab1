#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SZ 50
#define QUANTUM 3

typedef struct queue //Makiko
{
    int inicial_pos, final_pos, *array, sz;
}queue_t;
queue_t *create_queue (int sz);
void insert (queue_t *queue, int element);
bool full (queue_t *queue);
bool empty (queue_t *queue);
int get (queue_t *queue);

queue_t *create_queue (int sz) //Bob
{
    queue_t *queue_v = malloc(sizeof(queue_t));
    queue_v -> sz = sz;
    queue_v -> array = malloc(queue_v -> sz* sizeof(int));
    queue_v -> inicial_pos = 0;
    queue_v -> final_pos = 0;

    return queue_v;
}


void insert (queue_t *queue, int element) //Inserir
{
    if (!full (queue))
    {
        queue -> array [queue -> final_pos] = element;
        queue -> final_pos ++;
    }    
}

bool full (queue_t *queue) //Checka para saber se esta cheio
{
    return queue -> sz == queue -> final_pos;
}

bool empty (queue_t *queue) //Checka para saber se esta vazio
{
    return queue -> inicial_pos == queue -> final_pos;
}

int get (queue_t *queue) //Get primeiro elemento, o de baixo
{
    if (empty (queue))
    {
        return -1;
    }

    int temp = queue -> array[queue -> inicial_pos];
    for (int i = 0; i < (queue -> final_pos); i++)
    {
        queue -> array[i] = queue -> array[i+1];
    }
    queue -> final_pos --;   
    return temp;
}
 
void printQueue(queue_t *queue)
{
    if(empty(queue))
    {
        printf("A queue está vazia!");
    }
    else
    {
        for (int i = 0; i < queue->final_pos; i++)
        {
            printf("%d ", queue->array[i]);
        }
        
    }
}

int main()
{   

    return 0;
}
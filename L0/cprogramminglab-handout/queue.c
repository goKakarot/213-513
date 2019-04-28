/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (NULL == q)
    {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* q is not NULL */
    if (q)
    {
        list_ele_t *tmp = NULL;
        /* q->head not the end of queue */
        while (q->head) {
            tmp = q->head;
            q->head = q->head->next;
            /* Free queue's element */
            free(tmp);
            tmp = NULL;
        }
        /* free queue structure */
        free(q);
        q = NULL;
    }
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* q not NULL */
    if (q)
    {
        list_ele_t *newh;
        /* What should you do if the q is NULL? */
        /* What if malloc returned NULL? */
        newh = malloc(sizeof(list_ele_t));
        if (newh)
        {
            newh->value = v;
            newh->next = q->head;
            q->head = newh;
            /* set tail */
            if (!q->size)
            {
                q->tail = newh;
            }
            /* new node increases queue size */
            q->size++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (q)
    {
        list_ele_t *newh;
        newh = malloc(sizeof(list_ele_t));
        if (newh)
        {
            newh->value = v;
            newh->next = NULL;
            /* in case of q->tail is NULL,
             * which means just new a queue
             */
            if (q->tail)
            {
                q->tail->next = newh;
                q->tail = newh;
            }
            else
            {
                q->head = q->tail = newh;
            }
            /* new node increases queue size */
            q->size++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* if q and q->head are NULL */
    if (!q || !q->head)
    {
        return false;
    }
    /* store removed element value to *vo */
    if (vp)
    {
        *vp = q->head->value;
    }
    /* tmp to store removed head */
    list_ele_t *tmp;
    tmp = q->head;
    /* head to next node */
    q->head = q->head->next;
    /* free removed head storage */
    free(tmp);
    /* decrease the queue size */
    q->size--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (!q ||!q->head)
    {
        return 0;
    }
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q) {
    /* no need to reverse if queue less than 2 nodes */
    if (q && q->head && q->head->next)
    {
        list_ele_t *prev = NULL;
        list_ele_t *next = NULL;
        q->tail = q->head;
        while (NULL != q->head)
        {
            next = q->head->next;
            q->head->next = prev;
            prev = q->head;
            q->head = next;
        }
        /* q->head is NULL, re-point to prev */
        q->head = prev;
    }
}


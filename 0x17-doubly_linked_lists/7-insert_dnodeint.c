#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to the head of the list
 * @idx: Index where the new node should be added
 * @n: Value to be assigned to the new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp;
    unsigned int i;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    /* Assign values to the new node */
    new_node->n = n;

    /* If inserting at the beginning, update the head */
    if (idx == 0)
    {
        new_node->prev = NULL;
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
        return new_node;
    }

    /* Traverse the list to find the node at position idx - 1 */
    temp = *h;
    for (i = 0; i < idx - 1 && temp != NULL; i++)
        temp = temp->next;

    /* If the index is out of bounds, free the new node and return NULL */
    if (temp == NULL)
    {
        free(new_node);
        return NULL;
    }

    /* Update pointers to insert the new node */
    new_node->prev = temp;
    new_node->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;

    return new_node;
}

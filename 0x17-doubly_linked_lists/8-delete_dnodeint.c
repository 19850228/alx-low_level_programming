#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Pointer to the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp, *prev;
    unsigned int i;

    /* Check if the list is empty */
    if (*head == NULL)
        return -1;

    /* If deleting the first node, update the head */
    if (index == 0)
    {
        temp = *head;
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return 1;
    }

    /* Traverse the list to find the node at position index */
    temp = *head;
    for (i = 0; i < index && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    /* If the index is out of bounds, return -1 */
    if (temp == NULL)
        return -1;

    /* Update pointers to delete the node */
    prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = prev;
    free(temp);

    return 1;
}

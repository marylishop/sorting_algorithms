#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using an insertion sort algorithm.
 * @list: Doubly linked list of integers to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *insertion_point = current->prev;
        int value_to_insert = current->n;

        while (insertion_point != NULL && insertion_point->n > value_to_insert)
        {
            insertion_point->next->n = insertion_point->n;
            insertion_point = insertion_point->prev;
        }

        if (insertion_point == NULL)
        {
            (*list)->n = value_to_insert;
        }
        else
        {
            insertion_point->next->n = value_to_insert;
        }

        current = current->next;

        // Print the list after each insertion (optional)
        print_list(*list);
    }
}

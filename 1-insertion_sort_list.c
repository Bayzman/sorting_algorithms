#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list2(const listint_t *list, const listint_t *list2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}

	while (list2)
	{
		if (j >= 0)
			printf(", ");
		printf("%d", list2->n);
		++j;
		list2 = list2->next;
	}

	printf("\n");
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: double pointer to the doubly linked list (DLL)
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted;
	listint_t *unsorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = NULL;
	unsorted = *list;

	while (unsorted != NULL)
	{
		listint_t *current = unsorted;
		unsorted = unsorted->next;

		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;

			if (sorted != NULL)
				sorted->prev = current;

			sorted = current;
		}

		else
		{
			listint_t *temp = sorted;
			while (temp->next != NULL && current->n > temp->next->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;

			if (temp->next != NULL)
				temp->next->prev = current;

			temp->next = current;
		}
		print_list2(sorted, unsorted);
	}

	*list = sorted;
}

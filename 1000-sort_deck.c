#include <stdlib.h>
#include "deck.h"

int _strcomp(const char *s1, const char *s2);
char get_value_code(deck_node_t *card);
void insertion_sort_deck_kind_code(deck_node_t **deck);
void insertion_sort_deck_value_code(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcomp - used to compares two strings together.
 * @s1: The first string in the order to be compared.
 * @s2: The second string in the order to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 *         and vise-vasa
 */
int _strcomp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value_code - Used to get the numerical values of
 * the cards being initiated.
 * @card: Used to point to a deck_node_t of cards.
 *
 * Return: The numerical value of the cards being initiated.
 */
char get_value_code(deck_node_t *card)
{
	if (_strcomp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcomp(card->card->value, "1") == 0)
		return (1);
	if (_strcomp(card->card->value, "2") == 0)
		return (2);
	if (_strcomp(card->card->value, "3") == 0)
		return (3);
	if (_strcomp(card->card->value, "4") == 0)
		return (4);
	if (_strcomp(card->card->value, "5") == 0)
		return (5);
	if (_strcomp(card->card->value, "6") == 0)
		return (6);
	if (_strcomp(card->card->value, "7") == 0)
		return (7);
	if (_strcomp(card->card->value, "8") == 0)
		return (8);
	if (_strcomp(card->card->value, "9") == 0)
		return (9);
	if (_strcomp(card->card->value, "10") == 0)
		return (10);
	if (_strcomp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcomp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind_code - used to sort a deck
 * of cards from spades to diamonds in that order.
 * @deck: used to point to the head of a deck_node_t doubly-linked list order.
 */
void insertion_sort_deck_kind_code(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_value_code - Used to sort a deck of cards sorted from
 *                             spades to diamonds using the ace to king.
 * @deck: Used to point to the head of a deck_node_t doubly-linked list order.
 */
void insertion_sort_deck_value_code(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_value_code(insert) > get_value_code(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Used to sort a deck of cards from ace to king then
 *             from spades to diamonds in that order.
 * @deck: Used to point to the head of a deck_node_t doubly-linked list order.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind_code(deck);
	insertion_sort_deck_value_code(deck);
}

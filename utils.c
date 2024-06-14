/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024-05-27 13:32:46 by user              #+#    #+#             */
/*   Updated: 2024-05-27 13:32:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	wordcount(char *s, char c)
{
	int count;
	bool inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			inside_word = true;
			s++;
		}
		if (inside_word)
			count++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int cursor;
	char *word;
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[cursor] != c && s[cursor])
		word[i++] = s[cursor++];
	word[i] = '\0';
	return (word);
}

char	**split(char *s, char c)
{
	char **tab;
	int i;
	int word_count;

	i = 0;
	word_count = wordcount(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	while (i < word_count)
	{
		tab[i] = get_next_word(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

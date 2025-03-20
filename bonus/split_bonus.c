/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:29:08 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/03 23:29:50 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c && in_word == 1)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*allocation_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	i = 0;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	first_split(char **str, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = allocation_word(&s[i], c);
			if (!str[j])
				return (0);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char **strs;
	int i;

	if (s == NULL)
		return (NULL);
	i = 0;
	strs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!first_split(strs, s, c))
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		return (NULL);
	}
	return (strs);
}
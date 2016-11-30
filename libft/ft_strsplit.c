/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:06 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/15 11:28:38 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** accroit la taille d un tableau de str (termine par une chaine NULL
** en reallouant la memoire
*/

static char	**realloc_tab(char **tab, char *str)
{
	char	**nouveau_tab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if ((nouveau_tab = malloc(sizeof(char*) * (i + 1 + 1))) == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		nouveau_tab[i] = tab[i];
		i++;
	}
	free(tab);
	nouveau_tab[i] = str;
	nouveau_tab[i + 1] = NULL;
	return (nouveau_tab);
}

/*
** libere un tableau de chaines de caractaures termine
** par une chaine NULL
*/

static void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
** extrait un mot, le copie dans une nouvelle chaine
** l index est mis a jour
*/

static char	*extract_word(const char *s, char c, size_t *index)
{
	size_t	j;
	char	*str;

	j = 0;
	while (s[*index + j] && s[*index + j] != c)
		j++;
	if ((str = (char *)malloc(sizeof(char) * (j + 1))) == NULL)
		return (NULL);
	j = 0;
	while (s[*index + j] && s[*index + j] != c)
	{
		str[j] = s[*index + j];
		j++;
	}
	str[j] = 0;
	*index += j;
	return (str);
}

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de
** caractères “fraiches” (toutes terminées par un ’\0’, le tableau
** également donc) résultant de la découpe de s selon le caractère
** c. Si l’allocation echoue, la fonction retourne NULL. Exemple :
** ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
** le tableau ["salut", "les", "etudiants"].
*/

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * 1)) == NULL)
		return (NULL);
	tab[0] = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if ((str = extract_word(s, c, &i)) == NULL)
			{
				free_tab(tab);
				return (NULL);
			}
			tab = realloc_tab(tab, str);
		}
	}
	return (tab);
}

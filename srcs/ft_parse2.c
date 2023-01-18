/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 12:08:33 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_size(int nbr)
{
	int size;

	size = 0;
	if (nbr < 0)
	{
		size = 1;
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

int		ft_len_of_space(t_list *list)
{
	int len;

	len = 0;
	if (list->type == 'c' || list->type == '%')
		len = list->champ_min - 1;
	else if (list->type == 's')
		len = list->champ_min - ft_strlen(list->s);
	else if (list->type == 'd' || list->type == 'i')
		len = list->champ_min - ft_strlen(list->d);
	else if (list->type == 'p')
		len = list->champ_min - ft_strlen(list->p);
	else if (list->type == 'x' || list->type == 'X')
		len = list->champ_min - ft_strlen(list->x);
	else if (list->type == 'u')
		len = list->champ_min - ft_strlen(list->u);
	return (len);
}

int		ft_putspace(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		ft_putzero(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

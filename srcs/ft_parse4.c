/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse4.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 11:31:44 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 16:55:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tempo(t_list *list)
{
	if (list->champ_point < 0 && list->type != 's')
		list->champ_point = 1;
	if (list->champ_min < 0)
	{
		list->minus = 1;
		list->champ_min *= -1;
	}
}

void		ft_len_star(const char *str, int i, t_list *list, va_list va)
{
	if (str[i] == '%')
	{
		i++;
		while ((str[i] == '-' || str[i] == '.' || str[i] == '0') &&
		str[i] != 'X' && (str[i] < 'a' || str[i] > 'z'))
			i++;
		if (str[i] == '*' && str[i - 1] != '.')
			list->champ_min = va_arg(va, int);
		else if (str[i] == '*')
			list->champ_point = va_arg(va, int);
		i++;
		while (str[i] != 'X' && (str[i] < 'a' || str[i] > 'z')
		&& str[i] != '.' && str[i])
			i++;
		if (str[i] == '.')
		{
			list->point = 1;
			if (str[i + 1] == '*')
				list->champ_point = va_arg(va, int);
		}
	}
	ft_tempo(list);
}

static void	ft_corps(const char *str, int i, t_list *list)
{
	if (str[i] == '.')
	{
		list->point = 1;
		list->zero = 0;
		if (str[i + 1] != '*')
			list->champ_point = ft_atoi(str + i + 1);
	}
}

static void	ft_corps2(const char *str, int i, t_list *list)
{
	if (str[i] == '-')
		list->minus = 1;
	else if (str[i] == '0')
		list->zero = 1;
	else if (str[i] == '.')
		list->point = 1;
	while (str[i] == '0' || str[i] == '-')
		i++;
	list->champ_min = ft_atoi(str + i);
}

void		ft_check_flags(const char *str, int i, t_list *list, va_list va)
{
	int	j;

	j = i;
	if (str[i++] == '%')
	{
		if (str[i] > '0')
			list->champ_min = ft_atoi(str + i);
		else if ((str[i] == '.' || str[i] == '-'
			|| str[i] == '0'))
			ft_corps2(str, i, list);
		while (str[i] != 'X' && (str[i] < 'a' ||
			str[i] > 'z') && str[i] != '.' && str[i])
			i++;
		ft_corps(str, i, list);
	}
	ft_len_star(str, j, list, va);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 10:28:06 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_typeof(const char *str, int i, t_list *list)
{
	list->type = 0;
	if (str[i] == '%')
	{
		i++;
		while (str[i] != 'X' && (str[i] < 'a' || str[i] > 'z') && str[i] != '%')
			i++;
		list->type = str[i];
	}
}

int			ft_ispoint(const char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse3.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 15:54:34 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_initialize_string(t_list *list, va_list vacpy)
{
	char *str;

	str = NULL;
	if (list->type == 's')
	{
		str = va_arg(vacpy, char *);
		if (!str)
			list->s = ft_substr("(null)", 0, 6);
		else
			list->s = ft_substr(str, 0, ft_strlen(str));
	}
}

void	ft_initialize(t_list *list, va_list vacpy)
{
	if (list->type == 'c')
		list->c = va_arg(vacpy, int);
	else if (list->type == '%')
		list->c = '%';
	else if (list->type == 'd' || list->type == 'i')
		list->d = ft_itoa_base(va_arg(vacpy, int), "0123456789");
	else if (list->type == 'p')
		list->p = ft_strjoin("0x",
			ft_utoa_base(va_arg(vacpy, unsigned int long long),
				"0123456789abcdef"));
	else if (list->type == 'x' || list->type == 'X')
		list->x = ft_hextoa_base(va_arg(vacpy, int),
			"0123456789abcdef");
	else if (list->type == 'u')
		list->u = ft_litoa_base(va_arg(vacpy, int), "0123456789");
}

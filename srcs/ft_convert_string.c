/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_string.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 13:46:36 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 16:56:49 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_string(t_list *list, va_list va)
{
	char	*str;
	va_list vacpy;

	va_copy(vacpy, va);
	str = va_arg(va, char *);
	ft_initialize_string(list, vacpy);
	if (!str)
		return (ft_putnull(list));
	else
		return (ft_putstring(list, str));
	va_end(vacpy);
}

int			ft_put_char(t_list *list, va_list va)
{
	int		tmp;
	char	c;

	tmp = 0;
	if (list->type == 'c')
		c = va_arg(va, int);
	else if (list->type == '%')
		c = '%';
	if (list->minus == 1)
	{
		ft_putchar_fd(c, 1);
		tmp = ft_putspace(ft_len_of_space(list));
	}
	else
	{
		if (list->type == '%' && list->zero == 1 && list->champ_min != 0)
			tmp = ft_putzero(ft_len_of_space(list));
		else
			tmp = ft_putspace(ft_len_of_space(list));
		ft_putchar_fd(c, 1);
	}
	return (tmp + 1);
}

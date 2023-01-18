/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 09:55:27 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 15:09:30 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_zero(t_list *list)
{
	list->champ_min = 0;
	list->champ_point = 0;
	list->minus = 0;
	list->point = 0;
	list->zero = 0;
	list->star = 0;
	list->s = NULL;
	list->d = NULL;
	list->p = NULL;
	list->u = NULL;
	list->x = NULL;
}

void		ft_freelist(t_list *l)
{
	if (l->s)
		free(l->s);
	if (l->d)
		free(l->d);
	if (l->p)
		free(l->p);
	if (l->u)
		free(l->u);
	if (l->x)
		free(l->x);
}

static int	ft_corps(t_list *list, va_list va, int tmp)
{
	if (list->type == 's')
		tmp = ft_string(list, va);
	else if (list->type == 'c' || list->type == '%')
		tmp = ft_put_char(list, va);
	else if (list->type == 'p')
		tmp = ft_put_p(list, va);
	else if (list->type == 'd' || list->type == 'i')
		tmp = ft_put_number(list, va);
	else if (list->type == 'u')
		tmp = ft_put_unsigned(list, va);
	else if (list->type == 'x')
		tmp = ft_put_hexa_min(list, va);
	else if (list->type == 'X')
		tmp = ft_put_hexa_maj(list, va);
	return (tmp);
}

static int	ft_boucle(va_list va, t_list *list, const char *src, int i)
{
	int tmp;

	tmp = 0;
	while (src[i] != '\0')
	{
		ft_list_zero(list);
		if (src[i] != '%')
		{
			write(1, &src[i], 1);
			tmp++;
		}
		else if (src[i] == '%')
		{
			ft_typeof(src, i, list);
			ft_check_flags(src, i, list, va);
			tmp += ft_corps(list, va, tmp);
			i++;
			while (src[i] != 'X' && (src[i] < 'a' ||
				src[i] > 'z') && src[i] != '%')
				i++;
		}
		i++;
		ft_freelist(list);
	}
	return (tmp);
}

int			ft_printf(const char *src, ...)
{
	va_list		va;
	t_list		*list;
	int			i;
	int			tmp;

	i = 0;
	list = malloc(sizeof(t_list));
	va_start(va, src);
	tmp = ft_boucle(va, list, src, i);
	free(list);
	va_end(va);
	return (tmp);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_string2.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 10:07:04 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_corps(char *src, t_list *l, int len)
{
	if (src)
	{
		ft_putstr_fd(src, 1);
		if (((size_t)l->champ_point > ft_strlen(l->s)
		&& l->point == 1) || l->point == 0)
			len = ft_putspace(ft_len_of_space(l));
		else if (l->champ_point < l->champ_min && l->point == 1)
			len = ft_putspace(l->champ_min - l->champ_point);
	}
	else
	{
		ft_putstr_fd(src, 1);
		if (l->champ_point < l->champ_min && l->point == 1)
			ft_putspace(l->champ_min - l->champ_point);
		else if (l->point == 0 ||
			(l->champ_point >= l->champ_min && l->point == 1))
			ft_putspace(l->champ_min - 6);
	}
	return (len);
}

int			ft_putnull(t_list *list)
{
	int		len;
	char	*src;

	len = 0;
	if (list->point == 1)
		src = ft_substr("(null)", 0, (size_t)list->champ_point);
	else
		src = ft_substr("(null)", 0, 6);
	if (list->minus == 1)
		len = ft_corps(src, list, len);
	else
	{
		if (list->point == 1)
			len = ft_putspace((list->champ_min - 6)
			+ (6 - list->champ_point));
		else
			len = ft_putspace(list->champ_min - 6);
		ft_putstr_fd(src, 1);
	}
	len = len + ft_strlen(src);
	free(src);
	return (len);
}

static int	ft_corps2(t_list *l, int len)
{
	if (ft_strncmp(l->s, "", 1) == 0)
		len = ft_putspace(l->champ_min);
	else
		len = ft_putspace(ft_strlen(l->s));
	ft_putstr_fd("\0", 1);
	return (len);
}

static int	ft_corps3(t_list *l, int len, char *src)
{
	if (l->point == 1 && l->champ_point == 0)
	{
		len = ft_putspace(l->champ_min - ft_strlen(src));
		ft_putstr_fd("\0", 1);
	}
	else if (l->champ_point < 0)
	{
		ft_putstr_fd(l->s, 1);
		len += ft_strlen(l->s);
	}
	else
	{
		len = ft_putspace(l->champ_min - ft_strlen(src));
		ft_putstr_fd(src, 1);
	}
	return (len);
}

int			ft_putstring(t_list *l, char *str)
{
	char	*src;
	int		len;

	len = 0;
	if (l->point == 1)
		src = ft_substr(str, 0, l->champ_point);
	else
		src = ft_substr(str, 0, ft_strlen(str));
	if (l->minus == 1)
		len = ft_corps(src, l, len);
	else
	{
		if (l->point == 1 && ft_strncmp(l->s, "", 1) == 0)
			len += ft_corps2(l, len);
		else
			len += ft_corps3(l, len, src);
	}
	len = len + ft_strlen(src);
	free(src);
	return (len);
}

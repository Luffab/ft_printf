/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_p.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 14:56:32 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_corps(t_list *l, char *str)
{
	char *src;

	if (l->point == 1 && (l->minus == 0 && l->zero == 0))
	{
		if (l->champ_point == 0)
			src = ft_substr(str, 0, ft_strlen(str));
		else
			src = ft_substr(str, 0, (size_t)l->champ_min);
	}
	else if (l->point == 1)
		src = ft_substr(str, 0, (size_t)l->champ_point);
	else
		src = ft_substr(str, 0, ft_strlen(str));
	free(str);
	return (src);
}

static int	ft_corps2(char *src, t_list *l, int len)
{
	ft_putstr_fd(src, 1);
	if (((size_t)l->champ_point > ft_strlen(l->p)
	&& l->point == 1) || l->point == 0)
		len = ft_putspace(ft_len_of_space(l));
	else if (l->champ_point < l->champ_min && l->point == 1)
		len = ft_putspace(l->champ_min - l->champ_point);
	return (len);
}

static int	ft_corps3(t_list *l, int len, char *src)
{
	if (l->champ_min == 0 && (l->point == 1 && l->champ_point == 0)
		&& ft_strncmp(src + 2, "0", 1) == 0)
		len--;
	if (l->minus == 0 && l->point == 1)
		len += ft_putspace(ft_len_of_space(l) +
		(ft_strlen(l->s) - l->champ_point));
	else
		len += ft_putspace(ft_len_of_space(l));
	if (l->champ_min == 0 && (l->point == 1 && l->champ_point == 0)
		&& ft_strncmp(src + 2, "0", 1) == 0)
		ft_putstr_fd("\0", 1);
	else
		ft_putstr_fd(src, 1);
	return (len);
}

int			ft_put_p(t_list *l, va_list va)
{
	char	*src;
	int		len;
	va_list vacpy;

	va_copy(vacpy, va);
	len = 0;
	src = ft_utoa_base((intptr_t)va_arg(va, void *), "0123456789abcdef");
	src = ft_strjoin("0x", src);
	src = ft_corps(l, src);
	ft_initialize(l, vacpy);
	if (l->minus == 1)
		len = ft_corps2(src, l, len);
	else
		len += ft_corps3(l, len, src);
	len = len + ft_strlen(src);
	free(src);
	return (len);
}

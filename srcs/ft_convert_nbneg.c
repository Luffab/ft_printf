/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_nbneg.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 10:36:46 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_corps(t_list *l, int len, char *nb)
{
	if (l->zero == 1)
	{
		write(1, "-", 1);
		len = ft_putzero(ft_len_of_space(l));
	}
	else if (l->point == 1 && l->champ_point != 0)
	{
		if (l->champ_point < l->champ_min)
			len = ft_putspace(ft_len_of_space(l) -
			(l->champ_point - ft_strlen(nb)) - 1);
		else if (l->champ_point < l->champ_min &&
		(size_t)l->champ_point >= ft_strlen(nb))
			len = ft_putspace((l->champ_min - ft_strlen(nb)) -
			(l->champ_point - ft_strlen(nb)) - 1);
		write(1, "-", 1);
		len += ft_putzero(l->champ_point - ft_strlen(nb) + 1);
	}
	else if (l->point == 0)
	{
		len = ft_putspace(ft_len_of_space(l));
		write(1, "-", 1);
	}
	ft_putstr_fd(nb + 1, 1);
	return (len);
}

static int	ft_neg_corps(t_list *l, int len, char *nb)
{
	if (l->point == 1 && l->champ_point == 0)
	{
		len += ft_putspace(ft_len_of_space(l));
		ft_putstr_fd(nb, 1);
	}
	else
		len += ft_corps(l, len, nb);
	return (len);
}

static int	ft_corps2(t_list *l, int len, char *nb)
{
	if (l->point == 1 && l->champ_point == 0)
	{
		ft_putstr_fd(nb + 1, 1);
		len += ft_putspace(ft_len_of_space(l));
	}
	else if (l->point == 1)
	{
		ft_putstr_fd(nb + 1, 1);
		len += ft_putspace(l->champ_min - l->champ_point - 1);
	}
	else
	{
		ft_putstr_fd(nb, 1);
		if (l->point == 1)
			len = ft_putspace(l->champ_min - l->champ_point - 1);
		else
			len = ft_putspace(ft_len_of_space(l));
	}
	return (len);
}

int			ft_put_number_neg(t_list *l, char *nb, int len, va_list vacpy)
{
	ft_initialize(l, vacpy);
	if (l->minus == 0)
		len = ft_neg_corps(l, len, nb);
	else if (l->point == 1 || l->zero == 1)
	{
		write(1, "-", 1);
		len = ft_putzero(l->champ_point - ft_strlen(nb) + 1);
	}
	if (l->minus == 1)
		len = ft_corps2(l, len, nb);
	len = len + ft_strlen(nb);
	free(nb);
	return (len);
}

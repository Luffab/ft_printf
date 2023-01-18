/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_nbpos.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 12:15:08 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 15:50:39 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tmp(t_list *l, int len, char *nb)
{
	if (l->point == 1 && l->champ_point == 0)
	{
		len += ft_putspace(ft_len_of_space(l));
		ft_putstr_fd(nb, 1);
	}
	else
	{
		if (l->zero == 1)
			len += ft_putzero(ft_len_of_space(l));
		else if (l->point == 1)
		{
			if (l->champ_point < l->champ_min &&
				(size_t)l->champ_point < ft_strlen(nb))
				len += ft_putspace(ft_len_of_space(l));
			else
				len += ft_putspace(ft_len_of_space(l) -
					(l->champ_point - ft_strlen(nb)));
			len += ft_putzero(l->champ_point - ft_strlen(nb));
		}
		else if (l->point == 0)
			len += ft_putspace(ft_len_of_space(l));
		ft_putstr_fd(nb, 1);
	}
	return (len);
}

static int	ft_corps(t_list *l, int len, char *nb)
{
	if (l->point == 1 && l->champ_point == 0 &&
		ft_strncmp(nb, "0", 1) == 0)
	{
		len += ft_putspace(l->champ_min);
		len--;
		ft_putstr_fd("\0", 1);
	}
	else
		len += ft_tmp(l, len, nb);
	return (len);
}

static int	ft_tempo2(char *nb, t_list *l, int len, int tmp)
{
	ft_putstr_fd(nb, 1);
	if (l->champ_point >= l->champ_min)
		len = ft_putspace(ft_len_of_space(l) - l->champ_point);
	else if ((size_t)l->champ_point >= ft_strlen(nb))
		len = ft_putspace(ft_len_of_space(l) - tmp);
	else
		len = ft_putspace(ft_len_of_space(l));
	return (len);
}

static int	ft_tempo(char *nb, t_list *l, int len)
{
	int tmp;

	tmp = l->champ_point - ft_strlen(nb);
	if (l->point == 1 && l->champ_point != 0)
		len = ft_tempo2(nb, l, len, tmp);
	else if (l->point == 1 && l->champ_point == 0 &&
		ft_strncmp(nb, "0", 1) == 0)
	{
		ft_putstr_fd("\0", 1);
		len = ft_putspace(l->champ_min);
		len--;
	}
	else
	{
		ft_putstr_fd(nb, 1);
		len = ft_putspace(ft_len_of_space(l));
	}
	return (len);
}

int			ft_put_number(t_list *l, va_list va)
{
	char				*nb;
	int					len;
	long long int		nbr;
	va_list				vacpy;

	va_copy(vacpy, va);
	nbr = va_arg(va, int);
	len = 0;
	nb = ft_itoa_base(nbr, "0123456789");
	if (nbr < 0)
		return (ft_put_number_neg(l, nb, len, vacpy));
	ft_initialize(l, vacpy);
	if (l->minus == 0)
		len = ft_corps(l, len, nb);
	else if (l->point == 1 || l->zero == 1)
		len = ft_putzero(l->champ_point - ft_strlen(nb));
	if (l->minus == 1)
		len += ft_tempo(nb, l, len);
	len = len + ft_strlen(nb);
	free(nb);
	return (len);
}

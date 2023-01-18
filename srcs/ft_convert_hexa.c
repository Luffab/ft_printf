/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_hexa.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 11:04:16 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:49:59 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tempo(t_list *l, int len, char *nb, int tmp)
{
	ft_putstr_fd(nb, 1);
	if (l->champ_point >= l->champ_min)
		len += ft_putspace(ft_len_of_space(l) - l->champ_point);
	else if ((size_t)l->champ_point >= ft_strlen(nb))
		len += ft_putspace(ft_len_of_space(l) - tmp);
	else
		len += ft_putspace(ft_len_of_space(l));
	return (len);
}

static int	ft_corps(t_list *l, int len, char *nb)
{
	int tmp;

	tmp = l->champ_point - ft_strlen(nb);
	if (l->point == 1 && l->champ_point != 0)
		len = ft_tempo(l, len, nb, tmp);
	else if (l->point == 1 && l->champ_point == 0 &&
		ft_strncmp(nb, "0", 1) == 0)
	{
		ft_putstr_fd("\0", 1);
		len += ft_putspace(l->champ_min);
		len--;
	}
	else
	{
		ft_putstr_fd(nb, 1);
		len += ft_putspace(ft_len_of_space(l));
	}
	return (len);
}

int			ft_put_hexa_min(t_list *l, va_list va)
{
	char	*nb;
	int		len;
	va_list vacpy;

	va_copy(vacpy, va);
	len = 0;
	nb = ft_hextoa_base(va_arg(va, long int), "0123456789abcdef");
	ft_initialize(l, vacpy);
	if (l->minus == 0)
		len += ft_int_corps(l, len, nb);
	else if (l->point == 1 || l->zero == 1)
		len += ft_putzero(l->champ_point - ft_strlen(nb));
	if (l->minus == 1)
		len = ft_corps(l, len, nb);
	len = len + ft_strlen(nb);
	free(nb);
	return (len);
}

int			ft_put_hexa_maj(t_list *l, va_list va)
{
	char	*nb;
	int		len;
	va_list vacpy;

	va_copy(vacpy, va);
	len = 0;
	nb = ft_hextoa_base(va_arg(va, long int), "0123456789ABCDEF");
	ft_initialize(l, vacpy);
	if (l->minus == 0)
		len += ft_int_corps(l, len, nb);
	else if (l->point == 1 || l->zero == 1)
		len += ft_putzero(l->champ_point - ft_strlen(nb));
	if (l->minus == 1)
		len = ft_corps(l, len, nb);
	len += ft_strlen(nb);
	free(nb);
	return (len);
}

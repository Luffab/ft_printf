/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:56:29 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:27:42 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long long int nbr, char *base)
{
	unsigned long long int	size;
	size_t					len;

	len = ft_strlen(base);
	size = 0;
	if (nbr < 0)
	{
		size = 1;
		nbr *= -1;
	}
	while ((size_t)nbr >= len)
	{
		nbr = nbr / len;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa_base(long long int nb, char *base)
{
	char					*str;
	int						i;
	int						tmp;
	unsigned long long int	size;

	tmp = 0;
	size = count_size(nb, base);
	i = size - 1;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (i >= 0 && (size_t)nb >= ft_strlen(base))
	{
		tmp = nb % ft_strlen(base);
		nb = nb / ft_strlen(base);
		str[i--] = base[tmp];
	}
	if (nb >= 0 && (size_t)nb < ft_strlen(base))
		str[i] = base[nb];
	str[size] = '\0';
	return (str);
}

char		*ft_litoa_base(long int nb, char *base)
{
	char					*str;
	int						i;
	int						tmp;
	unsigned long long int	size;

	if (nb < 0)
		return (ft_litoa_base(nb + 4294967296, base));
	tmp = 0;
	size = count_size(nb, base);
	i = size - 1;
	if (!(str = (char *)malloc((size) * sizeof(char))))
		return (NULL);
	while (i > 0 && (size_t)nb >= ft_strlen(base))
	{
		tmp = nb % ft_strlen(base);
		nb = nb / ft_strlen(base);
		str[i--] = base[tmp];
	}
	if ((size_t)nb < ft_strlen(base))
		str[i] = base[nb];
	str[size] = '\0';
	return (str);
}

char		*ft_hextoa_base(unsigned int nb, char *base)
{
	char					*str;
	int						i;
	int						tmp;
	unsigned long long int	size;

	tmp = 0;
	size = count_size(nb, base);
	i = size - 1;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i > 0 && (size_t)nb >= ft_strlen(base))
	{
		tmp = nb % ft_strlen(base);
		nb = nb / ft_strlen(base);
		str[i] = base[tmp];
		i--;
	}
	if ((size_t)nb < ft_strlen(base))
		str[i] = base[nb];
	str[size] = '\0';
	return (str);
}

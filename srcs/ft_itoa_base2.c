/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 09:56:23 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:27:56 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(unsigned long long int nbr, char *base)
{
	unsigned long long int	size;
	size_t					len;

	len = ft_strlen(base);
	size = 0;
	while (nbr >= len)
	{
		nbr = nbr / len;
		size++;
	}
	return (size + 1);
}

char		*ft_utoa_base(unsigned int long long nb, char *base)
{
	char					*str;
	int						i;
	int						tmp;
	unsigned long long int	size;

	tmp = 0;
	size = count_size(nb, base);
	i = size - 1;
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i > 0 && nb >= ft_strlen(base))
	{
		tmp = nb % ft_strlen(base);
		nb = nb / ft_strlen(base);
		str[i] = base[tmp];
		i--;
	}
	if (nb < ft_strlen(base))
		str[i] = base[nb];
	str[size] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:41:29 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 13:23:53 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	if (!(str1 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (s[j] != '\0')
	{
		str1[j] = s[j];
		j++;
	}
	str1[j] = '\0';
	return (str1);
}

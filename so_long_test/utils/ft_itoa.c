/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:37:17 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 19:12:50 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_nb_len(unsigned int n, int nb_base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= nb_base;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned int nb, int nb_base)
{
	char	*base;
	char	*str;
	int		len;

	base = "0123456789abcdef";
	len = get_nb_len(nb, nb_base);
	if (!nb)
		len = 1;
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		ft_error(4);
	str[len] = '\0';
	if (!nb)
		str[0] = 0;
	else
	{
		while (nb)
		{
			str[--len] = base[nb % nb_base];
			nb /= nb_base;
		}
	}
	return (str);
}

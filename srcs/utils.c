/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:35:18 by osallak           #+#    #+#             */
/*   Updated: 2022/01/02 16:23:22 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<limits.h>
#include<unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\n' || str[i] == '\r'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
		ft_putchar((n + 48));
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putchar(((n % 10) + 48));
	}
}

void	ft_putstr(char *s)
{
	while (*s)
		write (1, s++, 1);
}

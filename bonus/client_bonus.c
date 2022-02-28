/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:17:21 by osallak           #+#    #+#             */
/*   Updated: 2022/02/28 13:49:17 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

void	handler(int sig)
{
	(void)sig;
	ft_putstr("\nMessage received seccessfully\n");
	exit (0);
}

void	shift_send_sig(int c, int pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		usleep(400);
		if ((c >> i & 1))
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = -1;
	signal(SIGUSR1, handler);
	if (ac != 3)
	{
		ft_putstr("---------MINITALK---------\n");
		ft_putstr("Usage : \n");
		ft_putstr("      1) ./server_bonus \"copy the output (pid)\"\n");
		ft_putstr("      2) ./client_bonus <pid> <string to send> \n");
		exit(0);
	}
	while (av[1][++i])
		if (av[1][i] < '0' || av[1][i] > '9')
			return (0);
	pid = ft_atoi(av[1]);
	if (!pid || pid == -1)
	{
		ft_putstr("Invalid pid\n");
		return (0);
	}
	while (*av[2])
		shift_send_sig(*av[2]++, pid);
	shift_send_sig('\0', pid);
	while (1)
		sleep(1);
}

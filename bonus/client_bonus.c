/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:17:21 by osallak           #+#    #+#             */
/*   Updated: 2022/01/02 16:56:53 by osallak          ###   ########.fr       */
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

	signal(SIGUSR1, handler);
	if (ac != 3)
	{
		ft_putstr("---------MINITALK---------\n");
		ft_putstr("Usage : \n");
		ft_putstr("      1) ./server_bonus \"copy the output (pid)\"\n");
		ft_putstr("      2) ./client_bonus <pid> <string to send> \n");
		exit(0);
	}
	pid = ft_atoi(av[1]);
	while (*av[2])
		shift_send_sig(*av[2]++, pid);
	shift_send_sig('\0', pid);
	while (1)
		sleep(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:18:01 by osallak           #+#    #+#             */
/*   Updated: 2022/01/02 16:57:17 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

int	g_pid;

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;

	(void)ucontext;
	if (!g_pid)
		g_pid = info->si_pid;
	if (g_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		g_pid = info->si_pid;
	}
	c = c << 1 | (sig - 30);
	i++;
	if (i == 8)
	{
		if (!c)
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	t_sig	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Pid : ");
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		sleep(1);
}

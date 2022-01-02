/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:18:34 by osallak           #+#    #+#             */
/*   Updated: 2022/01/02 16:25:20 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include<unistd.h>
# include<signal.h>
# include<stdio.h>
# include<stdlib.h>

typedef struct sigaction	t_sig;
int		ft_atoi(char *s);
void	ft_putnbr(int n);
void	ft_putstr(char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:31:57 by osallak           #+#    #+#             */
/*   Updated: 2022/01/02 16:27:41 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include<unistd.h>
# include<signal.h>
# include<stdio.h>
# include<stdlib.h>

typedef struct sigaction	t_sig;
int		ft_atoi(char *s);
void	ft_putnbr(int n);
void	ft_putstr(char *s);

#endif
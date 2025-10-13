/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:22:06 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/04/27 12:26:55 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sig_handler(int signal)
{	
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
	{
		c = c | (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction sa;

	(void)argv;
	if (argc != 1)
	{
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);

	sa.sa_handler = &ft_sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (argc == 1)
	{
		pause();
	}
	return (0);
}

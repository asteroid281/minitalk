/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:34:29 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/10 20:30:15 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_collector(int signal)
{
	static char	character;
	static char	bit;

	if (signal == SIGUSR1)
		character |= (1 << bit);
	else
		character |= (0 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)(av);
	if (ac != 1)
	{
		ft_printf("Server'i baslatmak icin ./server yaziniz.\n");
		return (0);
	}
	pid = getpid();
	if (pid)
	{
		ft_printf("Server PID'niz; %d\n", pid);
	}
	signal(SIGUSR1, &signal_collector);
	signal(SIGUSR2, &signal_collector);
	while (1)
		pause();
	return (0);
}

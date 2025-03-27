/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:41:41 by muhaoz            #+#    #+#             */
/*   Updated: 2025/03/01 15:05:13 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	my_signal_handler(int signal)
{
	static char	character = 0;
	static int	bit_pos = 7;

	if (signal == SIGUSR1)
		character = character * 2;
	else if (signal == SIGUSR2)
		character = character * 2 + 1;
	bit_pos--;
	if (bit_pos < 0)
	{
		write(1, &character, 1);
		character = 0;
		bit_pos = 7;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, my_signal_handler);
	signal(SIGUSR2, my_signal_handler);
	while (1)
		;
	return (0);
}

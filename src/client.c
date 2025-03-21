/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:47:57 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/20 19:20:10 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

static void	send_byte(pid_t pid, unsigned char octet)
{
	size_t	i;

	i = 8;
	while (i > 0)
	{
		if (octet & (1 << (i - 1)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		usleep(1);
		--i;
	}
}

static void	send_str(pid_t pid, char *s)
{
	while (*s)
	{
		send_byte(pid, *s);
		++s;
	}
	send_byte(pid, *s);
}

static void	signal_handler(int sig)
{
	(void)sig;
	if (sig == SIGUSR2)
		ft_putstr_fd("All received!\n", 1);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (argc != 3)
		return (1);
	send_str(ft_atoi(argv[1]), argv[2]);
}

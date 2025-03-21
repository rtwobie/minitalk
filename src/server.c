/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/20 19:20:18 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static unsigned char	g_c;

static void	put_bit(int sig, unsigned char *g_c)
{
	if (sig == SIGUSR1)
		*g_c = *g_c << 1;
	if (sig == SIGUSR2)
		*g_c = *g_c << 1 | 1;
}

static void	signal_handler(int sig, siginfo_t *info, void *cntxt)
{
	static int	size = 0;

	(void)cntxt;
	if (!size)
		g_c = 0;
	put_bit(sig, &g_c);
	usleep(1);
	kill(info->si_pid, SIGUSR1);
	if (++size == 8)
	{
		if (g_c == 0)
			kill(info->si_pid, SIGUSR2);
		ft_putchar_fd(g_c, 1);
		size = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID: %i\n", getpid());
	while (1)
		pause();
}

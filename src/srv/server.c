/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/18 16:48:13 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void put_zero(int sig)
{
	(void)sig;
	write(1, "0", 1);
}

void put_one(int sig)
{
	(void)sig;
	write(1, "1", 1);
}

int main(void)
{
	signal(SIGUSR1, put_zero);
	signal(SIGUSR2, put_one);

	printf("PID: %i\n", getpid());

	while (1)
	{
		printf("waiting for instruction...\n");
		pause();
	}
}

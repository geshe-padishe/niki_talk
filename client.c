#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "niki_talk.h"

int	ft_send_char(char c, int pid)
{
	int index;

	index = 0;
	while (index < 7)
	{
		if (c << index == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		index++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	pid;
	int i;

	i = 0;
	if (argc != 3)
		return (-1);
	pid = ft_uatoi(argv[1]);
	if (pid == -1 || pid == 0)
		return (-1);
	while (argv[2][i])
	{
		if (ft_send_char(argv[2][i], pid))
			return (-1);
		i++;
	}
	return (0);
}

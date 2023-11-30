
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd, int flg, int count)
{
	unsigned long	nb;

	nb = n;
	if (flg == '+' || flg == ' ')
	{
		if (nb > 1)
		{
		ft_putchar_fd(flg,fd);
		}
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -1 * nb;
	}
	while (nb == count)
	{
		if (nb >= 10)
		{
			ft_putnbr_fd(nb / 10, fd, 0);
			ft_putnbr_fd(nb % 10, fd, 0);
		}
		else
		{
			ft_putchar_fd(nb + '0', fd);
		}
	}
}

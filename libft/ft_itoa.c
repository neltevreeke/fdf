/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:00:46 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/17 17:00:47 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*loop(int n, int i, int size, int neg)
{
	char *str;

	if (size == 0)
		size++;
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = size;
	if (neg == 1)
		str[0] = '-';
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

static char	*maxint(void)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int	size;
	int	i;
	int	neg;

	if (n == -2147483648)
		return (maxint());
	size = 0;
	neg = 0;
	if (n < 0)
	{
		size++;
		neg = 1;
		n = n * -1;
	}
	i = n;
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (loop(n, i, size, neg));
}

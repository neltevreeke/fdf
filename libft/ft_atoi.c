/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 22:11:13 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/12 22:11:14 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned int	a;
	int				i;
	int				neg;

	i = 0;
	a = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = a * 10 + str[i] - 48;
		i++;
	}
	return (a * neg);
}

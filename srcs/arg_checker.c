/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:15 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/15 21:43:36 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit_str(char *str)
{
	size_t	i;
	size_t	flag;
	char	tmp;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) && str[i] != '-')
			return (write(2, "Error\n", 6));
		if (str[i] == '-')
			flag = 1;
		if (str[i++] == ' ')
			flag = 0;
		tmp = str[i];
		if (flag)
		{
			if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\0')
				return (write(2, "Error\n", 6));
			flag++;
			if ((str[i] == ' ' || !str[i] || !ft_isdigit(tmp)) && flag == 2)
				return (write(2, "Error\n", 6));
		}
	}
	return (0);
}

static int	sign_check(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static long long	ft_atoi_ll(const char *str)
{
	size_t		i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = sign_check(str[i++]);
	res = 0;
	while (ft_isdigit(str[i]))
	{
		if ((res * 10 + (str[i] - '0')) / 10 != res)
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_integer_check(char *str)
{
	size_t		i;
	long long	res;

	i = 0;
	while (str[i])
	{
		res = ft_atoi_ll(&str[i]);
		if (res > INT_MAX || res < INT_MIN)
			return (write(2, "Error\n", 6));
		while (ft_isspace(str[i]) || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (0);
}

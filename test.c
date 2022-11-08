/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:30:36 by marvin            #+#    #+#             */
/*   Updated: 2022/10/21 02:30:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void	test_ft_isalnum()
{
	int	inputs[] = {'0', '5', '9', 'a', 'e', 'z', 'A', 'E', 'Z', ' ', ':', ',', '!', '\n', 0, 127, 128, -4, -'A'};
	int	i;

	i = 0;
	while (i < 19)
	{
		printf("ft_isalnum(%d) == isalnum(%d)\n", inputs[i], inputs[i]);
		assert(!ft_isalnum(inputs[i]) == !isalnum(inputs[i]));
		i++;
	}
}

void	test_ft_isalpha()
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', 'a' - 1, 'z' + 1, -'f', 0, 127, 128};
	int	i;

	i = 0;
	while (i < 14)
	{
		printf("ft_isalpha(%d) == isalpha(%d)\n", inputs[i], inputs[i]);
		assert(!ft_isalpha(inputs[i]) == !isalpha(inputs[i]));
		i++;
	}
}

void	test_ft_isascii()
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', 'a' - 1, 'z' + 1, -'f', '\n', '\t', 0, 127, 128, 255, 256};
	int	i;

	i = 0;
	while (i < 18)
	{
		printf("ft_isascii(%d) == isascii(%d)\n", inputs[i], inputs[i]);
		assert(!ft_isascii(inputs[i]) == !isascii(inputs[i]));
		i++;
	}
}

void	test_ft_isdigit()
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', '5', 'a' - 1, 'z' + 1, -'f', '\n', '\t', 0, 127, 128, 255, 256};
	int	i;

	i = 0;
	while (i < 19)
	{
		printf("ft_isdigit(%d) == isdigit(%d)\n", inputs[i], inputs[i]);
		assert(!ft_isdigit(inputs[i]) == !isdigit(inputs[i]));
		i++;
	}
}

void	test_ft_isprint()
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', '5', 'a' - 1, 'z' + 1, -'f', '\n', '\t', 0, 127, 128, 255, 256};
	int	i;

	i = 0;
	while (i < 19)
	{
		printf("ft_isprint(%d) == isprint(%d)\n", inputs[i], inputs[i]);
		assert(!ft_isprint(inputs[i]) == !isprint(inputs[i]));
		i++;
	}
}

void	test_ft_atoi()
{
	char	*inputs[] = {"0", "9", "5", "17", "42", "128", "-128", "-0", "a42", "4a2", "42a", "-a42", "-4a2", "+42", " +42", "  42", "4 2", "1 000", "++42", "+-42"};
	int		i;

	i = 0;
	while (i < 20)
	{
		printf("ft_atoi(%s) == atoi(%s) -> %d, %d\n", inputs[i], inputs[i], ft_atoi(inputs[i]), atoi(inputs[i]));
		assert(ft_atoi(inputs[i]) == atoi(inputs[i]));
		i++;
	}
}

void	test_ft_strlen()
{
	char	*inputs[] = {"", "abc", "jhyb\0dacazerezar", "abcba\ndadasda"};
	int		i;

	i = 0;
	while (i < 4)
	{
		printf("ft_strlen(%s) == strlen(%s) -> %d, %d\n", inputs[i], inputs[i], ft_strlen(inputs[i]), strlen(inputs[i]));
		assert(ft_strlen(inputs[i]) == strlen(inputs[i]));
		i++;
	}
}

int	main(void)
{
	printf("===== STARTING TESTS :\n\n");

	printf("===== TESTING ft_isalnum(int c)..\n");
	test_ft_isalnum();
	printf("===== TESTS ft_isalnum(int c) completed.\n\n");

	printf("===== TESTING ft_isalpha(int c)..\n");
	test_ft_isalpha();
	printf("===== TESTS ft_isalpha(int c) completed.\n\n");

	printf("===== TESTING ft_isascii(int c)..\n");
	test_ft_isascii();
	printf("===== TESTS ft_isascii(int c) completed.\n\n");

	printf("===== TESTING ft_isdigit(int c)..\n");
	test_ft_isdigit();
	printf("===== TESTS ft_isdigit(int c) completed.\n\n");

	printf("===== TESTING ft_isprint(int c)..\n");
	test_ft_isprint();
	printf("===== TESTS ft_isprint(int c) completed.\n\n");

	printf("===== TESTING ft_atoi(int c)..\n");
	test_ft_atoi();
	printf("===== TESTS ft_atoi(int c) completed.\n\n");

	printf("===== TESTING ft_strlen(int c)..\n");
	test_ft_strlen();
	printf("===== TESTS ft_strlen(int c) completed.\n\n");


	printf("all TESTS completed.");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:30:36 by marvin            #+#    #+#             */
/*   Updated: 2022/11/16 16:48:23 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <malloc.h>

void	test_ft_isalnum(void)
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

void	test_ft_isalpha(void)
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

void	test_ft_isascii(void)
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', 'a' - 1, 'z' + 1, -'f', '\n', '\t', 0, 127, 128, 255, 256, -1, -150, 300};
	int	i;

	i = 0;
	while (i < 21)
	{
		printf("ft_isascii(%d) == isascii(%d)\n", inputs[i], inputs[i]);
		assert(!ft_isascii(inputs[i]) == !isascii(inputs[i]));
		i++;
	}
}

void	test_ft_isdigit(void)
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

void	test_ft_isprint(void)
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


void	test_ft_strlen(void)
{
	char	*inputs[] = {"", "abc", "jhyb\0dacazerezar", "abcba\ndadasda"};
	int		i;

	i = 0;
	while (i < 4)
	{
		printf("ft_strlen(%s) == strlen(%s) -> %ld, %ld\n", inputs[i], inputs[i], ft_strlen(inputs[i]), strlen(inputs[i]));
		assert(ft_strlen(inputs[i]) == strlen(inputs[i]));
		i++;
	}
}

void	uni_test_memset(int c)
{
	char	str[] = "ZIZI";
	char	str2[] = "ZIZI";
	char	*new = memset(str, c, 4);
	char	*new2 = ft_memset(str2, c, 4);
	for (int i = 0; i < 5; i++)
		assert(str[i] == str2[i]);
	for (int i = 0; i < 5; i++)
		assert(new[i] == new2[i]);
}

//void	*ft_memset(void *pointer, int value, size_t count);
void	test_ft_memset(void)
{
	int	inputs[] = {0, 'z', 128, -1, -128, -129, 3273};

	for (int i = 0; i < 7; i++)
	{
		printf("uni_test_memset(%d)\n", inputs[i]);
		uni_test_memset(inputs[i]);
	}
}

// max 5
void	uni_test_bzero(size_t n)
{
	char	str[] = "ZIZI";
	char	str2[] = "ZIZI";

	bzero(str, n);
	ft_bzero(str2, n);
	printf(" -> need {%d, %d, %d, %d, %d}", str[0], str[1], str[2], str[3], str[4]);
	printf(" | get {%d, %d, %d, %d, %d}\n", str2[0], str2[1], str2[2], str2[3], str2[4]);
	for (int i = 0; i < 5; i++)
		assert(str[i] == str2[i]);
}

//void	ft_bzero(void *s, size_t n);
void	test_ft_bzero(void)
{
	int	inputs[] = {0, 1, 4};

	for (int i = 0; i < 3; i++)
	{
		printf("uni_test_bzero(%d)", inputs[i]);
		uni_test_bzero(inputs[i]);
	}
}

void	uni_test_memcpy(int n)
{
	if (n <= 5)
	{
		printf("TEST 1\n");
		char	src[] = "ZIZI";
		char	src2[] = "ZIZI";
		char	dest[5] = "CACA";
		char	dest2[5] = "CACA";
		char	*new = memcpy(dest, src, n);
		char	*new2 = ft_memcpy(dest2, src2, n);
		printf("real -> %s\n", dest);
		printf("ft   -> %s\n", dest2);
		for (int i = 0; i < 5; i++)
			assert(dest[i] == dest2[i]);
		for (int i = 0; i < 5; i++)
			assert(new[i] == new2[i]);
	}

	//char	src8[] = "ZICAPITAMIXTAPE";
	//char	src28[] = "ZICAPITAMIXTAPE";
	//char	*dest8 = src8 + 2;
	//char	*dest28 = src28 + 2;
	//char	*new8 = memcpy(dest8, src8, n);
	//char	*new28 = ft_memcpy(dest28, src28, n);
	//printf("TEST 2\n");
	//printf("real -> %s\n", dest8);
	//printf("ft   -> %s\n", dest28);
	//for (int i = 0; i < 5; i++)
	//	assert(dest8[i] == dest28[i]);
	//for (int i = 0; i < 5; i++)
	//	assert(new8[i] == new28[i]);

	//char	dest89[] = "ZICAPITAMIXTAPE";
	//char	dest289[] = "ZICAPITAMIXTAPE";
	//char	*src89 = dest89 + 2;
	//char	*src289 = dest289 + 2;
	//char	*new89 = memcpy(dest89, src89, n);
	//char	*new289 = ft_memcpy(dest289, src289, n);
	//printf("TEST 3\n");
	//printf("real -> %s\n", dest89);
	//printf("ft   -> %s\n", dest289);
	//for (int i = 0; i < 5; i++)
	//	assert(dest89[i] == dest289[i]);
	//for (int i = 0; i < 5; i++)
	//	assert(new89[i] == new289[i]);
}

//void	*ft_memcpy(void *dest, const void *src, size_t n);
void	test_ft_memcpy(void)
{
	int	inputs[] = {0, 1, 4, 10};

	for (int i = 0; i < 3; i++)
	{
		printf("uni_test_memcpy(%d)\n", inputs[i]);
		uni_test_memcpy(inputs[i]);
	}
}

void	uni_test_memmove(int n)
{
	char	src[] = "ZIZI";
	char	src2[] = "ZIZI";
	char	dest[5] = "CACA";
	char	dest2[5] = "CACA";
	char	*new = memmove(dest, src, n);
	char	*new2 = ft_memmove(dest2, src2, n);
	for (int i = 0; i < 5; i++)
		assert(dest[i] == dest2[i]);
	for (int i = 0; i < 5; i++)
		assert(new[i] == new2[i]);

	char	src8[] = "ZICAPITAMIXTAPE";
	char	src28[] = "ZICAPITAMIXTAPE";
	char	*dest8 = src8 + 2;
	char	*dest28 = src28 + 2;
	char	*new8 = memmove(dest8, src8, n);
	char	*new28 = ft_memmove(dest28, src28, n);
	for (int i = 0; i < 5; i++)
		assert(dest8[i] == dest28[i]);
	for (int i = 0; i < 5; i++)
		assert(new8[i] == new28[i]);

	char	dest89[] = "ZICAPITAMIXTAPE";
	char	dest289[] = "ZICAPITAMIXTAPE";
	char	*src89 = dest89 + 2;
	char	*src289 = dest289 + 2;
	char	*new89 = memmove(dest89, src89, n);
	char	*new289 = ft_memmove(dest289, src289, n);
	for (int i = 0; i < 5; i++)
		assert(dest89[i] == dest289[i]);
	for (int i = 0; i < 5; i++)
		assert(new89[i] == new289[i]);

	char	src878[] = "ZICAPITAMIXTAPE";
	char	src2878[] = "ZICAPITAMIXTAPE";
	char	*dest878 = src878;
	char	*dest2878 = src2878;
	char	*new878 = memmove(dest878, src878, n);
	char	*new2878 = ft_memmove(dest2878, src2878, n);
	for (int i = 0; i < 5; i++)
		assert(dest878[i] == dest2878[i]);
	for (int i = 0; i < 5; i++)
		assert(new878[i] == new2878[i]);

	//char	*src007 = NULL;
	//char	*src2007 = NULL;
	//char	*dest007 = NULL;
	//char	*dest2007 = NULL;
	//ft_memmove(dest2007, src2007, n);
	//memmove(dest007, src007, n);
}

void	test_ft_memmove(void)
{
	int	inputs[] = {0, 1, 4};

	for (int i = 0; i < 3; i++)
	{
		printf("uni_test_memmove(%d)\n", inputs[i]);
		uni_test_memmove(inputs[i]);
	}
}

void	test_ft_strlcpy(void)
{
	char	dest[20] = "1234567890123456789";
	char	ft_dest[20] = "1234567890123456789";

	size_t res = strlcpy(dest, "abcd", 20);
	size_t ft_res = ft_strlcpy(ft_dest, "abcd", 20);
	printf("%ld == %ld\n", res, ft_res);
	assert(res == ft_res);

	printf("%s == %s\n", dest, ft_dest);
	assert(!strcmp(dest, ft_dest));

	for (int i = 0; i < 20; i++)
	{
		printf("'%c' == '%c' -> %d == %d | ", dest[i], ft_dest[i], dest[i], ft_dest[i]);
		assert(dest[i] == ft_dest[i]);
		if (i % 4 == 3)
			printf("\n");
	}
}


void	test_ft_strlcat(void)
{
	char dest[20] = "abcd";
	char dest2[5] = "ab";
	char src[10] = "OOK!";
	char ft_dest[20] = "abcd";
	char ft_dest2[5] = "ab";
	char ft_src[10] = "OOK!";

	size_t	rep1 = strlcat(dest, "efg", 2);
	size_t	ft_rep1 = ft_strlcat(ft_dest, "efg", 2);
	printf("strlcat(dest, \"efg\", 2) = %ld\n", rep1);
	printf("ft_strlcat(ft_dest, \"efg\", 2) = %ld\n", ft_rep1);
	assert(rep1 == ft_rep1);

	printf("dest = %s\n", dest);
	printf("ft_dest = %s\n", ft_dest);
	assert(!strcmp(dest, ft_dest));

	size_t	rep2 = strlcat(dest2, "efg", 2);
	size_t	ft_rep2 = ft_strlcat(ft_dest2, "efg", 2);
	printf("strlcat(dest2, \"efg\", 2) = %ld\n", rep2);
	printf("ft_strlcat(ft_dest2, \"efg\", 2) = %ld\n", ft_rep2);
	assert(rep2 == ft_rep2);

	printf("dest2 = %s\n", dest2);
	printf("ft_dest2 = %s\n", ft_dest2);
	assert(!strcmp(dest2, ft_dest2));

	size_t	rep3 = strlcat(dest2, src, 2);
	size_t	ft_rep3 = ft_strlcat(ft_dest2, ft_src, 2);
	printf("strlcat(dest2, src, 2) = %ld\n", rep3);
	printf("ft_strlcat(ft_dest2, ft_src, 2) = %ld\n", ft_rep3);
	assert(rep2 == ft_rep2);

	printf("dest2 = %s\n", dest2);
	printf("ft_dest2 = %s\n", ft_dest2);
	assert(!strcmp(dest2, ft_dest2));


	char	dest_test[20] = "12345678";
	char	dest_test2[20] = "12345678";
	char	ft_dest_test[20] = "12345678";
	char	ft_dest_test2[20] = "12345678";

	size_t	rep4 = strlcat(dest_test, "abcdefghijklmnopqrstuvwxyz", 20);
	size_t	ft_rep4 = ft_strlcat(ft_dest_test, "abcdefghijklmnopqrstuvwxyz", 20);
	printf("%ld == %ld\n", rep4, ft_rep4);
	assert(rep4 == ft_rep4);


	size_t	rep5 = strlcat(dest_test2, "abcde", 20);
	size_t	ft_rep5 = ft_strlcat(ft_dest_test2, "abcde", 20);
	printf("%ld == %ld\n", rep5, ft_rep5);
	assert(rep5 == ft_rep5);

	printf("%s == %s\n", dest_test, ft_dest_test);
	assert(!strcmp(dest_test, ft_dest_test));

	printf("%s == %s\n", dest_test2, ft_dest_test2);
	assert(!strcmp(dest_test2, ft_dest_test2));

	for (int i = 0; i < 20; i++)
	{
		printf("'%c' == '%c' -> %d == %d | ", dest_test[i], ft_dest_test[i], dest_test[i], ft_dest_test[i]);
		assert(dest_test[i] == ft_dest_test[i]);
		if (i % 4 == 3)
			printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 20; i++)
	{
		printf("'%c' == '%c' -> %d == %d | ", dest_test2[i], ft_dest_test2[i], dest_test2[i], ft_dest_test2[i]);
		assert(dest_test2[i] == ft_dest_test2[i]);
		if (i % 4 == 3)
			printf("\n");
	}

	char *last_dest = malloc(15 * sizeof(*last_dest));
	char *last_ft_dest = malloc(15 * sizeof(*last_dest));
	if (!last_dest || !last_ft_dest)
		exit(1);
	memset(last_dest, 'r', 14);
	last_dest[14] = 0;
	memset(last_ft_dest, 'r', 14);
	last_ft_dest[14] = 0;
	size_t	last_rep = strlcat(last_dest, "lorem ipsum dolor sit amet", 5);
	size_t	last_ft_rep = ft_strlcat(last_ft_dest, "lorem ipsum dolor sit amet", 5);
	printf("%ld == %ld\n", last_rep, last_ft_rep);
	assert(last_rep == last_ft_rep);

	printf("%s == %s\n", last_dest, last_ft_dest);
	assert(!strcmp(last_dest, last_ft_dest));

	for (int i = 0; i < 15; i++)
	{
		printf("'%c' == '%c' -> %d == %d | ", last_dest[i], last_ft_dest[i], last_dest[i], last_ft_dest[i]);
		assert(last_dest[i] == last_ft_dest[i]);
		if (i % 4 == 3)
			printf("\n");
	}
	free(last_dest);
	free(last_ft_dest);
}

void	test_ft_toupper()
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', '5', 'a' - 1, 'z' + 1, -'f', '\n', '\t', 0, 127, 128, 255, 256, 'A', 'Z', 'E', 300, 'a' + 256 * 5, 'A' + 256 * 5, -1, -('a' + 256 * 5), -127, -128, -129, 129};
	int	i;

	i = 0;
	while (i < 31)
	{
		printf("ft_toupper(%d) == toupper(%d) -> %d == %d\n", inputs[i], inputs[i], ft_toupper(inputs[i]), toupper(inputs[i]));
		assert(ft_toupper(inputs[i]) == toupper(inputs[i]));
		i++;
	}
}

void	test_ft_tolower()
{
	int	inputs[] = {'a', 'e', 'z', '0', ' ', '!', ',', '9', '5', 'a' - 1, 'z' + 1, -'f', '\n', '\t', 0, 127, 128, 255, 256, 'A', 'Z', 'E', 300, 'a' + 256 * 5, 'A' + 256 * 5, -1, -('a' + 256 * 5), -127, -128, -129, 129};
	int	i;

	i = 0;
	while (i < 31)
	{
		printf("ft_tolower(%d) == tolower(%d)\n", inputs[i], inputs[i]);
		assert(ft_tolower(inputs[i]) == tolower(inputs[i]));
		i++;
	}
}

//char	*ft_strchr(const char *s, int c);
void	test_ft_strchr(void)
{
	const char	*inputs[] = {"abcde", "abcde", "", "", "abcde", "uG&62\n\t+<,",
		"abcde", "abcde", "abacde", "abecde", "abcdeee", "abababab", "abababab",
		"abcde", "abcde", "abcdefghijklmnopqrstvwxyz"};
	const int	inputs1[] = {'c', 'f', 'a', '\0', '\0',
		'\n', 'a', 'e', 'a', 'e', 'e', 'a', 'b', 256, -8, -156};

	for (int i = 0; i < 16; i++)
	{
		printf("ft_strchr(%s, %d) == strchr(%s, %d) == %s == %s\n", inputs[i],
			inputs1[i], inputs[i], inputs1[i], ft_strchr(inputs[i], inputs1[i]), strchr(inputs[i],
				inputs1[i]));
		assert(ft_strchr(inputs[i], inputs1[i]) == strchr(inputs[i],
				inputs1[i]));
	}
}

//char	*ft_strrchr(const char *s, int c);
void	test_ft_strrchr(void)
{
	const char	*inputs[] = {"abcde", "abcde", "", "", "abcde", "uG&62\n\t+<,",
		"abcde", "abcde", "abacde", "abecde", "abcdeee", "abababab", "abababab",
		"abcde", "abcde", "abcdefghijklmnopqrstvwxyz"};
	const int	inputs1[] = {'c', 'f', 'a', '\0', '\0',
		'\n', 'a', 'e', 'a', 'e', 'e', 'a', 'b', 256, -8, -156};

	for (int i = 0; i < 16; i++)
	{
		printf("%d. ft_strrchr(%s, %d) == strrchr(%s, %d) -> %s == %s\n", i + 1, inputs[i],
			inputs1[i], inputs[i], inputs1[i], ft_strrchr(inputs[i], inputs1[i]),
			strrchr(inputs[i], inputs1[i]));
		assert(ft_strrchr(inputs[i], inputs1[i]) == strrchr(inputs[i],
				inputs1[i]));
	}
}

int	cmp_to_cmp(int i)
{
	if (!i)
		return (i);
	return (i / i);
}

//int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	test_ft_strncmp(void)
{
	const char	*inputs[] = {"abc", "abc", "abc", "azz", "abc", "abc", "abc", "azz", "abz", "ab\0cd"};
	const char	*inputs1[] = {"abcd", "abc", "acd", "abc", "abcd", "abc", "acd", "abc", "acc", "ab\0cd"};
	int	inputs2[] = {4, 3, 3, 3, 1, 1, 1, 1, 2, 5};

	for (int i = 0; i < 9; i++)
	{
		printf("ft_strncmp(%s, %s, %d) == strncmp(%s, %s, %d) -> %d == %d\n", inputs[i], inputs1[i], inputs2[i], inputs[i], inputs1[i], inputs2[i], ft_strncmp(inputs[i], inputs1[i], inputs2[i]), strncmp(inputs[i], inputs1[i], inputs2[i]));
		assert(cmp_to_cmp(ft_strncmp(inputs[i], inputs1[i], inputs2[i])) == cmp_to_cmp(strncmp(inputs[i], inputs1[i], inputs2[i])));
	}
}

//void	*ft_memchr(const void *s, int c, size_t n);
void	test_ft_memchr(void)
{
	const char		*inputs[] = {"abcde", "abcde", "", "", "abcde", "uG&62\n\t+<,",
		"abcde", "abcde", "abacde", "abecde", "abcdeee", "abababab", "abababab",
		"abcde", "abcde", "abcdefghijklmnopqrstvwxyz", "abcdefghijklmnopqrstvwxyz", "abcdefghijklmnopqrstvwxyz", "abcdefghijklmnopqrstvwxyz", "abcdefghijklmnopqrstvwxyz", "abcdefghijklmnopqrstvwxyz", "abcdefghijklm\0opqrstvwxyz"};
	const int		inputs1[] = {'c', 'f', 'a', '\0', '\0',
		'\n', 'a', 'e', 'a', 'e', 'e', 'a', 'b', 256, -8, -156, 'z', 0, 'g', '\n', '\n', 'o'};
	const size_t	inputs2[] = {6, 6, 1, 1, 6, 13, 6, 6, 7, 7, 8, 9, 9, 6, 6, 26, 20, 20, 20, 20, 26, 26};

	for (int i = 0; i < 22; i++)
	{
		printf("ft_memchr(%s, %d (%c), %ld) == memchr(%s, %d (%c), %ld) == %s == %s\n", inputs[i], inputs1[i], inputs1[i], inputs2[i], inputs[i], inputs1[i], inputs1[i], inputs2[i], (char *)ft_memchr(inputs[i], inputs1[i], inputs2[i]), (char *)memchr(inputs[i], inputs1[i], inputs2[i]));
		assert(ft_memchr(inputs[i], inputs1[i], inputs2[i]) == memchr(inputs[i], inputs1[i], inputs2[i]));
	}
}

//int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	test_ft_memcmp(void)
{
	const char	*inputs[] = {"abc", "abc", "abc", "azz", "abc", "abc", "abc", "azz", "abz", "te\0st"};
	const char	*inputs1[] = {"abcd", "abc", "acd", "abc", "abcd", "abc", "acd", "abc", "acc", "te\0at"};
	size_t		inputs2[] = {4, 3, 3, 3, 1, 1, 1, 1, 2, 5};

	for (int i = 0; i < 10; i++)
	{
		printf("ft_memcmp(%s, %s, %ld) == memcmp(%s, %s, %ld) -> %d == %d\n", inputs[i], inputs1[i], inputs2[i], inputs[i], inputs1[i], inputs2[i], ft_memcmp(inputs[i], inputs1[i], inputs2[i]), memcmp(inputs[i], inputs1[i], inputs2[i]));
		assert(!ft_memcmp(inputs[i], inputs1[i], inputs2[i]) == !memcmp(inputs[i], inputs1[i], inputs2[i]));
	}
}

//char	*ft_strnstr(const char	*big, const char *little, size_t len);
void	test_ft_strnstr(void)
{
	const char		str1[] = "abcdefghijklmnopqrstuvwxyz";
	const char		str2[] = "abababa";
	const char		str3[] = "aabaaabaabababababaaab";
	const char		str4[] = "";
	const char		*inputs[] = {str1, str2, str3, str3, str4, str4, str1, str1, str1, str1, str1, str1, str4, str1, str1, str1, str1, str1, str1, str1, str1, str1, str1, str1, str1};
	const char		*inputs1[] = {"hijkl", "ba", "aaab", "", "aa", "", "abcdf", "xyz", "efgzui", "efgzui", "efgzui", "efgzui", "\0", "", "", "z\0", "hijkl", "hijkl", "hijkl", "hijkl", "hijkl", "xyz", "xyz", "xyz", "xyz"};
	const size_t	inputs2[] = {5, 2, 4, 0, 2, 0, 5, 3, 5, 3, 4, 0, 1, 1, 5, 2, 12, 11, 10, 13, -1, 25, 26, -1, 27};

	for (int i = 0; i < 24; i++)
	{
		printf("ft_strnstr(%s, %s, %ld) == strnstr(%s, %s, %ld) -> \"%s\" == \"%s\"\n", inputs[i], inputs1[i], inputs2[i], inputs[i], inputs1[i], inputs2[i], ft_strnstr(inputs[i], inputs1[i], inputs2[i]), strnstr(inputs[i], inputs1[i], inputs2[i]));
		assert(ft_strnstr(inputs[i], inputs1[i], inputs2[i]) == strnstr(inputs[i], inputs1[i], inputs2[i]));
	}
}

//int	ft_atoi(const char *str);
void	test_ft_atoi(void)
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

//void	*ft_calloc(size_t nmemb, size_t size);
void	test_ft_calloc(void)
{
	char	*ft_res = ft_calloc(24, 1);
	char	*res = calloc(24, 1);
	char	*ft_res2 = ft_calloc(0, 1);
	char	*res2 = calloc(0, 1);
	char	*ft_res3 = ft_calloc(5, 0);
	char	*res3 = calloc(5, 0);
	char	*ft_res4 = ft_calloc(__INT_MAX__, __INT_MAX__);
	char	*res4 = calloc(__INT_MAX__, __INT_MAX__);
	char	*ft_res5 = ft_calloc(25, 1);
	char	*res5 = calloc(25, 1);
	char	*tmp;
	char	*tmp5;

	// if NULL : problem, retry
	assert(ft_res && res);
	assert(ft_res5 && res5);
	printf("Testing ft_calloc(0, 1)\n");
	tmp = malloc(0);
	assert(malloc_usable_size(ft_res2) == malloc_usable_size(tmp) && \
		malloc_usable_size(res2) == malloc_usable_size(tmp));
	free(tmp);
	printf("Testing ft_calloc(5, 0)\n");
	tmp = malloc(0);
	printf("%ld\n", malloc_usable_size(ft_res3));
	printf("%ld\n", malloc_usable_size(tmp));
	assert(malloc_usable_size(ft_res3) == malloc_usable_size(tmp) && \
		malloc_usable_size(res3) == malloc_usable_size(tmp));
	free(tmp);
	printf("Memory set to zero test processing..\n");
	for (int i = 0; i < 24; i++)
	{
		assert(!ft_res[i]);
		assert(!res[i]);
	}
	printf("Memory set to zero test finished\n");
	printf("Memory size check processing..\n");
	tmp = malloc(24);
	tmp5 = malloc(25);
	printf("%ld\n", malloc_usable_size(ft_res));
	printf("%ld\n", malloc_usable_size(tmp));
	printf("%ld\n", malloc_usable_size(ft_res5));
	printf("%ld\n", malloc_usable_size(tmp5));
	assert(malloc_usable_size(ft_res) == malloc_usable_size(tmp) && \
		malloc_usable_size(res) == malloc_usable_size(tmp));
	assert(malloc_usable_size(ft_res5) == malloc_usable_size(tmp5) && \
		malloc_usable_size(res5) == malloc_usable_size(tmp5));
	free(tmp);
	free(tmp5);
	printf("Memory size check finished\n");
	printf("Integer overflow check processing..\n");
	printf("ft_calloc(2147483648, 1) == %p\n", ft_res4);
	printf("calloc(536870912, 4) == %p\n", res4);
	assert(!ft_res4 && !res4);
	printf("Integer overflow check finished\n");
	free(ft_res);
	free(res);
	free(ft_res2);
	free(res2);
	free(ft_res3);
	free(res3);
	free(ft_res5);
	free(res5);
}

//char	*ft_strdup(const char *s);
void	test_ft_strdup(void)
{
	char	*res = strdup("abcd");
	char	*ft_res = ft_strdup("abcd");

	assert(ft_res && res);
	printf("strcmp(strdup(\"abcd\"), ft_strdup(\"abcd\")) == %s == %s\n",
		res, ft_res);
	assert(!strcmp(res, ft_res) && !strcmp(res, "abcd") && !strcmp(ft_res, "abcd"));
	assert(malloc_usable_size(res) == malloc_usable_size(ft_res));
	free(res);
	free(ft_res);

	res = strdup("");
	ft_res = ft_strdup("");

	assert(ft_res && res);
	printf("strcmp(strdup(\"\"), ft_strdup(\"\"))\n");
	assert(!strcmp(res, ft_res) && !strcmp(res, "") && !strcmp(ft_res, ""));
	assert(malloc_usable_size(res) == malloc_usable_size(ft_res));
	free(res);
	free(ft_res);
}

void	verif_malloc_size(void *p, size_t size)
{
	printf("Verif malloc size : \"%s\" <-> %ld\n", (char *) p, size);
	char *tmp = malloc(size);
	assert(tmp);
	assert(malloc_usable_size(tmp) == malloc_usable_size(p));
	free(tmp);
}

//char	*ft_substr(char const *s, unsigned int start, size_t len);
void	test_ft_substr(void)
{
	char	*res = ft_substr("abcdefghijklmnoparstuvwxyz", 4, 5);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 4, 5) == \"%s\"\n", res);
	assert(!strcmp(res, "efghi"));
	verif_malloc_size(res, 6);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 30, 5);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 30, 5) == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 30, 30);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 30, 30) == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 23, 30);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 23, 30) == \"%s\"\n", res);
	assert(!strcmp(res, "xyz"));
	verif_malloc_size(res, 4);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 0, 30);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 0, 30) == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijklmnoparstuvwxyz"));
	verif_malloc_size(res, 27);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 5, 0);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 5, 0) == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 0, 24);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 5, 0) == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijklmnoparstuvwx"));
	verif_malloc_size(res, 25);
	free(res);

	res = ft_substr("abcdefghijklmnoparstuvwxyz", 0, 25);
	assert(res);
	printf("ft_substr(\"abcdefghijklmnoparstuvwxyz\", 5, 0) == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijklmnoparstuvwxy"));
	verif_malloc_size(res, 26);
	free(res);

	res = ft_substr("l", 1, 1);
	assert(res);
	printf("ft_substr(\"l\", 1, 1) == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);
}

//char	*ft_strjoin(char const *s1, char const *s2);
void	test_ft_strjoin(void)
{
	char	*res = ft_strjoin("abcdefghijkl", "mnoparstuvwxyz");
	assert(res);
	printf("ft_strjoin(\"abcdefghijkl\", \"mnoparstuvwxyz\") == \"abcdefghijklmnoparstuvwxyz\"\n");
	assert(!strcmp(res, "abcdefghijklmnoparstuvwxyz"));
	verif_malloc_size(res, 27);
	free(res);

	res = ft_strjoin("abcdefghijkl", "");
	assert(res);
	printf("ft_strjoin(\"abcdefghijkl\", \"\") == \"abcdefghijkl\"\n");
	assert(!strcmp(res, "abcdefghijkl"));
	verif_malloc_size(res, 13);
	free(res);

	res = ft_strjoin("", "mnoparstuvwxyz");
	assert(res);
	printf("ft_strjoin(\"\", \"mnoparstuvwxyz\") == \"mnoparstuvwxyz\"\n");
	assert(!strcmp(res, "mnoparstuvwxyz"));
	verif_malloc_size(res, 15);
	free(res);

	res = ft_strjoin("", "");
	assert(res);
	printf("ft_strjoin(\"\", \"\") == \"\"\n");
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_strjoin("abcdefghijklmnopqrstuv", "wx");
	assert(res);
	printf("ft_strjoin(\"\", \"\") == \"\"\n");
	assert(!strcmp(res, "abcdefghijklmnopqrstuvwx"));
	verif_malloc_size(res, 25);
	free(res);

	res = ft_strjoin("abcdefghijklmnopqrstuv", "wxy");
	assert(res);
	printf("ft_strjoin(\"\", \"\") == \"\"\n");
	assert(!strcmp(res, "abcdefghijklmnopqrstuvwxy"));
	verif_malloc_size(res, 26);
	free(res);
}

//char	*ft_strtrim(char const *s1, char const *set);
void	test_ft_strtrim(void)
{
	char	*res;

	res = ft_strtrim("abcdefghijkl", "l");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkl\", \"l\") == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijk"));
	verif_malloc_size(res, 12);
	free(res);

	res = ft_strtrim("abcdefghijkll", "l");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkll\", \"l\") == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijk"));
	verif_malloc_size(res, 12);
	free(res);

	res = ft_strtrim("abcdefghijkll", "lacb");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkll\", \"lacb\") == \"%s\"\n", res);
	assert(!strcmp(res, "defghijk"));
	verif_malloc_size(res, 9);
	free(res);

	res = ft_strtrim("abcdefghijkll", "a");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkll\", \"a\") == \"%s\"\n", res);
	assert(!strcmp(res, "bcdefghijkll"));
	verif_malloc_size(res, 13);
	free(res);

	res = ft_strtrim("abcdefghijkll", "");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkll\", \"\") == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijkll"));
	verif_malloc_size(res, 14);
	free(res);

	res = ft_strtrim("abcdefghijkll", "gijglh");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkll\", \"gijglh\") == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijk"));
	verif_malloc_size(res, 12);
	free(res);

	res = ft_strtrim("abcdefghijkll", "hajlulr");
	assert(res);
	printf("ft_strtrim(\"abcdefghijkll\", \"hajlulr\") == \"%s\"\n", res);
	assert(!strcmp(res, "bcdefghijk"));
	verif_malloc_size(res, 11);
	free(res);

	res = ft_strtrim("aalaallaallaaal", "admkds l");
	assert(res);
	printf("ft_strtrim(\"aalaallaallaaal\", \"admkds l\") == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_strtrim("", "admkds l");
	assert(res);
	printf("ft_strtrim(\"\", \"admkds l\") == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_strtrim("", "");
	assert(res);
	printf("ft_strtrim(\"\", \"\") == \"%s\"\n", res);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);

	res = ft_strtrim("abcdefghijklmnopqrstuvwxyz", "az");
	assert(res);
	printf("ft_strtrim(\"\", \"\") == \"%s\"\n", res);
	assert(!strcmp(res, "bcdefghijklmnopqrstuvwxy"));
	verif_malloc_size(res, 25);
	free(res);

	res = ft_strtrim("abcdefghijklmnopqrstuvwxyz", "z");
	assert(res);
	printf("ft_strtrim(\"\", \"\") == \"%s\"\n", res);
	assert(!strcmp(res, "abcdefghijklmnopqrstuvwxy"));
	verif_malloc_size(res, 26);
	free(res);
}

static void	free_split(char **res, int len)
{
	while (len > 0)
	{
		free(res[len - 1]);
		len--;
	}
	free(res);
}

//char	**ft_split(char const *s, char c);
void	test_ft_split(void)
{
	char	**res;

	res = ft_split("bbbabbbb", 'a');
	assert(res);
	printf("ft_split(\"bbbabbbb\", 'a')\n");
	verif_malloc_size(res, 3 * sizeof(char *));
	assert(!strcmp(res[0], "bbb"));
	verif_malloc_size(res[0], 4);
	assert(!strcmp(res[1], "bbbb"));
	verif_malloc_size(res[1], 5);
	assert(!res[2]);
	free_split(res, 2);

	res = ft_split("bbbabbbbabb", 'a');
	assert(res);
	printf("ft_split(\"bbbabbbbabb\", 'a')\n");
	verif_malloc_size(res, 4 * sizeof(char *));
	assert(!strcmp(res[0], "bbb"));
	verif_malloc_size(res[0], 4);
	assert(!strcmp(res[1], "bbbb"));
	verif_malloc_size(res[1], 5);
	assert(!strcmp(res[2], "bb"));
	verif_malloc_size(res[2], 3);
	assert(!res[3]);
	free_split(res, 3);

	res = ft_split("bbbabbbbabb", 'c');
	assert(res);
	printf("ft_split(\"bbbabbbbabb\", 'c')\n");
	verif_malloc_size(res, 2 * sizeof(char *));
	assert(!strcmp(res[0], "bbbabbbbabb"));
	verif_malloc_size(res[0], 12);
	assert(!res[1]);
	free_split(res, 1);

	res = ft_split("abbbabbbbabbaaa", 'a');
	assert(res);
	printf("ft_split(\"abbbabbbbabbaaa\", 'a')\n");
	verif_malloc_size(res, 4 * sizeof(char *));
	assert(!strcmp(res[0], "bbb"));
	verif_malloc_size(res[0], 4);
	assert(!strcmp(res[1], "bbbb"));
	verif_malloc_size(res[1], 5);
	assert(!strcmp(res[2], "bb"));
	verif_malloc_size(res[2], 3);
	assert(!res[3]);
	free_split(res, 3);

	res = ft_split("aaaa", 'a');
	assert(res);
	printf("ft_split(\"aaaa\", 'a')\n");
	verif_malloc_size(res, 1 * sizeof(char *));
	assert(!res[0]);
	free_split(res, 0);

	res = ft_split("", 'a');
	assert(res);
	printf("ft_split(\"\", 'a')\n");
	verif_malloc_size(res, 1 * sizeof(char *));
	assert(!res[0]);
	free_split(res, 0);

	res = ft_split("aaabbaabbb", '\0');
	assert(res);
	printf("ft_split(\"aaabbaabbb\", '\\0')\n");
	verif_malloc_size(res, 2 * sizeof(char *));
	assert(!strcmp(res[0], "aaabbaabbb"));
	verif_malloc_size(res[0], 11);
	assert(!res[1]);
	free_split(res, 1);

	res = ft_split("abbbb", 'a');
	assert(res);
	printf("ft_split(\"abbbb\", 'a')\n");
	verif_malloc_size(res, 2 * sizeof(char *));
	assert(!strcmp(res[0], "bbbb"));
	verif_malloc_size(res[0], 5);
	assert(!res[1]);
	free_split(res, 1);

	res = ft_split("bbbba", 'a');
	assert(res);
	printf("ft_split(\"bbbba\", 'a')\n");
	verif_malloc_size(res, 2 * sizeof(char *));
	assert(!strcmp(res[0], "bbbb"));
	verif_malloc_size(res[0], 5);
	assert(!res[1]);
	free_split(res, 1);

	// @TODO Test NULL input ?
}

//char	*ft_itoa(int n);
void	test_ft_itoa(void)
{
	int	inputs[] = {0, INT_MAX, INT_MIN, 0, 1, -1, 42, -42};
	char	*ft_res;
	char	res[20];
	int		len;

	for (int i = 0; i < 8; i++)
	{
		ft_res = ft_itoa(inputs[i]);
		assert(ft_res);
		len = sprintf(res, "%d", inputs[i]);
		printf("ft_itoa(%d) -> \"%s\" (need \"%s\")\n", inputs[i], ft_res, res);
		assert(!strcmp(res, ft_res));
		verif_malloc_size(ft_res, len + 1);
		free(ft_res);
	}
}

char	add(unsigned int i, char c)
{
	return (i + c);
}

//char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	test_ft_strmapi(void)
{
	char	*res;

	res = ft_strmapi("12345", add); // if coredump -> trying to write in data layer
	assert(!strcmp(res, "13579"));
	verif_malloc_size(res, 6);
	free(res);

	res = ft_strmapi("", add);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
	free(res);
}

void	add2(unsigned int i, char *c)
{
	*c += i;
}

//void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	test_ft_striteri(void)
{
	char	*res;

	res = (char []){'1', '2', '3', '4', '5', '\0'};
	ft_striteri(res, add2);
	assert(!strcmp(res, "13579"));
	verif_malloc_size(res, 6);

	res = (char []){'\0'};
	ft_striteri(res, add2);
	assert(!strcmp(res, ""));
	verif_malloc_size(res, 1);
}

//void	ft_putchar_fd(char c, int fd);
void	test_ft_putchar_fd(void)
{
	int	fd = open("test_put", O_RDWR | O_CREAT);

	ft_putchar_fd('c', fd);
	char res[2] = {0};
	read(fd, res, 2);
	assert(strcmp(res, "c"));
	close(fd);
}

//void	ft_putstr_fd(char *s, int fd);
void	test_ft_putstr_fd(void)
{
	int	fd = open("test_put", O_RDWR | O_CREAT);

	ft_putstr_fd("bebe pas beau", fd);
	char res[15] = {0};
	read(fd, res, 15);
	assert(strcmp(res, "bebe pas beau"));
	close(fd);
}

//void	ft_putendl_fd(char *s, int fd);
void	test_ft_putendl_fd(void)
{
	int	fd = open("test_put", O_RDWR | O_CREAT);

	ft_putendl_fd("bebe pas beau", fd);
	char res[16] = {0};
	read(fd, res, 16);
	assert(strcmp(res, "bebe pas beau\n"));
	close(fd);
}

//void	ft_putnbr_fd(int n, int fd);
void	test_ft_putnbr_fd(void)
{
	int	fd = open("test_put", O_RDWR | O_CREAT);
	ft_putnbr_fd(42, fd);
	char res[50] = {0};
	read(fd, res, 3);
	assert(strcmp(res, "42"));
	close(fd);

	fd = open("test_put", O_RDWR | O_CREAT);
	ft_putnbr_fd(0, fd);
	read(fd, res, 2);
	assert(strcmp(res, "0"));
	close(fd);

	char real_res[50];
	sprintf(real_res, "%d", INT_MAX);
	fd = open("test_put", O_RDWR | O_CREAT);
	ft_putnbr_fd(INT_MAX, fd);
	read(fd, res, 50);
	assert(strcmp(res, real_res));
	close(fd);

	sprintf(real_res, "%d", INT_MIN);
	fd = open("test_put", O_RDWR | O_CREAT);
	ft_putnbr_fd(INT_MAX, fd);
	read(fd, res, 50);
	assert(strcmp(res, real_res));
	close(fd);

	fd = open("test_put", O_RDWR | O_CREAT);
	ft_putnbr_fd(-42, fd);
	read(fd, res, 4);
	assert(strcmp(res, "-42"));
	close(fd);
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

	printf("===== TESTING ft_strlen(int c)..\n");
	test_ft_strlen();
	printf("===== TESTS ft_strlen(int c) completed.\n\n");

	printf("===== TESTING ft_memset()..\n");
	test_ft_memset();
	printf("===== TESTS ft_memset completed.\n\n");

	printf("===== TESTING ft_bzero()..\n");
	test_ft_bzero();
	printf("===== TESTS ft_bzero completed.\n\n");

	printf("===== TESTING ft_memcpy()..\n");
	test_ft_memcpy();
	printf("===== TESTS ft_memcpy() completed.\n\n");

	printf("===== TESTING ft_memmove()..\n");
	test_ft_memmove();
	printf("===== TESTS ft_memmove() completed.\n\n");

	printf("===== TESTING ft_strlcpy()..\n");
	test_ft_strlcpy();
	printf("===== TESTS ft_strlcpy() completed.\n\n");

	printf("===== TESTING ft_strlcat()..\n");
	test_ft_strlcat();
	printf("===== TESTS ft_strlcat() completed.\n\n");

	printf("===== TESTING ft_toupper()..\n");
	test_ft_toupper();
	printf("===== TESTS ft_toupper() completed.\n\n");

	printf("===== TESTING ft_tolower()..\n");
	test_ft_tolower();
	printf("===== TESTS ft_tolower() completed.\n\n");

	printf("===== TESTING ft_strchr()..\n");
	test_ft_strchr();
	printf("===== TESTS ft_strchr() completed.\n\n");

	printf("===== TESTING ft_strrchr()..\n");
	test_ft_strrchr();
	printf("===== TESTS ft_strrchr() completed.\n\n");

	printf("===== TESTING ft_strncmp()..\n");
	test_ft_strncmp();
	printf("===== TESTS ft_strncmp() completed.\n\n");

	printf("===== TESTING ft_memchr()..\n");
	test_ft_memchr();
	printf("===== TESTS ft_memchr() completed.\n\n");

	printf("===== TESTING ft_memcmp()..\n");
	test_ft_memcmp();
	printf("===== TESTS ft_memcmp() completed.\n\n");

	printf("===== TESTING ft_strnstr()..\n");
	test_ft_strnstr();
	printf("===== TESTS ft_strnstr() completed.\n\n");

	printf("===== TESTING ft_atoi(int c)..\n");
	test_ft_atoi();
	printf("===== TESTS ft_atoi(int c) completed.\n\n");

	printf("===== TESTING ft_calloc()..\n");
	test_ft_calloc();
	printf("===== TESTS ft_calloc() completed.\n\n");

	printf("===== TESTING ft_strdup()..\n");
	test_ft_strdup();
	printf("===== TESTS ft_strdup() completed.\n\n");

	printf("===== TESTING ft_substr()..\n");
	test_ft_substr();
	printf("===== TESTS ft_substr() completed.\n\n");

	printf("===== TESTING ft_strjoin()..\n");
	test_ft_strjoin();
	printf("===== TESTS ft_strjoin() completed.\n\n");

	printf("===== TESTING ft_strtrim()..\n");
	test_ft_strtrim();
	printf("===== TESTS ft_strtrim() completed.\n\n");

	printf("===== TESTING ft_split()..\n");
	test_ft_split();
	printf("===== TESTS ft_split() completed.\n\n");

	printf("===== TESTING ft_itoa()..\n");
	test_ft_itoa();
	printf("===== TESTS ft_itoa() completed.\n\n");

	printf("===== TESTING ft_strmapi()..\n");
	test_ft_strmapi();
	printf("===== TESTS ft_strmapi() completed.\n\n");

	//printf("===== TESTING ft_striteri()..\n");
	//test_ft_striteri();
	//printf("===== TESTS ft_striteri() completed.\n\n");

	//printf("===== TESTING ft_putchar_fd()..\n");
	//test_ft_putchar_fd();
	//printf("===== TESTS ft_putchar_fd() completed.\n\n");

	//printf("===== TESTING ft_putstr_fd()..\n");
	//test_ft_putstr_fd();
	//printf("===== TESTS ft_putstr_fd() completed.\n\n");

	//printf("===== TESTING ft_putendl_fd()..\n");
	//test_ft_putendl_fd();
	//printf("===== TESTS ft_putendl_fd() completed.\n\n");

	//printf("===== TESTING ft_putnbr_fd()..\n");
	//test_ft_putnbr_fd();
	//printf("===== TESTS ft_putnbr_fd() completed.\n\n");

	printf("all TESTS completed. Think about norm ;)");
}

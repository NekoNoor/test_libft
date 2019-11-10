/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_part2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 19:30:08 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/10 18:47:57 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>

Test(part2, ft_substr)
{
	char	str[] = "blablablaISEEYOU";
	char	empty[] = "";

	cr_expect_str_eq(ft_substr(str, 3, 6), "blabla");
	cr_expect_str_eq(ft_substr(str, 9, 7), "ISEEYOU");
	cr_expect_str_eq(ft_substr(str, 15, 3), "U");
	cr_expect_str_eq(ft_substr(str, 16, 3), "");
	cr_expect_str_eq(ft_substr(empty, 0, 1), "");
	cr_expect_null(ft_substr(NULL, 16, 3));
}

Test(part2, ft_strjoin)
{
	char	s1[] = "1234567890";
	char	s2[] = "0987654321";

	cr_expect_str_eq(ft_strjoin(s1, s2), "12345678900987654321");
}

Test(part2, ft_strtrim)
{
	char	str[] = "the quick brown fox jumps over the lazy dog";
	char	set1[] = "the dog";
	char	set2[] = "abcdefghijklmnopqrstuvwxyz ";
	char	set3[] = "";

	cr_expect_str_eq(ft_strtrim(str, set1), "quick brown fox jumps over the lazy");
	cr_expect_str_eq(ft_strtrim(str, set2), "");
	cr_expect_str_eq(ft_strtrim(str, set3), "the quick brown fox jumps over the lazy dog");
	cr_expect_str_eq(ft_strtrim(str, NULL), "the quick brown fox jumps over the lazy dog");
}

Test(part2, ft_split)
{
	char	str[] = "///this///is//a///test//string/seperated/by//slashes///";
	char	**arr;

	arr = ft_split(str, '/');
	cr_expect_str_eq(arr[0], "this");
	cr_expect_str_eq(arr[1], "is");
	cr_expect_str_eq(arr[2], "a");
	cr_expect_str_eq(arr[3], "test");
	cr_expect_str_eq(arr[4], "string");
	cr_expect_str_eq(arr[5], "seperated");
	cr_expect_str_eq(arr[6], "by");
	cr_expect_str_eq(arr[7], "slashes");
	cr_expect_null(arr[8]);
	arr = ft_split(str, '\0');
	cr_expect_str_eq(arr[0], "///this///is//a///test//string/seperated/by//slashes///");
	cr_expect_null(arr[1]);
	arr = ft_split(str, '%');
	cr_expect_str_eq(arr[0], "///this///is//a///test//string/seperated/by//slashes///");
	cr_expect_null(arr[1]);
}

Test(part2, ft_itoa)
{
	cr_expect_str_eq(ft_itoa(-2147483648), "-2147483648");
	cr_expect_str_eq(ft_itoa(2147483647), "2147483647");
}

char	mapi_f(unsigned int i, char c)
{
	return (c + i);
}

Test(part2, ft_strmapi)
{
	char	str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaa";

	cr_expect_str_eq(ft_strmapi(str, &mapi_f), "abcdefghijklmnopqrstuvwxyz");
}

Test(part2, ft_putchar_fd)
{
}

Test(part2, ft_putstr_fd)
{
}

Test(part2, ft_putendl_fd)
{
}

Test(part2, ft_putnbr_fd)
{
}

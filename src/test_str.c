/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:48 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/06 12:21:14 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>

Test(str, ft_strlen)
{
	cr_expect_eq(ft_strlen("hello world!"), 12);
}

Test(str, ft_strlcpy)
{
	char	src[] = "abcdefghijkl";
	char	dst[256];

	cr_expect_eq(ft_strlcpy(dst, src, 256), 12);
	cr_expect_str_eq(dst, "abcdefghijkl", "%s", dst);
}

Test(str, ft_strlcat)
{
	char	*dst = ft_strdup("meow");
	char	*src = ft_strdup("woof");

	cr_expect_eq(ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 1), 8);
	cr_expect_str_eq(dst, "meowwoof");
}

Test(str, ft_strchr)
{
	char	str[] = "fhio ghio io\x2a \0\52 \200ds9g0dbxkldf\242";

	cr_expect_eq(ft_strchr(str, '\x2a'), strchr(str, '\x2a'));
	cr_expect_eq(ft_strchr(str, '\200'), strchr(str, '\200'));
	cr_expect_eq(ft_strchr(str, '\200'), strchr(str, '\200'));
	cr_expect_eq(ft_strchr(str, '\212'), strchr(str, '\212'));
	cr_expect_eq(ft_strchr(str, '\242'), strchr(str, '\242'));
	cr_expect_eq(ft_strchr(str, '\0'), strchr(str, '\0'));
}

Test(str, ft_strrchr)
{
}

Test(str, ft_strnstr)
{
}

Test(str, ft_strncmp)
{
}

Test(str, ft_strdup)
{
}

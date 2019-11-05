/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:48 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/05 13:33:57 by nschat        ########   odam.nl         */
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
}

Test(str, ft_strchr)
{
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

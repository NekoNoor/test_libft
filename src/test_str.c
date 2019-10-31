/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:48 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/01 00:28:05 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <criterion/criterion.h>

Test(str, ft_strlen)
{
	cr_expect_eq(ft_strlen("hello world!"), 12, "should return 12");
}

Test(str, ft_strlcpy)
{
	char	src[] = "abcdefghijkl";
	char	dst[] = "000000000000";

	cr_expect_eq(ft_strlcpy(dst, src, 10), 12, "should return length of src");
	cr_expect_str_eq(dst, "abcdefghi", "dst should be only 9 long");
}

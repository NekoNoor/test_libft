/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:48 by nschat        #+#    #+#                 */
/*   Updated: 2019/10/31 16:33:55 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <criterion/criterion.h>

Test(str, ft_strlen)
{
	cr_expect(ft_strlen("hello world!") == 12, "should return 12");
}

Test(str, ft_strlcpy)
{
	char	src[] = "abcdefghijkl";
	char	dst[] = "000000000000";

	cr_expect(ft_strlcpy(dst, src, 10) == 12, "should return length of s1");
	cr_expect(strcmp(dst, "abcdefghi") == 0, "dst should be only 9 long");
}

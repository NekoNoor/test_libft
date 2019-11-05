/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_part2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 19:30:08 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/05 13:36:34 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"

Test(part2, ft_substr)
{
}

Test(part2, ft_strjoin)
{
}

Test(part2, ft_strtrim)
{
}

Test(part2, ft_split)
{
}

Test(part2, ft_itoa)
{
	cr_expect_str_eq(ft_itoa(-2147483648), "-2147483648");
	cr_expect_str_eq(ft_itoa(2147483647), "2147483647");
}

Test(part2, ft_strmapi)
{
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

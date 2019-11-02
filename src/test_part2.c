/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_part2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 19:30:08 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/02 19:42:19 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_libft.h"

Test(part2, ft_itoa)
{
	cr_expect_str_eq(ft_itoa(-2147483648), "-2147483648");
	cr_expect_str_eq(ft_itoa(2147483647), "2147483647");
}

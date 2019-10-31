/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_misc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:12:09 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/01 00:36:14 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <criterion/criterion.h>
#include <ctype.h>

Test(misc, ft_atoi)
{
	cr_expect_eq(ft_atoi("14"), atoi("14"));
	cr_expect_eq(ft_atoi("+14"), atoi("14"));
	cr_expect_eq(ft_atoi("-14"), atoi("-14"));
	cr_expect_eq(ft_atoi("--14"), atoi("--14"));
	cr_expect_eq(ft_atoi("++14"), atoi("++14"));
	cr_expect_eq(ft_atoi("asd14"), atoi("asd14"));
	cr_expect_eq(ft_atoi("14asd"), atoi("14asd"));
	cr_expect_eq(ft_atoi("2147483647"), atoi("2147483647"));
	cr_expect_eq(ft_atoi("-2147483648"), atoi("-2147483648"));
	cr_expect_eq(ft_atoi("0"), atoi("0"));
	cr_expect_eq(ft_atoi(""), atoi(""));
	cr_expect_eq(ft_atoi("		14"), atoi("		14"));
	cr_expect_eq(ft_atoi("		-14"), atoi("		-14"));
}

Test(misc, ft_isalpha)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_isalpha(c), isalpha(c));
		c++;
	}
}

Test(misc, ft_isdigit)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_isdigit(c), isdigit(c));
		c++;
	}
}

Test(misc, ft_isalnum)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_isalnum(c), isalnum(c));
		c++;
	}
}

Test(misc, ft_isascii)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_isprint(c), isprint(c));
		c++;
	}
}

Test(misc, ft_isprint)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_isprint(c), isprint(c));
		c++;
	}
}

Test(misc, ft_toupper)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_toupper(c), toupper(c));
		c++;
	}
}

Test(misc, ft_tolower)
{
	int	c;

	c = -300;
	while (c <= 300)
	{
		cr_expect_eq(ft_tolower(c), tolower(c));
		c++;
	}
}


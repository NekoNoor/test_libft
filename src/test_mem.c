/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:32 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/05 13:33:43 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>

Test(mem, ft_memset)
{
	char	a[] = "ajskdasjldk";

	ft_memset(a, 'A', 8);
	cr_expect_arr_eq(a, "AAAAAAAAldk", 12);
}

Test(mem, ft_bzero)
{
	char	a[] = "ajskdasjldk";
	char	b[] = "ajskdasjldk";

	ft_bzero(a, 8);
	bzero(b, 8);
	cr_expect_arr_eq(a, b, 12);
}

Test(mem, ft_memcpy)
{
	char	a[] = "\0ajskdasjldki\0uvnadhipsrl";
	char	b[] = "\0ajskdasjldki\0uvnadhipsrl";

	cr_expect_arr_eq(ft_memcpy(a, "19274128390", 12), memcpy(b, "19274128390", 12), 12);
	cr_expect_arr_eq(ft_memcpy(a, "", 12), memcpy(b, "", 12), 12);
	cr_expect_eq(ft_memcpy(NULL, NULL, 12), memcpy(NULL, NULL, 12));
}

Test(mem, ft_memccpy)
{
}

Test(mem, ft_memmove)
{
}

Test(mem, ft_memchr)
{
}

Test(mem, ft_memcmp)
{
}

Test(mem, ft_calloc)
{
}

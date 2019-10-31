/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:32 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/01 00:28:15 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <criterion/criterion.h>

Test(mem, ft_memset)
{
	char	a[] = "ajskdasjldk";

	ft_memset(a, 'A', 8);
	cr_expect_arr_eq(a, "AAAAAAAAldk", 12, "memset 8 bytes");
}

Test(mem, ft_bzero)
{
	char	a[] = "ajskdasjldk";
	char	b[] = "ajskdasjldk";

	ft_bzero(a, 8);
	bzero(b, 8);
	cr_expect_arr_eq(a, b, 12, "compare to system bzero");
}

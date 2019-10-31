/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:32 by nschat        #+#    #+#                 */
/*   Updated: 2019/10/31 16:02:06 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include <criterion/criterion.h>

Test(memset, test)
{
	char	a[] = "ajskdasjldk";
	char	b[] = "ajskdasjldk";

	memset(a, 0x41, 8);
	ft_memset(b, 0x41, 8);
	cr_expect(memcmp(a, b, 12) == 0, "compare to libc memset");
}

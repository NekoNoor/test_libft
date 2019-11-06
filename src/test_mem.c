/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:32 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/06 11:08:28 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>

Test(mem, ft_memset)
{
	char	a[] = "ajskdasjldk";
	char	b[] = "ajskdasjldk";

	ft_memset(a, 'A', 8);
	memset(b, 'A', 8);
	cr_expect_arr_eq(a, b, 12);
	ft_memset(a, '\242', 8);
	memset(b, '\242', 8);
	cr_expect_arr_eq(a, b, 12);
	cr_expect_eq(ft_memset(a, '\222', 8), memset(a, '\222', 8));
	memset(b, '\222', 8);
	cr_expect_eq(ft_memset(NULL, 'a', 8), NULL);
	ft_memset(a, '\x2a', 0);
	memset(b, '\x2a', (0));
	cr_expect_arr_eq(a, b, 12);
}

Test(mem, ft_bzero)
{
	char	a[] = "ajskdasjldk";
	char	b[] = "ajskdasjldk";

	ft_bzero(a, 8);
	bzero(b, 8);
	cr_expect_arr_eq(a, b, 12);
	ft_bzero(a, 0);
	bzero(b, (0));
	cr_expect_arr_eq(a, b, 12);
	ft_bzero(NULL, 12);
}

Test(mem, ft_memcpy)
{
	char	a[] = "\0ajskdasjldki\0uvnadhipsrl";
	char	b[] = "\0ajskdasjldki\0uvnadhipsrl";
	char	str[] = "hellothisisme";

	cr_expect_arr_eq(ft_memcpy(a, "19274128390", 12), memcpy(b, "19274128390", 12), 12);
	cr_expect_arr_eq(ft_memcpy(a, "", 12), memcpy(b, "", 12), 12);
	cr_expect_eq(ft_memcpy(a, "owowhatsthis", 12), memcpy(a, "owowhatsthis", 12));
	cr_expect_eq(ft_memcpy(NULL, NULL, 12), memcpy(NULL, NULL, 12));
	cr_expect_arr_eq(ft_memcpy(a, str, ft_strlen(str)), memcpy(b, str, ft_strlen(str)), ft_strlen(str));
}

Test(mem, ft_memccpy)
{
	char	a[] = "ajskdasjldkiuvnadhipsrl";
	char	b[] = "ajskdasjldkiuvnadhipsrl";
	char	str[] = "hellothisisme";
	char	str_uc[] = "hello\242thisisme";
	char	str_nbr[] = "0123456789";

	ft_memccpy(a, str, 't', 13);
	memccpy(b, str, 't', 13);
	cr_expect_arr_eq(a, b, 13);
	ft_memccpy(a, str_uc, '\242', 14);
	memccpy(b, str_uc, '\242', 14);
	cr_expect_arr_eq(a, b, 14);
	ft_memccpy(a, str_uc, 342, 14);
	memccpy(b, str_uc, 342, 14);
	cr_expect_arr_eq(a, b, 14);
	cr_expect_eq(ft_memccpy(a, str, 'm', 13), memccpy(a, str, 'm', 13));
	cr_expect_eq(ft_memccpy(a, str_nbr, 'm', 10), memccpy(a, str_nbr, 'm', 10));
	ft_memcpy(b, a, 24);
	ft_memccpy(a, str_uc, '\242', 0);
	cr_expect_arr_eq(a, b, 24);
	cr_expect_arr_eq(ft_memccpy(a, str, 'i', 13), memccpy(b, str, 'i', 13), 15);
}

Test(mem, ft_memmove)
{
	char			str[] = "nyaaaaaaaaaaaaaaaaaaaaaaaaa";
	char			str0[] = "nyaaaaaa\0aaaaa\0aa\200aaaa\150aaaaaaaa";
	char			strover[] = "v8h9efbhg89234-grfh8a9dg89ade0gfh8392gf89gds";
	char			strrevo[] = "sdg98fg2938hfg0eda98gd9a8hfrg-43298ghbfe9h8v";
	char			a[] = "b190-12895n 7s9adfdiog dasfg90naehq90123904h124";
	char			b[] = "b190-12895n 7s9adfdiog dasfg90naehq90123904h124";
	unsigned long	src = 0xdeadbeef;
	unsigned long	dst1;
	unsigned long	dst2;

	ft_memmove(a, str, ft_strlen(str));
	memmove(b, str, ft_strlen(str));
	cr_expect_arr_eq(a, b, ft_strlen(str));
	memmove(&dst1, &src, sizeof(src));
	ft_memmove(&dst2, &src, sizeof(src));
	cr_expect_arr_eq(a, b, sizeof(src));
	cr_expect_eq(ft_memmove(a, str, ft_strlen(str)), memmove(a, str, ft_strlen(str)));
	cr_expect_eq(ft_memmove("", "" - 1, 0), memmove("", "" - 1, 0));
	ft_memmove(a, str0, 31);
	memmove(b, str0, 31);
	cr_expect_arr_eq(a, b, 31);
	ft_memcpy(a, strover, ft_strlen(strover));
	ft_memcpy(b, strover, ft_strlen(strover));
	ft_memmove(a + 5, a, 39);
	memmove(b + 5, b, 39);
	cr_expect_arr_eq(a, b, 31);
	ft_memcpy(a, strrevo, ft_strlen(strrevo));
	ft_memcpy(b, strrevo, ft_strlen(strrevo));
	ft_memmove(a, a + 5, 39);
	memmove(b, b + 5, 39);
	cr_expect_arr_eq(a, b, 31);
	ft_memmove(NULL, NULL, 100);
	ft_memmove(a, a, 30);
	memmove(b, b, 30);
	cr_expect_arr_eq(a, b, 30);
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

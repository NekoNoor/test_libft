/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:48 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/06 22:14:30 by nschat        ########   odam.nl         */
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
	char	*dst = ft_strdup("meow");
	char	*src = ft_strdup("woof");

	cr_expect_eq(ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 1), 8);
	cr_expect_str_eq(dst, "meowwoof");
}

Test(str, ft_strchr)
{
	char	str[] = "fhio ghio io\x2a \0\52 \200ds9g0dbxkldf\242";

	cr_expect_eq(ft_strchr(str, '\x2a'), strchr(str, '\x2a'));
	cr_expect_eq(ft_strchr(str, '\200'), strchr(str, '\200'));
	cr_expect_eq(ft_strchr(str, '\200'), strchr(str, '\200'));
	cr_expect_eq(ft_strchr(str, '\212'), strchr(str, '\212'));
	cr_expect_eq(ft_strchr(str, '\242'), strchr(str, '\242'));
	cr_expect_eq(ft_strchr(str, '\0'), strchr(str, '\0'));
}

Test(str, ft_strrchr)
{
	char	str[] = "fhio ghio io\x2a \0\52 \200ds9g0dbxkldf\242";

	cr_expect_eq(ft_strrchr(str, '\x2a'), strrchr(str, '\x2a'));
	cr_expect_eq(ft_strrchr(str, '\200'), strrchr(str, '\200'));
	cr_expect_eq(ft_strrchr(str, '\200'), strrchr(str, '\200'));
	cr_expect_eq(ft_strrchr(str, '\212'), strrchr(str, '\212'));
	cr_expect_eq(ft_strrchr(str, '\242'), strrchr(str, '\242'));
	cr_expect_eq(ft_strrchr(str, '\0'), strrchr(str, '\0'));
}

Test(str, ft_strnstr)
{
	char	s1[] = "90dhgas90ghas90gahs90vhxzcklfvadsfhOWOdklfjklxcjv";
	char	s2[] = "OWO";
	char	str[] = "90dhgas90ghb";
	char	owo[] = "90dh";
	char	ghb[] = "ghb";
	char	empty[] = "";

	cr_expect_eq(ft_strnstr(s1, s2, ft_strlen(s1)), strnstr(s1, s2, ft_strlen(s1)));
	cr_expect_eq(ft_strnstr(s2, s1, ft_strlen(s2)), strnstr(s2, s1, ft_strlen(s2)));
	cr_expect_eq(ft_strnstr(s1, str, ft_strlen(s1)), strnstr(s1, str, ft_strlen(s1)));
	cr_expect_eq(ft_strnstr(owo, str, ft_strlen(owo)), strnstr(owo, str, ft_strlen(owo)));
	cr_expect_eq(ft_strnstr(str, ghb, 11), strnstr(str, ghb, 11));
	cr_expect_eq(ft_strnstr(str, ghb, 9), strnstr(str, ghb, 9));
	cr_expect_eq(ft_strnstr(s1, ghb, ft_strlen(s1)), strnstr(s1, ghb, ft_strlen(s1)));
	cr_expect_eq(ft_strnstr(s1, empty, ft_strlen(s1)), strnstr(s1, empty, ft_strlen(s1)));
	cr_expect_eq(ft_strnstr(s1, s1, ft_strlen(s1)), strnstr(s1, s1, ft_strlen(s1)));
	cr_expect_eq(ft_strnstr(s2, s2, 4), strnstr(s2, s2, 4));
}

Test(str, ft_strncmp)
{
	char	a[] = "u'9t3790 t23n90t390n33790n";
	char	b[] = "u'9t3790 t23n90t390n33790n";
	char	c[] = "u'9t3790 t23n90t\090n33790n";
	char	d[] = "u'9t3790 t23n90t\090n\2423790n";

	cr_expect_eq(ft_strncmp(a, b, 26), strncmp(a, b, 26));
	cr_expect_eq(ft_strncmp(b, c, 6), strncmp(b, c, 6));
	cr_expect_eq(ft_strncmp(b, c, 16), strncmp(b, c, 16));
	cr_expect_eq(ft_strncmp(b, c, 26), strncmp(b, c, 26));
	cr_expect_eq(ft_strncmp(c, d, 26), strncmp(c, d, 26));
}

Test(str, ft_strdup)
{
	char	str[] = "duplicator";
	char	str0[] = "ahsgioasgopahsgopasg\0asghiaodghiaosg";
	char	*dst;

	cr_expect_str_eq(ft_strdup(str), str);
	cr_expect_eq(ft_strlen(ft_strdup(str)), ft_strlen(str));
	dst = ft_strdup(str);
	free(dst);
	cr_expect_str_eq(ft_strdup(str0), str0);
	cr_expect_str_eq(ft_strdup(""), "");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_misc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:12:09 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/03 20:51:09 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>

Test(bonus, ft_lstnew)
{
	t_list	*lst;

	cr_expect(lst = ft_lstnew(ft_strdup("nya")));
	cr_expect_str_eq(lst->content, "nya");
}

Test(bonus, ft_lstadd_front)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup("bla"));
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("owo")));
	cr_expect_str_eq(new->content, "owo");
	cr_expect_str_eq(new->next->content, "bla");
	cr_expect_eq(new->next->next, NULL);
}

Test(bonus, ft_lstsize)
{
	t_list	*new;

	new = NULL;
	cr_expect_eq(ft_lstsize(new), 0);
	new = ft_lstnew(ft_strdup("test"));
	cr_expect_eq(ft_lstsize(new), 1);
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("dup")));
	cr_expect_eq(ft_lstsize(new), 2);
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("bup")));
	cr_expect_eq(ft_lstsize(new), 3);
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("snup")));
	cr_expect_eq(ft_lstsize(new), 4);
}

Test(bonus, ft_lstlast)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup("last"));
	cr_expect_str_eq(ft_lstlast(new)->content, "last");
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("nyoom")));
	cr_expect_str_eq(ft_lstlast(new)->content, "last");
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("weeew")));
	cr_expect_str_eq(ft_lstlast(new)->content, "last");
}

Test(bonus, ft_lstadd_back)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("new")));
	cr_expect_str_eq(ft_lstlast(new)->content, "new");
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("newer")));
	cr_expect_str_eq(ft_lstlast(new)->content, "newer");
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("newest")));
	cr_expect_str_eq(ft_lstlast(new)->content, "newest");
}

void	del_f(void *content)
{
	ft_bzero(content, ft_strlen(content));
	free(content);
}

Test(bonus, ft_lstdelone)
{
	t_list	*new;
	char	*str;

	str = ft_strdup("delme");
	new = ft_lstnew(str);
	ft_lstdelone(new, &del_f);
	cr_expect_str_eq(str, "");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_misc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:12:09 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/05 21:32:43 by nschat        ########   odam.nl         */
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

	new = NULL;
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("bla")));
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
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("test")));
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

	new = NULL;
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("last")));
	cr_expect_str_eq(ft_lstlast(new)->content, "last");
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("nyoom")));
	cr_expect_str_eq(ft_lstlast(new)->content, "last");
	ft_lstadd_front(&new, ft_lstnew(ft_strdup("weeew")));
	cr_expect_str_eq(ft_lstlast(new)->content, "last");
}

Test(bonus, ft_lstadd_back)
{
	t_list	*new;

	new = NULL;
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("first")));
	cr_expect_str_eq(ft_lstlast(new)->content, "first");
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
}

Test(bonus, ft_lstdelone)
{
	t_list	*new;
	char	*str;

	str = ft_strdup("delme");
	new = ft_lstnew(str);
	ft_lstdelone(new, &del_f);
	cr_expect_str_empty(str);
}

Test(bonus, ft_lstclear)
{
	t_list	*new;
	char	**str_p;
	int		i;

	str_p = (char **)malloc(sizeof(char *) * 10);
	i = 0;
	while (i < 10)
	{
		str_p[i] = ft_strdup("delme");
		i++;
	}
	new = NULL;
	i = 0;
	while (i < 10)
	{
		ft_lstadd_back(&new, ft_lstnew(str_p[i]));
		i++;
	}
	ft_lstclear(&new, &del_f);
	cr_expect_eq(new, NULL);
	i = 0;
	while (i < 10)
	{
		cr_expect_str_empty(str_p[i]);
		i++;
	}
}

void	iter_f(void *content)
{
	char	*str;
	int		i;

	str = (char *)content;
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

Test(bonus, ft_lstiter)
{
	t_list	*new;

	new = NULL;
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("owo")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("whats")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("this")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("notices")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("your")));
	ft_lstiter(new, &iter_f);
	cr_expect_str_eq(new->content, "OWO");
	cr_expect_str_eq(new->next->content, "WHATS");
	cr_expect_str_eq(new->next->next->content, "THIS");
	cr_expect_str_eq(new->next->next->next->content, "NOTICES");
	cr_expect_str_eq(new->next->next->next->next->content, "YOUR");
}

void	*map_f(void *content)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(content) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (((char *)content)[i])
	{
		str[i] = ft_toupper(((char *)content)[i]);
		i++;
	}
	return ((void *)str);
}

Test(bonus, ft_lstmap)
{
	t_list	*new;

	new = NULL;
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("owo")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("whats")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("this")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("notices")));
	ft_lstadd_back(&new, ft_lstnew(ft_strdup("your")));
	new = ft_lstmap(new, &map_f, &del_f);
	cr_expect_str_eq(new->content, "OWO");
	cr_expect_str_eq(new->next->content, "WHATS");
	cr_expect_str_eq(new->next->next->content, "THIS");
	cr_expect_str_eq(new->next->next->next->content, "NOTICES");
	cr_expect_str_eq(new->next->next->next->next->content, "YOUR");
}

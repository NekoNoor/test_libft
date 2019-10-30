/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:11:32 by nschat        #+#    #+#                 */
/*   Updated: 2019/10/30 13:31:14 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "common.h"
#include <string.h>
#include <stdio.h>

void	test_memset(void)
{
	char	*libft;
	char	*libc;

	libc = strdup("asjgkasg");
	memset(libc, 0x41, 4);
	libft = strdup("asjgkasg");
	ft_memset(libft, 0x41, 4);

	if (strcmp(libc, libft))
		printf("ft_memset failed\n\n");
	else
		printf("ft_memset succeeded\n\n");
	printf("libc:\n%s\n\nlibft:\n%s\n", libc, libft);
}

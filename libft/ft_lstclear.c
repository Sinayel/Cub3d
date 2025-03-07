/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:59:07 by ylouvel           #+#    #+#             */
/*   Updated: 2023/12/04 13:00:17 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cette fonction supprime tout les elements,
de la liste chainer (**lst) en prenant une fonction
pour supprimer les element de la liste (void (*del)(void *))
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*backup;

	if (!(*del) || !lst || !*lst)
		return ;
	backup = *lst;
	while (*lst && lst)
	{
		*lst = backup->next;
		ft_lstdelone(backup, (*del));
		backup = *lst;
	}
}

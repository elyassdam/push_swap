/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:14:32 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 02:20:10 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content) {
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (node == NULL) {
        return (NULL);
    }
    node->content = content; 
    node->next = NULL;       
    return (node); 
}
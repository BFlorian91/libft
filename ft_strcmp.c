/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:38:19 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/11 10:55:08 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1++ == *s2++)
	{
		if (!(*s1) && !(*s2))
			return (0);
	}
	return ((unsigned char)*--s1 - (unsigned char)*--s2);
}

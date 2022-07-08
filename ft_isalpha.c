/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:36:40 by hsano             #+#    #+#             */
/*   Updated: 2022/07/08 22:25:08 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	else if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}

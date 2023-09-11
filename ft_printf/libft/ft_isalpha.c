/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:53:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2022/10/24 19:03:04 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c < 65 || c > 122)
	{
		return (0);
	}
	else if (c > 90 && c < 97)
	{
		return (0);
	}
	return (1);
}

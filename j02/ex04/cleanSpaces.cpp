/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanSpaces.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:01:27 by jochang           #+#    #+#             */
/*   Updated: 2018/10/04 10:04:39 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.hpp"

char	*cleanSpaces(char *str)
{
	int	c = 0;

	for (int i = 0;str[i];i++)
		if (!isspace(str[i]))
			str[c++] = str[i];
	str[c] = '\0';
	return (str);
}

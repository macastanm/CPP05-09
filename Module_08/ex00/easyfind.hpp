/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:19 by macastan          #+#    #+#             */
/*   Updated: 2024/04/30 15:59:23 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

template <typename T> int easyfind(T& container, int compare)
{
	if (std::find(container.begin(), container.end(), compare) != container.end())
	{
		std::cout << "Value found" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "Value not found" << std::endl;
		return (-1);
	}
}

#endif

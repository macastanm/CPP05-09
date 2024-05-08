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
# include <iterator>
# include <list>
# include <set>

template <typename T> int easyfind(T& container, int compare)
{
	typename T::iterator found = std::find(container.begin(), container.end(), compare);
	if (found != container.end())
	{
		std::cout << "Value found in position: " << std::distance(container.begin(), found) << std::endl;
		return (0);
	}
	else
	{
		std::cout << "Value not found" << std::endl;
		return (-1);
	}
}

#endif

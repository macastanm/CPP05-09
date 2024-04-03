/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:34:13 by macastan          #+#    #+#             */
/*   Updated: 2024/04/01 12:34:19 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat	b("Cracked", 149);
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
			b.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	return(0);
}
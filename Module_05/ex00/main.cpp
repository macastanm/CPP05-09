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
			Bureaucrat	b("Maria", 149);
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
			b.decrementGrade();
			std::cout << b;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	a("Luiza", 2);
			std::cout << a;
			a.incrementGrade();
			std::cout << a;
			a.incrementGrade();
			std::cout << a;
			a.incrementGrade();
			std::cout << a;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	c("lulu", 180);
			std::cout << c;
			c.incrementGrade();
			std::cout << c;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	d("malu", 75);
			std::cout << d;
			d.incrementGrade();
			std::cout << d;
			d.decrementGrade();
			std::cout << d;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return(0);
}
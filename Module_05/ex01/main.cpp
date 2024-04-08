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
#include "Form.hpp"

int	main()
{
	Bureaucrat	Ma("Maria", 50);
	Form	a("A", 49, 45);
	std::cout << Ma;
	std::cout << a;
	std::cout << "Maria trys to sign the form A" << std::endl;
	Ma.signForm(a);
	std::cout << "Incrementing Maria's grade" << std::endl;
	Ma.incrementGrade();
	std::cout << "Maria trys to sign the form A again" << std::endl;
	Ma.signForm(a);
	std::cout << Ma;
	std::cout << a;
	return(0);
}
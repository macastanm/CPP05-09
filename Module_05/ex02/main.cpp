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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	Ma("Maria", 138);
	ShrubberyCreationForm	a("A");
	std::cout << Ma;
	std::cout << a;
	std::cout << RED << "Maria trys to sign the form A and execute" << NRM << std::endl;
	Ma.signForm(a);
	Ma.executeForm(a);
	std::cout << RED << "Incrementing Maria's grade" << NRM << std::endl;
	Ma.incrementGrade();
	std::cout << RED << "Maria trys to sign the form A and execute again" << NRM << std::endl;
	Ma.signForm(a);
	Ma.executeForm(a);
	std::cout << Ma;
	std::cout << a;
	return(0);
}
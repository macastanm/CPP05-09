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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << RED << "First test" << NRM << std::endl;
	try {
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "Second test" << NRM << std::endl;
	try {
		Bureaucrat	Lu("Malu", 40);
		RobotomyRequestForm	b("28");
		std::cout << Lu;
		std::cout << b;
		std::cout << RED << "Malu trys to execute the form 28 without sign" << NRM << std::endl;
		Lu.executeForm(b);
		std::cout << RED << "Now Malu trys to sign the form 28 and then execute" << NRM << std::endl;
		Lu.signForm(b);
		Lu.executeForm(b);
		std::cout << Lu;
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "Third test" << NRM << std::endl;
	try {
		Bureaucrat	Ju("Julia", 1);
		PresidentialPardonForm	c("C");
		std::cout << Ju;
		std::cout << c;
		std::cout << RED << "Julia trys to sign the form A and execute" << NRM << std::endl;
		Ju.signForm(c);
		Ju.executeForm(c);
		std::cout << Ju;
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return(0);
}
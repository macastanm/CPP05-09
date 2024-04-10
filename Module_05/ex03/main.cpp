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
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << RED << "First test: right form name" << NRM << std::endl;
	AForm *rrf = 0;
	try {
		Bureaucrat	Ma("Maria", 46);
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << RED << "Maria trys to sign the form and execute" << NRM << std::endl;
		Ma.signForm(*rrf);
		Ma.executeForm(*rrf);
		std::cout << RED << "Incrementing Maria's grade" << NRM << std::endl;
		Ma.incrementGrade();
		std::cout << RED << "Maria trys to sign the form A and execute again" << NRM << std::endl;
		Ma.signForm(*rrf);
		Ma.executeForm(*rrf);
		//std::cout << Ma;
		//std::cout << rrf;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete rrf;
	}

	std::cout << std::endl << RED << "Second: wrong form name" << NRM << std::endl;
	AForm *b = 0;
	try {
		Bureaucrat	Lu("Malu", 40);
		Intern someRandom;
		b = someRandom.makeForm("bata", "ta");
		std::cout << RED << "Malu trys to execute the form without sign" << NRM << std::endl;
		Lu.executeForm(*b);
		std::cout << RED << "Now Malu trys to sign the form and then execute" << NRM << std::endl;
		Lu.signForm(*b);
		Lu.executeForm(*b);
		delete b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete b;
	}
	return(0);
}
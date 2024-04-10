/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:15:04 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:15:06 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)copy;
}

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}

AForm	*Intern::makeShrubberyCreation(std::string _target)
{
	std::cout << "Intern is now creating the ShrubberyCreation Form, with target " << _target << std::endl;
	return new ShrubberyCreationForm(_target);
}

AForm	*Intern::makeRobotomyRequest(std::string _target)
{
	std::cout << "Intern is now creating the RobotomyRequest Form, with target " << _target << std::endl;
	return new RobotomyRequestForm(_target);
}

AForm	*Intern::makePresidentialPardon(std::string _target)
{
	std::cout << "Intern is now creating the PresidentialPardon Form, with target " << _target << std::endl;
	return new PresidentialPardonForm(_target);
}

AForm	*Intern::makeForm(std::string _formName, std::string _targetName)
{
	AForm *(Intern::*function[3])(std::string) = {&Intern::makeShrubberyCreation, &Intern::makeRobotomyRequest, &Intern::makePresidentialPardon};
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i;
	for (i = 0; i < 3; i++)
	{
		if (formNames[i] == _formName)
		{
			std::cout << "Intern found the right form" << std::endl;
			return (this->*function[i])(_targetName);
		}
	}
	throw NotFound();
	return NULL;
}
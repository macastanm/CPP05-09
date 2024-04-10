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
	std::cout << "Intern " << this->target << " copy constructor called" << std::endl;
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:12:35 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:12:37 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("undefined")
{
	std::cout << "ShrubberyCreationForm: default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : AForm("ShrubberyCreationForm", 145, 137), target(_name)
{
	std::cout << "ShrubberyCreationForm " << this->target << " has ben created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	std::cout << "ShrubberyCreationForm " << this->target << " copy constructor called" << std::endl;
	this->target = copy.target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->target << " default destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat & _executor) const
{
	if (_executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	if (this->getSignature() == false)
		throw NotSigned();
	std::cout << "faz algo" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:13:06 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:13:07 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137), target("undefined")
{
	std::cout << "PresidentialPardonForm: default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _name) : AForm("PresidentialPardonForm", 145, 137), target(_name)
{
	std::cout << "PresidentialPardonForm " << this->target << " has ben created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
	std::cout << "PresidentialPardonForm " << this->target << " copy constructor called" << std::endl;
	this->target = copy.target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->target << " default destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat & _executor) const
{
	if (_executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	if (this->getSignature() == false)
		throw NotSigned();
	std::cout << "faz algo" << std::endl;
}

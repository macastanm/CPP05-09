/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:12:50 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:12:51 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("undefined")
{
	std::cout << "RobotomyRequestForm: default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _name) : AForm("RobotomyRequestForm", 72, 45), target(_name)
{
	std::cout << "RobotomyRequestForm " << this->target << " has ben created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
	std::cout << "RobotomyRequestForm " << this->target << " copy constructor called" << std::endl;
	this->target = copy.target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->target << " default destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat & _executor) const
{
	if (_executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	if (this->getSignature() == 0)
	{
		throw NotSigned();
	}
	std::cout << "Drilling noises!!!" << std::endl;
	srand(time(NULL));
	int i = (rand() % 2) + 1;
	if(i == 1)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:35:48 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 14:35:49 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("undefinedForm"), signature(false), gradeSign(75), gradeExecute(75)
{
	std::cout << "Form: default constructor called" << std::endl;
}

Form::Form(std::string _name, int _gradeS, int _gradeE) : name(_name), signature(false), gradeSign(_gradeS), gradeExecute(_gradeE)
{
	std::cout << "Form " << this->name << " has ben created with signed grade: " << this->gradeSign << std::endl;
	if(_gradeS < 1)
		throw GradeTooHighException();
	if(_gradeS > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy) : name(copy.name), signature(copy.signature), gradeSign(copy.gradeSign), gradeExecute(copy.gradeExecute)
{
	std::cout << "Form: copy constructor called" << std::endl;
	if(copy.gradeSign < 1)
		throw GradeTooHighException();
	if(copy.gradeSign > 150)
		throw GradeTooLowException();
}

Form&	Form::operator=(const Form& src)
{
	if (this != &src)
	{
		this->signature = src.signature;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->name << ": default destructor called" << std::endl;
}

void	Form::beSigned(Bureaucrat &_bureaucrat)
{
	if (_bureaucrat.getGrade() > this->gradeSign)
	{
		std::cout << "Fail: ";
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "Success: ";
		this->signature = true;
	}
}

std::string	Form::getName() const
{
	return (this->name);
}

bool		Form::getSignature() const
{
	return (this->signature);
}

int			Form::getGradeSign() const
{
	return (this->gradeSign);
}

int			Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

std::ostream&	operator<<(std::ostream& output, const Form& copy)
{
	std::string	isSigned;
	if (copy.getSignature() == 0)
	{
		isSigned = "False";
	}
	else
	{
		isSigned = "True";
	}
	output << "Form " << copy.getName() << " | signed: " << isSigned;
	output << " | grade required to sign it: " << copy.getGradeSign();
	output << " | grade required to execute it: " << copy.getGradeExecute() << std::endl;
	return (output);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:34:39 by macastan          #+#    #+#             */
/*   Updated: 2024/04/01 12:34:41 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
private:
	std::string	name;
	int			grade;
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat &operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(AForm& _form);
	void		executeForm(AForm const & _form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Bureaucrat grade is too high");}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Bureaucrat grade is too low");}
	};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& copy);

#endif
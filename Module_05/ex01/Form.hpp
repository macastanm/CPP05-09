/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:35:43 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 14:35:45 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	const std::string	name;
	bool		signature;
	const int			gradeSign;
	const int			gradeExecute;

public:
	Form();
	Form(std::string _name, int _gradeS, int _gradeE);
	Form(const Form& copy);
	Form &operator=(const Form& src);
	~Form();

	void	beSigned(Bureaucrat& _bureaucrat);
	std::string	getName() const;
	bool		getSignature() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;

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

std::ostream& operator<<(std::ostream& output, const Form& copy);

#endif
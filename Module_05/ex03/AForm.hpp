/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:14:39 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:14:40 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

# define RED "\033[1;31m"
# define NRM "\033[0;37m"
# define GRN "\033[1;32m"
# define BLD "\033[1;37m"

class	Bureaucrat;

class	AForm
{
private:
	std::string	name;
	bool		signature;
	int			gradeSign;
	int			gradeExecute;

public:
	AForm();
	AForm(std::string _name, int _gradeS, int _gradeE);
	AForm(const AForm& copy);
	AForm &operator=(const AForm& src);
	~AForm();

	void	beSigned(Bureaucrat& _bureaucrat);
	std::string	getName() const;
	bool		getSignature() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;
	virtual void	execute(Bureaucrat const & _executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Form grade is too high");}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Form grade is too low");}
	};
	class NotSigned : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Bureaucrat has nos signed the form");}
	};
};

std::ostream& operator<<(std::ostream& output, const AForm& copy);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:12:54 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:12:56 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
private:
	std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _name);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& src);
	~RobotomyRequestForm();

	std::string	getTarget() const;
	void	execute(Bureaucrat const & _executor) const;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:03:32 by macastan          #+#    #+#             */
/*   Updated: 2024/04/30 16:03:34 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <limits>

template <class T>
class	MutantStack : public std::stack<T>
{
public:
	MutantStack(){
	}
	MutantStack(const MutantStack& copy){
		*this = copy;
	}
	MutantStack &operator=(const MutantStack& src){
		if (this != &src)
		{
			std::stack<T>::operator=(src);
		}
		return (*this);
	}
	~MutantStack(){
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin(void){
		return (this->c.begin());
	}
	iterator	end(void){
		return (this->c.end());
	}
};

#endif
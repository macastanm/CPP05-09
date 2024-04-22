/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:31:30 by macastan          #+#    #+#             */
/*   Updated: 2024/04/18 17:31:31 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{

	Base* TestOne = generate();
	std::cout << std::endl << "TestOne pointer: " << TestOne << std::endl;
	identify(TestOne);
	Base& TestTwo = *TestOne;
	std::cout << std::endl << "TestTwo address: " << &TestTwo << std::endl;
	identify(TestTwo);
	delete TestOne;
	return (0);
}


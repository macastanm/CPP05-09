/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:31:38 by macastan          #+#    #+#             */
/*   Updated: 2024/04/18 17:31:40 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	generate(void)
{
	srand(time(NULL));
	int i = (rand() % 3) + 1;
	if(i == 1)
	{
		std::cout << "Instanciating A" << std::endl;
		return (new A());
	}
	else if(i == 2)
	{
		std::cout << "Instanciating B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "Instanciating C" << std::endl;
		return (new C());
	}
}

void	identify(Base* p)
{
	if (A* testA = dynamic_cast<A*>(p))
	{
		std::cout << "A pointer: " << testA << std::endl;
		std::cout << "The pointer identifies as A class" << std::endl;
	}
	else if (B* testB = dynamic_cast<B*>(p))
	{
		std::cout << "B pointer: " << testB << std::endl;
		std::cout << "The pointer identifies as B class" << std::endl;
	}
	else if (C* testC = dynamic_cast<C*>(p))
	{
		std::cout << "C pointer: " << testC << std::endl;
		std::cout << "The pointer identifies as C class" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		A& testA = dynamic_cast<A&>(p);
		std::cout << "A address: " << &testA << std::endl;
		std::cout << "The address identifies as A class" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		B& testB = dynamic_cast<B&>(p);
		std::cout << "B address: " << &testB << std::endl;
		std::cout << "The address identifies as B class" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		C& testC = dynamic_cast<C&>(p);
		std::cout << "C address: " << &testC << std::endl;
		std::cout << "The address identifies as C class" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
}
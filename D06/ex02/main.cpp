/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:31:12 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/19 13:44:09 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base *generate(void)
{
	Base *base;
	int r;

	std::cout << "  -- Generating -- " << std::endl;
	r = rand() % 3;
	std::cout << "Generated class instance: ";
	switch (r)
	{
	case 0:
		std::cout << "A" << std::endl;
		base = new A;
		break;
	case 1:
		std::cout << "B" << std::endl;
		base = new B;
		break;
	default:
		std::cout << "C" << std::endl;
		base = new C;
		break;
	}
	std::cout << "----------------------------------------" << std::endl;
	return base;
}

void identify_from_pointer(Base *p)
{
	std::cout << "Identifiying class instance type from pointer: ";

	Base *tester = p;

	A *a = dynamic_cast<A *>(tester);
	B *b = dynamic_cast<B *>(tester);
	C *c = dynamic_cast<C *>(tester);

	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else if (c != NULL)
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
	std::cout << "Identifiying class instance type from reference: ";

	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
}

int main(void)
{
	srand(time(NULL));
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}

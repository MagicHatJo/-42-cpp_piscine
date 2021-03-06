/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jochang <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2018/10/10 21:01:24 by jochang		   #+#	#+#			 */
/*   Updated: 2018/10/10 22:07:43 by jochang          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base
{
public:
	virtual ~Base(void) { };
};

class A : public Base { };
class B : public Base { };
class C : public Base { };

Base*   generate(void)
{
	int r = rand() % 3;

	switch (r) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
		default: return NULL;
	}
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &bc) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &bc) { }
}

int main()
{
	A *a = new A;
	B *b = new B;
	C *c = new C;

	srand(time(nullptr));
	std::cout << "Preset" << std::endl;
	identify_from_pointer(a);
	identify_from_pointer(b);
	identify_from_pointer(c);
	identify_from_reference(*a);
	identify_from_reference(*b);
	identify_from_reference(*c);
	std::cout << "Randomized" << std::endl;
	for (int i = 0;i < 10;i++)
	{
		Base *base = generate();
		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;
	}
	return (0);
}

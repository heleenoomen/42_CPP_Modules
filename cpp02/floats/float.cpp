#include <iostream>
#include <cmath>
#include <stdio.h>


int	main( ) {

	union {
	float	f;
	int		i;
	} p;

	
	// p.f = 0.5;

	// std::bitset<32> x(p.i);
	// std::cout << x << std::endl;
	
	// int	i = 1; 
	// i <<= 31;

	// p.i |= i;

	// std::bitset<32> q(p.i);
	// std::cout << q << std::endl;

	// std::cout << p.f << std::endl;

	// p.i &= ~i; 

	// std::cout << p.f << std::endl;


	// int s = 127;

	// s <<= 23;
	// p.i = 0;
	// p.i |= s;
	// std::bitset<32> r(s);
	// std::cout << r << std::endl;

	// int i = 18;
	// std::bitset<32> q(i);
	// std::cout << q << std::endl;
	// i = ~i;
	// std::bitset<32> r(i);
	// std::cout << r << std::endl;

	// i = 1;
	// std::bitset<32> s(i);
	// std::cout << s << std::endl;
	// i <<= 8;
	// std::bitset<32> t(i);
	// std::cout << t << std::endl;
	// i = (int) pow((float)2, (float)8);
	// std::bitset<32> v(i);
	// std::cout << v << std::endl;
	// i = (1 << 31);
	// std::bitset<32> u(i);
	// std::cout << u << std::endl;

	// float	f = -2.5;
	// int		raw;

	// if (f >= 0)
	// 	raw = f * pow((float)2, (float)8);
	// else
	// {
	// 	f *= f;
	// 	raw = (int) (f * pow((float)2, (float)8));
	// 	raw -= 1;
	// 	raw = ~raw;
	// }
	// std::bitset<32> q(raw);
	// std::cout << q << std::endl;
	//std::cout << (int) -42.42 << std::endl;
	float	f = -1234.4321f;
	int		i = (int) f;
	printf("f = %d\n", i);

}

// 0100 0000   0100 0000  0000 0000
// sign bit = 0
// exponent = 1000 0000 = 128 - 127 = 1
// mantissa = 1000 0000 0000 000 
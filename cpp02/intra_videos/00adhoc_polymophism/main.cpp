#include "Sample.class.hpp"

int	main(void)
{
	Sample	sample;
	float	f = 3.14;

	sample.bar('a');
	sample.bar(42);
	sample.bar(f);
	sample.bar(sample);
}

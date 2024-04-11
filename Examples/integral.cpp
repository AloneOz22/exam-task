#include <cmath>
#include <stdexcept>
#include <iostream>
#include <tuple>

#define ZERO 1e-9

double linear_func(double x)
{
	return x;
}

double square_func(double x)
{
	return x * x;
}

double cube_func(double x)
{
	return x * x * x;
}

double hyperbolic_func(double x) 
{
	if (fabs(x) < ZERO) 
	{
		throw std::logic_error("Division by zero!");
	}
	return 1.0 / x;
}

double calc_square(double a, double b, double f_a, double f_b) 
{
	return (f_b + f_a) * (b - a) / 2;
}

std::tuple<double, double, int, double(*)(double)> read_input()
{
	std::cout << "Enter function to calculate: \n1 - linear\n2 - square\n3 - cubic\n4 - hyberbolic ";
	double (*function_type)(double);
	int function_input_type;
	if (!(std::cin >> function_input_type))
	{
		throw std::invalid_argument("Invalid input!");
	}
	switch (function_input_type) 
	{
	case 1:
		function_type = linear_func;
		break;
	case 2:
		function_type = square_func;
		break;
	case 3:
		function_type = cube_func;
		break;
	case 4:
		function_type = hyperbolic_func;
		break;
	default:
		throw std::logic_error("Unknown function type!");
		break;
	}
	std::cout << "Enter x1: ";
	double x1;
	if (!(std::cin >> x1))
	{
		throw std::invalid_argument("Invalid input!");
	}
	std::cout << "Enter x2: ";
	double x2;
	if (!(std::cin >> x2))
	{
		throw std::invalid_argument("Invalid input!");
	}
	if (x2 - x1 <= 0) 
	{
		throw std::invalid_argument("b - a must be larger than 0!");
	}
	std::cout << "Enter steps count: ";
	int steps_count;
	if (!(std::cin >> steps_count))
	{
		throw std::invalid_argument("Invalid input!");
	}
	if (steps_count <= 0) 
	{
		throw std::invalid_argument("Steps count must be larger than 0!");
	}
	return { x1, x2, steps_count, function_type};
}

double calc_integral(std::tuple<double, double, int, double(*)(double)> input) {
	double a, b;
	int steps_count;
	double (*function)(double);
	std::tie(a, b, steps_count, function) = input;
	double delta_x = (b - a) / steps_count;
	double result_square = 0.0;
	for (int i = 0; i < steps_count; i++) 
	{
		double local_a = a + i * delta_x;
		double local_b = a + (i + 1) * delta_x;
		double f_a = function(local_a);
		double f_b = function(local_b);
		
		result_square += calc_square(local_a, local_b, f_a, f_b);
	}
	return result_square;
}
/*
int main() 
{
	try 
	{
		auto input = read_input();
		double result = calc_integral(input);
		std::cout << "I = " << result;
		return 0;
	}
	catch (std::logic_error& e) 
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
	catch (std::invalid_argument& e) 
	{
		std::cout << e.what() << std::endl;
		return -2;
	}
}
*/
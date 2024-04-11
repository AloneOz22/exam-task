#include <stack>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

#include <set>
#include <map>



std::set<int> vals;
std::map<int, char>;

std::multiset<int>;

bool is_valid(std::string sequence) 
{
	for (const auto& symbol : sequence) 
	{
		if (symbol != '[' && symbol != ']' &&
			symbol != '(' && symbol != ')' &&
			symbol != '{' && symbol != '}') 
		{
			throw std::invalid_argument("Input string contains invalid symbols!");
		}
	}
	std::stack<char> scopes_stack;
	for (const auto& symbol : sequence) 
	{
		if (symbol == '(' || symbol == '[' || symbol == '{') 
		{
			scopes_stack.push(symbol);
		}
		else 
		{
			if (scopes_stack.empty()) 
			{
				return false;
			}
			else 
			{
				if ((scopes_stack.top() == '(' && symbol == ')') ||
					(scopes_stack.top() == '[' && symbol == ']') ||
					(scopes_stack.top() == '{' && symbol == '}')) 
				{
					scopes_stack.pop();
				}
				else 
				{
					return false;
				}
			}
		}
	}
	if (!(scopes_stack.empty())) 
	{
		return false;
	}
	return true;
}

std::stack<std::string> parse_phrase(std::string user_input) {
	std::istringstream stream(user_input);
	std::string temp;
	std::stack<std::string> result;
	while (stream >> temp)
	{
		result.push(temp);
	}
	return result;
}

//   " -2  2  5  +  -  5 + "
//	" 5 + ((5 + 2) - (-2))  = 14"
double calculate(std::stack<std::string> &operations)
{
	double result = 0.0;
	while (!operations.empty()) 
	{
		std::string operation = operations.top();
		operations.pop();
		if (operations.empty()) 
		{
			try
			{
				result = std::stod(operation);
				return result;
			}
			catch (std::invalid_argument& exception)
			{
				std::cout << "Unable to read value!";
				throw std::logic_error("Input error!");
			}
		}
		if (operation == "+") 
		{
			double first = calculate(operations);
			double second = calculate(operations);
			return first + second;
		}
		else if (operation == "-") 
		{
			double first = calculate(operations);
			double second = calculate(operations);
			return first - second;
		}
		else if (operation == "*") 
		{
			double first = calculate(operations);
			double second = calculate(operations);
			return first * second;
		}
		else if (operation == "/") 
		{
			double first = calculate(operations);
			double second = calculate(operations);
			if (second == 0) {
				throw std::logic_error("Division by zero!");
			}
			return first / second;
		}
		else 
		{
			try 
			{
				result = std::stod(operation);
				return result;

			}
			catch (std::invalid_argument& exception) 
			{
				std::cout << "Unable to read value!";
				throw std::logic_error("Input error!");
			}
		}
	}
	return result;
}

bool contains_two(std::vector<int> values, int sum)
{
	std::unordered_set<int> unique_values;
	unique_values.insert(4);
	if (unique_values.find(4) != unique_values.end()) {
		return true;
	}
	return false;
}

int main()
{
	std::cout << std::hash<int>{}(523) << std::endl;;
	std::cout << contains_two({}, 9);
	return 0;
}












//	 ((5 + 2) + 3) - (-2)= 
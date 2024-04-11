#include <vector>
#include <tuple>
#include <iostream>
#include <numeric>
#include "my_list.h"

std::tuple<std::vector<double>, int> get_input() 
{
	std::cout << "Enter array size ";
	int size;
	if (!(std::cin >> size)) 
	{
		throw std::invalid_argument("Incorrect input!\n");
	}
	std::vector<double> arr(size);
	for (int i = 0; i < size; i++) {
		std::cout << "Enter array element with index " << i << "  ";
		if (!(std::cin >> arr[i])) 
		{
			throw std::invalid_argument("Incorrect input!\n");
		}
	}
	int window_size;
	std::cout << "Enter window size ";
	if (!(std::cin >> window_size)) 
	{
		throw std::invalid_argument("Incorrect input!\n");
	}
	return { arr, window_size };
}

double average(std::vector<double>& arr) {
	if (arr.empty()) {
		return 0;
	}
	auto count = static_cast<double>(arr.size());
	return std::reduce(arr.begin(), arr.end()) / count;
}

std::vector<double> mean_in_window(std::vector<double> arr, int window_size) 
{
	if (arr.size() < 1) 
	{
		std::cout << "Array is too small..." << std::endl;
		return arr;
	}
	if (window_size < 1) 
	{
		throw std::logic_error("Invalid window size!");
	}
	if (window_size == 1) 
	{
		return arr;
	}
	if (window_size > arr.size() * 2) 
	{
		std::fill(arr.begin(), arr.end(), average(arr));
		return arr;
		//	TODO: Нужна функция, усредняющая весь массив
	}
	//	Инициализируем output
	std::vector<double> result(arr.size());
	double sum = 0;
	int current_window_size = window_size % 2 == 1 ? (window_size / 2) + 1 : window_size / 2;
	//	Инициализируем сумму
	for (int i = 0; i < current_window_size; i++) 
	{
		sum += arr[i];
	}
	//	Инициализируем первый элемент
	result[0] = sum / current_window_size;
	//	Левый краевой случай. Увеличивается фактический размер окна
	int begin_index = 1;
	int end_index = (window_size / 2) + 1;
	for (int i = begin_index; i < end_index; i++) 
	{
		int current_added_index = window_size % 2 == 1 ? i + (window_size / 2) : i + (window_size / 2) - 1;
		sum += arr[current_added_index];
		result[i] = sum / ++current_window_size;
	}
	//	Общий случай. Элементы в середине массива. Полное окно
	begin_index = (window_size / 2) + 1;
	end_index = window_size / 2 == 1 ? arr.size() - (window_size / 2) : arr.size() - (window_size / 2) + 1;
	for (int i = begin_index; i < end_index; i++) 
	{
		int added_index = window_size % 2 == 1 ? i + (window_size / 2) : i + (window_size / 2) - 1;
		int removed_index = i - (window_size / 2) - 1;
		sum += arr[added_index] - arr[removed_index];
		result[i] = sum / current_window_size;
	}
	//	Правый краевой случай. Уменьшается фактический размер окна
	begin_index = end_index;
	for (int i = begin_index; i < arr.size(); i++) 
	{
		sum += - arr[i - (window_size / 2) - 1];
		result[i] = sum / --current_window_size;
	}
	return result;
}
/*

int main() 
{
	
}
*/
#include <string>
#include <iostream>
#include <vector>
#include <exception>

std::vector<int> getFibonacciSequence(std::size_t amountOfNumbers) {
	if (amountOfNumbers == 0)
		throw std::invalid_argument("amountOfNumbers cannot be 0");
	else if (amountOfNumbers == 1)
		return {1};
	else if (amountOfNumbers == 2)
		return {1, 1};

	std::vector<int> result(amountOfNumbers);
	result[0] = 1;
	result[1] = 1;

	std::size_t lastIndex2 = 0;
	std::size_t lastIndex1 = 1;

	for (std::size_t i = 0; i < amountOfNumbers-2; i++) {
		std::size_t value = result[lastIndex1] + result[lastIndex2];
		lastIndex1++;
		lastIndex2++;
		result[lastIndex1] = value;
	}
	return result;
}


int main() {
	std::size_t amountOfNumbers;
	std::cout << "How Many Fibonacci Numbers should be shown?" << std::endl;
	std::cin >> amountOfNumbers;

	auto result = getFibonacciSequence(amountOfNumbers);
	for (const auto& value : result) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}
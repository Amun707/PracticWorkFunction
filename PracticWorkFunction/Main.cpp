#include <iostream>
#include <ctime>
#include <cstdlib>

//Задача 1. 
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
			std::cout << arr[i] << ", ";
			std::cout << "\b\b }" << std::endl;
		
}
template <typename T>
void clean_arr(T arr[], const int length, int num) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		if (arr[i] == num) {
			arr[i] == 0;
			std::cout << arr[i] << std::endl;
		}
}
//Задача 2.
int index_sum(int arr1[], const int length1, int arr2[], const int length2, int num) {
	int sum = arr1[num] + arr2[num];
	for(int i = 0; i<length1; i++)
		for(int i = 0; i<length2; i++)
	return sum;
}

//Задача 3.
template <typename T>
int mean_arr(T arr[], const int length) {
	int min = arr[0];
	for (int i = 1; i < length; i++)
		if (arr[i] < min)
			min = arr[i];
	int max = arr[0];
	for (int i = 1; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	return (min + max) / 2;
}

//Задача 4.



int main() {
	system("chcp 1251>nul");
	int n, m;

	// Задача 1.
	const int size = 10;
	int arr[size];
	fill_arr(arr, size, 1, 21);
	std::cout << "Задача 1.\nИзначальный массив:\n";
	print_arr(arr, size);
	std::cout << "Введите ключевое значение ->\n";
	std::cin >> n;
	std::cout << "Итоговый массив:\n";
	clean_arr(arr, size, n);

	
	


	//Задача 2.
	std::cout << "Задача 2.\nМассив №1:\n";
	const int size2 = 5;
	int arr2[size2];

	const int size2_2 = 6;
	int arr2_2[size2_2];

	srand(time(NULL));
	for (int i = 0; i < size2; i++)
		arr2[i] = rand() % 51;
	for (int i = 0; i < size2_2; i++)
		arr2_2[i] = rand() % 51;
	print_arr(arr2, size2);
	std::cout << "Массив №2:\n";
	print_arr(arr2_2, size2_2);

	std::cout << "Введите индекс элемента массива ->\n";
	std::cin >> n;
	index_sum(arr2, size2, arr2_2, size2_2, n);
	std::cout << "Сумма элементов под указанным индексом = " << index_sum(arr2, size2, arr2_2, size2_2, n) << std::endl;

	//Задача 3. 
	std::cout << "Задача 3.\n";
	const int size3 = 10;
	int arr3[size3];
	srand(time(NULL));
	for (int i = 0; i < size3; i++)
		arr3[i] = rand() % 21+10;
	std::cout << "Массив:\n";
	print_arr(arr3, size3);
	std::cout << "Ср.арифметическое минимального и максимального значений элементов массива = " << mean_arr(arr3, size3) << "\n\n";

	//Задача 4.
	std::cout << "Задача 4.\n";





	return 0;
}
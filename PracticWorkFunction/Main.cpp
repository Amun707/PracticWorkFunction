#include <iostream>
#include <ctime>
#include <cstdlib>


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


//Задача 1. 
template <typename T>
void clean_arr(T arr[], const int length, int num) {
	for (int i = 0; i < length; i++)
		if (arr[i] == num)
			arr[i] = 0;
}


//Задача 2.
int index_sum(int arr1[], const int length1, int arr2[], const int length2, int num) {
	if (num >= length1 || num >= length2 || num < 0) { // дополнительное условие задачи
		std::cout << "ERROR\n";
		return 0;
	}
	
	return arr1[num] + arr2[num];
}


//Задача 3.
template <typename T>
double mean_arr(T arr[], const int length) {
	int min = arr[0];
	int max = min;
	for (int i = 1; i < length; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	return (min + max) / 2.0;
}


//Задача 4.
void prime_range(int left, int right) {
	for (int i = left; i <= right; i++) { // перебор всех чисел диапазона
		int counter = 0;
		for (int j = 1; j <= i; j++) // подсчёт кол-ва делителей
			if (i % j == 0)
				counter++;
		if (counter == 2)
			std::cout << i << ' ';
	}
	std::cout << std::endl;
}
void prime_range(int num) {
	// prime_range(1, num); // простой вариант решения задачи

	for (int i = 1; i <= num; i++) { // перебор всех чисел от 1 до num
		int counter = 0;
		for (int j = 1; j <= i; j++) // подсчёт кол-ва делителей
			if (i % j == 0)
				counter++;
		if (counter == 2)
			std::cout << i << ' ';
	}
	std::cout << std::endl;
}


// Задача 5.
template <typename T>
void permute_arr(T arr[], const int length) {
	for (int i = 0; i < length / 2; i++)
		if (length % 2 == 0)
			std::swap(arr[i], arr[length / 2 + i]);
		else
			std::swap(arr[i], arr[length / 2 + i + 1]);
}


// Задача 3 из новой версии практики.
int compare_pare(int arr[], const int length, int num1, int num2) {
	for (int i = 0; i < length - 1; i++)
		if (arr[i] == num1)
			if (arr[i + 1] == num2)
				return i;
	return -1;
}


int main() {
	system("chcp 1251>nul");
	int n, m;


	// Задача 1.
	std::cout << "Задача 1.\nИзначальный массив:\n";
	const int size1 = 10;
	int arr1[size1];
	fill_arr(arr1, size1, 1, 21);
	print_arr(arr1, size1);

	std::cout << "Введите ключевое значение -> ";
	std::cin >> n;
	clean_arr(arr1, size1, n);

	std::cout << "Итоговый массив:\n";
	print_arr(arr1, size1);
	std::cout << std::endl;
	

	//Задача 2.
	std::cout << "Задача 2.\nМассив №1:\n";
	const int size2_1 = 5;
	int arr2_1[size2_1];
	fill_arr(arr2_1, size2_1, 0, 51);
	print_arr(arr2_1, size2_1);

	std::cout << "Массив №2:\n";
	const int size2_2 = 6;
	int arr2_2[size2_2];
	fill_arr(arr2_2, size2_2, 5, 46);
	print_arr(arr2_2, size2_2);

	std::cout << "Введите индекс элемента массива -> ";
	std::cin >> n;
	std::cout << "Сумма элементов под указанным индексом = " << index_sum(arr2_1, size2_1, arr2_2, size2_2, n) << "\n\n";


	//Задача 3. 
	std::cout << "Задача 3.\n";
	const int size3 = 10;
	int arr3[size3];
	std::cout << "Массив:\n";
	fill_arr(arr3, size3, 20, 41);
	print_arr(arr3, size3);
	std::cout << "Ср.арифметическое минимального и максимального значений элементов массива = " << mean_arr(arr3, size3) << "\n\n";


	//Задача 4.
	std::cout << "Задача 4.\nВведите два числа -> ";
	std::cin >> n >> m;
	std::cout << "Простые числа из данного диапазона:\n";
	prime_range(n, m);
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << "Простые числа от 1-го до данного числа:\n";
	prime_range(n);
	std::cout << std::endl;


	// Задача 5.
	std::cout << "Задача 5.\nВведите размер массива -> ";
	int size5;
	std::cin >> size5;
	int* arr5 = new int[size5];
	for (int i = 0; i < size5; i++)
		arr5[i] = i + 1;
	std::cout << "Изначальный массив:\n";
	print_arr(arr5, size5);

	permute_arr(arr5, size5);

	std::cout << "Итоговый массив:\n";
	print_arr(arr5, size5);


	// Задача 3 из новой версии практики.
	std::cout << "Задача 3 (new).\nИзначальный массив:\n";
	const int size3n = 10;
	int arr3n[size3n];
	fill_arr(arr3n, size3n, 1, 21);
	print_arr(arr3n, size3n);

	std::cout << "Введите два числа -> ";
	std::cin >> n >> m;

	int index = compare_pare(arr3n, size3n, n, m);

	if (index != -1)
		std::cout << "Индекс: " << index << std::endl;
	else
		std::cout << "Такой пары нет в массиве\n";


	return 0;
}
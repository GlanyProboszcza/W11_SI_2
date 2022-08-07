#include <iostream>
#include <algorithm>
#include <random>




/* mozna uzywac, ale przy intach
void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
*/

template <class T> // <--- wygodniejszy przy roznych typach zmiennych 
void swapie(T& x, T& y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

void bubbleSortOfChar(char letter[]) {

	std::cout << "\n\n=== Letters before bubble sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}

	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19 - j; i++) {
			if (letter[i] > letter[i + 1]) {
				swapie(letter[i], letter[i + 1]);
			}
		}
	}

	std::cout << "\n\n=== Sorted letters ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}
	std::cout << std::endl;
}

void bubbleSortOfNumbers(int num[]) {

	std::cout << "\n=== Numbers before bubble sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}

	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19 - j; i++){
			if (num[i] > num[i + 1]) {
				swapie(num[i], num[i + 1]);
			}
		}
	}

	std::cout << "\n\n=== Sorted numbers ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}

void selectionSortOfChar(char letter[]) {

	std::cout << "\n=== Letters before selection sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}

	std::cout << "\n\n=== Sorting ===" << std::endl;
	for (int j = 0; j < 20; j++) {
		int min = j;
		for (int i = min; i < 20; i++) {
			if (letter[min] > letter[i]) {
				min = i;
			}
		}

		for (int i = 0; i < 20; i++) {
			std::cout << letter[i] << " ";
		}
		std::cout << std::endl;


		if (min == j) continue;
		swapie(letter[min], letter[j]);
	}

	std::cout << "\n\n=== Sorted letters ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}
	std::cout << std::endl;
}

void selectionSortOfNumbers(int num[]) {

	std::cout << "\n\n=== Numbers before selection sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}

	std::cout << "\n\n=== Sorting ===" << std::endl;
	for (int j = 0; j < 20; j++) {
		int min = j;
		for (int i = min; i < 20; i++) {
			if (num[min] > num[i]) {
				min = i;
			}
		}

	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;


	if (min == j) continue;
	swapie(num[min], num[j]);
	}

	std::cout << "\n\n=== Sorted numbers ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}

void insertionSortOfNumbers(int num[]) {

	std::cout << "\n=== Numbers before insertion sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}

	for (int step = 0; step < 20; step++) {
		int key = num[step];
		int j = step - 1;
	while (key < num[j] && j >= 0) {
		num[j + 1] = num[j];
		--j;
	}
	num[j + 1] = key;
	}
	std::cout << "\n\n=== Sorted numbers  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}

void insertionSortOfChar(char letter[]) {

	std::cout << "\n=== Letters before insertion sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}

	for (int step = 0; step < 20; step++) {
		int key = letter[step];
		int j = step - 1;
		while (key < letter[j] && j >= 0) {
			letter[j + 1] = letter[j];
			--j;
		}
		letter[j + 1] = key;
	}
	std::cout << "\n\n=== Sorted letters  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}
	std::cout << std::endl;
}

void divideMergeSortOfNumbers(int num[], int a, int b, int c) { // table, begin, middle, end

	for (int i = a; i <= c; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	
	int l=a, r= b+1, h=0;
	int* helpNum = new int[c - a + 1];

	while (l <= b && r <= c) {
		if (num[l] < num[r]) {
			helpNum[h] = num[l];
			h++;
			l++;
		}
		else {
			helpNum[h] = num[r];
			h++;
			r++;
		}
	}

	while (l <= b) {
		helpNum[h] = num[l];
		h++;
		l++;
	}

	while (r <= c) {
			helpNum[h] = num[r];
			h++;
			r++;
	}

	for (int i = a; i <= c; i++) {
		num[i] = helpNum[i-a];
	}

	delete[] helpNum;

	for (int i = 0; i <= c; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}

void mergeSortOfNumbers(int num[], int l, int r) {
	if (l < r) {
		// m is the point where the array is divided into two subarrays
		int m = (r + l) / 2;

		mergeSortOfNumbers(num, l, m);
		mergeSortOfNumbers(num, m + 1, r);

		// Merge the sorted subarrays
		divideMergeSortOfNumbers(num, l, m, r);
	}
}
void mergeSortOfChar(char letter[]) {

	std::cout << "\n=== Letters before insertion sorting  ===" << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << letter[i] << " ";
	}


}

int partition(int num[], int s, int e) {
	int count = 0;
	int m = num[s];

	for (int i = s+1; i <= e; i++) {
		if (i < m)
		count++;
	}
	int im = count +s; // im --> indexMediany
	swapie(num[s], num[im]);
	int l = s;
	int r = e;
	while (l < im && r > im) {
		while (num[l] <= m)
			l++;
		while (num[r] > m)
			r--;
		if (l < im && r <= e)
		swapie(num[l++], num[r--]);
	}
	return im;
}

void quickSortOfNumbers(int num[], int s, int e) {
	
	if (s >= e)
		return;
	int pivot = partition(num, s, e);

	for (int i = 0; i < 20; i++) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;

	quickSortOfNumbers(num, s, pivot -1);
	quickSortOfNumbers(num, pivot + 1, e);
}


int main()
{
	int num[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	char letter[20] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u' };
	auto rng = std::default_random_engine{};   // <- generowanie klucza do mieszania

	std::cout << "\n\n\tSIMPLE SORTS\n\n" << std::endl;

	std::cout << "-------------------" << std::endl;
	std::cout << "--- Bubble sort ---" << std::endl;
	std::cout << "-------------------" << std::endl;
	shuffle(std::begin(num), std::end(num), rng);
	shuffle(std::begin(letter), std::end(letter), rng);

	bubbleSortOfNumbers(num);
	bubbleSortOfChar(letter);

	std::cout << "\n\n----------------------" << std::endl;
	std::cout << "--- Selection sort ---" << std::endl;
	std::cout << "----------------------" << std::endl;
	shuffle(std::begin(num), std::end(num), rng);
	shuffle(std::begin(letter), std::end(letter), rng);

	selectionSortOfNumbers(num);
	selectionSortOfChar(letter);

	std::cout << "\n\n----------------------" << std::endl;
	std::cout << "--- Insertion sort ---" << std::endl;
	std::cout << "----------------------" << std::endl;
	shuffle(std::begin(num), std::end(num), rng);
	shuffle(std::begin(letter), std::end(letter), rng);

	insertionSortOfNumbers(num);
	insertionSortOfChar(letter);

	std::cout << "\n\n\tEFFICIENT SORTS\n\n" << std::endl;

	std::cout << "------------------" << std::endl;
	std::cout << "--- Merge sort ---" << std::endl;
	std::cout << "------------------" << std::endl;
	shuffle(std::begin(num), std::end(num), rng);
	shuffle(std::begin(letter), std::end(letter), rng);

	mergeSortOfNumbers(num, 0,19);
	mergeSortOfChar(letter);

	std::cout << "\n\n------------------" << std::endl;
	std::cout << "--- Quick sort ---" << std::endl;
	std::cout << "------------------" << std::endl;
	shuffle(std::begin(num), std::end(num), rng);
	quickSortOfNumbers(num, 0, 19);
	//quickSortOfChar(letter);

	//std::cout << "\n\n-----------------" << std::endl;
	//std::cout << "--- Heap sort ---" << std::endl;
	//std::cout << "-----------------" << std::endl;

}

/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int key;
	char eye, nose, mouth;
	int size, balance_num, generous_num, circle_num, happy_num, smile_num, cheer_num, festival_num;
	int buffer = 0, module = 10;
	do{
		printf("Choose an option: \n"
			"        1. Happy Face\n"
			"        2. Balanced Number\n"
			"        3. Generous Number\n"
			"        4. Circle Of Joy\n"
			"        5. Happy Numbers\n"
			"        6. Festival Of Laughter\n"
			"        7. Exit\n");
		scanf("%d", &key);

		switch (key) {
			case 1:
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eye, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &size);
				while (size <= 0 || size % 2 == 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &size);
				}
				printf("%c", eye);
				for (int i = size; i != 0; i--) {
					printf(" ");
				}
				printf("%c\n", eye);
				for (int i = size/2 + 1; i != 0; i--) { //division by integer returns round to smaller so to round up to bigger need to add 1
					printf(" ");
				}
				printf("%c\n", nose);
				printf("\\");
				for (int i = size; i != 0; i--) {
					printf("%c", mouth);
				}
				printf("/\n");
			break;

			case 2:
				printf("Enter a number:\n");
				scanf("%d", &balance_num);
				while(balance_num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &balance_num);
				}
				int sumToLeft = 0, sumToRight = 0, j = 0;
				buffer = balance_num;
				while (buffer != 0) {
					buffer /= module;
					j++;
				}
				int k = j;
				k = k/2;
				while ( k != 0) {
					sumToLeft += balance_num % module;
					balance_num /= module;
					k--;
				}
				j = j/2;
				while (j != 0) {
					sumToRight += balance_num % module;
					balance_num /= module;
					j--;
				}
				if (sumToLeft == sumToRight)
					printf("This number is balanced and brings harmony!\n");
				else
					printf("This number isn't balanced and destroys harmony.\n");
				break;
			case 3:
				printf("Enter a number:\n");
				scanf("%d", &generous_num);
				while(generous_num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &generous_num);
				}
				int sumOfDiv = 0;
				for (int i = 2; i != generous_num; i++) {
					if (generous_num % i == 0)
						sumOfDiv += i;
				}
				if (sumOfDiv > generous_num)
					printf("This number is generous!\n");
				else
					printf("This number does not share.\n");
			break;
			case 4:
				printf("Enter a number:\n");
				scanf("%d", &circle_num);
				int check1 = 2, check2 = 2;
				while(circle_num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &circle_num);
				}
				int circle_num_left = 0;
				buffer = circle_num;
				for (int i = 2; circle_num % i != 0 && circle_num != i; i++) {
					if (circle_num % i == 0) {
						break;
					}
					check1++;
				}
				while (buffer != 0) {
					circle_num_left += buffer % module;
					if (buffer / module == 0)
						break;
					buffer /= module;
					circle_num_left *= module;
				}
				for (int i = 2; circle_num_left % i != 0 && circle_num_left != i; i++) {
					if (circle_num_left % i == 0) {
						break;
					}
					check2++;
				}
				if (circle_num_left == check2 && circle_num == check1)
					printf("This number completes the circle of joy!\n");
				else
					printf("The circle remains incomplete.\n");
			break;
			case 5:
				printf("Enter a number:\n");
				scanf("%d", &happy_num);
				int totalOfDigits, counter = 0;
				while(happy_num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%i", &happy_num);
				}
				printf("Between 1 and %d only these numbers bring happiness: ", happy_num);
				for (int i = 1; i <= happy_num; i++) {
					counter = i;
					while (counter != 1) {
						totalOfDigits = 0;
						buffer = counter;
						while (buffer > 0) {
							totalOfDigits += (buffer % module) * (buffer % module);
							buffer /= module;
						}
						counter = totalOfDigits;
						if (counter == 4) //if number comes to 4 then it's definetly not happy and infinite loop
							break;
					}
					if (counter == 1)
						printf("%d ",i);
				}
				printf("\n");
			break;
			case 6:
				printf("Enter a smile and cheer number:\n");
				while (scanf(" smile: %d, cheer: %d", &smile_num, &cheer_num) != 2 || smile_num < 0 || cheer_num < 0 || smile_num == cheer_num) {
					scanf("%*[^\n]");
					scanf("%*c");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				}
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &festival_num);
				while (festival_num <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &festival_num);
				}
				for (int i = 1; i <= festival_num; i++) {
					if (i % cheer_num == 0 && i % smile_num == 0)
						printf("Festival! \n");
					else if (i % cheer_num == 0 && i % smile_num != 0)
						printf("Cheer!\n");
					else if (i % smile_num == 0 && i % cheer_num != 0)
						printf("Smile!\n");
					else
						printf("%d\n", i);
				}
			break;
			case 7:
				printf("Thank you for your journey through Numeria!\n");
			break;
			default:
				printf("This option is not available, please try again.\n");
			break;

		}
	} while (key != 7);
	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/
    

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}

/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int key;
	char eye, nose, mouth;
	int size, balance, generous, circle, happy, smile, cheer, festival_num;
	int buffer = 0;
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
			for (int i = size/2 + 1; i != 0; i--) {
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
			scanf("%d", &balance);
			while(balance <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &balance);
			}
			int module = 10, sum1 = 0, sum2 = 0, j = 0;
			buffer = balance;
			while (buffer != 0) {
				buffer /= 10;
				j++;
			}
			int k = j;
			k = k/2;
			while ( k != 0) {
				sum1 += balance % module;
				balance /= 10;
				k--;
			}
			j = j/2;
			while (j != 0) {
				sum2 += balance % module;
				balance /= 10;
				j--;
			}
			if (sum1 == sum2)
				printf("This number is balanced and brings harmony!\n");
			else
				printf("This number isn't balanced and destroys harmony.\n");
			break;
			case 3:
				printf("Enter a number:\n");
			scanf("%d", &generous);
			while(generous <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &generous);
			}
			int sum3 = 0;
			for (int i = 2; i != generous; i++) {
				if (generous % i == 0)
					sum3 += i;
			}
			if (sum3 > generous)
				printf("This number is generous!\n");
			else
				printf("This number does not share.\n");
			break;
			case 4:
				printf("Enter a number:\n");
			scanf("%d", &circle);
			int check1 = 2, check2 = 2;
			while(circle <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &circle);
			}
			int circle2 = 0;
			buffer = circle;
			for (int i = 2; circle % i != 0 && circle != i; i++) {
				if (circle % i == 0) {
					break;
				}
				check1++;
			}
			while (buffer != 0) {
				circle2 += buffer % 10;
				if (buffer / 10 == 0)
					break;
				buffer /= 10;
				circle2 *= 10;
			}
			for (int i = 2; circle2 % i != 0 && circle2 != i; i++) {
				if (circle2 % i == 0) {
					break;
				}
				check2++;
			}
			if (circle2 == check2 && circle == check1)
				printf("This number completes the circle of joy!\n");
			else
				printf("The circle remains incomplete.\n");
			break;
			case 5:
				printf("Enter a number:\n");
			scanf("%d", &happy);
			int total, num = 0;
			while(happy <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%i", &happy);
			}
			printf("Between 1 and %d only these numbers bring happiness: \n", happy);
			for (int i = 1; i <= happy; i++) {
				num = i;
				while (num != 1) {
					total = 0;
					buffer = num;
					while (buffer > 0) {
						total += (buffer % 10) * (buffer % 10);
						buffer /= 10;
					}
					num = total;
					if (num == 4)
						break;
				}
				if (num == 1)
					printf("%d ",i);
			}
			break;
			case 6:
				printf("Enter a smile and cheer number:\n");
			while (scanf(" smile: %d, cheer: %d", &smile, &cheer) != 2 || smile < 0 || cheer < 0 || smile == cheer) {
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
				if (i % cheer == 0 && i % smile == 0)
					printf("Festival! \n");
				else if (i % cheer == 0 && i % smile != 0)
					printf("Cheer!\n");
				else if (i % smile == 0 && i % cheer != 0)
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

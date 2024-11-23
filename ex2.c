/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int key;
	char eye, nose, mouth;
	int size, balance, generous, circle, happy, smile, cheer;
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
			scanf("%i", &size);
			while (size <= 0 || size % 2 == 0) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%i", &size);
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
			scanf("%i", &balance);
			while(balance <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%i", &balance);
			}
			int module = 10, sum1 = 0, sum2 = 0, j = 0;
			int reserve = balance;
			while (reserve != 0) {
				reserve /= 10;
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
			scanf("%i", &generous);
			while(generous <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%i", &generous);
			}
			int sum3 = 0, n = 2;
			while (n != generous) {
				if (generous % n == 0)
					sum3 += n;
				n++;
			}
			if (sum3 > generous)
				printf("This number is generous!\n");
			else
				printf("This number does not share.\n");
			 break;
		case 4:
			printf("Enter a number:\n");
			scanf("%i", &circle);
			while(circle <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%i", &circle);
			}
			int circle2 = 0, m = 2, buffer = circle;
			while (circle % m != 0 && circle != m) {
				if (circle % m == 0) {
					break;
				}
				// while (buffer != 0) {
				// 	circle2 += buffer % 10;
				// 	if (buffer / 10 == 0)
				// 		break;
				// 	circle2 *= 10;
				// 	buffer /= 10;
				// }
				m++;
			}
			while (buffer != 0) {
				circle2 += buffer % 10;
				if (buffer / 10 == 0)
					break;
				buffer /= 10;
				circle2 *= 10;
			}
			int m2 = 2;
			while (circle2 % m2 != 0 && circle2 != m2) {
				if (circle2 % m2 == 0) {
					break;
				}
				m2++;
			}
			if (circle2 == m2 && circle == m)
				printf("This number completes the circle of joy!\n");
			else
				printf("The circle remains incomplete.\n");
			break;
		case 5:
			printf("Enter a number:\n");
			scanf("%i", &happy);
			int total, num = 2, buffer2;
			while(happy <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%i", &happy);
			}
			printf("Between 1 and %d only these numbers bring happiness: ", happy);
			for (int i = 1; i <= happy; i++) {
				num = i;
				int cycle = 0;
				while (num != 1) {
					total = 0;
					buffer2 = num;
					while (buffer2 > 0) {
						total += (buffer2 % 10) * (buffer2 % 10);
						buffer2 /= 10;
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
			printf("\nEnter a smile and cheer number:\n");

			break;
		case 7:
			printf("Thank you for your journey through Numeria!\n");
			break;
		default:
			printf("This option is not available, please try again.\n");
		break;

	}
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
   time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int Year = (tm.tm_year +1900); // year now
	int Moth = (tm.tm_mon + 1);    // moth now
	int Day  = (tm.tm_mday );      // day now
	printf("Year : %d\n",Year);
	printf("Moth : %d\n",Moth);
	printf("Day : %d\n",Day);

	char date[11];
	/*
	 *  Add Day to date
	 */

	date[0] = Day / 10 + '0';
	date[1] = Day % 10 + '0';

	/*
	 * Add / to date
	 */
	date[2] = '/';

	/*
	 * Add Moth to date
	 */
	date[3] = Moth / 10 + '0';
	date[4] = Moth % 10 + '0';

	/*
	 * Add / to date
	 */
	date[5] = '/';

	/*
	 * Add Year to date
	 */
	date[6] = Year /1000 + '0';
	date[7] = (Year /100) % 10 + '0';
	date[8] = (Year /10) % 10 + '0';
	date[9] = Year % 10 + '0';
	date[10] = '\0';

	printf("%s",date);

    return 0;
}

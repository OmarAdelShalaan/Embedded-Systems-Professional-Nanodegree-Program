/*
 * terminal.c
 *
 *  Created on: Aug 6, 2022
 *      Author: omar
 */


#include "terminal.h"

void getTransactionDate(ST_terminalData_t *termData)
{
	/*
	 * Local Variable
	 */
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int Year = (tm.tm_year + 1900); // year now
	int Moth = (tm.tm_mon + 1);    // moth now
	int Day  = (tm.tm_mday );      // day now
	//printf("Year in getTransactionDate fun: %d\n",Year);
	//printf("Moth in getTransactionDate fun : %d\n",Moth);
	//printf("Day in getTransactionDate fun : %d\n",Day);

	/*
	 *  Add Day to transactionDate
	 */
	termData->transactionDate[0] = Day / 10 + '0';
	termData->transactionDate[1] = Day % 10 + '0';

	/*
	 * Add / to transactionDate
	 */
	termData->transactionDate[2] = '/';

	/*
	 * Add Moth to transactionDate
	 */
	termData->transactionDate[3] = Moth / 10 + '0';
	termData->transactionDate[4] = Moth % 10 + '0';

	/*
	 * Add / to transactionDate
	 */
	termData->transactionDate[5] = '/';

	/*
	 * Add Year to transactionDate
	 */
	termData->transactionDate[6] = Year /1000 + '0';
	termData->transactionDate[7] = (Year /100) % 10 + '0';
	termData->transactionDate[8] = (Year /10) % 10 + '0';
	termData->transactionDate[9] = Year % 10 + '0';

	/*
	 * Add End of String
	 */
	termData->transactionDate[10] = '\0';
	/*
	 * the format DD/MM/YYYY
	 */
	//printf("Terminal Date :  %s\n",termData->transactionDate);
	return ;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
	int terYear  = (termData->transactionDate[8] - '0') * 10 + (termData->transactionDate[9] - '0');
	int terMoth  = (termData->transactionDate[3] - '0') * 10 + (termData->transactionDate[4] - '0');
	int cardYear = (cardData->cardExpirationDate[3] - '0') * 10 + (cardData->cardExpirationDate[4] - '0');
	int cardMoth = (cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0');
	//printf("terYear : %d\n",terYear);
	//printf("terMoth : %d\n",terMoth);
	//printf("cardYear : %d\n",cardYear);
	//printf("cardMoth : %d\n",cardMoth);
	if ( terYear < cardYear )
	{
			//printf("Return fun isCardExpired is OK\n");
			return OK;
	}
	else if ( (terYear == cardYear) && cardMoth >= terMoth)
	{
		//printf("Return fun isCardExpired is OK\n");
		return OK;
	}
	//printf("Return fun isCardExpired is EXPIRED_CARD\n");
	return EXPIRED_CARD;
}
/*
 * Luhn algorithm
 * (https://en.wikipedia.org/wiki/Luhn_algorithm)
 */

EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)
{
	int i,lenPAN,temp,j;
	int sum = 0;
	//printf("Enter CardPAN : ");
	//scanf("%s",cardData->primaryAccountNumber);
	//printf("Your CardPAN : %s\n",cardData->primaryAccountNumber);
	lenPAN = strlen(cardData->primaryAccountNumber);
	//printf("Len PAN : %d\n",lenPAN);

	for( i = lenPAN - 2, j = 0; i >= 0 ; i-- ,j++)
	{
		if( j % 2 != 0 )
		{
			sum += (cardData->primaryAccountNumber[i] - '0');
		}
		else
		{
			temp = (cardData->primaryAccountNumber[i] - '0') * 2 ;
			if(temp > 9)
			{
				sum += ( temp - 9 );
			}
			else
			{
				sum += temp;
			}
		}
		///printf("count : %d  sum : %d  PAN num : %d   pan *2 : %d\n",j,sum,cardData->primaryAccountNumber[i] -'0',\
				(cardData->primaryAccountNumber[i] -'0') *2);
	}
	//printf("(10 -%d)\tcheck num : %d\n",sum%10,cardData->primaryAccountNumber[ lenPAN - 1] -'0');
	if( ( 10 - sum % 10 ) == ( cardData->primaryAccountNumber[ lenPAN - 1] -'0' ) )
	{
		//printf("return isValidCardPAN is OK\n");
		return OK;
	}
	//printf("return isValidCardPAN is INVALID_CARD\n");
	return INVALID_CARD;

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{

	printf("Enter your transAmount : ");
	scanf("%f",&(termData->transAmount));
	if( (termData->transAmount) > (float)0 )
	{
		//printf("Return fun getTransactionAmount is OK\n");
		return OK;
	}
	//printf("Return fun getTransactionAmount is INVALID_AMOUNT\n");
	return INVALID_AMOUNT;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{

	if( termData->maxTransAmount >= termData->transAmount)
	{
		//printf("return of fun isBelowMaxAmount is Ok\n");
		return OK;
	}

	//printf("return of fun isBelowMaxAmount is EXCEED_MAX_AMOUNT\n");
	return EXCEED_MAX_AMOUNT;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
	//printf("Set Max Amount : ");
	//scanf("%f",&termData->maxTransAmount);
	if( termData->maxTransAmount > (float) 0 )
	{
		//printf("Return fun setMaxAmount is OK\n");
		return OK;
	}
	//printf("Return fun setMaxAmount is INVALID_MAX_AMOUNT\n");
	return INVALID_MAX_AMOUNT;
}

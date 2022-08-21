/*
 * card.c
 *
 *  Created on: Aug 6, 2022
 *      Author: omar
 */


#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	int lenStr_HolderName;

	//ask for the cardholder's name
	printf("Enter the cardholder's name : ");
	//scanf("%s",cardData->cardHolderName); //scanf gets all char before space
	/*
	 * scanf => omar adel shalaan  will take omar
	 * gets  => omar adel shalaan  will take omar adel shalaan
	 */
	gets(cardData->cardHolderName); // can we use gets to scanf all words with spaces between them

	//printf("cardHolderName : %s \n",cardData->cardHolderName);

	lenStr_HolderName = strlen(cardData->cardHolderName);
	//printf("StrLen : %d\n",lenStr_HolderName);

	//Card holder name is 24 characters string max and 20 min.
	if ((lenStr_HolderName >= 20) && (lenStr_HolderName <= 24) )
	{
		//printf("return getCardHolderName : OK\n");
		return OK ;
	}
	else
	{
		//printf("return getCardHolderName : WRONG_NAME\n");
		return WRONG_NAME;
	}
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
	printf("Enter Card Date \nplease enter Card Date like that MM/YY \nCard Date : ");
	scanf("%s",cardData->cardExpirationDate);
	if(strlen(cardData->cardExpirationDate) != 5 || cardData->cardExpirationDate[2] !='/' )
	{
		//printf("return getCardExpiryDate : WRONG_EXP_DATE\n");
		return WRONG_EXP_DATE;
	}
	//printf("return getCardExpiryDate : OK\n");
	return OK;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
	int lenStr_primaryAccountNumber;

	//ask for the cardholder's name
	printf("Enter the primary Account Number : ");
	scanf("%s",cardData->primaryAccountNumber);
	//printf("primaryAccountNumber : %s \n",cardData->primaryAccountNumber);
	lenStr_primaryAccountNumber = strlen(cardData->primaryAccountNumber);
	//printf("len of primaryAccountNumber : %d\n",lenStr_primaryAccountNumber);

	//Card holder name is 24 characters string max and 20 min.
	if ((lenStr_primaryAccountNumber >= 16) && (lenStr_primaryAccountNumber <= 19) )
	{
		//printf("return primaryAccountNumber : OK\n");
		return OK ;
	}
	else
	{
		//printf("return primaryAccountNumber : WRONG_PAN\n");
		return WRONG_PAN;
	}
}

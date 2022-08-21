/*
 * app.c
 *
 *  Created on: Aug 6, 2022
 *      Author: omar
 */

#include "app.h"


void appStart(void)
{
	//ST_cardData_t *cardData = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
	//ST_terminalData_t *termData = (ST_terminalData_t *)malloc(sizeof(ST_terminalData_t));
	ST_transaction_t *transData = malloc(sizeof(ST_transaction_t));

	int return_fun;
	/*
	 *  Card Fun
	 */
	if( getCardHolderName(&transData->cardHolderData) != OK)
	{
		printf("please enter correct Card Holder Name next time \n");
		return;
	}
	if(getCardExpiryDate(&transData->cardHolderData) != OK)
	{
		printf("please enter correct Card Expire Date next time \n");
		return;
	}
	getTransactionDate(&transData->terminalData);
	if(isCardExpired(&transData->cardHolderData , &transData->terminalData) != OK)
	{
		printf("Card is Expired \n");
		return;
	}
	if(getCardPAN(&transData->cardHolderData) != OK)
	{
		printf("please enter correct Card PAN next time \n");
		return;
	}

	if(isValidCardPAN(&transData->cardHolderData ) != OK)
	{
		printf("Card is Stolen \n");
		return;
	}
	if(getTransactionAmount(&transData->terminalData ) )
	{
		printf("amount not accepted \n");
		return;
	}

	transData->terminalData.maxTransAmount = 10000.0;

	if(isBelowMaxAmount(&transData->terminalData ) )
	{
		printf("amount more than max amount accepted \n");
		return;
	}

	return_fun =recieveTransactionData(transData);
	if(return_fun != APPROVED)
	{
		if(return_fun == FRAUD_CARD)
			printf("account not found\n");
		if(return_fun == DECLINED_INSUFFECIENT_FUND)
			printf("amount more than balance amount\n");
		if(return_fun == DECLINED_STOLEN_CARD)
			printf("account is Blocked");
		return;
	}
	if(saveTransaction(transData) == SAVING_FAILED)
	{
		printf("not save Transaction\n ");
		return;
	}
	printf("the transaction is approved\n");
	free(transData);
	return;
}
/*
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);


void getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);

EN_transState_t  recieveTransactionData(ST_transaction_t *transData);// isValidAccount ->  isBlockedAccount -> isValidAccount
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence);// Check PAN is Found is not
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence); // check state of account
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence); // check amount less or more than balance
EN_serverError_t saveTransaction(ST_transaction_t *transData);


*/



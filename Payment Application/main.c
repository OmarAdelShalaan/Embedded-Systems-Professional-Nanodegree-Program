/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: omar
 */


#include <stdio.h>
#include <stdlib.h>

//#include "Application/app.h"


/*
EN_transState_t  recieveTransactionData(ST_transaction_t *transData);// isValidAccount ->  isBlockedAccount -> isValidAccount
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence);// Check PAN is Found is not
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence); // check state of account
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence); // check amount less or more than balance

 */
int main()
{
	while(1)
	{
		appStart();
		printf("\n\n");
	}
	return 0;
}

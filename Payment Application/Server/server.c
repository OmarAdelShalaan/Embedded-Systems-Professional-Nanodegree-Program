/*
 * server.c
 *
 *  Created on: Aug 6, 2022
 *      Author: omar
 */


#include "server.h"

/*
 * Global Array type of ST_transaction_t
 */
ST_transaction_t arrTransaction_g[255] = {0};

/*
 * Global Array type of ST_accountsDB_t
 */

ST_accountsDB_t  arrAcounts_g[255]={{2000.0,   RUNNING,   "8989374615436851"},\
									{100000.0, RUNNING,   "5807007076043875"},\
									{100000.0, BLOCKED,   "5807007076043875"},\
									{100000.0, BLOCKED,   "5807007076043877"},\
									{1900.0,   RUNNING,   "8989374615436858"},\
									{2000.0,   RUNNING,   "8989374615436859"},\
									{800.0,    RUNNING,   "8989374615436850"},\
									{6948.0,   BLOCKED,   "89893746154368501"},\
									{5000.0,   RUNNING,   "8989374615436899"},\
									{50.0,     RUNNING,   "8989374615439999"},\
									{10.0,     BLOCKED,   "89893746159968511"},\
									};

EN_transState_t  recieveTransactionData(ST_transaction_t *transData) // isValidAccount ->  isBlockedAccount -> isValidAccount
{
	ST_accountsDB_t *accountRefrence = malloc(sizeof( ST_accountsDB_t ));
	if(  isValidAccount( &transData->cardHolderData, accountRefrence))
	{
		return FRAUD_CARD; // return 3
	}
	if( isAmountAvailable( &transData->terminalData, accountRefrence))
	{
		return DECLINED_INSUFFECIENT_FUND; // return 1
	}
	if(! isBlockedAccount( accountRefrence ))
	{
		return DECLINED_STOLEN_CARD; // return 2
	}
	return APPROVED; // return  0
}

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence)// Check PAN is Found is not
{
	int i;
	for( i = 0; i < 255 ; i++)
	{
		//printf("%s  %s\n",cardData->primaryAccountNumber,arrAcounts_g[i].primaryAccountNumber);
		if(! strcmp( cardData->primaryAccountNumber , arrAcounts_g[i].primaryAccountNumber) )
		{
			accountRefrence->balance = arrAcounts_g[i].balance;
			strcpy(accountRefrence->primaryAccountNumber ,arrAcounts_g[i].primaryAccountNumber);
			accountRefrence->state = arrAcounts_g[i].state;
			//printf("isValidAccount return is OK\n");
			return OK; // return  0
		}
	}
	//printf("isValidAccount return is ACCOUNT_NOT_FOUND\n");
	return ACCOUNT_NOT_FOUND;  // return  3
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence) // check state of account
{
	printf("b: %d\n",accountRefrence->state);
	if( accountRefrence->state == BLOCKED)
	{
		//printf("isBlockedAccount return is OK\n");
		return OK;  // retrun 0
	}
	//printf("isBlockedAccount return is NOT_BLOCKED_ACCOUNT\n");
	return NOT_BLOCKED_ACCOUNT; // return  6
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence) // check amount less or more than balance
{
	//printf("%f\n",accountRefrence->balance);
	if( termData->transAmount <= accountRefrence->balance)
	{
		//printf("isAmountAvailable return is OK\n");
		return OK;// retrun 0
	}
	//printf("isAmountAvailable return is LOW_BALANCE\n");
	return LOW_BALANCE;
}

EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	static int i = 0;
	if( ! recieveTransactionData(transData))
	{
		arrTransaction_g[i] = *transData;
		i++;
		arrTransaction_g[i].transactionSequenceNumber = i;
		return OK;// retrun 0
	}
	return SAVING_FAILED;
}



/*
{2000.0, RUNNING,   "8989374615436851"},\
{100000.0, BLOCKED, "5807007076043875"},\
{100000.0, BLOCKED, "5807007076043876"},\
{100000.0, BLOCKED, "5807007076043877"},\
{2000.0, RUNNING,   "8989374615436858"},\
{2000.0, RUNNING,   "8989374615436859"},\
{2000.0, RUNNING,   "8989374615436850"},\
{2000.0, RUNNING,   "8989374615436888"},\
{2000.0, RUNNING,   "8989374615436899"},\
{2000.0, RUNNING,   "8989374615439999"},\
{2000.0, BLOCKED,   "8989374615996851"},\

*/

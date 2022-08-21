/*
 * server.h
 *
 *  Created on: Aug 6, 2022
 *      Author: omar
 */

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include "../Terminal/terminal.h"



/*
 * Use the following typedef as-is:
 */
typedef enum EN_transState_t
{
APPROVED, 							// 0
DECLINED_INSUFFECIENT_FUND,			// 1
DECLINED_STOLEN_CARD,				// 2
FRAUD_CARD,							// 3
INTERNAL_SERVER_ERROR				// 4
}EN_transState_t;

typedef struct ST_transaction_t
{
ST_cardData_t cardHolderData;
ST_terminalData_t terminalData;
EN_transState_t transState;
uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
SERVER_OK, 					// 0
SAVING_FAILED, 				// 1
TRANSACTION_NOT_FOUND, 		// 2
ACCOUNT_NOT_FOUND, 			// 3
LOW_BALANCE, 				// 4
BLOCKED_ACCOUNT,			// 5
NOT_BLOCKED_ACCOUNT			// 6
}EN_serverError_t ;

typedef enum EN_accountState_t
{
RUNNING,
BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
float balance;
EN_accountState_t state;
uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;


EN_transState_t  recieveTransactionData(ST_transaction_t *transData);// isValidAccount ->  isBlockedAccount -> isValidAccount
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence);// Check PAN is Found is not
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence); // check state of account
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence); // check amount less or more than balance
EN_serverError_t saveTransaction(ST_transaction_t *transData);
//EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData);


#endif /* SERVER_SERVER_H_ */

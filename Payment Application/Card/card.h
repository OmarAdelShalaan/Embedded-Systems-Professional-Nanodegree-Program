/*
 * card.h
 *
 *  Created on: Aug 6, 2022
 *      Author: omar
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

#include "../Platform_Types.h"
#include <string.h>
#include <time.h>

/*
 * Use the following typedef as-is:
 */
typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
OK,// Ok -> 0
WRONG_NAME,//  WRONG_NAME -> 1
WRONG_EXP_DATE, // WRONG_EXP_DATE-> 2
WRONG_PAN // WRONG_PAN-> 3
}EN_cardError_t;

/*
 * Use the following prototypes as is:
 */
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);



#endif /* CARD_CARD_H_ */

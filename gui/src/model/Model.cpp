/******************************************************************************
 *
 * @brief     This file is part of the TouchGFX 4.8.0 evaluation distribution.
 *
 * @author    Draupner Graphics A/S <http://www.touchgfx.com>
 *
 ******************************************************************************
 *
 * @section Copyright
 *
 * This file is free software and is provided for example purposes. You may
 * use, copy, and modify within the terms and conditions of the license
 * agreement.
 *
 * This is licensed software for evaluation use, any use must strictly comply
 * with the evaluation license agreement provided with delivery of the
 * TouchGFX software.
 *
 * The evaluation license agreement can be seen on www.touchgfx.com
 *
 * @section Disclaimer
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Draupner Graphics A/S has
 * no obligation to support this software. Draupner Graphics A/S is providing
 * the software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Draupner Graphics A/S can not be held liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this software.
 *
 *****************************************************************************/
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
	#include "data.hpp"
	#include "FreeRTOS.h"
	#include "task.h"
	#include "queue.h"
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
#ifndef SIMULATOR
	struct message rx_mess;
	if(xQueueReceive(card_to_lcd, static_cast<void*>(&rx_mess), 0))
	{
		message_parser(&rx_mess);
	}
#endif

#ifdef SIMULATOR
	static int tick_counter = 0;
	tick_counter++;
	if(tick_counter == 300 * 2)
	{
		static const char *init_pin = "Enter PINCODE";
		touchgfx::Unicode::strncpy(dialogText, init_pin, TEXT_SIZE);
		toPincodeScreen();
	}
	else if(tick_counter == 600 * 2)
	{
		toMainScreen();
	}

	else if(tick_counter == 900 * 2)
	{
		dialogText[0] = 0;
		toStatusScreen();
		tick_counter = 0;
	}

#endif
}

void Model::pincodeEntered(int pincode)
{
	pin = pincode;

#ifndef SIMULATOR
	struct message pin_data = {
			.cmd = PINCODE,
			.data = static_cast<void*>(&pin)
	};

	xQueueSend(lcd_to_card, static_cast<void*>(&pin_data), 0);
#endif
}

void Model::pincodeScreenEntered()
{
	setDialogText(dialogText);
}

void Model::transactionScreenEntered()
{
	static const char *message = "Confirmation";
	touchgfx::Unicode::strncpy(dialogText, message, TEXT_SIZE);
	setDialogText(dialogText);
#ifndef SIMULATOR
	setCurrency(transaction->curr_name);
	setAddress(transaction->addr);
	setValue(transaction->value);
#endif

#ifdef SIMULATOR
	static char addr[43] = "0x123456789abCdEf1653abcEF098174eABcef1253";
	static char curr[] = "Bitcoin";
	setCurrency(curr);
	setAddress(addr);
	setValue(1);
#endif
}

void Model::statusScreenEntered()
{
	setDialogText(dialogText);
}

void Model::toMainScreen()
{
	modelListener->toMainScreen();
}

void Model::toStatusScreen()
{
	modelListener->toStatusScreen();
}

void Model::toPincodeScreen()
{
	modelListener->toPincodeScreen();
}

void Model::message_parser(struct message *message)
{
#ifndef SIMULATOR
	switch(message->cmd)
	{
		case TO_MAIN:
			toMainScreen();
			break;

		case INIT_PINCODE:
			toPincodeScreen();
			static const char *init_pin = "Init PINCODE";
			touchgfx::Unicode::strncpy(dialogText, init_pin, TEXT_SIZE);
			break;

		case WRONG_PINCODE:
			static const char *wrong_pin = "Wrong PINCODE";
			touchgfx::Unicode::strncpy(dialogText, wrong_pin, TEXT_SIZE);
			setDialogText(dialogText);
			break;

		case TO_STATUS:
			toStatusScreen();
			dialogText[0] = 0;
			break;

		case TRANSACTION_CONFIRMED:
			toStatusScreen();
			static const char *transaction_confirmed = "Transaction send";
			touchgfx::Unicode::strncpy(dialogText, transaction_confirmed, TEXT_SIZE);
			break;

		case TRANSACTION:
			toMainScreen();
			transaction = static_cast<struct transaction*>(message->data);
			break;
	}
#endif
}

void Model::setCurrency(char *currency)
{
	modelListener->setCurrency(currency);
}

void Model::setAddress(char *addr)
{
	modelListener->setAddress(addr);
}

void Model::setValue(double value)
{
	modelListener->setValue(value);
}

void Model::setDialogText(touchgfx::Unicode::UnicodeChar *text)
{
	modelListener->setDialogText(text);
}

void Model::cancelPressed()
{
	toStatusScreen();
	static const char *message = "Transaction was canceled";
	touchgfx::Unicode::strncpy(dialogText, message, TEXT_SIZE);

#ifndef SIMULATOR
	struct message mess = {
			.cmd = TRANSACTION_CANCELED
	};
	xQueueSend(lcd_to_card, static_cast<void*>(&mess), 0);
#endif
}

void Model::confirmPressed()
{
	toPincodeScreen();
	static const char *init_pin = "Enter PINCODE";
	touchgfx::Unicode::strncpy(dialogText, init_pin, TEXT_SIZE);
}



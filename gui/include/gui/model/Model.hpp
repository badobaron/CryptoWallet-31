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
#ifndef MODEL_HPP
#define MODEL_HPP

#include "data.hpp"
#include <touchgfx/Unicode.hpp>

class ModelListener;
using namespace touchgfx;

/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class Model
{
public:
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();

    void pincodeEntered(int pincode);
    void msEntered(Unicode::UnicodeChar *mnemonic);
    void pincodeScreenEntered();
    void transactionScreenEntered();
    void statusScreenEntered();
    void pinScreenEntered();

    void walletTransaction(struct transaction *trans);
    void setAddress(char *addr);
    void setValue(char *value);
    void setDialogText(touchgfx::Unicode::UnicodeChar *text);
    void setHeadText(touchgfx::Unicode::UnicodeChar *text);
    void setMnemonicSeed(Unicode::UnicodeChar *mnemonic);

    void toMainScreen();
    void toPincodeScreen();
    void toStatusScreen();
    void toPinScreen();
    void toInitScreen();

    void cancelPressed();
    void confirmPressed();
    void closePressed();

    void showPinKeyboard();
    void showMSKeyboard();
    void showMSWindow();
    void walletStatus(struct wallet_status *status);

    void clearWallet();
    void initWallet();
    void restoreWallet();
protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener* modelListener;

private:
    void message_parser(struct message *message);

    enum STATE
	{
    	PIN_ENTER,
		MS_ENTER,
		PIN_SET,
		MS_SET
	} pinScreenState;

	static const uint16_t MNEMONIC_SIZE = 123;
	static const uint16_t WORDS_NUM = 12;
	static const uint16_t STRING_LEN = 32;

    int pin;
    char mnemonicSeed[MNEMONIC_SIZE];
    struct transaction *transaction;
    static const uint16_t TEXT_SIZE = 123;
    touchgfx::Unicode::UnicodeChar tmpText[TEXT_SIZE];
    struct message rx_mess;
	struct message tx_mess;
};

#endif /* MODEL_HPP */

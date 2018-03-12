#ifndef PIN_CODE_VIEW_HPP
#define PIN_CODE_VIEW_HPP

#include <gui_generated/pin_code_screen/pin_codeViewBase.hpp>
#include <gui/pin_code_screen/pin_codePresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <mvp/View.hpp>
#include <gui/common/dialog.hpp>

class pin_codeView : public pin_codeViewBase
{
public:
    pin_codeView();
    virtual ~pin_codeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void pincodeEntered(int);
    void pincodeScreenEntered();
    void setDialogText(touchgfx::Unicode::UnicodeChar *text);
private:
    CustomKeyboard keyboard;
    Callback<pin_codeView, int> pincodeEnteredCallback;

    Dialog dialog;
};

#endif // PIN_CODE_VIEW_HPP

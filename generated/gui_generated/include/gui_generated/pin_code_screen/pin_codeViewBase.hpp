/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PIN_CODE_VIEW_BASE_HPP
#define PIN_CODE_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/pin_code_screen/pin_codePresenter.hpp>

class pin_codeViewBase : public touchgfx::View<pin_codePresenter>
{
public:
    pin_codeViewBase();
    virtual ~pin_codeViewBase() {}

protected:
    FrontendApplication& application() { 
        return *static_cast<FrontendApplication*>(Application::getInstance()); 
    }

private:

};

#endif // PIN_CODE_VIEW_BASE_HPP
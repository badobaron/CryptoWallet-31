/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef BLOCKED_VIEW_BASE_HPP
#define BLOCKED_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/blocked_screen/blockedPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class blockedViewBase : public touchgfx::View<blockedPresenter>
{
public:
    blockedViewBase();
    virtual ~blockedViewBase() {}

protected:
    FrontendApplication& application() { 
        return *static_cast<FrontendApplication*>(Application::getInstance()); 
    }

    /*
     * Member Declarations
     */
    touchgfx::Image background;
    touchgfx::TextArea blocked;

private:

};

#endif // BLOCKED_VIEW_BASE_HPP

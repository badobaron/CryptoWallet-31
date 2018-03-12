/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STARTUP_VIEW_BASE_HPP
#define STARTUP_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/startup_screen/startupPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>

class startupViewBase : public touchgfx::View<startupPresenter>
{
public:
    startupViewBase();
    virtual ~startupViewBase() {}
    virtual void afterTransition();

protected:
    FrontendApplication& application() { 
        return *static_cast<FrontendApplication*>(Application::getInstance()); 
    }

    /*
     * Member Declarations
     */
    touchgfx::Image background;
    touchgfx::FadeAnimator< touchgfx::Image > logo_png;
    touchgfx::FadeAnimator< touchgfx::TextArea > logo_text;

private:

    /*
     * Interaction Handlers
     */
    void show_logoEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Image>& comp);

    /*
     * Interaction Callback Declarations
     */
    touchgfx::Callback < startupViewBase, const touchgfx::FadeAnimator<touchgfx::Image>& >  show_logoEndedCallback;

};

#endif // STARTUP_VIEW_BASE_HPP
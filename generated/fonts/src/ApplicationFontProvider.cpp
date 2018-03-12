/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <touchgfx/InternalFlashFont.hpp>

#ifndef NO_USING_NAMESPACE_TOUCHGFX
using namespace touchgfx;
#endif

extern touchgfx::InternalFlashFont& getFont_Heebo_Regular_18_4bpp();
extern touchgfx::InternalFlashFont& getFont_RobotoCondensed_Regular_20_4bpp();
extern touchgfx::InternalFlashFont& getFont_RobotoCondensed_Regular_24_4bpp();
extern touchgfx::InternalFlashFont& getFont_RobotoCondensed_Regular_55_4bpp();
extern touchgfx::InternalFlashFont& getFont_Heebo_Regular_30_4bpp();
extern touchgfx::InternalFlashFont& getFont_Heebo_Thin_28_4bpp();
extern touchgfx::InternalFlashFont& getFont_Heebo_Regular_28_4bpp();
extern touchgfx::InternalFlashFont& getFont_Heebo_Thin_28_4bpp();
extern touchgfx::InternalFlashFont& getFont_Heebo_Regular_20_4bpp();

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId fontId)
{
  switch(fontId)
  {
    
    case Typography::TRANSACTION:
      return &(getFont_Heebo_Regular_18_4bpp());
    
    case Typography::KEYBOARD:
      return &(getFont_RobotoCondensed_Regular_20_4bpp());
    
    case Typography::MODE:
      return &(getFont_RobotoCondensed_Regular_24_4bpp());
    
    case Typography::LOGO:
      return &(getFont_RobotoCondensed_Regular_55_4bpp());
    
    case Typography::TRANSACTION_HEAD:
      return &(getFont_Heebo_Regular_30_4bpp());
    
    case Typography::LOGO_TEXT:
      return &(getFont_Heebo_Thin_28_4bpp());
    
    case Typography::BUTTON_TEXT:
      return &(getFont_Heebo_Regular_28_4bpp());
    
    case Typography::ENTERED:
      return &(getFont_Heebo_Thin_28_4bpp());
    
    case Typography::DIALOG:
      return &(getFont_Heebo_Regular_20_4bpp());
    
    default:
      return 0;
  }
}

//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#ifndef MK_SCROLLBAR_H_INCLUDED
#define MK_SCROLLBAR_H_INCLUDED

/* mk */
#include <Object/mkId.h>
#include <Object/String/mkString.h>
#include <Object/Util/mkUpdatable.h>
#include <Ui/mkUiForward.h>
#include <Ui/Widget/mkWidget.h>
#include <Ui/Widget/mkButton.h>
#include <Ui/Widget/mkSlider.h>
#include <Ui/Frame/mkStripe.h>

#include <memory>

namespace mk
{
	class MK_UI_EXPORT Scroller : public Slider, public Styled<Scroller>
	{
	public:
		Scroller(Dimension dim);

		void sliderStep(float offset, bool ended);

		using Styled<Scroller>::styleCls;
	};

	class MK_UI_EXPORT ScrollerX : public Scroller
	{
	public:
		ScrollerX();
	};

	class MK_UI_EXPORT ScrollerY : public Scroller
	{
	public:
		ScrollerY();
	};

	class MK_UI_EXPORT ScrollerKnobX : public SliderKnob, public Styled<ScrollerKnobX>
	{
	public:
		ScrollerKnobX();

		using Styled<ScrollerKnobX>::styleCls;
	};

	class MK_UI_EXPORT ScrollerKnobY : public SliderKnob, public Styled<ScrollerKnobY>
	{
	public:
		ScrollerKnobY();

		using Styled<ScrollerKnobY>::styleCls;
	};

	class MK_UI_EXPORT ScrollUp : public Button, public Styled<ScrollUp>
	{
	public:
		ScrollUp(const Trigger& trigger);

		using Styled<ScrollUp>::styleCls;
	};

	class MK_UI_EXPORT ScrollDown : public Button, public Styled<ScrollDown>
	{
	public:
		ScrollDown(const Trigger& trigger);

		using Styled<ScrollDown>::styleCls;
	};

	class MK_UI_EXPORT _I_ Scrollbar : public Sheet, public Typed<Scrollbar>, public Styled<Scrollbar>
	{
	public:
		Scrollbar(Stripe* sheet);
		~Scrollbar();

		void show();
		void hide();
	
		void scrollup();
		void scrolldown();
		void scroll(float offset);
		void nextFrame(size_t tick, size_t delta);

		using Typed<Scrollbar>::cls;

	protected:
		Stripe* mSheet;
		Button* mUp;
		Scroller* mScroller;
		Button* mDown;
	};
}

#endif // MK_SCROLLBAR_H_INCLUDED

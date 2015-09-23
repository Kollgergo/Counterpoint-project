\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef alto
	{
	e4	b4	g'4	b'4	b'2	d'4	c'4	b8	d'8
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef alto
	{
	c'4	b4	eis4	b'4	d2	d4	e'4	e'8	d'8
	\bar "|."
	}
}
>>
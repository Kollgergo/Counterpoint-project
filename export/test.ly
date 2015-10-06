\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	e''4	b'4	c''4	b'4	c''4
	\bar "|."
	}
}
>>
\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	c'4	e'4	c'4	e'4	a'2	g'2
	\bar "|."
	}
}
>>
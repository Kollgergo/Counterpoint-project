\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	a2	c'2	b2	d'2	c'2	e'2	f'2	e'2	d'2	c'2	b2	a1
	\bar "|."
	}
}
>>
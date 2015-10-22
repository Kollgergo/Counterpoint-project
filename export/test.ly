\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	a2	b2	c'2	d'2	c'''2	b''2	a''2	g''2
	\bar "|."
	}
}
>>
\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	d'2	f'2	e'2	d'2	g'2	f'2	a'2	g'2	f'2	e'2	d'1
	\bar "|."
	}
}
>>
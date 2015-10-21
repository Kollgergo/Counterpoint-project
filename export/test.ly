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
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	a'2	e'2	g'2	f'2	e'2	c''2	a'2	b'2	b'2	a'2	gis'2	a'1
	\bar "|."
	}
}
>>
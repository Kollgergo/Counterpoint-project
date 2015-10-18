\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	c'4	e'4	c'4	e'4	g'2	g'2	c'4	e'4	c'4	e'4	g'2	g'2	c''4	b'4	a'4	g'4	f'2	a'2	g'4	f'4	e'4	d'4	c'2	c'2
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef bass
	{
	c4	c4	c4	c4	g,4	g4	g,4	g4	c4	c4	c4	c4	g,4	g4	g,4	g4	c4	c4	c4	c4	f,4	f,4	f,4	f,4	g,4	g,4	a,4	b,4	c2	c,2
	\bar "|."
	}
}
>>
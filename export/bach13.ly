\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	g'4	c''4	g'4	a'4	g'4	f'4	e'4	e'4	g'4	g'4	f'4	e'4	d'4	d'8	c'8	c'2
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	c'4	c'4	c'4	c'4	c'4	b4	c'4	c'4	c'4	c'8	b8	a8	b8	c'4	c'4	b4	c'2
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef bass
	{
	e4	e8	f8	g4	f8	e8	d8	c8	d4	c4	c4	e4	e4	f4	g4	a4	g8	f8	e2
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef bass
	{
	c4	a,4	e,4	f,4	g,4	g,4	c,4	c,4	c4	c4	d4	e4	f8	d8	g8	g,8	c2
	\bar "|."
	}
}
>>
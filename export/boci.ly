\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	c'4	e'4	c'4	e'4	ges'2	ges'2
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef bass
	{
	c4	c4	c4	c4	g,4	g4	g,4	g4
	\bar "|."
	}
}
>>
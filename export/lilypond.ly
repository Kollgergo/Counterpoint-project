\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	c'4	e'4	c'4	e'4	g'2	g'2
	\bar "|."
	}
}\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef alto
	{
	c'4	e'4	c'4	e'4	g'2	g'2
	\bar "|."
	}
}\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef tenor
	{
	c'4	e'4	c'4	e'4	g'2	g'2
	\bar "|."
	}
}\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef bass
	{
	c4	e4	c4	e4	g2	g2
	\bar "|."
	}
}>>
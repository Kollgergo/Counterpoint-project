\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef alto
	{
	d4	b4	g'4	b'4	b'2	g2
	\bar "|."
	}
}
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef alto
	{
	c'4	b4	d4	b'4	d2	d2
	\bar "|."
	}
}
>>
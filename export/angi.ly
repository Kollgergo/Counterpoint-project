\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	g'4	f'4	g'4	b'4	f''2	c''2
	\bar "|."
	}
}
>>
\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	g'4	a'4	g'4	b'4	f''2	a'2
	\bar "|."
	}
}
>>
\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	g'4	g'4	g'4	g'4	g'2	g'2
	\bar "|."
	}
}
>>
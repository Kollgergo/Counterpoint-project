\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	\key a \major
	{
	a'4	b'4	cis''4	d''4	e''4	fis''4	gis''4	a''4
	\bar "|."
	}
}
>>
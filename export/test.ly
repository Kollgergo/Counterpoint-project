\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	fis'4	gis'4	cis''4	eis'4
	\bar "|."
	}
}
>>
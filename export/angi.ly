\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	gis'4	ges'8	r4	r4	r2	fis'2
	\bar "|."
	}
}
>>
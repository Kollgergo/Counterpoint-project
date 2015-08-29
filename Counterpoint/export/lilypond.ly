\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	{
	 c'1	 e'2	 c'4	 e'8	 r1	 r2	 r4	 r8
\bar "|."
	}
}>>
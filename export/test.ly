\version "2.16.0"
\header{}
\new StaffGroup << 
\new Staff{
	\override Staff.TimeSignature #'stencil = ##f
	\set Score.timing = ##f
	\clef treble
	{
	cis'4	c'4	cis'4	d'4	d'4	dis'4	e'4	e'4	eis'4	fes'4	f'4	fis'4	ges'4	g'4	gis'4	aes'4	a'4	ais'4	bes'4	b'4	bis'4	ces''4	c''4	cis''4	des''4	d''4	dis''4	ees''4	e''4	eis''4	fes''4	f''4	fis''4	ges''4	g''4	gis''4	aes''4	a''4	ais''4
	\bar "|."
	}
}
>>
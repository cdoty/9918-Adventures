FontColor:
	incbin "..\Graphics\Inverted\Font.col"
FontColorEnd:
FontColorSize = FontColorEnd - FontColor

FontPattern:
	incbin "..\Graphics\Font.pat"
FontPatternEnd:

FontPatternSize	= FontPatternEnd - FontPattern

Title1Screen:
	incbin "..\Graphics\Title1.mgb"
Title1ScreenEnd:

Title1ScreenSize	= Title1ScreenEnd - Title1Screen

Title2Screen:
	incbin "..\Graphics\Title2.mgb"
Title2ScreenEnd:

Title2ScreenSize	= Title2ScreenEnd - Title2Screen

Title3Screen:
	incbin "..\Graphics\Title3.mgb"
Title3ScreenEnd:

Title3ScreenSize	= Title3ScreenEnd - Title3Screen

GameColor:
	incbin "..\Graphics\Inverted\Game.col"
GameColorEnd:

GameColorSize	= GameColorEnd - GameColor

GamePattern:
	incbin "..\Graphics\Game.pat"
GamePatternEnd:

GamePatternSize	= GamePatternEnd - GamePattern

GameScreen:
	incbin "..\Graphics\Game.mgb"
GameScreenEnd:

GameScreenSize	= GameScreenEnd - GameScreen

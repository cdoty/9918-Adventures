FontPatternStart:
	.binfile "..\Graphics\Font.pat"
FontPatternEnd:

	.set FontPatternSize	= FontPatternEnd - FontPatternStart

FontColorStart:
	.binfile "..\Graphics\Font.col"
FontColorEnd:

	.set FontColorSize	= FontColorEnd - FontColorStart

Title1Start:
	.binfile "..\Graphics\Title1.mgb"
Title1End:

	.set Title1Size	= Title1End - Title1Start

Title2Start:
	.binfile "..\Graphics\Title2.mgb"
Title2End:

	.set Title2Size	= Title2End - Title2Start

Title3Start:
	.binfile "..\Graphics\Title3.mgb"
Title3End:

	.set Title3Size	= Title3End - Title3Start

GamePatternStart:
	.binfile "..\Graphics\Game.pat"
GamePatternEnd:

	.set GamePatternSize = GamePatternEnd - GamePatternStart

GameColorStart:
	.binfile "..\Graphics\Game.col"
GameColorEnd:

	.set GameColorSize = GameColorEnd - GameColorStart

GameStart:
	.binfile "..\Graphics\Game.mgb"
GameEnd:

	.set GameSize = GameEnd - GameStart

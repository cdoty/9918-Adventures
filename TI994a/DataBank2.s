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

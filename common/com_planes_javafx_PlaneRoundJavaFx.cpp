#include "com_planes_javafx_PlaneRoundJavaFx.h"
#include "planeround.h"

PlaneRound* global_Round = nullptr;
GuessPoint::Type global_Guess_Result = GuessPoint::Miss;
PlayerGuessReaction global_Player_Guess_Reaction;

JNIEXPORT void JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_createPlanesRound
(JNIEnv *, jobject)
{
	if (global_Round)
		return;
	global_Round = new PlaneRound(10, 10, 3);
	global_Round->initRound();
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getRowNo
(JNIEnv *, jobject)
{
	return global_Round->getRowNo();
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getColNo
(JNIEnv *, jobject)
{
	return global_Round->getColNo();
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getPlaneNo
(JNIEnv *, jobject)
{
	return global_Round->getPlaneNo();
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getPlaneSquareType
(JNIEnv *, jobject, jint i, jint j, jint isComputer)
{
	
	return global_Round->getPlaneSquareType(i, j, isComputer > 0 ? true : false);
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_movePlaneLeft
(JNIEnv *, jobject, jint idx)
{
	return global_Round->movePlaneLeft(int(idx)) ? 1 : 0;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_movePlaneRight
(JNIEnv *, jobject, jint idx)
{
	return global_Round->movePlaneRight(int(idx)) ? 1 : 0;
}


JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_movePlaneUpwards
(JNIEnv *, jobject, jint idx)
{
	return global_Round->movePlaneUpwards(int(idx)) ? 1 : 0;
}


JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_movePlaneDownwards
(JNIEnv *, jobject, jint idx)
{
	return global_Round->movePlaneDownwards(int(idx)) ? 1 : 0;
}


JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_rotatePlane
(JNIEnv *, jobject, jint idx)
{
	return global_Round->rotatePlane(int(idx)) ? 1 : 0;
}

JNIEXPORT void JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_doneClicked
(JNIEnv *, jobject)
{
	global_Round->doneEditing();
}

JNIEXPORT void JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess
(JNIEnv *, jobject, jint row, jint col)
{
	global_Round->playerGuessIncomplete(int(row), int(col), global_Guess_Result, global_Player_Guess_Reaction);
}

JNIEXPORT jboolean JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1RoundEnds
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_RoundEnds;
}

JNIEXPORT jboolean JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1IsPlayerWinner
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_isPlayerWinner;
}

JNIEXPORT jboolean JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1ComputerMoveGenerated
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_ComputerMoveGenerated;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoPlayerMoves
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_playerMoves;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoPlayerHits
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_playerHits;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoPlayerMisses
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_playerMisses;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoPlayerDead
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_playerDead;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoPlayerWins
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_playerWins;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoComputerMoves
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_computerMoves;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoComputerHits
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_computerHits;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoComputerMisses
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_computerMisses;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoComputerDead
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_computerDead;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_playerGuess_1StatNoComputerWins
(JNIEnv *, jobject)
{
	return global_Player_Guess_Reaction.m_GameStats.m_computerWins;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getPlayerGuessesNo
(JNIEnv *, jobject)
{
	return global_Round->getPlayerGuessesNo();
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getPlayerGuessRow
(JNIEnv *, jobject, jint idx)
{
	return global_Round->getPlayerGuess(idx).m_row;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getPlayerGuessCol
(JNIEnv *, jobject, jint idx)
{
	return global_Round->getPlayerGuess(idx).m_col;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getPlayerGuessType
(JNIEnv *, jobject, jint idx)
{
	return int(global_Round->getPlayerGuess(idx).m_type);
}


JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getComputerGuessesNo
(JNIEnv *, jobject)
{
	return global_Round->getComputerGuessesNo();
}


JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getComputerGuessRow
(JNIEnv *, jobject, jint idx)
{
	return global_Round->getComputerGuess(idx).m_row;
}


JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getComputerGuessCol
(JNIEnv *, jobject, jint idx)
{
	return global_Round->getComputerGuess(idx).m_col;
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getComputerGuessType
(JNIEnv *, jobject, jint idx)
{
	return int(global_Round->getComputerGuess(idx).m_type);
}

JNIEXPORT void JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_roundEnds
(JNIEnv *, jobject)
{
	global_Round->roundEnds();
}

JNIEXPORT void JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_initRound
(JNIEnv *, jobject) {
	global_Round->initRound();
	global_Player_Guess_Reaction.m_GameStats.reset();
}

JNIEXPORT jint JNICALL Java_com_planes_javafx_PlaneRoundJavaFx_getGameStage
(JNIEnv *, jobject) {
	return global_Round->getCurrentStage();
}
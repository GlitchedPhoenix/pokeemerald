ConvenienceRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ConvenienceRoom_EventScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ConvenienceRoom_EventScript_OnResume
	.byte 0

ConvenienceRoom_EventScript_OnTransition::
	map_script_2 VAR_TEMP_1, 0, ConvenienceRoom_EventScript_SetUpExit
	.2byte 0

ConvenienceRoom_EventScript_OnResume::
	map_script_2 VAR_TEMP_1, 0, ConvenienceRoom_EventScript_SetUpExit
	.2byte 0

ConvenienceRoom_EventScript_SetUpExit::
	switch VAR_CONVENIENCE_ROOM
	case 1, ConvenienceRoom_EventScript_ExitLilycove
	case 2, ConvenienceRoom_EventScript_ExitFallarbor
	case 3, ConvenienceRoom_EventScript_ExitVerdanturf
	goto ConvenienceRoom_EventScript_ExitSlateport
	end

ConvenienceRoom_Script_Azumarill::
	lock
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ConvenienceRoom_Text_Azumarill
	closemessage
	applymovement 8, Common_Movement_FaceUp
	waitmovement 0
	delay 32
	msgbox ConvenienceRoom_Text_CookingEggs
	release
	end

ConvenienceRoom_EventScript_Harpy_ExplainRoom::
	msgbox ConvenienceRoom_Text_Harpy_ExplainRoom
	setflag FLAG_CONVENIENCE_EXPLAINED
	release
	end

ConvenienceRoom_Text_Harpy_ExplainRoom:
	.string "Oh! You must be new here.\p"
	.string "Welcome to the CONVENIENCE\n"
	.string "ROOM!\p"
	.string "By popular demand, we gathered up\n"
	.string "several specialists around HOENN\l"
	.string "and paid them to move in here.\p"
	.string "KIRLIA here automatically warps\n"
	.string "you here from SLATEPORT, LILYCOVE,\l"
	.string "FALLARBOR, and VERDANTURF,\l"
	.string "respectively.\p"
	.string "If you come back later, I can\n"
	.string "also help you with high-speed\l"
	.string "POKéMON training whenever you\l"
	.string "like!\p"
	.string "Please enjoy your stay.$"

ConvenienceRoom_EventScript_Harpy_ComeBackLater::
	msgbox ConvenienceRoom_Text_Harpy_ComeBackLater
	release
	end

ConvenienceRoom_Text_Harpy_ComeBackLater:
	.string "Welcome to the CONVENIENCE\n"
	.string "ROOM!\p"
	.string "Unfortunately, training is\n"
	.string "not available just yet.\l"
	.string "Please come back later.$"

ConvenienceRoom_EventScript_Harpy::
	lock
	faceplayer
	goto_if_unset FLAG_CONVENIENCE_EXPLAINED, ConvenienceRoom_EventScript_Harpy_ExplainRoom
	goto_if_unset FLAG_BADGE05_GET, ConvenienceRoom_EventScript_Harpy_ComeBackLater
	call_if_unset FLAG_CONVENIENCE_WARNING, ConvenienceRoom_EventScript_Harpy_BlisseyCheck
	msgbox ConvenienceRoom_Text_Harpy_WouldYouLikeToTrain, MSGBOX_YESNO
	switch VAR_RESULT
	case 1, ConvenienceRoom_EventScript_StartFight
	release
	end

ConvenienceRoom_EventScript_Harpy_BlisseyCheck::
	call_if_set FLAG_SYS_GAME_CLEAR, ConvenienceRoom_EventScript_Harpy_Warning
	return

ConvenienceRoom_EventScript_Harpy_Warning::
	msgbox ConvenienceRoom_Text_Harpy_Warning
	setflag FLAG_CONVENIENCE_WARNING
	return

ConvenienceRoom_Text_Harpy_Warning:
	.string "I should warn you.\p"
	.string "The training program has been\n"
	.string "upgraded, and it is HIGHLY\l"
	.string "recommended you bring TOXIC.$"

ConvenienceRoom_EventScript_StartFight::
	goto_if_unset FLAG_SYS_GAME_CLEAR, ConvenienceRoom_EventScript_StartChanseyFight
	trainerbattle_no_intro TRAINER_BLISSEY, ConvenienceRoom_Text_Harpy_Defeat
	msgbox ConvenienceRoom_Text_Harpy_ThereYouGo
	release
	end

ConvenienceRoom_EventScript_StartChanseyFight::
	trainerbattle_no_intro TRAINER_CHANSEY, ConvenienceRoom_Text_Harpy_Defeat
	msgbox ConvenienceRoom_Text_Harpy_ThereYouGo
	release
	end

ConvenienceRoom_Text_Harpy_WouldYouLikeToTrain:
	.string "Welcome to the CONVENIENCE\n"
	.string "ROOM!\p"
	.string "Would you like to train?\p"
	.string "You should bring a POKéMON with\n"
	.string "TOXIC in your party.$"

ConvenienceRoom_Text_Harpy_Defeat:
	.string "Excellent! Your POKéMON is\n"
	.string "looking much stronger now!$"

ConvenienceRoom_Text_Harpy_ThereYouGo:
	.string "Come back anytime!$"

ConvenienceRoom_EventScript_ExitSlateport::
	setdynamicwarp MAP_SLATEPORT_CITY, 6
	end

ConvenienceRoom_EventScript_ExitLilycove::
	setdynamicwarp MAP_LILYCOVE_CITY, 7
	end

ConvenienceRoom_EventScript_ExitFallarbor::
	setdynamicwarp MAP_FALLARBOR_TOWN, 4
	end

ConvenienceRoom_EventScript_ExitVerdanturf::
	setdynamicwarp MAP_VERDANTURF_TOWN, 5
	end

ConvenienceRoom_EventScript_Kirlia::
	lock
	msgbox ConvenienceRoom_Text_KirliaBusy
	release
	end

ConvenienceRoom_Text_KirliaBusy::
	.string "It's a KIRLIA!\p"
	.string "She seems to be concentrating...$"

ConvenienceRoom_Text_Azumarill::
	.string "Azu!$"

ConvenienceRoom_Text_CookingEggs::
	.string "It's cooking eggs...$"

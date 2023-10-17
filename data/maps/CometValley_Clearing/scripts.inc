CometValley_Clearing_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CometValley_Clearing_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CometValley_Clearing_OnResume
	.byte 0

CometValley_Clearing_OnTransition:
	call_if_set FLAG_CAUGHT_JIRACHI, CometValley_EventScript_HideJirachi
	call_if_unset FLAG_CAUGHT_JIRACHI, CometValley_EventScript_TryShowJirachi
	end
	
CometValley_EventScript_HideJirachi::
	setflag FLAG_HIDE_JIRACHI
	return

CometValley_EventScript_TryShowJirachi::
	goto_if_set FLAG_DEFEATED_JIRACHI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_JIRACHI
	call_if_eq VAR_JIRACHI_STATE, 3, CometValley_EventScript_MoveJirachi
	return

CometValley_EventScript_MoveJirachi::
	setobjectxyperm 1, 30, 21
	return

CometValley_Clearing_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CometValley_EventScript_TryRemoveJirachi
	end

CometValley_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject 1
	return

CometValley_EventScript_DiscImpression::
	lock
	msgbox CometValley_Text_DiscShapeHere, MSGBOX_DEFAULT
	checkitem ITEM_MYSTERY_DISC
	goto_if_eq VAR_RESULT, TRUE, CometValley_EventScript_AskPlaceDisc
	release
	end

CometValley_EventScript_AskPlaceDisc::
	msgbox CometValley_Text_TMMightFit, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CometValley_EventScript_PlaceDisc
	case NO, Common_EventScript_NopReturn
	case MULTI_B_PRESSED, Common_EventScript_NopReturn

CometValley_EventScript_PlaceDisc::
	setflag FLAG_PLACED_MYSTERY_DISC
	msgbox CometValley_Text_YouPlaceTheTM
	removeitem ITEM_MYSTERY_DISC
	setvar VAR_JIRACHI_STATE, 1
	release
	end

CometValley_EventScript_JirachiWarning::
	lock
	msgbox CometValley_Text_JirachiWarning, MSGBOX_DEFAULT
	setvar VAR_JIRACHI_STATE, 2
	release
	end

CometValley_EventScript_JirachiFlyDown::
	addobject 1
	setobjectxy 1, 30, 10
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement 1, CometValley_Movement_JirachiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_JIRACHI_STATE, 3
	setvar VAR_LAST_TALKED, 1

CometValley_EventScript_JirachiTalkTo::
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	goto CometValley_EventScript_JirachiEncounter

CometValley_EventScript_JirachiEncounter::
	seteventmon SPECIES_JIRACHI, 75
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CometValley_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CometValley_EventScript_RanFromJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CometValley_EventScript_RanFromJirachi
	setflag FLAG_CAUGHT_JIRACHI
	release
	end
	
CometValley_EventScript_DefeatedJirachi::
	setflag FLAG_DEFEATED_JIRACHI
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

CometValley_EventScript_RanFromJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

CometValley_Movement_JirachiApproach:
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

CometValley_Text_JirachiWarning:
	.string "You think you can see something flying\n"
	.string "towards you, off in the distance.$"

CometValley_Text_DiscShapeHere:
	.string "There's a circular impression on the\n"
	.string "the surface of this rock.$"

CometValley_Text_TMMightFit:
	.string "The MYSTERY DISC might fit here.\n"
	.string "Place it on the rock?$"

CometValley_Text_YouPlaceTheTM:
	.string "You placed the MYSTERY DISC into the\n"
	.string "slot on the rock. \p"
	.string "...\p"
	.string "...\p"
	.string "Nothing happened...$"

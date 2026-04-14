Route123_HiddenGrotto_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_HiddenGrotto_OnTransition
	.byte 0

Route123_HiddenGrotto_OnTransition:
	call_if_eq VAR_ROAMER_POKEMON, 0, Route123_HiddenGrotto_EventScript_SetUpLatias
	call_if_ne VAR_ROAMER_POKEMON, 0, Route123_HiddenGrotto_EventScript_SetUpLatios
	end

Route123_HiddenGrotto_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

Route123_HiddenGrotto_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

HiddenGrotto_EventScript_Warning::
	lock
	msgbox HiddenGrotto_Text_Warning
	setvar VAR_ROAMER_EVENT_TRIGGER, 2
	release
	end

HiddenGrotto_EventScript_SpawnLati::
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON
	special InitRoamer
	specialvar VAR_0x8005, GetRoamerShininess
	switch VAR_0x8005
	case TRUE, HiddenGrotto_EventScript_LoadShiny
	goto HiddenGrotto_EventScript_SpawnLati2
	end

HiddenGrotto_EventScript_LoadShiny::
	goto_if_eq VAR_ROAMER_POKEMON, 0, Route123_HiddenGrotto_EventScript_LoadShinyLatias
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHINY_LATIOS
	goto HiddenGrotto_EventScript_SpawnLati2

Route123_HiddenGrotto_EventScript_LoadShinyLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHINY_LATIAS
	goto HiddenGrotto_EventScript_SpawnLati2

HiddenGrotto_EventScript_PlayShinySFX::
	setflag FLAG_SHOW_SHINY_PIC
	playse SE_SHINY
	waitse
	return

HiddenGrotto_EventScript_SpawnLati2::
	special SpawnCameraObject
	addobject LOCALID_ROUTE123_LATI
	applymovement LOCALID_CAMERA, HiddenGrotto_Movement_CameraPanUp
	waitmovement 0
	applymovement LOCALID_ROUTE123_LATI, HiddenGrotto_Movement_LatiApproach2
	waitmovement 0
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	call_if_eq VAR_0x8005, TRUE, HiddenGrotto_EventScript_PlayShinySFX
	applymovement LOCALID_CAMERA, HiddenGrotto_Movement_CameraPanDown
	applymovement LOCALID_ROUTE123_LATI, HiddenGrotto_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	copyvar VAR_0x8006, VAR_TEMP_4
	showmonpic VAR_0x8006, 10, 3
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	waitbuttonpress
	hidemonpic
	copyvar VAR_0x8004, VAR_0x8006
	special SetSeenMon
	clearflag FLAG_SHOW_SHINY_PIC
	playse SE_LEDGE
	applymovement LOCALID_ROUTE123_LATI, HiddenGrotto_Movement_LatiPrep
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE123_LATI, HiddenGrotto_Movement_LatiPrep
	waitmovement 0
	delay 50
	playse SE_THUNDER
	applymovement LOCALID_ROUTE123_LATI, HiddenGrotto_Movement_LatiTakeoff
	delay 16
	playse SE_M_CONFUSE_RAY
	applymovement LOCALID_PLAYER, HiddenGrotto_Movement_PlayerSpin
	waitmovement 0
	removeobject LOCALID_ROUTE123_LATI
	setvar VAR_ROAMER_EVENT_TRIGGER, 3
	release
	end

HiddenGrotto_Movement_LatiPrep:
	jump_in_place_down
	step_end

HiddenGrotto_Movement_LatiTakeoff:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

HiddenGrotto_Movement_PlayerSpin:
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_16
	face_down
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end

HiddenGrotto_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

HiddenGrotto_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

HiddenGrotto_Movement_LatiApproach2:
	walk_down
	walk_down
	walk_down
	step_end

HiddenGrotto_Movement_LatiApproach:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

HiddenGrotto_Text_Warning:
	.string "You feel eyes watching you...\p"
	.string "It may be wise to {COLOR RED}{SHADOW LIGHT_RED}{PLAY_SE}{SE_SHINY}save.$"

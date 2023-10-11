.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9
.set LOCALID_WALLY, 11

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	textcolor 8
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	textcolor 6
	msgbox MeteorFalls_1F_1R_Text_Wally1, MSGBOX_DEFAULT
	textcolor 8
	msgbox MeteorFalls_1F_1R_Text_WhoCares, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_EFFECTIVE
	applymovement LOCALID_WALLY, Common_Movement_GetPushedBackwards
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WhoAreYou, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MeteorFalls_1F_1R_EventScript_YouBrendan
	call_if_eq VAR_RESULT, FEMALE, MeteorFalls_1F_1R_EventScript_YouMay
	closemessage
	applymovement LOCALID_WALLY, Common_Movement_FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	textcolor 6
	msgbox MeteorFalls_1R_Text_WhatAreYouDoingHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer1
	waitmovement 0
	applymovement LOCALID_WALLY, MeteorFalls_1F_1R_Movement_GetPushedLeft
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer2
	waitmovement 0
	textcolor 8
	msgbox MeteorFalls_1F_1R_Text_YouThink, MSGBOX_DEFAULT
	textcolor 15
	msgbox MeteorFalls_1F_1R_Text_HoldIt, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_ExclamationMark
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_FaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BullyingKids, MSGBOX_DEFAULT
	closemessage
	textcolor 8
	msgbox MeteorFalls_1F_1R_Text_OfAllThe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	textcolor 15
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	textcolor 8
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	textcolor 15
	msgbox MeteorFalls_1F_1R_Text_YeahIKnow, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	applymovement LOCALID_WALLY, MeteorFalls_1F_1R_Movement_WallyApproachPlayer
	waitmovement 0
	textcolor 6
	msgbox MeteorFalls_1F_1R_Text_WallySorry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRightThenLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WallyTakeThis, MSGBOX_DEFAULT
	textcolor 2
	giveitem ITEM_HM03
	textcolor 6
	msgbox MeteorFalls_1F_1R_Text_WallyIllGetStronger, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, MeteorFalls_1F_1R_Movement_WallyExit
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WallyWillBeEnough, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLY, MeteorFalls_1F_1R_Movement_WallyExit
	waitmovement 0
	removeobject LOCALID_WALLY
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

Common_Movement_WalkInPlaceFasterRightThenLeft::
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	step_end

MeteorFalls_1F_1R_Movement_WallyExit::
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1R_Text_WhatAreYouDoingHere::
	.string "{PLAYER}?! W-What are you doing here?$"

MeteorFalls_1F_1R_EventScript_YouBrendan::
	msgbox MeteorFalls_1F_1R_Text_YouBrendan, MSGBOX_DEFAULT
	return

MeteorFalls_1F_1R_EventScript_YouMay::
	msgbox MeteorFalls_1F_1R_Text_YouMay, MSGBOX_DEFAULT
	return

MeteorFalls_1F_1R_Movement_WallyApproachPlayer::
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Text_WallySorry:
	.string "WALLY: Sorry you got wrapped up in all\n"
	.string "this, {PLAYER}.\p"
	.string "I just heard that the professor was\n"
	.string "in trouble, and I had to do something.\p"
	.string "B-but it looks like I kind of...dropped\n"
	.string "the b-ball, ha...$"

MeteorFalls_1F_1R_Text_WallyTakeThis:
	.string "I...went back home while my folks were\n"
	.string "sleeping to get some of my stuff, but\l"
	.string "I accidentally grabbed this on the way\l"
	.string "out. It's a disc that your POKéMON\l"
	.string "can use to learn SURF.\p"
	.string "I-If it's any help to you, then\n"
	.string "please take it.$"

MeteorFalls_1F_1R_Text_WallyIllGetStronger:
	.string "...\p"
	.string "I am going to get stronger, together\n"
	.string "with KIRLIA. A-And when I do, I'll\l"
	.string "challenge you again, {PLAYER}, and win!\p"
	.string "...$"

MeteorFalls_1F_1R_Text_WallyWillBeEnough:
	.string "But...\p"
	.string "Will me and KIRLIA really be enough?$"

Common_Movement_GetPushedBackwards::
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer1:
	walk_up
	step_end

MeteorFalls_1F_1R_Movement_GetPushedLeft:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer2:
	walk_up
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Hehehe!\p"
	.string "You're a tenacious little punk,\n"
	.string "aren't you?\p"
	.string "What made you think that you and\n"
	.string "your pet ballerina would be enough\l"
	.string "to beat me?$"

MeteorFalls_1F_1R_Text_YouThink::
	.string "What, are you also here for the\n"
	.string "professor? You kids need to learn\l"
	.string "how to keep your nose out of\l"
	.string "other people's business!$"

MeteorFalls_1F_1R_Text_Wally1:
	.string "WALLY: I-It's KIRLIA...$"

MeteorFalls_1F_1R_Text_WhoCares:
	.string "Oh, it's a KIRLIA, is it? Hehe...\n"
	.string "Let me give you some advice, kid.\p"
	.string "It's gonna take you a bit more than\n"
	.string "that if you're shooting to win.$"

MeteorFalls_1F_1R_Text_WhoAreYou:
	.string "Eh?\p"
	.string "And who in the blazes are you?$"

MeteorFalls_1F_1R_Text_YouBrendan:
	.string "Yeah, you with the white hair!$"

MeteorFalls_1F_1R_Text_YouMay:
	.string "Yeah, you with the green do-rag!$"

MeteorFalls_1F_1R_Text_HoldIt:
	.string "???: Hold it!$"

MeteorFalls_1F_1R_Text_BullyingKids:
	.string "ARCHIE: Bullying children, eh? TEAM\n"
	.string "MAGMA really doesn't have any line\l"
	.string "it won't cross, does it?$"

MeteorFalls_1F_1R_Text_OfAllThe:
	.string "Ugh, of all the...$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Nice of you to join us, ARCHIE.\n"
	.string "I was just telling these lost kids\l"
	.string "why they shouldn't be snooping\l"
	.string "around in old caves.\p"
	.string "Now if you don't have anything to\n"
	.string "add, we were just on our way out!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous cult of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "it's in the name of land expansion.\p"
	.string "We at TEAM AQUA want to preserve the\n"
	.string "oceans, making us their sworn enemy.$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "Boss, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_YeahIKnow::
	.string "ARCHIE: Yeah, yeah, I know!$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "We've got to get moving.\p"
	.string "We believe their next move will be\n"
	.string "at MT. CHIMNEY. Join us there if you\l"
	.string "really want to help. Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me and took my\n"
	.string "METEORITE away. Then that boy\p"
	.string "shows up to rescue me, but loses,\n"
	.string "and now there's another gang called\p"
	.string "TEAM AQUA...\p"
	.string "Yeesh, I need some coffee...\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: That TEAM MAGMA…\p"
	.string "What are they planning to do with\n"
	.string "the METEORITE?$"

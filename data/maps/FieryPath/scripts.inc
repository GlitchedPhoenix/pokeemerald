FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FortuneTeller_IntroLeft::
	lock
	applymovement LOCALID_FORTUNE_TELLER, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FORTUNE_TELLER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_FORTUNE_TELLER, FieryPath_FTWalkDownLeft
	waitmovement 0
	goto FortuneTeller_Intro
	end

FortuneTeller_IntroMiddle::
	lock
	applymovement LOCALID_FORTUNE_TELLER, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FORTUNE_TELLER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_FORTUNE_TELLER, FieryPath_FTWalkDownMiddle
	waitmovement 0
	goto FortuneTeller_Intro
	end

FortuneTeller_IntroRight::
	lock
	applymovement LOCALID_FORTUNE_TELLER, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FORTUNE_TELLER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_FORTUNE_TELLER, FieryPath_FTWalkDownRight
	waitmovement 0
	goto FortuneTeller_Intro
	end

FortuneTeller_Intro::
	msgbox FortuneTeller_Text_Greetings
	closemessage
	special HealPlayerParty
	trainerbattle_no_intro TRAINER_FORTUNE_TELLER, FortuneTeller_Text_Defeat
	msgbox FortuneTeller_Text_LookInYourEyes
	closemessage
	giveitem ITEM_EMERALD_MAIL, 1
	msgbox FortuneTeller_Text_ShowMe
	closemessage
	applymovement LOCALID_FORTUNE_TELLER, FieryPath_FTWalkAway
	waitmovement 0
	removeobject LOCALID_FORTUNE_TELLER
	setflag FLAG_HIDE_FORTUNE_TELLER_FIERY_PATH
	clearflag FLAG_HIDE_FORTREE_FT
	setvar VAR_FORTUNE_TELLER_STATE, 1
	setvar VAR_ARTIFACT_CAP, 1
	release
	end

FortuneTeller_Text_Greetings:
	.string "Oh, hello there.\p"
	.string "I'm sorry to impose, but would you\n"
	.string "indulge me a short battle?\p"
	.string "Excellent! Onwards!$"

FortuneTeller_Text_LookInYourEyes:
	.string "Thank you very much. Now, could\n"
	.string "I get a good look at your eyes?\p"
	.string "...\p"
	.string "Hm...I see...\p"
	.string "Yes, they glitter with a\n"
	.string "deep, shimmering green...\p"
	.string "Here, I would like you to have\n"
	.string "this.$"

FortuneTeller_Text_ShowMe:
	.string "There is a theory I wish to\n"
	.string "prove.\p"
	.string "Send this letter out into the world,\n"
	.string "and if you can find one like it,\l"
	.string "bring it to me.\p"
	.string "I may have something special for\n"
	.string "you if you do.\p"
	.string "May our paths cross again, my\n"
	.string "dear!$"

FieryPath_FTWalkAway:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FortuneTeller_Text_Defeat:
	.string "Yes, I believe you may be\n"
	.string "the right one...$"

FieryPath_FTWalkDownLeft:
	walk_left
	walk_down
	walk_down
	step_end

FieryPath_FTWalkDownMiddle:
	walk_down
	walk_down
	step_end

FieryPath_FTWalkDownRight:
	walk_right
	walk_down
	walk_down
	step_end


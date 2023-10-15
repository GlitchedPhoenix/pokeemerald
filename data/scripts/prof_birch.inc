ProfBirch_EventScript_UpdateLocation::
	goto_if_eq VAR_PETALBURG_GYM_STATE, 0, Common_EventScript_NopReturn
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 0, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 1, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 2, ProfBirch_EventScript_MoveToRoute101
	call_if_eq VAR_BIRCH_STATE, 3, ProfBirch_EventScript_MoveToRoute101
	call_if_eq VAR_BIRCH_STATE, 4, ProfBirch_EventScript_MoveToRoute103
	call_if_eq VAR_BIRCH_STATE, 5, ProfBirch_EventScript_MoveToRoute103
	call_if_eq VAR_BIRCH_STATE, 6, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 7, ProfBirch_EventScript_MoveToLab
	return

ProfBirch_EventScript_MoveToLab::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute101::
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute103::
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	return

ProfBirch_EventScript_RatePokedexOrRegister::
	lock
	faceplayer
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch

ProfBirch_EventScript_AskRatePokedex::
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfBirch_EventScript_DeclineRating
	call ProfBirch_EventScript_RatePokedex
	release
	end

ProfBirch_EventScript_DeclineRating::
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfBirch_EventScript_CheckForDeoxys::
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, ProfBirch_EventScript_RateNationalPokedex
	goto ProfBirch_EventScript_GiveAuroraTicket

ProfBirch_EventScript_ComeToLab::
	call_if_unset FLAG_BIRCH_SEEN_COMPLETE_HOENN_DEX, ProfBirch_EventScript_Congratulations
	goto_if_set FLAG_BIRCH_SEEN_COMPLETE_HOENN_DEX, ProfBirch_EventScript_PleaseComeToLab
	return

ProfBirch_EventScript_Congratulations::
	msgbox ProfBirch_Text_CompletedStandardHoennDex
	setflag FLAG_BIRCH_SEEN_COMPLETE_HOENN_DEX
	return

ProfBirch_EventScript_PleaseComeToLab::
	msgbox ProfBirch_Text_PleaseComeToLab
	return
	
ProfBirch_EventScript_GiveAuroraTicket::
	call_if_unset FLAG_BIRCH_SEEN_COMPLETE_HOENN_DEX, ProfBirch_EventScript_Congratulations
	msgbox ProfBirch_Text_ExplainAuroraTicket
	textcolor 2
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	textcolor 8
	msgbox ProfBirch_Text_GetAuroraTicket
	release
	end

ProfBirch_Text_ExplainAuroraTicket:
	.string "This calls for a celebration!\n"
	.string "Oh, but there's so much work to do...\p"
	.string "How about this, {PLAYER}. I recently\n"
	.string "recieved an odd ticket from a friend\l"
	.string "overseas, that will ferry you to an\l"
	.string "small island in the SEVII ISLANDS.\p"
	.string "They say a meteor recently landed there,\n"
	.string "but attempts to study it have turned\l"
	.string "up nothing.\p"
	.string "I'd have liked to visit it myself, but\n"
	.string "I'm afraid I'm a little tied up here, and\l"
	.string "my wife probably wouldn't like me\l"
	.string "running off just to study a rock...\p"
	.string "So, I'd like you to have it!$"

ProfBirch_Text_GetAuroraTicket:
	.string "Go and see it for yourself, {PLAYER}!\p"
	.string "Since you're quite the scholar already,\n"
	.string "I'm sure you can learn something about\l"
	.string "it that we've yet to.$"

ProfBirch_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfBirch_EventScript_ShowRatingMessage
	goto_if_ge VAR_0x8007, 201, ProfBirch_EventScript_CheckForDeoxys
	goto ProfBirch_EventScript_RateNationalPokedex

ProfBirch_EventScript_RateNationalPokedex::
	goto_if_eq VAR_0x800A, 0, Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num National seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num National caught
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	return

RedfireRange_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route113_OnResume
	.byte 0

AshenRange_OnResume:
	setstepcallback STEP_CB_ASH
	end

AshenRange_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

AshenRange_EventScript_DeoxysAttackForm::
	lock
	specialvar VAR_RESULT, Special_LeadMonIsDeoxys
	goto_if_eq VAR_RESULT, TRUE, AshenRange_EventScript_DeoxysAttackForm2
	msgbox Deoxys_Text_MysteriousTriangle, MSGBOX_DEFAULT
	release
	end

AshenRange_EventScript_DeoxysAttackForm2::
	msgbox Deoxys_Text_MysteriousTriangle, MSGBOX_DEFAULT
	msgbox Deoxys_Text_Suddenly, MSGBOX_DEFAULT
	playse SE_WARP_OUT
	fadescreenspeed FADE_TO_WHITE, 1
	fadescreen FADE_FROM_WHITE
	setvar VAR_DEOXYS_FORM_CHANGE, 1
	callnative (SetFirstDeoxysForm)
	msgbox Deoxys_Text_YouFeltChange, MSGBOX_DEFAULT
	release
	end

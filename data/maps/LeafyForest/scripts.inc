LeafyForest_MapScripts::
	.byte 0

VerdantGrove_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

VerdantGrove_EventScript_DeoxysDefenseForm::
	lock
	specialvar VAR_RESULT, Special_LeadMonIsDeoxys
	goto_if_eq VAR_RESULT, TRUE, VerdantGrove_EventScript_DeoxysDefenseForm2
	msgbox Deoxys_Text_MysteriousTriangle, MSGBOX_DEFAULT
	release
	end

VerdantGrove_EventScript_DeoxysDefenseForm2::
	msgbox Deoxys_Text_MysteriousTriangle, MSGBOX_DEFAULT
	msgbox Deoxys_Text_Suddenly, MSGBOX_DEFAULT
	playse SE_WARP_OUT
	fadescreenspeed FADE_TO_WHITE, 2
	fadescreen FADE_FROM_WHITE
	setvar VAR_DEOXYS_FORM_CHANGE, 2
	callnative (SetFirstDeoxysForm)
	msgbox Deoxys_Text_YouFeltChange, MSGBOX_DEFAULT
	release
	end

Deoxys_Text_YouFeltChange::
	.string "You felt something change\n"
	.string "about DEOXYS!$"

Deoxys_Text_MysteriousTriangle::
	.string "You feel a strange, otherworldly\n"
	.string "power emanating from this rock.$"

Deoxys_Text_Suddenly::
	.string "Suddenly...!$"

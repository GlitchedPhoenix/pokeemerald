Route119_EventScript_WaterfallNests::
	switch VAR_RESULT
	case 0, FeebasGuy_WaterfallNone
	case 1, FeebasGuy_WaterfallQuiet
	case 2, FeebasGuy_WaterfallBusy
	return

FeebasGuy_WaterfallNone::
	msgbox FeebasGuy_Text_WaterfallNone
	return

FeebasGuy_Text_WaterfallNone:
	.string "I don't reckon there's any action\n"
	.string "above the waterfall today.$"

FeebasGuy_WaterfallQuiet::
	msgbox FeebasGuy_Text_WaterfallQuiet
	return

FeebasGuy_Text_WaterfallQuiet:
	.string "There might be a nest or two above\n"
	.string "above the waterfall.$"

FeebasGuy_WaterfallBusy::
	msgbox FeebasGuy_Text_WaterfallBusy
	return

FeebasGuy_Text_WaterfallBusy:
	.string "Despite all the odds, there's quite\n"
	.string "a bit of activity up there!$"



Route119_EventScript_TopNests::
	switch VAR_RESULT
	case 0, FeebasGuy_TopNone
	case 1, FeebasGuy_TopQuiet
	case 2, FeebasGuy_TopBusy
	return

FeebasGuy_TopNone::
	msgbox FeebasGuy_Text_TopNone
	return

FeebasGuy_Text_TopNone:
	.string "Doesn't seem like the water just\n"
	.string "after the fall is very busy.$"

FeebasGuy_TopQuiet::
	msgbox FeebasGuy_Text_TopQuiet
	return

FeebasGuy_Text_TopQuiet:
	.string "There's a bit of activity down\n"
	.string "after the waterfall.$"

FeebasGuy_TopBusy::
	msgbox FeebasGuy_Text_TopBusy
	return

FeebasGuy_Text_TopBusy:
	.string "The area just after the waterfall\n"
	.string "is quite busy today!$"



Route119_EventScript_RiverUpperNests::
	switch VAR_RESULT
	case 0, FeebasGuy_UpperNone
	case 1, FeebasGuy_UpperQuiet
	case 2, FeebasGuy_UpperBusy
	return

FeebasGuy_UpperNone::
	msgbox FeebasGuy_Text_UpperNone
	return

FeebasGuy_Text_UpperNone:
	.string "Unfortunately, seems like the upper\n"
	.string "river doesn't have anything.$"

FeebasGuy_UpperQuiet::
	msgbox FeebasGuy_Text_UpperQuiet
	return

FeebasGuy_Text_UpperQuiet:
	.string "Coming down a bit, there's not\n"
	.string "too much activity, but a little.$"

FeebasGuy_UpperBusy::
	msgbox FeebasGuy_Text_UpperBusy
	return

FeebasGuy_Text_UpperBusy:
	.string "Down here, there's quite a bit of\n"
	.string "activity today!$"



Route119_EventScript_RockyBankNests::
	switch VAR_RESULT
	case 0, FeebasGuy_RockNone
	case 1, FeebasGuy_RockQuiet
	case 2, FeebasGuy_RockBusy
	return

FeebasGuy_RockNone::
	msgbox FeebasGuy_Text_RockNone
	return

FeebasGuy_Text_RockNone:
	.string "The rocky bank seems to be pretty\n"
	.string "empty today.$"

FeebasGuy_RockQuiet::
	msgbox FeebasGuy_Text_RockQuiet
	return

FeebasGuy_Text_RockQuiet:
	.string "The rocky bank actually has a bit\n"
	.string "of action today.$"

FeebasGuy_RockBusy::
	msgbox FeebasGuy_Text_RockBusy
	return

FeebasGuy_Text_RockBusy:
	.string "The FEEBAS are everywhere in the\n"
	.string "rocky bank right now!$"



Route119_EventScript_RiverLowerNests::
	switch VAR_RESULT
	case 0, FeebasGuy_LowerNone
	case 1, FeebasGuy_LowerQuiet
	case 2, FeebasGuy_LowerBusy
	return

FeebasGuy_LowerNone::
	msgbox FeebasGuy_Text_LowerNone
	return

FeebasGuy_Text_LowerNone:
	.string "It's pretty quiet in the lower half\n"
	.string "of the river.$"

FeebasGuy_LowerQuiet::
	msgbox FeebasGuy_Text_LowerQuiet
	return

FeebasGuy_Text_LowerQuiet:
	.string "Spotted a couple of FEEBAS down in\n"
	.string "the lower river.$"

FeebasGuy_LowerBusy::
	msgbox FeebasGuy_Text_LowerBusy
	return

FeebasGuy_Text_LowerBusy:
	.string "A lot of FEEBAS seem to be moving\n"
	.string "downstream today.$"



Route119_EventScript_SouthBankNests::
	switch VAR_RESULT
	case 0, FeebasGuy_SouthNone
	case 1, FeebasGuy_SouthQuiet
	case 2, FeebasGuy_SouthBusy
	return

FeebasGuy_SouthNone::
	msgbox FeebasGuy_Text_SouthNone
	return

FeebasGuy_Text_SouthNone:
	.string "Surprisingly, there's no FEEBAS\n"
	.string "hanging around the river mouth.$"

FeebasGuy_SouthQuiet::
	msgbox FeebasGuy_Text_SouthQuiet
	return

FeebasGuy_Text_SouthQuiet:
	.string "There's a nest or two down in the\n"
	.string "river mouth right now.$"

FeebasGuy_SouthBusy::
	msgbox FeebasGuy_Text_SouthBusy
	return

FeebasGuy_Text_SouthBusy:
	.string "Seems like there's a ton of nests\n"
	.string "down south today.$"



Route119_Movement_CameraWaterfall:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route119_Movement_CameraTop:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route119_Movement_CameraRiverUpper:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route119_Movement_CameraRockyBank:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route119_Movement_CameraRiverLower:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_Movement_CameraSouthBank:
	walk_fast_left
	walk_fast_left
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
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_Movement_CameraReturn:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end
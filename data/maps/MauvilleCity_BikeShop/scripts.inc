MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_YouCameBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesDeclined
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NoDeclined
	end

MauvilleCity_BikeShop_Text_YouCameBack::
	.string "Well well well, look who's back\n"
	.string "for one of my awesome bikes.$"

MauvilleCity_BikeShop_EventScript_YesDeclined::
	setflag FLAG_RECEIVED_BIKE
	msgbox MauvilleCity_BikeShop_Text_KnewYouWould
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_NoDeclined::
	msgbox MauvilleCity_BikeShop_Text_Fine
	release
	end

MauvilleCity_BikeShop_Text_KnewYouWould::
	.string "Ha! I knew you would come\n"
	.string "around!$"

MauvilleCity_BikeShop_Text_Fine::
	.string "Fine! I didn't want to give\n"
	.string "you a FREE bike anyway!$"

MauvilleCity_BikeShop_EventScript_ChooseBike::
	msgbox MauvilleCity_BikeShop_Text_ExplainBikes, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	msgbox MauvilleCity_BikeShop_Text_NotAJabAtAnyoneInParticular, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	msgbox MauvilleCity_BikeShop_Text_ExplainDistance, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_Tutorial, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_Text_Tutorial::
	.string "Remember! To change modes, press\n"
	.string "the lever on your {COLOR RED}{SHADOW LIGHT_RED}right{COLOR BLUE}{SHADOW LIGHT_GRAY}!$"

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Is that right?\p"
	.string "Well then, I guess you don't\n"
	.string "NEED any of my bikes, do you?$"

MauvilleCity_BikeShop_Text_ExplainDistance:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "That's pretty far, isn't it?\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!$"

MauvilleCity_BikeShop_Text_ExplainBikes:
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "In fact, I'll even give you one of\n"
	.string "my special prototypes!\p"
	.string "See, a while ago we dealt two\n"
	.string "different kinds of bikes, the\l"
	.string "MACH and ACRO bikes.\p"
	.string "But, a few of our customers got\n"
	.string "a little frustrated because I\l"
	.string "didn't make just one bike that could\l"
	.string "both go fast and do tricks.\p"
	.string "Personally, I like to think that\n"
	.string "the full experience of my bikes is\l"
	.string "earned by trading them to\l"
	.string "experience what the other can't!\p"
	.string "But, some people think that's just\n"
	.string "a lame excuse to make them buy both.\p"
	.string "SO!\p"
	.string "I designed a better, third version.\p"
	.string "Allow me to introduce you to...\p"
	.string "the MACRO BIKE!$"
	
MauvilleCity_BikeShop_Text_NotAJabAtAnyoneInParticular::
	.string "While riding, you can click the\n"
	.string "lever on your {COLOR RED}{SHADOW LIGHT_RED}right{COLOR BLUE}{SHADOW LIGHT_GRAY} to swap\l"
	.string "between flying like the wind and\l"
	.string "impressing all your friends with\l"
	.string "your crazy tricks!\p"
	.string "However, do keep in mind that I\n"
	.string "took the rubber grips off of\l"
	.string "the handle bars.\p"
	.string "What? Just because you have the\n"
	.string "definitive version doesn't mean\l"
	.string "you get to have EVERYTHING.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Good, good!\n"
	.string "I'm happy that you like it!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "I'm learning about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "BIKE, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "It's a handbook on MACH mode.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "MACH mode is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But with your bike in MACH mode,\n"
	.string "you can zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "It's a handbook on ACRO mode.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"


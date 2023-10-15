#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetExtendedPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetExtendedPokedexCount(FLAG_GET_CAUGHT);
		gSpecialVar_0x8007 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
		
		if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DEOXYS), FLAG_GET_CAUGHT) && !FlagGet(FLAG_RECEIVED_AURORA_TICKET))
			gSpecialVar_0x8007 -= 1;
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

// This shows your Hoenn Pokedex rating and not your National Dex.
const u8 *GetPokedexRatingText(u16 count)
{	
    if (count < 15)
        return gBirchDexRatingText_LessThan10;
    else if (count < 30)
        return gBirchDexRatingText_LessThan20;
    else if (count < 45)
        return gBirchDexRatingText_LessThan30;
    else if (count < 60)
        return gBirchDexRatingText_LessThan40;
    else if (count < 75)
        return gBirchDexRatingText_LessThan50;
    else if (count < 90)
        return gBirchDexRatingText_LessThan60;
    else if (count < 105)
        return gBirchDexRatingText_LessThan70;
    else if (count < 120)
        return gBirchDexRatingText_LessThan80;
    else if (count < 135)
        return gBirchDexRatingText_LessThan90;
    else if (count < 150)
        return gBirchDexRatingText_LessThan100;
    else if (count < 165)
        return gBirchDexRatingText_LessThan110;
    else if (count < 180)
        return gBirchDexRatingText_LessThan120;
    else if (count < 195)
        return gBirchDexRatingText_LessThan130;
    else if (count < 210)
        return gBirchDexRatingText_LessThan140;
    else if (count < 225)
        return gBirchDexRatingText_LessThan150;
    else if (count < 240)
        return gBirchDexRatingText_LessThan160;
    else if (count < 255)
        return gBirchDexRatingText_LessThan170;
    else if (count < 270)
        return gBirchDexRatingText_LessThan180;
    else if (count < 285)
        return gBirchDexRatingText_LessThan190;
    else if (count < 300)
        return gBirchDexRatingText_LessThan200;
    else if (count == 300)
    {
        return gBirchDexRatingText_DexCompleted;
    }
    return gBirchDexRatingText_LessThan10;
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}

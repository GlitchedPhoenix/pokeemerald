#include "global.h"
#include "random.h"
#include "event_data.h"
#include "battle_setup.h"
#include "gym_leader_rematch.h"

static void UpdateGymLeaderRematchFromArray(const u16 *data, size_t size, u32 maxRematch);
static s32 GetRematchIndex(u32 trainerIdx);

static void UpdateGymLeaderRematchFromArray(const u16 *data, size_t size, u32 maxRematch)
{
    s32 whichLeader = 0;
    s32 lowestRematchIndex = 5;
    u32 i;
    s32 rematchIndex;
    for (i = 0; i < size; i++)
    {
        if (!gSaveBlock1Ptr->trainerRematches[data[i]])
        {
            rematchIndex = GetRematchIndex(data[i]);
            if (lowestRematchIndex > rematchIndex)
                lowestRematchIndex = rematchIndex;
            whichLeader++;
        }
    }
    if (whichLeader != 0 && lowestRematchIndex <= maxRematch)
    {
        whichLeader = 0;
        for (i = 0; i < size; i++)
        {
            if (!gSaveBlock1Ptr->trainerRematches[data[i]])
            {
                rematchIndex = GetRematchIndex(data[i]);
                if (rematchIndex == lowestRematchIndex)
                    whichLeader++;
            }
        }
        if (whichLeader != 0)
        {
            whichLeader = Random() % whichLeader;
            for (i = 0; i < size; i++)
            {
                if (!gSaveBlock1Ptr->trainerRematches[data[i]])
                {
                    rematchIndex = GetRematchIndex(data[i]);
                    if (rematchIndex == lowestRematchIndex)
                    {
                        if (whichLeader == 0)
                        {
                            gSaveBlock1Ptr->trainerRematches[data[i]] = lowestRematchIndex;
                            break;
                        }
                        whichLeader--;
                    }
                }
            }
        }
    }
}

const u8 GetDifficulty(void)
{
	u8 difficulty = gSaveBlock2Ptr->difficulty;
	u8 progression = VarGet(VAR_SYS_PROGRESSION);
	u8 diffBonus = 0;
	
	if ((difficulty >= 2) && (progression > 7))
		diffBonus += 1;
	if ((difficulty == 3) && (progression >= 12))
		diffBonus += 1;
	else if (difficulty == 4)
		diffBonus = 0;
	
	return (progression + diffBonus);
}

static s32 GetRematchIndex(u32 trainerIdx)
{
    s32 i;
    for (i = 0; i < 5; i++)
    {
        if (!HasTrainerBeenFought(gRematchTable[trainerIdx].trainerIds[i]))
        {
            return i;
        }
    }
    return 5;
}

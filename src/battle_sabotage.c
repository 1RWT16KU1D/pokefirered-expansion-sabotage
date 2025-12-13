#include "global.h"
#include "battle.h"
#include "battle_sabotage.h"
#include "event_data.h"

#include "constants/items.h"
#include "constants/species.h"

// List of all traps
struct TrapData gTrapData[] = 
{
    // Passive Traps
    [TRAP_TRAPPERS_TERRITORY] = 
    {
        .name = sText_Name_TrappersTerritory,
        .desc = sText_Desc_TrappersTerritory,
    },
    [TRAP_GRAVEYARD] = 
    {
        .name = sText_Name_Graveyard,
        .desc = sText_Desc_Graveyard,
    },
    [TRAP_ITS_RAINING_HAZARDS] = 
    {
        .name = sText_Name_ItsRainingHazards,
        .desc = sText_Desc_ItsRainingHazards,
    },
    [TRAP_BALLROOM_BONANZA] = 
    {
        .name = sText_Name_BallroomBonanza,
        .desc = sText_Desc_BallroomBonanza,
    },
    [TRAP_ABILITY_NULL] = 
    {
        .name = sText_Name_AbilityNull,
        .desc = sText_Desc_AbilityNull,
    },
    [TRAP_CHILLY_WINDS] = 
    {
        .name = sText_Name_ChillyWinds,
        .desc = sText_Desc_ChillyWinds,
    },
    [TRAP_HEALING_GROUNDS] =
    {
        .name = sText_Name_HealingGrounds,
        .desc = sText_Desc_HealingGrounds,
    },
    [TRAP_BIZZARE_TEMPLE] =
    {
        .name = sText_Name_BizzareTemple,
        .desc = sText_Desc_BizzareTemple,
    },
    [TRAP_HOT_LAVA] =
    {
        .name = sText_Name_HotLava,
        .desc = sText_Desc_HotLava,
    },
    [TRAP_STAT_ROULETTE] =
    {
        .name = sText_Name_StatRoulette,
        .desc = sText_Desc_StatRoulette,
    },
    [TRAP_COFFEE_FIELDS] =
    {
        .name = sText_Name_CoffeeFields,
        .desc = sText_Desc_CoffeeFields,
    },
    [TRAP_DISTORTED_FURY] =
    {
        .name = sText_Name_DistortedFury,
        .desc = sText_Desc_DistortedFury,
    },
    [TRAP_WRONG_INTUITION] =
    {
        .name = sText_Name_WrongIntuition,
        .desc = sText_Desc_WrongIntuition,
    },

    // Active Traps
    [TRAP_NO_INTERFERENCE] =
    {
        .name = sText_Name_NoInterference,
        .desc = sText_Desc_NoInterference,
    },
    [TRAP_SHATTERED_DREAMS] =
    {
        .name = sText_Name_ShatteredDreams,
        .desc = sText_Desc_ShatteredDreams,
    },
    [TRAP_JACKPOT] =
    {
        .name = sText_Name_Jackpot,
        .desc = sText_Desc_Jackpot,
    },
    [TRAP_BANANA_PEEL] =
    {
        .name = sText_Name_BananaPeel,
        .desc = sText_Desc_BananaPeel,
    },
    [TRAP_NO_HOLDS_BARRED] =
    {
        .name = sText_Name_NoHoldsBarred,
        .desc = sText_Desc_NoHoldsBarred,
    },
    [TRAP_SEALED_DEMON] =
    {
        .name = sText_Name_SealedDemon,
        .desc = sText_Desc_SealedDemon,
    },
    [TRAP_BLOOD_PACT] =
    {
        .name = sText_Name_BloodPact,
        .desc = sText_Desc_BloodPact,
    },
    [TRAP_SIN_OF_PRIDE] =
    {
        .name = sText_Name_SinOfPride,
        .desc = sText_Desc_SinOfPride,
    },
    [TRAP_DETONATION_DELUSION] =
    {
        .name = sText_Name_DetonationDelusion,
        .desc = sText_Desc_DetonationDelusion,
    },
    [TRAP_NOTHING_SPECIAL] =
    {
        .name = sText_Name_NothingSpecial,
        .desc = sText_Desc_NothingSpecial,
    },
};

u8 GetRandomTrap(bool8 isActive)
{
    u8 start = isActive ? TRAP_PASSIVE_COUNT : TRAP_TRAPPERS_TERRITORY;
    u8 end = isActive ? TRAP_TOTAL_COUNT : TRAP_PASSIVE_COUNT;

    return start + (Random() % (end - start));
}

const u8 *GetTrapName(u8 trapId)
{
    return gTrapData[trapId].name;
}

const u8 *GetTrapDesc(u8 trapId)
{
    return gTrapData[trapId].desc;
}

bool8 IsPassiveTrapCounterZero(void)
{
    return gBattleStruct->sabotage.passiveTrapCtr == 0;
}

bool8 IsActiveTrapCounterZero(void)
{
    return gBattleStruct->sabotage.activeTrapCtr == 0;
}

void ResetSabotageCounters(void)
{
    gBattleStruct->sabotage.passiveTrapCtr = 3;
    gBattleStruct->sabotage.activeTrapCtr = 3;
}

void ResetActiveTrapCounter(void)
{
    gBattleStruct->sabotage.activeTrapCtr = 3;
}

void ResetPassiveTrapCounter(void)
{
    gBattleStruct->sabotage.passiveTrapCtr = 3;
}

bool8 IsValidTrapId(u8 trapId)
{
    return (trapId > TRAP_NONE && trapId < TRAP_TOTAL_COUNT);
}

bool8 IsSabotageBattle(void)
{
    return FlagGet(B_FLAG_SABOTAGE_BATTLE);
}

bool8 IsTrappersTerritorySwitchingPrevented(void)
{
    return (IsSabotageBattle() && gBattleStruct->sabotage.activeTrapId == TRAP_TRAPPERS_TERRITORY);
}

u8 GetCurrentActiveTrap(void)
{
    return gBattleStruct->sabotage.activeTrapId;
}

u8 GetCurrentPassiveTrap(void)
{
    return gBattleStruct->sabotage.passiveTrapId;
}

void SabotageBattleEffects(u8 caseId, u8 trapId)
{
    ; // Placeholder
}
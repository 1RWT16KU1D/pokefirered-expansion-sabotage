#include "global.h"
#include "battle.h"
#include "battle_sabotage.h"
#include "event_data.h"

#include "constants/items.h"
#include "constants/species.h"

// List of all traps
// struct TrapData gTrapData[] = 
// {
//     // Passive Traps
//     [SABOTAGE_TRAP_TRAPPERS_TERRITORY] = 
//     {
//         .name = sText_Name_TrappersTerritory,
//         .desc = sText_Desc_TrappersTerritory,
//     },
//     [SABOTAGE_TRAP_GRAVEYARD] = 
//     {
//         .name = sText_Name_Graveyard,
//         .desc = sText_Desc_Graveyard,
//     },
//     [SABOTAGE_TRAP_ITS_RAINING_HAZARDS] = 
//     {
//         .name = sText_Name_ItsRainingHazards,
//         .desc = sText_Desc_ItsRainingHazards,
//     },
//     [SABOTAGE_TRAP_BALLROOM_BONANZA] = 
//     {
//         .name = sText_Name_BallroomBonanza,
//         .desc = sText_Desc_BallroomBonanza,
//     },
//     [SABOTAGE_TRAP_ABILITY_NULL] = 
//     {
//         .name = sText_Name_AbilityNull,
//         .desc = sText_Desc_AbilityNull,
//     },
//     [SABOTAGE_TRAP_CHILLY_WINDS] = 
//     {
//         .name = sText_Name_ChillyWinds,
//         .desc = sText_Desc_ChillyWinds,
//     },
//     [SABOTAGE_TRAP_HEALING_GROUNDS] =
//     {
//         .name = sText_Name_HealingGrounds,
//         .desc = sText_Desc_HealingGrounds,
//     },
//     [SABOTAGE_TRAP_BIZZARE_TEMPLE] =
//     {
//         .name = sText_Name_BizzareTemple,
//         .desc = sText_Desc_BizzareTemple,
//     },
//     [SABOTAGE_TRAP_HOT_LAVA] =
//     {
//         .name = sText_Name_HotLava,
//         .desc = sText_Desc_HotLava,
//     },
//     [SABOTAGE_TRAP_STAT_ROULETTE] =
//     {
//         .name = sText_Name_StatRoulette,
//         .desc = sText_Desc_StatRoulette,
//     },
//     [SABOTAGE_TRAP_COFFEE_FIELDS] =
//     {
//         .name = sText_Name_CoffeeFields,
//         .desc = sText_Desc_CoffeeFields,
//     },
//     [SABOTAGE_TRAP_DISTORTED_FURY] =
//     {
//         .name = sText_Name_DistortedFury,
//         .desc = sText_Desc_DistortedFury,
//     },
//     [SABOTAGE_TRAP_WRONG_INTUITION] =
//     {
//         .name = sText_Name_WrongIntuition,
//         .desc = sText_Desc_WrongIntuition,
//     },

//     // Active Traps
//     [SABOTAGE_TRAP_NO_INTERFERENCE] =
//     {
//         .name = sText_Name_NoInterference,
//         .desc = sText_Desc_NoInterference,
//     },
//     [SABOTAGE_TRAP_SHATTERED_DREAMS] =
//     {
//         .name = sText_Name_ShatteredDreams,
//         .desc = sText_Desc_ShatteredDreams,
//     },
//     [SABOTAGE_TRAP_JACKPOT] =
//     {
//         .name = sText_Name_Jackpot,
//         .desc = sText_Desc_Jackpot,
//     },
//     [SABOTAGE_TRAP_BANANA_PEEL] =
//     {
//         .name = sText_Name_BananaPeel,
//         .desc = sText_Desc_BananaPeel,
//     },
//     [SABOTAGE_TRAP_NO_HOLDS_BARRED] =
//     {
//         .name = sText_Name_NoHoldsBarred,
//         .desc = sText_Desc_NoHoldsBarred,
//     },
//     [SABOTAGE_TRAP_SEALED_DEMON] =
//     {
//         .name = sText_Name_SealedDemon,
//         .desc = sText_Desc_SealedDemon,
//     },
//     [SABOTAGE_TRAP_BLOOD_PACT] =
//     {
//         .name = sText_Name_BloodPact,
//         .desc = sText_Desc_BloodPact,
//     },
//     [SABOTAGE_TRAP_SIN_OF_PRIDE] =
//     {
//         .name = sText_Name_SinOfPride,
//         .desc = sText_Desc_SinOfPride,
//     },
//     [SABOTAGE_TRAP_DETONATION_DELUSION] =
//     {
//         .name = sText_Name_DetonationDelusion,
//         .desc = sText_Desc_DetonationDelusion,
//     },
//     [SABOTAGE_TRAP_NOTHING_SPECIAL] =
//     {
//         .name = sText_Name_NothingSpecial,
//         .desc = sText_Desc_NothingSpecial,
//     },
// };

u8 GetRandomTrap(bool8 isActive)
{
    // u8 start = isActive ? SABOTAGE_TRAP_PASSIVE_COUNT : SABOTAGE_TRAP_TRAPPERS_TERRITORY;
    // u8 end = isActive ? SABOTAGE_TRAP_TOTAL_COUNT : SABOTAGE_TRAP_PASSIVE_COUNT;

    u8 start = isActive ? SABOTAGE_TRAP_PASSIVE_COUNT : SABOTAGE_TRAP_TRAPPERS_TERRITORY;
    u8 end = isActive ? SABOTAGE_TRAP_TOTAL_COUNT : SABOTAGE_TRAP_WRONG_INTUITION;

    u8 trapId;

    // Prevent getting the same trap twice in a row
    do trapId = start + (Random() % (end - start));
    while (trapId == GetCurrentActiveTrap() || trapId == GetCurrentPassiveTrap());

    return trapId;
}

void SetRandomActiveTrap(void)
{
    gBattleStruct->sabotage.activeTrapId = GetRandomTrap(TRUE);
}

void SetRandomPassiveTrap(void)
{
    gBattleStruct->sabotage.passiveTrapId = GetRandomTrap(FALSE);
}

// const u8 *GetTrapName(u8 trapId)
// {
//     return gTrapData[trapId].name;
// }

// const u8 *GetTrapDesc(u8 trapId)
// {
//     return gTrapData[trapId].desc;
// }

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
    return (trapId > SABOTAGE_TRAP_NONE && trapId < SABOTAGE_TRAP_TOTAL_COUNT);
}

bool8 IsSabotageBattle(void)
{
    return FlagGet(B_FLAG_SABOTAGE_BATTLE);
}

bool8 IsTrappersTerritorySwitchingPrevented(void)
{
    return (IsSabotageBattle() && gBattleStruct->sabotage.activeTrapId == SABOTAGE_TRAP_TRAPPERS_TERRITORY);
}

u8 GetCurrentActiveTrap(void)
{
    return gBattleStruct->sabotage.activeTrapId;
}

u8 GetCurrentPassiveTrap(void)
{
    return gBattleStruct->sabotage.passiveTrapId;
}

#ifndef GUARD_BATTLE_INTERFACE_H
#define GUARD_BATTLE_INTERFACE_H

#include "global.h"
#include "battle_controllers.h"

enum
{
    HP_CURRENT,
    HP_MAX
};

enum
{
    HEALTH_BAR,
    EXP_BAR
};

enum
{
    HP_BAR_EMPTY,
    HP_BAR_RED,
    HP_BAR_YELLOW,
    HP_BAR_GREEN,
    HP_BAR_FULL,
};

#define TAG_HEALTHBOX_PLAYER1_TILE              55039
#define TAG_HEALTHBOX_PLAYER2_TILE              55040
#define TAG_HEALTHBOX_OPPONENT1_TILE            55041
#define TAG_HEALTHBOX_OPPONENT2_TILE            55042

#define TAG_HEALTHBAR_PLAYER1_TILE              55044
#define TAG_HEALTHBAR_OPPONENT1_TILE            55045
#define TAG_HEALTHBAR_PLAYER2_TILE              55046
#define TAG_HEALTHBAR_OPPONENT2_TILE            55047

#define TAG_HEALTHBOX_PALS_1                    55049
#define TAG_HEALTHBOX_PALS_2                    55050
#define TAG_HEALTHBOX_SAFARI_TILE               55051
#define TAG_PARTY_SUMMARY_BAR_PLAYER_TILE       55052
#define TAG_PARTY_SUMMARY_BAR_OPPONENT_TILE     55053

#define TAG_PARTY_SUMMARY_BAR_PLAYER_PAL        55056
#define TAG_PARTY_SUMMARY_BAR_OPPONENT_PAL      55057
#define TAG_PARTY_SUMMARY_BALL_PLAYER_PAL       55058
#define TAG_PARTY_SUMMARY_BALL_OPPONENT_PAL     55059
#define TAG_PARTY_SUMMARY_BALL_PLAYER_TILE      55060
#define TAG_PARTY_SUMMARY_BALL_OPPONENT_TILE    55061

#define TAG_HEALTHBOX_PAL                       TAG_HEALTHBOX_PLAYER1_TILE
#define TAG_HEALTHBAR_PAL                       TAG_HEALTHBAR_PLAYER1_TILE

#define TAG_GIMMICK_TRIGGER_TILE        0xD777
#define TAG_MEGA_INDICATOR_TILE         0xD778
#define TAG_ALPHA_INDICATOR_TILE        0xD779
#define TAG_OMEGA_INDICATOR_TILE        0xD77A
#define TAG_DYNAMAX_INDICATOR_TILE      0xD77B

#define TAG_NORMAL_INDICATOR_TILE       0xD77F
#define TAG_FIGHTING_INDICATOR_TILE     0xD780
#define TAG_FLYING_INDICATOR_TILE       0xD781
#define TAG_POISON_INDICATOR_TILE       0xD782
#define TAG_GROUND_INDICATOR_TILE       0xD783
#define TAG_ROCK_INDICATOR_TILE         0xD784
#define TAG_BUG_INDICATOR_TILE          0xD785
#define TAG_GHOST_INDICATOR_TILE        0xD786
#define TAG_STEEL_INDICATOR_TILE        0xD787
// empty spot for TYPE_MYSTERY
#define TAG_FIRE_INDICATOR_TILE         0xD786
#define TAG_WATER_INDICATOR_TILE        0xD787
#define TAG_GRASS_INDICATOR_TILE        0xD788
#define TAG_ELECTRIC_INDICATOR_TILE     0xD789
#define TAG_PSYCHIC_INDICATOR_TILE      0xD78A
#define TAG_ICE_INDICATOR_TILE          0xD78B
#define TAG_DRAGON_INDICATOR_TILE       0xD78C
#define TAG_DARK_INDICATOR_TILE         0xD78D
#define TAG_FAIRY_INDICATOR_TILE        0xD78E
#define TAG_STELLAR_INDICATOR_TILE      0xD78F
#define TAG_TERA_TRIGGER_TILE           0xD790

#define TAG_GIMMICK_TRIGGER_PAL         0xD777
#define TAG_MEGA_INDICATOR_PAL          0xD778
#define TAG_MISC_INDICATOR_PAL          0xD779 // Alpha, Omega, and Dynamax indicators use the same palette as each of them only uses 4 different colors.
#define TAG_TERA_INDICATOR_PAL          0xD77A

enum
{
    HEALTHBOX_ALL,
    HEALTHBOX_CURRENT_HP,
    HEALTHBOX_MAX_HP,
    HEALTHBOX_LEVEL,
    HEALTHBOX_NICK,
    HEALTHBOX_HEALTH_BAR,
    HEALTHBOX_EXP_BAR,
    HEALTHBOX_UNUSED_7,
    HEALTHBOX_UNUSED_8,
    HEALTHBOX_STATUS_ICON,
    HEALTHBOX_SAFARI_ALL_TEXT,
    HEALTHBOX_SAFARI_BALLS_TEXT
};

u32 WhichBattleCoords(u32 battlerId);
void Task_HidePartyStatusSummary(u8 taskId);
u8 CreateBattlerHealthboxSprites(u8 battlerId);
u8 CreateSafariPlayerHealthboxSprites(void);
void SetBattleBarStruct(u8 battlerId, u8 healthboxSpriteId, s32 maxVal, s32 currVal, s32 receivedValue);
void SetHealthboxSpriteInvisible(u8 healthboxSpriteId);
void SetHealthboxSpriteVisible(u8 healthboxSpriteId);
void DestoryHealthboxSprite(u8 healthboxSpriteId);
void DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBankOnly);
void UpdateOamPriorityInAllHealthboxes(u8 priority, bool32 hideHPBoxes);
void InitBattlerHealthboxCoords(u8 battlerId);
void GetBattlerHealthboxCoords(u8 battler, s16 *x, s16 *y);
void UpdateHpTextInHealthbox(u32 healthboxSpriteId, u32 maxOrCurrent, s16 currHp, s16 maxHp);
void SwapHpBarsWithHpText(void);
u8 CreatePartyStatusSummarySprites(u8 battlerId, struct HpAndStatus *partyInfo, u8 isSwitchingMons, bool8 isBattleStart);
void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId);
u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale);
u8 GetHPBarLevel(s16 hp, s16 maxhp);
void UpdateNickInHealthbox(u8 spriteId, struct Pokemon *mon);
void TryAddPokeballIconToHealthbox(u8 spriteId, u8);
s32 MoveBattleBar(u8 battler, u8 healthboxSpriteId, u8 whichBar, u8 arg3);

void CreateMegaTriggerSprite(u8 battlerId, u8 palId);
void ChangeMegaTriggerSprite(u8 spriteId, u8 animId);
void HideMegaTriggerSprite(void);
void DestroyMegaTriggerSprite(void);
bool32 IsMegaTriggerSpriteActive(void);

void CreateBurstTriggerSprite(u8 battlerId, u8 palId);
void ChangeBurstTriggerSprite(u8 spriteId, u8 animId);
void HideBurstTriggerSprite(void);
void DestroyBurstTriggerSprite(void);
bool32 IsBurstTriggerSpriteActive(void);

void HideTriggerSprites(void);

void CreateAbilityPopUp(u8 battlerId, u32 ability, bool32 isDoubleBattle);
void DestroyAbilityPopUp(u8 battlerId);
void UpdateAbilityPopup(u8 battlerId);
void CategoryIcons_LoadSpritesGfx(void);

#endif // GUARD_BATTLE_INTERFACE_H

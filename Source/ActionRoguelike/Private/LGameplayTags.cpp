// Yujiang Li All Rights Reserved

#include "LGameplayTags.h"

namespace LGamePlayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interact, "InputTag.Interact");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipDao, "InputTag.EquipDao");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipDao, "InputTag.UnequipDao");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Dao, "Player.Weapon.Dao");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Dao, "Player.Event.Equip.Dao");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Dao, "Player.Event.Unequip.Dao");
}
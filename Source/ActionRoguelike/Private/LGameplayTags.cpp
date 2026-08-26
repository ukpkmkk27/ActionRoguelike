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

	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Dao, "InputTag.LightAttack.Dao");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Dao, "InputTag.HeavyAttack.Dao");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Dao, "Player.Ability.Equip.Dao");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Dao, "Player.Ability.Unequip.Dao");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Dao, "Player.Ability.Attack.Light.Dao");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Dao, "Player.Ability.Attack.Heavy.Dao");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Dao, "Player.Weapon.Dao");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Dao, "Player.Event.Equip.Dao");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Dao, "Player.Event.Unequip.Dao");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");

	/** Enemy Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");
}
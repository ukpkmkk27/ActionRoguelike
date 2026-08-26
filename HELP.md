# ActionRoguelike 帮助文档

## 1. 项目简介

`ActionRoguelike` 是一个基于 Unreal Engine 5 和 C++ 的第三人称动作 Roguelike 项目，核心系统围绕以下能力构建：

- `Gameplay Ability System (GAS)`：角色能力、属性、效果和技能授予。
- `Enhanced Input`：输入映射与行为绑定。
- `GameplayTag`：输入标签、武器标签、角色状态标签和事件标签。
- `DataAsset`：角色启动能力、输入配置、武器能力配置的数据驱动管理。

当前仓库内已经包含主角、敌人、武器、输入配置、动画、能力蓝图和测试地图，适合作为 GAS 战斗系统练习项目或后续功能扩展的基础工程。

## 2. 运行环境

### 2.1 引擎与插件

- 使用 `ActionRoguelike.uproject` 关联的 Unreal Engine 版本打开项目。
- 项目已启用以下插件：
  - `EnhancedInput`
  - `GameplayAbilities`

### 2.2 开发环境建议

- Windows
- Visual Studio 2022
- Unreal Engine 5 C++ 开发环境

## 3. 快速开始

### 3.1 打开项目

1. 双击根目录下的 [ActionRoguelike.uproject](/D:/Github/ActionRoguelike/ActionRoguelike.uproject)。
2. 使用已关联的 UE5 版本打开项目。
3. 如需重新生成工程文件，可右键 `.uproject` 选择 `Generate Visual Studio project files`。
4. 使用 [ActionRoguelike.sln](/D:/Github/ActionRoguelike/ActionRoguelike.sln) 打开 C++ 工程。

### 3.2 默认入口

- 默认地图：`/Game/Maps/FeatureTestMap`
- 编辑器启动地图：`/Game/Maps/FeatureTestMap`
- 默认 GameMode：`/Game/GameModes/BP_BaseGameMode`

对应配置位于 [Config/DefaultEngine.ini](/D:/Github/ActionRoguelike/Config/DefaultEngine.ini)。

## 4. 当前项目内容

### 4.1 角色与敌人

- 主角蓝图：`/Game/PlayerCharacter/BP_HeroCharacter`
- 主角控制器：`/Game/PlayerCharacter/BP_HeroPlayerController`
- 敌人基础蓝图：`/Game/EnemyCharacter/BP_EnemyCharacter_Base`
- 示例敌人：`/Game/EnemyCharacter/DarkKnight/BP_DarkKnight`

### 4.2 武器与能力

- 主角武器基础蓝图：`/Game/PlayerCharacter/HeroWeapon/BP_HeroWeapon_Base`
- 示例武器：`/Game/PlayerCharacter/HeroWeapon/BP_HeroWeapon_Dao`
- 主角能力示例：
  - `GA_Hero_SpawnDao`
  - `GA_Hero_EquipDao`
  - `GA_Hero_UnequipDao`
  - `GA_Hero_LightAttackMaster`
  - `GA_Hero_LightAttack_Dao`
  - `GA_Hero_HeavyAttackMaster`
  - `GA_Hero_HeavyAttack_Dao`
- 敌人能力示例：
  - `GA_DarkKnight_SpawnWeapon`

### 4.3 效果与数据

- 主角启动效果：`GE_Hero_StartUp`
- 主角静态效果：`GE_Hero_Static`
- 主角启动数据表：`Hero_StartUp.csv`
- 敌人启动效果：`GE_DarkKnight_StartUp`
- 敌人启动数据表：`DarkKnight_StartUp.csv`

## 5. 输入与操作说明

### 5.1 当前输入设计

项目使用 `Enhanced Input + DataAsset + GameplayTag` 组织输入：

- `NativeInputActions`：移动、视角、跳跃、交互
- `GameAbilityInputActions`：装备、卸下、轻攻击、重攻击等能力输入

核心输入配置资源位于：

- `Content/PlayerCharacter/InputConfig/DA_InputConfig.uasset`
- `Content/PlayerCharacter/InputConfig/DA_Hero.uasset`
- `Content/PlayerCharacter/InputConfig/IMC_CharacterDefault.uasset`
- `Content/PlayerCharacter/InputConfig/IMC_Dao.uasset`

### 5.2 已确认的基础操作

从 [Config/DefaultInput.ini](/D:/Github/ActionRoguelike/Config/DefaultInput.ini) 和 C++ 代码可确认：

- `W/A/S/D`：移动
- `鼠标移动`：视角控制
- `Space`：跳跃
- `交互/装备/攻击`：由 `InputConfig DataAsset` 和对应 `InputAction` 资源决定

如果需要确认具体能力按键，请在编辑器中打开 `DA_InputConfig`、`DA_Hero` 和对应 `Input Mapping Context` 查看。

## 6. 核心系统架构

### 6.1 角色基类

[Source/ActionRoguelike/Public/Characters/LBaseCharacter.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Characters/LBaseCharacter.h)

`ALBaseCharacter` 是角色系统入口，负责：

- 实现 `IAbilitySystemInterface`
- 持有自定义 `ULAbilitySystemComponent`
- 持有 `ULAttributeSet`
- 在 `PossessedBy` 中调用 `InitAbilityActorInfo`
- 通过 `CharacterStartUpData` 下发角色初始能力和效果

### 6.2 属性系统

[Source/ActionRoguelike/Public/AbilitySystem/LAttributeSet.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/AbilitySystem/LAttributeSet.h)

当前属性集包括：

- `CurrentHealth`
- `MaxHealth`
- `CurrentRage`
- `MaxRage`
- `AttackPower`
- `DefensePower`

### 6.3 能力激活链路

主角能力输入链路如下：

1. `ALHeroCharacter::SetupPlayerInputComponent` 绑定原生输入和能力输入标签。
2. `ULInputComponent` 从 `ULDataAsset_InputConfig` 中读取 `InputAction -> GameplayTag` 配置。
3. `ALHeroCharacter::Input_AbilityPressed` 将输入标签转发给 `ULAbilitySystemComponent`。
4. `ULAbilitySystemComponent::OnAbilityInputPressed` 遍历可激活能力。
5. 使用 `AbilitySpec.DynamicAbilityTags` 匹配输入标签。
6. 调用 `TryActivateAbility` 激活对应能力。

相关代码：

- [Source/ActionRoguelike/Public/Components/Input/LInputComponent.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Components/Input/LInputComponent.h)
- [Source/ActionRoguelike/Private/Characters/LHeroCharacter.cpp](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Private/Characters/LHeroCharacter.cpp)
- [Source/ActionRoguelike/Private/AbilitySystem/LAbilitySystemComponent.cpp](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Private/AbilitySystem/LAbilitySystemComponent.cpp)

说明：

- 当前 C++ 层已经实现按下触发逻辑。
- `OnAbilityInputReleased` 接口已预留，后续可以扩展长按、蓄力、松开结算等能力。

### 6.4 启动能力与效果下发

启动数据基类：

- [LDataAsset_StartUpDataBase.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/DataAssets/StartUp/LDataAsset_StartUpDataBase.h)

派生数据：

- [LDataAsset_HeroStartUpData.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/DataAssets/StartUp/LDataAsset_HeroStartUpData.h)
- [LDataAsset_EnemyStartUpData.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/DataAssets/StartUp/LDataAsset_EnemyStartUpData.h)

启动数据负责：

- 授予 `ActivateOnGivenAbilities`
- 授予 `ReactiveAbilities`
- 应用 `StartUpGameplayEffects`
- 为主角或敌人批量注入专属能力

差异：

- 主角启动数据在 `PossessedBy` 中同步加载并授予能力。
- 敌人启动数据在 `PossessedBy` 中异步加载并授予能力。

### 6.5 能力基类设计

基础能力类：

- [LGameplayAbility.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/AbilitySystem/Abilities/LGameplayAbility.h)

主角能力类：

- [LHeroGameplayAbility.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/AbilitySystem/Abilities/LHeroGameplayAbility.h)

敌人能力类：

- `ULEnemyGameplayAbility`

其中 `ULGameplayAbility` 封装了两种激活策略：

- `OnTriggered`：输入触发
- `OnGiven`：授予即激活

这使得项目可以同时支持：

- 主动攻击技能
- 出生即执行的初始化能力
- 被动或响应式能力

### 6.6 武器与战斗组件

武器基类：

- [LWeaponBase.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Items/Weapons/LWeaponBase.h)
- [LHeroWeapon.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Items/Weapons/LHeroWeapon.h)

战斗组件：

- [PawnCombatComponent.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Components/Combat/PawnCombatComponent.h)
- [HeroCombatComponent.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Components/Combat/HeroCombatComponent.h)

当前实现特点：

- 使用 `GameplayTag -> Weapon` 映射保存角色已携带武器。
- 通过 `CurrentEquippedWeaponTag` 管理当前装备武器。
- 武器可携带专属能力配置 `FLHeroWeaponData`。
- 武器能力授予后，会记录 `FGameplayAbilitySpecHandle`，便于卸下武器时安全回收。

### 6.7 GameplayTag 设计

标签定义位于：

- [Source/ActionRoguelike/Public/LGameplayTags.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/LGameplayTags.h)
- [Source/ActionRoguelike/Private/LGameplayTags.cpp](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Private/LGameplayTags.cpp)

当前标签主要分为：

- 输入标签：`InputTag.Move`、`InputTag.Look`、`InputTag.Jump`、`InputTag.Interact`
- 武器/能力标签：`InputTag.EquipDao`、`InputTag.LightAttack.Dao`、`InputTag.HeavyAttack.Dao`
- 玩家能力标签：`Player.Ability.*`
- 玩家事件标签：`Player.Event.*`
- 玩家状态标签：`Player.Status.JumpToFinisher`
- 敌人标签：`Enemy.Weapon`

## 7. 目录结构

### 7.1 代码目录

`Source/ActionRoguelike/Public`

- `AbilitySystem`：ASC、AttributeSet、Ability 基类
- `Characters`：角色基类、主角、敌人
- `Components`：战斗组件、输入组件、扩展组件
- `Controllers`：玩家控制器
- `DataAssets`：启动数据、输入配置
- `Items`：武器系统
- `Interfaces`：交互与战斗接口
- `LTypes`：结构体、枚举等公共类型

`Source/ActionRoguelike/Private`

- 对应模块的实现文件

### 7.2 资源目录

`Content/PlayerCharacter`

- 主角蓝图、输入配置、武器、能力、特效、动画

`Content/EnemyCharacter`

- 敌人蓝图、敌人能力、敌人特效、敌人动画

`Content/Maps`

- 默认测试地图 `FeatureTestMap`

## 8. 常见扩展流程

### 8.1 新增主角能力

1. 在 `LGameplayTags` 中增加新的输入标签或能力标签。
2. 新建 `GameplayAbility` 蓝图或 C++ 派生类。
3. 在 `DA_Hero` 或对应 `StartUp DataAsset` 中配置能力。
4. 如需输入触发，在 `DA_InputConfig` 中添加 `InputAction -> GameplayTag` 映射。
5. 如为武器专属能力，在武器的 `HeroWeaponData` 中配置 `WeaponAbilitiesToGrant`。

### 8.2 新增武器

1. 基于 `BP_HeroWeapon_Base` 创建新武器蓝图。
2. 配置武器的动画层、输入映射和能力数组。
3. 在能力中通过 `GrantHeroWeaponAbilities` 授予武器技能。
4. 卸下武器时通过 `RemoveHeroWeaponAbilities` 回收能力。

### 8.3 新增敌人

1. 基于 `ALEnemyCharacter` 或敌人蓝图创建新敌人。
2. 新建敌人专属 `StartUp DataAsset`。
3. 配置敌人能力、启动效果和武器。
4. 在地图中摆放敌人并验证启动能力是否正常下发。

## 9. 调试建议

- 优先检查角色蓝图是否正确绑定了：
  - `CharacterStartUpData`
  - `InputConfigDataAsset`
  - 武器和能力资源
- 若能力无法触发，重点检查：
  - `InputAction` 是否映射到正确 `GameplayTag`
  - 能力是否已通过 `GiveAbility` 授予 ASC
  - `DynamicAbilityTags` 是否与输入标签一致
- 若角色出生后无属性或无技能，检查：
  - `StartUp DataAsset` 是否赋值
  - 对应 `GameplayEffect` 和能力蓝图是否有效

## 10. 已知说明

- 当前项目默认以 `FeatureTestMap` 作为测试场景。
- 输入系统已经完成标签化设计，但部分具体按键映射保存在 `.uasset` 中，需要在编辑器内查看和调整。
- C++ 层能力释放事件接口已经预留，适合后续继续扩展蓄力、持续施法和松键结算逻辑。

## 11. 相关文件索引

- 项目入口：[ActionRoguelike.uproject](/D:/Github/ActionRoguelike/ActionRoguelike.uproject)
- 工程文件：[ActionRoguelike.sln](/D:/Github/ActionRoguelike/ActionRoguelike.sln)
- 默认地图配置：[Config/DefaultEngine.ini](/D:/Github/ActionRoguelike/Config/DefaultEngine.ini)
- 输入配置：[Config/DefaultInput.ini](/D:/Github/ActionRoguelike/Config/DefaultInput.ini)
- 模块依赖：[Source/ActionRoguelike/ActionRoguelike.Build.cs](/D:/Github/ActionRoguelike/Source/ActionRoguelike/ActionRoguelike.Build.cs)
- 角色基类：[Source/ActionRoguelike/Public/Characters/LBaseCharacter.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Characters/LBaseCharacter.h)
- 主角：[Source/ActionRoguelike/Public/Characters/LHeroCharacter.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Characters/LHeroCharacter.h)
- 敌人：[Source/ActionRoguelike/Public/Characters/LEnemyCharacter.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/Characters/LEnemyCharacter.h)
- ASC：[Source/ActionRoguelike/Public/AbilitySystem/LAbilitySystemComponent.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/AbilitySystem/LAbilitySystemComponent.h)
- 属性集：[Source/ActionRoguelike/Public/AbilitySystem/LAttributeSet.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/AbilitySystem/LAttributeSet.h)
- 标签定义：[Source/ActionRoguelike/Public/LGameplayTags.h](/D:/Github/ActionRoguelike/Source/ActionRoguelike/Public/LGameplayTags.h)

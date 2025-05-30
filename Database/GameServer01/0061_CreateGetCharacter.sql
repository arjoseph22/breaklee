CREATE PROCEDURE GetCharacter (
    IN InCharacterID INT
)
BEGIN
    DECLARE WarehousePassword VARCHAR(255);
    DECLARE WarehouseLocked INT;
    DECLARE InventoryPassword VARCHAR(255);
    DECLARE InventoryLocked INT;

    DECLARE IsWarehousePasswordSet INT DEFAULT 0;
    DECLARE IsInventoryPasswordSet INT DEFAULT 0;
    DECLARE IsWarehouseLocked INT DEFAULT 0;
    DECLARE IsInventoryLocked INT DEFAULT 0;

    -- Prefetch warehouse password and lock status
    SELECT Password, Locked
    INTO WarehousePassword, WarehouseLocked
    FROM Subpasswords
    WHERE AccountID = (SELECT AccountID FROM Characters WHERE CharacterID = InCharacterID)
      AND Type = 2;

    -- Set warehouse password flags
    IF WarehousePassword IS NOT NULL THEN
        SET IsWarehousePasswordSet = 1;
    END IF;
    
    IF WarehouseLocked IS NOT NULL THEN
        SET IsWarehouseLocked = WarehouseLocked;
    ELSE
        SET IsWarehouseLocked = 0;
    END IF;

    -- Prefetch inventory password and lock status
    SELECT Password, Locked
    INTO InventoryPassword, InventoryLocked
    FROM Subpasswords
    WHERE AccountID = (SELECT AccountID FROM Characters WHERE CharacterID = InCharacterID)
      AND Type = 3;

    -- Set inventory password flags
    IF InventoryPassword IS NOT NULL THEN
        SET IsInventoryPasswordSet = 1;
    END IF;

    IF InventoryLocked IS NOT NULL THEN
        SET IsInventoryLocked = InventoryLocked;
    ELSE
        SET IsInventoryLocked = 0;
    END IF;

    SELECT 
        IsWarehousePasswordSet,
        IsInventoryPasswordSet,
        IsWarehouseLocked,
        IsInventoryLocked,
        Characters.WorldIndex,
        Characters.DungeonIndex,
        Characters.X AS PositionX,
        Characters.Y AS PositionY,
        Characters.Exp,
        Characters.Currency,
        Characters.HonorExp,
        Characters.Level AS Level,
        Characters.StatSTR AS StatSTR,
        Characters.StatDEX AS StatDEX,
        Characters.StatINT AS StatINT,
        Characters.StatPNT AS StatPNT,
        Characters.SkillRank AS SkillRank,
        Characters.HP AS HP,
        Characters.MP AS MP,
        Characters.SP AS SP,
        Characters.Rage AS Rage,
        Characters.BP AS BP,
        Characters.DPDuration AS DPDuration,
        Characters.DP AS DP,
        Characters.SkillLevel AS SkillLevel,
        Characters.SkillExp AS SkillExp,
        Characters.SkillPoint AS SkillPoint,
        0 AS RestExp,
        Characters.HonorPoint,
        0 AS DeathPenaltyExp,
        0 AS DeathPenaltyHp,
        0 AS DeathPenaltyMp,
        Characters.PKState,
        Characters.Nation AS Nation,
        Characters.WarpMask,
        Characters.MapsMask,
        Characters.Style,
        Characters.LiveStyle,
        DailyReset.LastResetTimestamp,
        DailyReset.NextResetTimestamp,
        Equipment.EquipmentSlotCount,
        Equipment.InventorySlotCount,
        Equipment.LinkSlotCount,
        Equipment.LockSlotCount,
        Inventory.SlotCount,
        VehicleInventory.SlotCount,
        SkillSlot.SlotCount,
        QuickSlot.SlotCount,
        Mercenary.SlotCount,
        0 AS ItemPeriodCount,
        Ability.APTotal,
        Ability.AP,
        Ability.Axp,
        Ability.EssenceAbilityCount,
        Ability.ExtendedEssenceAbilityCount,
        Ability.BlendedAbilityCount,
        Ability.ExtendedBlendedAbilityCount,
        Ability.KarmaAbilityCount,
        Ability.ExtendedKarmaAbilityCount,
        BlessingBead.SlotCount,
        PremiumService.SlotCount,
        Quest.QuestSlotCount,
        Quest.FinishedQuestData,
        Quest.DeletedQuestData,
        Quest.FinishedQuestDungeonData,
        Quest.FinishedMissionDungeonData,
        DailyQuest.SlotCount,
        0 AS HelpWindow,
        Appearance.EquipmentSlotCount,
        Appearance.InventorySlotCount,
        Achievement.TotalScore,
        Achievement.NormalScore,
        Achievement.QuestScore,
        Achievement.DungeonScore,
        Achievement.ItemsScore,
        Achievement.PvpScore,
        Achievement.WarScore,
        Achievement.HuntingScore,
        Achievement.CraftScore,
        Achievement.CommunityScore,
        Achievement.SharedScore,
        Achievement.SpecialScore,
        Achievement.GeneralMemoirScore,
        Achievement.SharedMemoirScore,
        Achievement.DisplayTitle,
        Achievement.EventTitle,
        Achievement.GuildTitle,
        Achievement.WarTitle,
        Achievement.SlotCount,
        Achievement.RewardSlotCount,
        Craft.SlotCount,
        Craft.Energy,
        RequestCraft.SlotCount,
        RequestCraft.Exp,
        RequestCraft.RegisteredFlagData,
        RequestCraft.FavoriteFlagData,
        RequestCraft.SortingOrder,
        Cooldown.CooldownSlotCount,
        Cooldown.SpiritRaiseCooldown,
        Upgrade.Point,
        Upgrade.Timestamp,
        GoldMeritMastery.MasterySlotCount,
        GoldMeritMastery.Exp,
        GoldMeritMastery.Points,
        PlatinumMeritMastery.IsEnabled,
        PlatinumMeritMastery.Exp,
        PlatinumMeritMastery.Points,
        PlatinumMeritMastery.ActiveMemorizeIndex,
        PlatinumMeritMastery.OpenSlotMasteryIndex,
        PlatinumMeritMastery.OpenSlotUnlockTime,
        PlatinumMeritMastery.TotalMemorizeSlotCount,
        PlatinumMeritMastery.UnlockedSlotCount,
        PlatinumMeritMastery.MasterySlotCount,
        PlatinumMeritMastery.SpecialMasterySlotCount,
        PlatinumMeritMastery.ExtendedMemorizeSlotCount,
        DiamondMeritMastery.IsEnabled,
        DiamondMeritMastery.Exp,
        DiamondMeritMastery.Points,
        DiamondMeritMastery.ActiveMemorizeIndex,
        DiamondMeritMastery.OpenSlotMasteryIndex,
        DiamondMeritMastery.OpenSlotUnlockTime,
        DiamondMeritMastery.TotalMemorizeSlotCount,
        DiamondMeritMastery.UnlockedSlotCount,
        DiamondMeritMastery.MasterySlotCount,
        DiamondMeritMastery.SpecialMasterySlotCount,
        DiamondMeritMastery.SpecialMasteryExp,
        DiamondMeritMastery.ExtendedMemorizeSlotCount,
        AchievementExtended.SlotCount,
        Accounts.ForceGems,
        WarpService.SlotCount,
        OverlordMastery.Level,
        OverlordMastery.Exp,
        OverlordMastery.Points,
        OverlordMastery.SlotCount,
        HonorMedal.Grade,
        HonorMedal.Score,
        HonorMedal.SlotCount,
        ForceWing.Grade,
        ForceWing.Level,
        ForceWing.Exp,
        ForceWing.ActivePresetIndex,
        ForceWing.PresetEnabled,
        ForceWing.PresetTrainingPointCount,
        ForceWing.PresetSlotCount,
        ForceWing.TrainingSlotCount,
        ForceWing.TrainingUnlockFlagData,
        ForceWing.ArrivalSkillSlotData,
        ForceWing.ArrivalSkillRestoreSlotData,
        Giftbox.SpecialBoxPoints,
        Giftbox.SlotCount,
        Collection.SlotCount,
        Transform.SlotCount,
        SecretShop.RefreshCost,
        SecretShop.ResetTimestamp,
        SecretShop.RefreshCount,
        SecretShop.SlotData,
        AuraMastery.Points,
        AuraMastery.AccumulatedTimeInMinutes,
        AuraMastery.SlotCount,
        SkillTranscendence.Points,
        SkillTranscendence.SlotCount,
        DamageBooster.ItemData,
        DamageBooster.SlotCount,
        ResearchSupport.Exp,
        ResearchSupport.DecodedCircuitCount,
        ResearchSupport.ResetCount,
        ResearchSupport.SeasonStartDate,
        ResearchSupport.SeasonEndDate,
        ResearchSupport.MaterialSlotData,
        ResearchSupport.ActiveMissionBoard,
        ResearchSupport.MissionBoardData,
        StellarMastery.SlotCount,
        MythMastery.Rebirth,
        MythMastery.HolyPower,
        MythMastery.Level,
        MythMastery.Exp,
        MythMastery.Points,
        MythMastery.UnlockedPageCount,
        MythMastery.PropertySlotCount,
        MythMastery.StigmaGrade,
        MythMastery.StigmaExp,
        NewbieSupport.Timestamp,
        NewbieSupport.SlotCount,
        EventPass.StartDate,
        EventPass.EndDate,
        EventPass.MissionPageCount,
        EventPass.MissionSlotCount,
        EventPass.RewardSlotCount,
        CostumeWarehouse.SlotCount,
        CostumeWarehouse.MillagePoints,
        Costume.PageCount,
        Costume.AppliedSlotCount,
        Costume.ActivePageIndex,
        Exploration.EndDate,
        Exploration.Points,
        Exploration.Level,
        Exploration.SlotCount,
        AnimaMastery.PresetCount,
        AnimaMastery.StorageCount,
        AnimaMastery.UnlockedCategoryFlags,
        Preset.ConfigurationData,
        Preset.ActiveEquipmentPresetIndex,
        Preset.ActiveAnimaMasteryPresetIndex,
        Settings.HotKeysDataLength,
        Settings.OptionsDataLength,
        Settings.MacrosDataLength,
        Warehouse.Count,
        Warehouse.Currency,
        BattleMode.BattleModeDuration,
        BattleMode.BattleModeIndex,
        BattleMode.BattleModeUnknown1,
        BattleMode.BattleModeStyleRank,
        BattleMode.AuraModeIndex,
        BattleMode.AuraModeUnknown1,
        BattleMode.AuraModeStyleRank,
        BattleMode.AuraModeDuration,
        BattleMode.VehicleState,
        Buff.SkillBuffCount,
        Buff.PotionBuffCount,
        Buff.GmBuffCount,
        Buff.UnknownBuffCount1,
        Buff.UnknownBuffCount2,
        Buff.ForceWingBuffCount,
        Buff.FirePlaceBuffCount,
        LENGTH(Characters.Name) AS NameLength,
        Characters.Name,
        Equipment.EquipmentSlotData,
        Equipment.InventorySlotData,
        Equipment.LinkSlotData,
        Equipment.LockSlotData,
        Inventory.SlotData,
        SkillSlot.SlotData,
        QuickSlot.SlotData,
        Ability.EssenceAbilityData,
        Ability.BlendedAbilityData,
        Ability.KarmaAbilityData,
        BlessingBead.SlotData,
        PremiumService.SlotData,
        Quest.QuestSlotData,
        DailyQuest.SlotData,
        Mercenary.SlotData,
        Appearance.EquipmentSlotData,
        Appearance.InventorySlotData,
        Achievement.SlotData,
        Achievement.RewardSlotData,
        AchievementExtended.SlotData,
        Cooldown.CooldownSlotData,
        Craft.SlotData,
        RequestCraft.SlotData,
        VehicleInventory.SlotData,
        GoldMeritMastery.MasterySlotData,
        PlatinumMeritMastery.ExtendedMemorizeSlotData,
        PlatinumMeritMastery.UnlockedSlotData,
        PlatinumMeritMastery.MasterySlotData,
        PlatinumMeritMastery.SpecialMasterySlotData,
        DiamondMeritMastery.ExtendedMemorizeSlotData,
        DiamondMeritMastery.UnlockedSlotData,
        DiamondMeritMastery.MasterySlotData,
        DiamondMeritMastery.SpecialMasterySlotData,
        WarpService.SlotData,
        OverlordMastery.SlotData,
        HonorMedal.SlotData,
        ForceWing.PresetSlotData,
        ForceWing.TrainingSlotData,
        Giftbox.SlotData,
        Collection.SlotData,
        Transform.SlotData,
        AuraMastery.SlotData,
        SkillTranscendence.SlotData,
        DamageBooster.SlotData,
        StellarMastery.SlotData,
        MythMastery.PropertySlotData,
        NewbieSupport.SlotData,
        EventPass.MissionPageData,
        EventPass.MissionSlotData,
        EventPass.RewardSlotData,
        CostumeWarehouse.SlotData,
        Costume.PageData,
        Costume.AppliedSlotData,
        Exploration.SlotData,
        AnimaMastery.PresetData,
        AnimaMastery.CategoryData,
        Settings.HotKeysData,
        Settings.OptionsData,
        Settings.MacrosData,
        Warehouse.SlotData,
        Buff.SlotData
    FROM Characters
    LEFT JOIN Accounts ON Characters.AccountID = Accounts.AccountID
    LEFT JOIN DailyReset ON Characters.CharacterID = DailyReset.CharacterID
    LEFT JOIN BattleMode ON Characters.CharacterID = BattleMode.CharacterID
    LEFT JOIN Buff ON Characters.CharacterID = Buff.CharacterID
    LEFT JOIN Equipment ON Characters.CharacterID = Equipment.CharacterID
    LEFT JOIN Inventory ON Characters.CharacterID = Inventory.CharacterID
    LEFT JOIN VehicleInventory ON Characters.CharacterID = VehicleInventory.CharacterID
    LEFT JOIN SkillSlot ON Characters.CharacterID = SkillSlot.CharacterID
    LEFT JOIN QuickSlot ON Characters.CharacterID = QuickSlot.CharacterID
    LEFT JOIN Mercenary ON Characters.CharacterID = Mercenary.CharacterID
    LEFT JOIN Ability ON Characters.CharacterID = Ability.CharacterID
    LEFT JOIN BlessingBead ON Characters.CharacterID = BlessingBead.CharacterID
    LEFT JOIN PremiumService ON Characters.CharacterID = PremiumService.CharacterID
    LEFT JOIN Quest ON Characters.CharacterID = Quest.CharacterID
    LEFT JOIN DailyQuest ON Characters.CharacterID = DailyQuest.CharacterID
    LEFT JOIN Appearance ON Characters.CharacterID = Appearance.CharacterID
    LEFT JOIN Achievement ON Characters.CharacterID = Achievement.CharacterID
    LEFT JOIN Craft ON Characters.CharacterID = Craft.CharacterID
    LEFT JOIN RequestCraft ON Characters.CharacterID = RequestCraft.CharacterID
    LEFT JOIN Cooldown ON Characters.CharacterID = Cooldown.CharacterID
    LEFT JOIN Upgrade ON Characters.CharacterID = Upgrade.CharacterID
    LEFT JOIN GoldMeritMastery ON Characters.AccountID = GoldMeritMastery.AccountID
    LEFT JOIN PlatinumMeritMastery ON Characters.AccountID = PlatinumMeritMastery.AccountID
    LEFT JOIN DiamondMeritMastery ON Characters.AccountID = DiamondMeritMastery.AccountID
    LEFT JOIN AchievementExtended ON Characters.CharacterID = AchievementExtended.CharacterID
    LEFT JOIN WarpService ON Characters.CharacterID = AchievementExtended.CharacterID
    LEFT JOIN OverlordMastery ON Characters.CharacterID = OverlordMastery.CharacterID
    LEFT JOIN HonorMedal ON Characters.CharacterID = HonorMedal.CharacterID
    LEFT JOIN ForceWing ON Characters.CharacterID = ForceWing.CharacterID
    LEFT JOIN Giftbox ON Characters.CharacterID = Giftbox.CharacterID
    LEFT JOIN Collection ON Characters.AccountID = Collection.AccountID
    LEFT JOIN Transform ON Characters.CharacterID = Transform.CharacterID
    LEFT JOIN SecretShop ON Characters.CharacterID = SecretShop.CharacterID
    LEFT JOIN AuraMastery ON Characters.CharacterID = AuraMastery.CharacterID
    LEFT JOIN SkillTranscendence ON Characters.CharacterID = SkillTranscendence.CharacterID
    LEFT JOIN DamageBooster ON Characters.CharacterID = DamageBooster.CharacterID
    LEFT JOIN ResearchSupport ON Characters.AccountID = ResearchSupport.AccountID
    LEFT JOIN StellarMastery ON Characters.CharacterID = StellarMastery.CharacterID
    LEFT JOIN MythMastery ON Characters.CharacterID = MythMastery.CharacterID
    LEFT JOIN NewbieSupport ON Characters.CharacterID = NewbieSupport.CharacterID
    LEFT JOIN EventPass ON Characters.AccountID = EventPass.AccountID
    LEFT JOIN CostumeWarehouse ON Characters.AccountID = CostumeWarehouse.AccountID
    LEFT JOIN Costume ON Characters.CharacterID = Costume.CharacterID
    LEFT JOIN Exploration ON Characters.CharacterID = Exploration.CharacterID
    LEFT JOIN AnimaMastery ON Characters.AccountID = AnimaMastery.AccountID
    LEFT JOIN Preset ON Characters.CharacterID = Preset.CharacterID
    LEFT JOIN Settings ON Characters.AccountID = Settings.AccountID
    LEFT JOIN Warehouse ON Characters.AccountID = Warehouse.AccountID
    WHERE Characters.CharacterID = InCharacterID;
END;

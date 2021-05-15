/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (C) 2021 OpenTibiaBR <opentibiabr@outlook.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SRC_LUA_FUNCTIONS_CREATURES_PLAYER_PLAYER_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_PLAYER_PLAYER_FUNCTIONS_HPP_

#include <set>

#include "lua/scripts/luascript.h"
#include "lua/functions/creatures/player/group_functions.hpp"
#include "lua/functions/creatures/player/guild_functions.hpp"
#include "lua/functions/creatures/player/mount_functions.hpp"
#include "lua/functions/creatures/player/party_functions.hpp"
#include "lua/functions/creatures/player/vocation_functions.hpp"

class PlayerFunctions final : LuaScriptInterface
{
private:
	static void init(lua_State* L)
	{
		registerClass(L, "Player", "Creature", luaPlayerCreate);
		registerMetaMethod(L, "Player", "__eq", luaUserdataCompare);

		registerMethod(L, "Player", "resetCharmsBestiary", luaPlayerResetCharmsMonsters);
		registerMethod(L, "Player", "unlockAllCharmRunes", luaPlayerUnlockAllCharmRunes);
		registerMethod(L, "Player", "addCharmPoints", luaPlayeraddCharmPoints);
		registerMethod(L, "Player", "isPlayer", luaPlayerIsPlayer);

		registerMethod(L, "Player", "getGuid", luaPlayerGetGuid);
		registerMethod(L, "Player", "getIp", luaPlayerGetIp);
		registerMethod(L, "Player", "getAccountId", luaPlayerGetAccountId);
		registerMethod(L, "Player", "getLastLoginSaved", luaPlayerGetLastLoginSaved);
		registerMethod(L, "Player", "getLastLogout", luaPlayerGetLastLogout);

		registerMethod(L, "Player", "getAccountType", luaPlayerGetAccountType);
		registerMethod(L, "Player", "setAccountType", luaPlayerSetAccountType);

		registerMethod(L, "Player", "addBestiaryKill", luaPlayeraddBestiaryKill);
		registerMethod(L, "Player", "charmExpansion", luaPlayercharmExpansion);
		registerMethod(L, "Player", "getCharmMonsterType", luaPlayergetCharmMonsterType);

		registerMethod(L, "Player", "getCapacity", luaPlayerGetCapacity);
		registerMethod(L, "Player", "setCapacity", luaPlayerSetCapacity);

		registerMethod(L, "Player", "setTraining", luaPlayerSetTraining);

		registerMethod(L, "Player", "getFreeCapacity", luaPlayerGetFreeCapacity);

		registerMethod(L, "Player", "getKills", luaPlayerGetKills);
		registerMethod(L, "Player", "setKills", luaPlayerSetKills);

		registerMethod(L, "Player", "getReward", luaPlayerGetReward);
		registerMethod(L, "Player", "removeReward", luaPlayerRemoveReward);
		registerMethod(L, "Player", "getRewardList", luaPlayerGetRewardList);

		registerMethod(L, "Player", "setDailyReward", luaPlayerSetDailyReward);

		registerMethod(L, "Player", "sendInventory", luaPlayerSendInventory);
		registerMethod(L, "Player", "sendLootStats", luaPlayerSendLootStats);
		registerMethod(L, "Player", "updateSupplyTracker", luaPlayerUpdateSupplyTracker);
		registerMethod(L, "Player", "updateKillTracker", luaPlayerUpdateKillTracker);

		registerMethod(L, "Player", "updateLootTracker", luaPlayerUpdateLootTracker);

		registerMethod(L, "Player", "getDepotLocker", luaPlayerGetDepotLocker);
		registerMethod(L, "Player", "getDepotChest", luaPlayerGetDepotChest);
		registerMethod(L, "Player", "getInbox", luaPlayerGetInbox);

		registerMethod(L, "Player", "getSkullTime", luaPlayerGetSkullTime);
		registerMethod(L, "Player", "setSkullTime", luaPlayerSetSkullTime);
		registerMethod(L, "Player", "getDeathPenalty", luaPlayerGetDeathPenalty);

		registerMethod(L, "Player", "getExperience", luaPlayerGetExperience);
		registerMethod(L, "Player", "addExperience", luaPlayerAddExperience);
		registerMethod(L, "Player", "removeExperience", luaPlayerRemoveExperience);
		registerMethod(L, "Player", "getLevel", luaPlayerGetLevel);

		registerMethod(L, "Player", "getMagicLevel", luaPlayerGetMagicLevel);
		registerMethod(L, "Player", "getBaseMagicLevel", luaPlayerGetBaseMagicLevel);
		registerMethod(L, "Player", "getMana", luaPlayerGetMana);
		registerMethod(L, "Player", "addMana", luaPlayerAddMana);
		registerMethod(L, "Player", "getMaxMana", luaPlayerGetMaxMana);
		registerMethod(L, "Player", "setMaxMana", luaPlayerSetMaxMana);
		registerMethod(L, "Player", "getManaSpent", luaPlayerGetManaSpent);
		registerMethod(L, "Player", "addManaSpent", luaPlayerAddManaSpent);

		registerMethod(L, "Player", "getBaseMaxHealth", luaPlayerGetBaseMaxHealth);
		registerMethod(L, "Player", "getBaseMaxMana", luaPlayerGetBaseMaxMana);

		registerMethod(L, "Player", "getSkillLevel", luaPlayerGetSkillLevel);
		registerMethod(L, "Player", "getEffectiveSkillLevel", luaPlayerGetEffectiveSkillLevel);
		registerMethod(L, "Player", "getSkillPercent", luaPlayerGetSkillPercent);
		registerMethod(L, "Player", "getSkillTries", luaPlayerGetSkillTries);
		registerMethod(L, "Player", "addSkillTries", luaPlayerAddSkillTries);

		registerMethod(L, "Player", "setMagicLevel", luaPlayerSetMagicLevel);
		registerMethod(L, "Player", "setSkillLevel", luaPlayerSetSkillLevel);

		registerMethod(L, "Player", "addOfflineTrainingTime", luaPlayerAddOfflineTrainingTime);
		registerMethod(L, "Player", "getOfflineTrainingTime", luaPlayerGetOfflineTrainingTime);
		registerMethod(L, "Player", "removeOfflineTrainingTime", luaPlayerRemoveOfflineTrainingTime);

		registerMethod(L, "Player", "addOfflineTrainingTries", luaPlayerAddOfflineTrainingTries);

		registerMethod(L, "Player", "getOfflineTrainingSkill", luaPlayerGetOfflineTrainingSkill);
		registerMethod(L, "Player", "setOfflineTrainingSkill", luaPlayerSetOfflineTrainingSkill);

		registerMethod(L, "Player", "getItemCount", luaPlayerGetItemCount);
		registerMethod(L, "Player", "getStashItemCount", luaPlayerGetStashItemCount);
		registerMethod(L, "Player", "getItemById", luaPlayerGetItemById);

		registerMethod(L, "Player", "getVocation", luaPlayerGetVocation);
		registerMethod(L, "Player", "setVocation", luaPlayerSetVocation);

		registerMethod(L, "Player", "getSex", luaPlayerGetSex);
		registerMethod(L, "Player", "setSex", luaPlayerSetSex);

		registerMethod(L, "Player", "getTown", luaPlayerGetTown);
		registerMethod(L, "Player", "setTown", luaPlayerSetTown);

		registerMethod(L, "Player", "getGuild", luaPlayerGetGuild);
		registerMethod(L, "Player", "setGuild", luaPlayerSetGuild);

		registerMethod(L, "Player", "getGuildLevel", luaPlayerGetGuildLevel);
		registerMethod(L, "Player", "setGuildLevel", luaPlayerSetGuildLevel);

		registerMethod(L, "Player", "getGuildNick", luaPlayerGetGuildNick);
		registerMethod(L, "Player", "setGuildNick", luaPlayerSetGuildNick);

		registerMethod(L, "Player", "getGroup", luaPlayerGetGroup);
		registerMethod(L, "Player", "setGroup", luaPlayerSetGroup);

		registerMethod(L, "Player", "setSpecialContainersAvailable", luaPlayerSetSpecialContainersAvailable);
		registerMethod(L, "Player", "getStashCount", luaPlayerGetStashCounter);
		registerMethod(L, "Player", "openStash", luaPlayerOpenStash);

		registerMethod(L, "Player", "getStamina", luaPlayerGetStamina);
		registerMethod(L, "Player", "setStamina", luaPlayerSetStamina);

		registerMethod(L, "Player", "getPreyStamina", luaPlayerGetPreyStamina);
		registerMethod(L, "Player", "getPreyType", luaPlayerGetPreyType);
		registerMethod(L, "Player", "getPreyValue", luaPlayerGetPreyValue);
		registerMethod(L, "Player", "getPreyName", luaPlayerGetPreyName);
		registerMethod(L, "Player", "setPreyStamina", luaPlayerSetPreyStamina);
		registerMethod(L, "Player", "setPreyType", luaPlayerSetPreyType);
		registerMethod(L, "Player", "setPreyValue", luaPlayerSetPreyValue);
		registerMethod(L, "Player", "setPreyName", luaPlayerSetPreyName);

		registerMethod(L, "Player", "getSoul", luaPlayerGetSoul);
		registerMethod(L, "Player", "addSoul", luaPlayerAddSoul);
		registerMethod(L, "Player", "getMaxSoul", luaPlayerGetMaxSoul);

		registerMethod(L, "Player", "getBankBalance", luaPlayerGetBankBalance);
		registerMethod(L, "Player", "setBankBalance", luaPlayerSetBankBalance);

		registerMethod(L, "Player", "getStorageValue", luaPlayerGetStorageValue);
		registerMethod(L, "Player", "setStorageValue", luaPlayerSetStorageValue);

		registerMethod(L, "Player", "addItem", luaPlayerAddItem);
		registerMethod(L, "Player", "addItemEx", luaPlayerAddItemEx);
		registerMethod(L, "Player", "removeStashItem", luaPlayerRemoveStashItem);
		registerMethod(L, "Player", "removeItem", luaPlayerRemoveItem);
		registerMethod(L, "Player", "sendContainer", luaPlayerSendContainer);

		registerMethod(L, "Player", "getMoney", luaPlayerGetMoney);
		registerMethod(L, "Player", "addMoney", luaPlayerAddMoney);
		registerMethod(L, "Player", "removeMoney", luaPlayerRemoveMoney);

		registerMethod(L, "Player", "showTextDialog", luaPlayerShowTextDialog);

		registerMethod(L, "Player", "sendTextMessage", luaPlayerSendTextMessage);
		registerMethod(L, "Player", "sendChannelMessage", luaPlayerSendChannelMessage);
		registerMethod(L, "Player", "sendPrivateMessage", luaPlayerSendPrivateMessage);
		registerMethod(L, "Player", "channelSay", luaPlayerChannelSay);
		registerMethod(L, "Player", "openChannel", luaPlayerOpenChannel);

		registerMethod(L, "Player", "getSlotItem", luaPlayerGetSlotItem);

		registerMethod(L, "Player", "getParty", luaPlayerGetParty);

		registerMethod(L, "Player", "addOutfit", luaPlayerAddOutfit);
		registerMethod(L, "Player", "addOutfitAddon", luaPlayerAddOutfitAddon);
		registerMethod(L, "Player", "removeOutfit", luaPlayerRemoveOutfit);
		registerMethod(L, "Player", "removeOutfitAddon", luaPlayerRemoveOutfitAddon);
		registerMethod(L, "Player", "hasOutfit", luaPlayerHasOutfit);
		registerMethod(L, "Player", "sendOutfitWindow", luaPlayerSendOutfitWindow);

		registerMethod(L, "Player", "addMount", luaPlayerAddMount);
		registerMethod(L, "Player", "removeMount", luaPlayerRemoveMount);
		registerMethod(L, "Player", "hasMount", luaPlayerHasMount);

		registerMethod(L, "Player", "addFamiliar", luaPlayerAddFamiliar);
		registerMethod(L, "Player", "removeFamiliar", luaPlayerRemoveFamiliar);
		registerMethod(L, "Player", "hasFamiliar", luaPlayerHasFamiliar);
		registerMethod(L, "Player", "setFamiliarLooktype", luaPlayerSetFamiliarLooktype);
		registerMethod(L, "Player", "getFamiliarLooktype", luaPlayerGetFamiliarLooktype);

		registerMethod(L, "Player", "getPremiumDays", luaPlayerGetPremiumDays);
		registerMethod(L, "Player", "addPremiumDays", luaPlayerAddPremiumDays);
		registerMethod(L, "Player", "removePremiumDays", luaPlayerRemovePremiumDays);

		registerMethod(L, "Player", "getTibiaCoins", luaPlayerGetTibiaCoins);
		registerMethod(L, "Player", "addTibiaCoins", luaPlayerAddTibiaCoins);
		registerMethod(L, "Player", "removeTibiaCoins", luaPlayerRemoveTibiaCoins);

		registerMethod(L, "Player", "hasBlessing", luaPlayerHasBlessing);
		registerMethod(L, "Player", "addBlessing", luaPlayerAddBlessing);
		registerMethod(L, "Player", "removeBlessing", luaPlayerRemoveBlessing);
		registerMethod(L, "Player", "getBlessingCount", luaPlayerGetBlessingCount);

		registerMethod(L, "Player", "canLearnSpell", luaPlayerCanLearnSpell);
		registerMethod(L, "Player", "learnSpell", luaPlayerLearnSpell);
		registerMethod(L, "Player", "forgetSpell", luaPlayerForgetSpell);
		registerMethod(L, "Player", "hasLearnedSpell", luaPlayerHasLearnedSpell);

		registerMethod(L, "Player", "sendImbuementPanel", luaPlayerSendImbuementPanel);

		registerMethod(L, "Player", "sendTutorial", luaPlayerSendTutorial);
		registerMethod(L, "Player", "addMapMark", luaPlayerAddMapMark);

		registerMethod(L, "Player", "save", luaPlayerSave);
		registerMethod(L, "Player", "popupFYI", luaPlayerPopupFYI);

		registerMethod(L, "Player", "isPzLocked", luaPlayerIsPzLocked);

		registerMethod(L, "Player", "getClient", luaPlayerGetClient);

		// New prey
		// GET
		registerMethod(L, "Player", "getPreyState", luaPlayerGetPreyState);
		registerMethod(L, "Player", "getPreyUnlocked", luaPlayerGetPreyUnlocked);
		registerMethod(L, "Player", "getPreyCurrentMonster", luaPlayerGetPreyCurrentMonster);
		registerMethod(L, "Player", "getPreyMonsterList", luaPlayerGetPreyMonsterList);
		registerMethod(L, "Player", "getPreyFreeRerollIn", luaPlayerGetPreyFreeRerollIn);
		registerMethod(L, "Player", "getPreyTimeLeft", luaPlayerGetPreyTimeLeft);
		registerMethod(L, "Player", "getPreyNextUse", luaPlayerGetPreyNextUse);
		registerMethod(L, "Player", "getPreyBonusType", luaPlayerGetPreyBonusType);
		registerMethod(L, "Player", "getPreyBonusValue", luaPlayerGetPreyBonusValue);
		registerMethod(L, "Player", "getPreyBonusGrade", luaPlayerGetPreyBonusGrade);
		registerMethod(L, "Player", "getPreyBonusRerolls", luaPlayerGetPreyBonusRerolls);
		registerMethod(L, "Player", "getPreyTick", luaPlayerGetPreyTick);
		// SET
		registerMethod(L, "Player", "setPreyState", luaPlayerSetPreyState);
		registerMethod(L, "Player", "setPreyUnlocked", luaPlayerSetPreyUnlocked);
		registerMethod(L, "Player", "setPreyCurrentMonster", luaPlayerSetPreyCurrentMonster);
		registerMethod(L, "Player", "setPreyMonsterList", luaPlayerSetPreyMonsterList);
		registerMethod(L, "Player", "setPreyFreeRerollIn", luaPlayerSetPreyFreeRerollIn);
		registerMethod(L, "Player", "setPreyTimeLeft", luaPlayerSetPreyTimeLeft);
		registerMethod(L, "Player", "setPreyNextUse", luaPlayerSetPreyNextUse);
		registerMethod(L, "Player", "setPreyBonusType", luaPlayerSetPreyBonusType);
		registerMethod(L, "Player", "setPreyBonusValue", luaPlayerSetPreyBonusValue);
		registerMethod(L, "Player", "setPreyBonusGrade", luaPlayerSetPreyBonusGrade);
		registerMethod(L, "Player", "setPreyBonusRerolls", luaPlayerSetPreyBonusRerolls);
		registerMethod(L, "Player", "setPreyTick", luaPlayerSetPreyTick);

		registerMethod(L, "Player", "getHouse", luaPlayerGetHouse);
		registerMethod(L, "Player", "sendHouseWindow", luaPlayerSendHouseWindow);
		registerMethod(L, "Player", "setEditHouse", luaPlayerSetEditHouse);

		registerMethod(L, "Player", "setGhostMode", luaPlayerSetGhostMode);

		registerMethod(L, "Player", "getContainerId", luaPlayerGetContainerId);
		registerMethod(L, "Player", "getContainerById", luaPlayerGetContainerById);
		registerMethod(L, "Player", "getContainerIndex", luaPlayerGetContainerIndex);

		registerMethod(L, "Player", "getInstantSpells", luaPlayerGetInstantSpells);
		registerMethod(L, "Player", "canCast", luaPlayerCanCast);

		registerMethod(L, "Player", "hasChaseMode", luaPlayerHasChaseMode);
		registerMethod(L, "Player", "hasSecureMode", luaPlayerHasSecureMode);
		registerMethod(L, "Player", "getFightMode", luaPlayerGetFightMode);

		registerMethod(L, "Player", "getBaseXpGain", luaPlayerGetBaseXpGain);
		registerMethod(L, "Player", "setBaseXpGain", luaPlayerSetBaseXpGain);
		registerMethod(L, "Player", "getVoucherXpBoost", luaPlayerGetVoucherXpBoost);
		registerMethod(L, "Player", "setVoucherXpBoost", luaPlayerSetVoucherXpBoost);
		registerMethod(L, "Player", "getGrindingXpBoost", luaPlayerGetGrindingXpBoost);
		registerMethod(L, "Player", "setGrindingXpBoost", luaPlayerSetGrindingXpBoost);
		registerMethod(L, "Player", "getStoreXpBoost", luaPlayerGetStoreXpBoost);
		registerMethod(L, "Player", "setStoreXpBoost", luaPlayerSetStoreXpBoost);
		registerMethod(L, "Player", "getStaminaXpBoost", luaPlayerGetStaminaXpBoost);
		registerMethod(L, "Player", "setStaminaXpBoost", luaPlayerSetStaminaXpBoost);
		registerMethod(L, "Player", "getExpBoostStamina", luaPlayerGetExpBoostStamina);
		registerMethod(L, "Player", "setExpBoostStamina", luaPlayerSetExpBoostStamina);

		registerMethod(L, "Player", "getIdleTime", luaPlayerGetIdleTime);
		registerMethod(L, "Player", "getFreeBackpackSlots", luaPlayerGetFreeBackpackSlots);

		registerMethod(L, "Player", "isOffline", luaPlayerIsOffline);

		registerMethod(L, "Player", "openMarket", luaPlayerOpenMarket);

		GroupFunctions::init(L);
		GuildFunctions::init(L);
		MountFunctions::init(L);
		PartyFunctions::init(L);
		VocationFunctions::init(L);
	}

	static int luaPlayerCreate(lua_State* L);

	static int luaPlayerUnlockAllCharmRunes(lua_State* L);
	static int luaPlayerResetCharmsMonsters(lua_State* L);
	static int luaPlayeraddCharmPoints(lua_State* L);
	static int luaPlayerIsPlayer(lua_State* L);

	static int luaPlayerGetGuid(lua_State* L);
	static int luaPlayerGetIp(lua_State* L);
	static int luaPlayerGetAccountId(lua_State* L);
	static int luaPlayerGetLastLoginSaved(lua_State* L);
	static int luaPlayerGetLastLogout(lua_State* L);

	static int luaPlayerGetAccountType(lua_State* L);
	static int luaPlayerSetAccountType(lua_State* L);

	static int luaPlayeraddBestiaryKill(lua_State* L);
	static int luaPlayercharmExpansion(lua_State* L);
	static int luaPlayergetCharmMonsterType(lua_State* L);

	static int luaPlayerGetCapacity(lua_State* L);
	static int luaPlayerSetCapacity(lua_State* L);

	static int luaPlayerSetTraining(lua_State* L);

	static int luaPlayerGetKills(lua_State* L);
	static int luaPlayerSetKills(lua_State* L);

	static int luaPlayerGetFreeCapacity(lua_State* L);

	static int luaPlayerGetReward(lua_State* L);
	static int luaPlayerRemoveReward(lua_State* L);
	static int luaPlayerGetRewardList(lua_State* L);

	static int luaPlayerSetDailyReward(lua_State* L);

	static int luaPlayerSendInventory(lua_State* L);
	static int luaPlayerSendLootStats(lua_State* L);
	static int luaPlayerUpdateKillTracker(lua_State* L);
	static int luaPlayerUpdateLootTracker(lua_State* L);
	static int luaPlayerUpdateSupplyTracker(lua_State* L);

	static int luaPlayerGetDepotLocker(lua_State* L);
	static int luaPlayerGetDepotChest(lua_State* L);
	static int luaPlayerGetInbox(lua_State* L);

	static int luaPlayerGetSkullTime(lua_State* L);
	static int luaPlayerSetSkullTime(lua_State* L);
	static int luaPlayerGetDeathPenalty(lua_State* L);

	static int luaPlayerGetExperience(lua_State* L);
	static int luaPlayerAddExperience(lua_State* L);
	static int luaPlayerRemoveExperience(lua_State* L);
	static int luaPlayerGetLevel(lua_State* L);

	static int luaPlayerGetMagicLevel(lua_State* L);
	static int luaPlayerGetBaseMagicLevel(lua_State* L);
	static int luaPlayerGetMana(lua_State* L);
	static int luaPlayerAddMana(lua_State* L);
	static int luaPlayerGetMaxMana(lua_State* L);
	static int luaPlayerSetMaxMana(lua_State* L);
	static int luaPlayerGetManaSpent(lua_State* L);
	static int luaPlayerAddManaSpent(lua_State* L);

	static int luaPlayerGetBaseMaxHealth(lua_State* L);
	static int luaPlayerGetBaseMaxMana(lua_State* L);

	static int luaPlayerGetSkillLevel(lua_State* L);
	static int luaPlayerGetEffectiveSkillLevel(lua_State* L);
	static int luaPlayerGetSkillPercent(lua_State* L);
	static int luaPlayerGetSkillTries(lua_State* L);
	static int luaPlayerAddSkillTries(lua_State* L);

	static int luaPlayerSetMagicLevel(lua_State* L);
	static int luaPlayerSetSkillLevel(lua_State* L);

	static int luaPlayerAddOfflineTrainingTime(lua_State* L);
	static int luaPlayerGetOfflineTrainingTime(lua_State* L);
	static int luaPlayerRemoveOfflineTrainingTime(lua_State* L);

	static int luaPlayerAddOfflineTrainingTries(lua_State* L);

	static int luaPlayerGetOfflineTrainingSkill(lua_State* L);
	static int luaPlayerSetOfflineTrainingSkill(lua_State* L);

	static int luaPlayerGetItemCount(lua_State* L);
	static int luaPlayerGetStashItemCount(lua_State* L);
	static int luaPlayerGetItemById(lua_State* L);

	static int luaPlayerGetVocation(lua_State* L);
	static int luaPlayerSetVocation(lua_State* L);

	static int luaPlayerGetSex(lua_State* L);
	static int luaPlayerSetSex(lua_State* L);

	static int luaPlayerGetTown(lua_State* L);
	static int luaPlayerSetTown(lua_State* L);

	static int luaPlayerGetGuild(lua_State* L);
	static int luaPlayerSetGuild(lua_State* L);

	static int luaPlayerGetGuildLevel(lua_State* L);
	static int luaPlayerSetGuildLevel(lua_State* L);

	static int luaPlayerGetGuildNick(lua_State* L);
	static int luaPlayerSetGuildNick(lua_State* L);

	static int luaPlayerGetGroup(lua_State* L);
	static int luaPlayerSetGroup(lua_State* L);

	static int luaPlayerIsSupplyStashAvailable(lua_State* L);
	static int luaPlayerGetStashCounter(lua_State* L);
	static int luaPlayerOpenStash(lua_State* L);
	static int luaPlayerSetSpecialContainersAvailable(lua_State* L);

	static int luaPlayerGetStamina(lua_State* L);
	static int luaPlayerSetStamina(lua_State* L);

	static int luaPlayerGetPreyStamina(lua_State* L);
	static int luaPlayerGetPreyType(lua_State* L);
	static int luaPlayerGetPreyValue(lua_State* L);
	static int luaPlayerGetPreyName(lua_State* L);
	static int luaPlayerSetPreyStamina(lua_State* L);
	static int luaPlayerSetPreyType(lua_State* L);
	static int luaPlayerSetPreyValue(lua_State* L);
	static int luaPlayerSetPreyName(lua_State* L);

	static int luaPlayerGetSoul(lua_State* L);
	static int luaPlayerAddSoul(lua_State* L);
	static int luaPlayerGetMaxSoul(lua_State* L);

	static int luaPlayerGetBankBalance(lua_State* L);
	static int luaPlayerSetBankBalance(lua_State* L);

	static int luaPlayerGetStorageValue(lua_State* L);
	static int luaPlayerSetStorageValue(lua_State* L);

	static int luaPlayerAddItem(lua_State* L);
	static int luaPlayerAddItemEx(lua_State* L);
	static int luaPlayerRemoveStashItem(lua_State* L);
	static int luaPlayerRemoveItem(lua_State* L);
	static int luaPlayerSendContainer(lua_State* L);

	static int luaPlayerGetMoney(lua_State* L);
	static int luaPlayerAddMoney(lua_State* L);
	static int luaPlayerRemoveMoney(lua_State* L);

	static int luaPlayerShowTextDialog(lua_State* L);

	static int luaPlayerSendTextMessage(lua_State* L);
	static int luaPlayerSendChannelMessage(lua_State* L);
	static int luaPlayerSendPrivateMessage(lua_State* L);

	static int luaPlayerChannelSay(lua_State* L);
	static int luaPlayerOpenChannel(lua_State* L);

	static int luaPlayerGetSlotItem(lua_State* L);

	static int luaPlayerGetParty(lua_State* L);

	static int luaPlayerAddOutfit(lua_State* L);
	static int luaPlayerAddOutfitAddon(lua_State* L);
	static int luaPlayerRemoveOutfit(lua_State* L);
	static int luaPlayerRemoveOutfitAddon(lua_State* L);
	static int luaPlayerHasOutfit(lua_State* L);
	static int luaPlayerSendOutfitWindow(lua_State* L);

	static int luaPlayerAddMount(lua_State* L);
	static int luaPlayerRemoveMount(lua_State* L);
	static int luaPlayerHasMount(lua_State* L);

	static int luaPlayerAddFamiliar(lua_State* L);
	static int luaPlayerRemoveFamiliar(lua_State* L);
	static int luaPlayerHasFamiliar(lua_State* L);
	static int luaPlayerSetFamiliarLooktype(lua_State* L);
	static int luaPlayerGetFamiliarLooktype(lua_State* L);

	static int luaPlayerGetPremiumDays(lua_State* L);
	static int luaPlayerAddPremiumDays(lua_State* L);
	static int luaPlayerRemovePremiumDays(lua_State* L);

	static int luaPlayerGetTibiaCoins(lua_State* L);
	static int luaPlayerAddTibiaCoins(lua_State* L);
	static int luaPlayerRemoveTibiaCoins(lua_State* L);

	static int luaPlayerHasBlessing(lua_State* L);
	static int luaPlayerAddBlessing(lua_State* L);
	static int luaPlayerRemoveBlessing(lua_State* L);

	static int luaPlayerGetBlessingCount(lua_State* L);

	static int luaPlayerCanLearnSpell(lua_State* L);
	static int luaPlayerLearnSpell(lua_State* L);
	static int luaPlayerForgetSpell(lua_State* L);
	static int luaPlayerHasLearnedSpell(lua_State* L);

	static int luaPlayerSendImbuementPanel(lua_State* L);

	static int luaPlayerSendTutorial(lua_State* L);
	static int luaPlayerAddMapMark(lua_State* L);

	static int luaPlayerSave(lua_State* L);
	static int luaPlayerPopupFYI(lua_State* L);

	static int luaPlayerIsPzLocked(lua_State* L);
	static int luaPlayerIsOffline(lua_State* L);

	static int luaPlayerGetContainers(lua_State* L);
	static int luaPlayerSetLootContainer(lua_State* L);
	static int luaPlayerGetLootContainer(lua_State* L);

	static int luaPlayerGetPreyState(lua_State* L);
	static int luaPlayerGetPreyUnlocked(lua_State* L);
	static int luaPlayerGetPreyCurrentMonster(lua_State* L);
	static int luaPlayerGetPreyMonsterList(lua_State* L);
	static int luaPlayerGetPreyFreeRerollIn(lua_State* L);
	static int luaPlayerGetPreyTimeLeft(lua_State* L);
	static int luaPlayerGetPreyNextUse(lua_State* L);
	static int luaPlayerGetPreyBonusType(lua_State* L);
	static int luaPlayerGetPreyBonusValue(lua_State* L);
	static int luaPlayerGetPreyBonusGrade(lua_State* L);
	static int luaPlayerGetPreyBonusRerolls(lua_State* L);
	static int luaPlayerGetPreyTick(lua_State* L);

	static int luaPlayerSetPreyState(lua_State* L);
	static int luaPlayerSetPreyUnlocked(lua_State* L);
	static int luaPlayerSetPreyCurrentMonster(lua_State* L);
	static int luaPlayerSetPreyMonsterList(lua_State* L);
	static int luaPlayerSetPreyFreeRerollIn(lua_State* L);
	static int luaPlayerSetPreyTimeLeft(lua_State* L);
	static int luaPlayerSetPreyNextUse(lua_State* L);
	static int luaPlayerSetPreyBonusType(lua_State* L);
	static int luaPlayerSetPreyBonusValue(lua_State* L);
	static int luaPlayerSetPreyBonusGrade(lua_State* L);
	static int luaPlayerSetPreyBonusRerolls(lua_State* L);
	static int luaPlayerSetPreyTick(lua_State* L);

	static int luaPlayerGetClient(lua_State* L);

	static int luaPlayerGetHouse(lua_State* L);
	static int luaPlayerSendHouseWindow(lua_State* L);
	static int luaPlayerSetEditHouse(lua_State* L);

	static int luaPlayerSetGhostMode(lua_State* L);

	static int luaPlayerGetContainerId(lua_State* L);
	static int luaPlayerGetContainerById(lua_State* L);
	static int luaPlayerGetContainerIndex(lua_State* L);

	static int luaPlayerGetInstantSpells(lua_State* L);
	static int luaPlayerCanCast(lua_State* L);

	static int luaPlayerHasChaseMode(lua_State* L);
	static int luaPlayerHasSecureMode(lua_State* L);
	static int luaPlayerGetFightMode(lua_State* L);

	static int luaPlayerGetBaseXpGain(lua_State* L);
	static int luaPlayerSetBaseXpGain(lua_State* L);
	static int luaPlayerGetVoucherXpBoost(lua_State* L);
	static int luaPlayerSetVoucherXpBoost(lua_State* L);
	static int luaPlayerGetGrindingXpBoost(lua_State* L);
	static int luaPlayerSetGrindingXpBoost(lua_State* L);
	static int luaPlayerGetStoreXpBoost(lua_State* L);
	static int luaPlayerSetStoreXpBoost(lua_State* L);
	static int luaPlayerGetStaminaXpBoost(lua_State* L);
	static int luaPlayerSetStaminaXpBoost(lua_State* L);
	static int luaPlayerGetExpBoostStamina(lua_State* L);
	static int luaPlayerSetExpBoostStamina(lua_State* L);

	static int luaPlayerGetIdleTime(lua_State* L);
	static int luaPlayerGetFreeBackpackSlots(lua_State* L);

	static int luaPlayerOpenMarket(lua_State* L);

	friend class CreatureFunctions;
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_PLAYER_PLAYER_FUNCTIONS_HPP_

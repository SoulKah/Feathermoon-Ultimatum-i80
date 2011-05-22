#include "ScriptPCH.h"

enum eCreatureCredit
{
	CREDIT_WINDUEL_RANDOM = 80050,
	CREDIT_WINDUEL_ALL = 80051,

	CREDIT_WINDUEL_ROGUE = 80052,
	CREDIT_WINDUEL_WARLOCK = 80053,
	CREDIT_WINDUEL_WARRIOR = 80054,
	CREDIT_WINDUEL_SHAMAN = 80055,
	CREDIT_WINDUEL_PRIEST = 80056,
	CREDIT_WINDUEL_PALADIN = 80057,
	CREDIT_WINDUEL_DRUID = 80058,
	CREDIT_WINDUEL_MAGE = 80059,
	CREDIT_WINDUEL_DEATH_KNIGHT = 80060,
	CREDIT_WINDUEL_HUNTER = 80061,
};

enum eQuestList
{
	QUEST_WINDUEL_RANDOM = 85000,
	QUEST_WINDUEL_ALL = 85001,
	
	QUEST_WINDUEL_ROGUE = 85002,
	QUEST_WINDUEL_WARLOCK = 85003,
	QUEST_WINDUEL_WARRIOR = 85004,
	QUEST_WINDUEL_SHAMAN = 85005,
	QUEST_WINDUEL_PRIEST = 85006,
	QUEST_WINDUEL_PALADIN = 85007,
	QUEST_WINDUEL_DRUID = 85008,
	QUEST_WINDUEL_MAGE = 85009,
	QUEST_WINDUEL_DEATH_KNIGHT =85010,
	QUEST_WINDUEL_HUNTER = 85011,
};

class system_hook : public PlayerScript
{
    public:
        system_hook() : PlayerScript("system_hook") {}
        
    // Hook PvP
    void OnPvPKill(Player *pKiller, Player *pVictim)
    {
    }

   // Hook Player Login
   void OnPlayerLogout(Player *pPlayer)
   {
   }

   // Hook Duel end
   void OnDuelEnd(Player *winner, Player *loser, DuelCompleteType type)
   {
		if(winner->GetQuestStatus(QUEST_WINDUEL_RANDOM) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_RANDOM,0);
	  
		if(winner->GetQuestStatus(QUEST_WINDUEL_ROGUE) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_ROGUE,0);
	   
		if(winner->GetQuestStatus(QUEST_WINDUEL_WARLOCK) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_WARLOCK,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_WARRIOR) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_WARRIOR,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_SHAMAN) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_SHAMAN,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_PRIEST) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_PRIEST,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_PALADIN) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_PALADIN,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_DRUID) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_DRUID,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_MAGE) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_MAGE,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_DEATH_KNIGHT) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_DEATH_KNIGHT,0);

		if(winner->GetQuestStatus(QUEST_WINDUEL_HUNTER) == QUEST_STATUS_INCOMPLETE)
		   winner->KilledMonsterCredit(CREDIT_WINDUEL_HUNTER,0);
	   
	   if(winner->GetQuestStatus(QUEST_WINDUEL_ALL) == QUEST_STATUS_INCOMPLETE)
	   {
		   switch(loser->getClass())
		   {
				case CLASS_ROGUE :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_ROGUE,0);
				break;

				case CLASS_HUNTER :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_HUNTER,0);
				break;

				case CLASS_PALADIN :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_PALADIN,0);
				break;

				case CLASS_WARRIOR :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_WARRIOR,0);
				break;
					
				case CLASS_PRIEST :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_PRIEST,0);
				break;

				case CLASS_DEATH_KNIGHT :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_DEATH_KNIGHT,0);
				break;

				case CLASS_SHAMAN :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_SHAMAN,0);
				break;

				case CLASS_MAGE:
					winner->KilledMonsterCredit(CREDIT_WINDUEL_MAGE,0);
				break;

				case CLASS_WARLOCK :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_WARLOCK,0);
				break;

				case CLASS_DRUID :
					winner->KilledMonsterCredit(CREDIT_WINDUEL_DRUID,0);
				break;

				default:
				break;
		   }
	   }

   }
};

void AddSC_system_hook()
{
    new system_hook;
}
﻿#pragma once

#ifdef USE_AHNLAB_HACKSHIELD
#include "Hackshield.h"
#include METIN2HS_INCLUDE_ANTICPXSVR
#else
#pragma pack(push) //±âÁ¸ alignment ÀúÀå

#pragma pack(8)

#define ANTICPX_TRANS_BUFFER_MAX			400

typedef struct _AHNHS_TRANS_BUFFER
{
	unsigned char byBuffer[ANTICPX_TRANS_BUFFER_MAX/* ¼Û¼ö½Å ÆÐÅ¶ÀÇ ÃÖ´ë Å©±â */];
	unsigned short nLength;
} AHNHS_TRANS_BUFFER, *PAHNHS_TRANS_BUFFER;

#pragma pack(pop) // ±âÁ¸ alignment º¹±¸.

#endif /* !USE_AHNLAB_HACKSHIELD */

#include "../gamelib/RaceData.h"

typedef BYTE TPacketHeader;

enum
{
	/////////////////////////////////////////////////
	// To Server
	// HEADER_BLANK is the not use(for future use)
	HEADER_CG_LOGIN = 1,
	HEADER_CG_ATTACK = 2,
	HEADER_CG_CHAT = 3,
	HEADER_CG_PLAYER_CREATE = 4,		// 새로운 플래이어를 생성
	HEADER_CG_PLAYER_DESTROY = 5,		// 플래이어를 삭제.
	HEADER_CG_PLAYER_SELECT = 6,
	HEADER_CG_CHARACTER_MOVE = 7,
	HEADER_CG_SYNC_POSITION = 8,
	HEADER_CG_DIRECT_ENTER = 9,
	HEADER_CG_ENTERGAME = 10,
	HEADER_CG_ITEM_USE = 11,
	HEADER_CG_ITEM_DROP = 12,
	HEADER_CG_ITEM_MOVE = 13,
	HEADER_CG_ITEM_PICKUP = 15,
	HEADER_CG_QUICKSLOT_ADD = 16,
	HEADER_CG_QUICKSLOT_DEL = 17,
	HEADER_CG_QUICKSLOT_SWAP = 18,
	HEADER_CG_WHISPER = 19,
	HEADER_CG_ITEM_DROP2 = 20,
	HEADER_CG_ITEM_DESTROY = 21,
	//HEADER_BLANK21								= 21,
	//HEADER_BLANK22								= 22,
	//HEADER_BLANK22								= 23,
	//HEADER_BLANK24								= 24,
	//HEADER_BLANK25								= 25,
	HEADER_CG_ON_CLICK = 26,
	HEADER_CG_EXCHANGE = 27,
	HEADER_CG_CHARACTER_POSITION = 28,
	HEADER_CG_SCRIPT_ANSWER = 29,
	HEADER_CG_QUEST_INPUT_STRING = 30,
	HEADER_CG_QUEST_CONFIRM = 31,
	//HEADER_BLANK32								= 32,
	//HEADER_BLANK33								= 33,
	//HEADER_BLANK34								= 34,
	//HEADER_BLANK35								= 35,
	//HEADER_BLANK36								= 36,
	//HEADER_BLANK37								= 37,
	//HEADER_BLANK38								= 38,
	//HEADER_BLANK39								= 39,
	//HEADER_BLANK40								= 40,
	HEADER_CG_PVP = 41,
	//HEADER_BLANK42								= 42,
	//HEADER_BLANK43								= 43,
	//HEADER_BLANK44								= 44,
	//HEADER_BLANK45								= 45,
	//HEADER_BLANK46								= 46,
	//HEADER_BLANK47								= 47,
	//HEADER_BLANK48								= 48,
	//HEADER_BLANK49								= 49,
	HEADER_CG_SHOP = 50,
	HEADER_CG_FLY_TARGETING = 51,
	HEADER_CG_USE_SKILL = 52,
	HEADER_CG_ADD_FLY_TARGETING = 53,
	HEADER_CG_SHOOT = 54,
	HEADER_CG_MYSHOP = 55,
	//HEADER_BLANK56								= 56,
	//HEADER_BLANK57								= 57,
	//HEADER_BLANK58								= 58,
	//HEADER_BLANK59								= 59,
	HEADER_CG_ITEM_USE_TO_ITEM = 60,
	HEADER_CG_TARGET = 61,
	//HEADER_BLANK62								= 62,
	//HEADER_BLANK63								= 63,
	//HEADER_BLANK64								= 64,
	HEADER_CG_WARP = 65,
	HEADER_CG_SCRIPT_BUTTON = 66,
	HEADER_CG_MESSENGER = 67,
	//HEADER_BLANK68								= 68,
	HEADER_CG_MALL_CHECKOUT = 69,
	HEADER_CG_SAFEBOX_CHECKIN = 70,   // 아이템을 창고에 넣는다.
	HEADER_CG_SAFEBOX_CHECKOUT = 71,   // 아이템을 창고로 부터 빼온다.
	HEADER_CG_PARTY_INVITE = 72,
	HEADER_CG_PARTY_INVITE_ANSWER = 73,
	HEADER_CG_PARTY_REMOVE = 74,
	HEADER_CG_PARTY_SET_STATE = 75,
	HEADER_CG_PARTY_USE_SKILL = 76,
	HEADER_CG_SAFEBOX_ITEM_MOVE = 77,
	HEADER_CG_PARTY_PARAMETER = 78,
	//HEADER_BLANK68								= 79,
	HEADER_CG_GUILD = 80,
	HEADER_CG_ANSWER_MAKE_GUILD = 81,
	HEADER_CG_FISHING = 82,
	HEADER_CG_GIVE_ITEM = 83,
	//HEADER_BLANK84								= 84,
	//HEADER_BLANK85								= 85,
	//HEADER_BLANK86								= 86,
	//HEADER_BLANK87								= 87,
	//HEADER_BLANK88								= 88,
	//HEADER_BLANK89								= 89,
	HEADER_CG_EMPIRE = 90,
	//HEADER_BLANK91								= 91,
	//HEADER_BLANK92								= 92,
	//HEADER_BLANK93								= 93,
	//HEADER_BLANK94								= 94,
	//HEADER_BLANK95								= 95,
	HEADER_CG_REFINE = 96,
	//HEADER_BLANK97								= 97,
	//HEADER_BLANK98								= 98,
	//HEADER_BLANK99								= 99,

	HEADER_CG_MARK_LOGIN = 100,
	HEADER_CG_MARK_CRCLIST = 101,
	HEADER_CG_MARK_UPLOAD = 102,
	HEADER_CG_MARK_IDXLIST = 104,

	HEADER_CG_CRC_REPORT = 103,

	HEADER_CG_HACK = 105,
	HEADER_CG_CHANGE_NAME = 106,
	HEADER_CG_SMS = 107,
	HEADER_CG_CHINA_MATRIX_CARD = 108,
	HEADER_CG_LOGIN2 = 109,
	HEADER_CG_DUNGEON = 110,
	HEADER_CG_LOGIN3 = 111,
	HEADER_CG_GUILD_SYMBOL_UPLOAD = 112,
	HEADER_CG_GUILD_SYMBOL_CRC = 113,
	HEADER_CG_SCRIPT_SELECT_ITEM = 114,
	HEADER_CG_LOGIN4 = 115,
	HEADER_CG_LOGIN5_OPENID = 116,	//OpenID : 실행시 받은 인증키를 서버에 보냄.

#ifdef NEW_PET_SYSTEM
	HEADER_CG_PetSetName = 147,
#endif

	HEADER_CG_RUNUP_MATRIX_ANSWER = 201,
	HEADER_CG_NEWCIBN_PASSPOD_ANSWER = 202,

	HEADER_CG_HS_ACK = 203,
	HEADER_CG_XTRAP_ACK = 204,

	HEADER_CG_DRAGON_SOUL_REFINE = 205,
	HEADER_CG_STATE_CHECKER = 206,

#ifdef __AUCTION__
	HEADER_CG_AUCTION_CMD							= 205,
#endif

	HEADER_CG_KEY_AGREEMENT = 0xfb, // _IMPROVED_PACKET_ENCRYPTION_
	HEADER_CG_TIME_SYNC = 0xfc,
	HEADER_CG_CLIENT_VERSION = 0xfd,
	HEADER_CG_CLIENT_VERSION2 = 0xf1,
	HEADER_CG_PONG = 0xfe,
	HEADER_CG_HANDSHAKE = 0xff,
	/////////////////////////////////////////////////
	// From Server

	HEADER_GC_CHARACTER_ADD = 1,
	HEADER_GC_CHARACTER_DEL = 2,
	HEADER_GC_CHARACTER_MOVE = 3,
	HEADER_GC_CHAT = 4,
	HEADER_GC_SYNC_POSITION = 5,
	HEADER_GC_LOGIN_SUCCESS3 = 6,
	HEADER_GC_LOGIN_FAILURE = 7,
	HEADER_GC_PLAYER_CREATE_SUCCESS = 8,
	HEADER_GC_PLAYER_CREATE_FAILURE = 9,
	HEADER_GC_PLAYER_DELETE_SUCCESS = 10,
	HEADER_GC_PLAYER_DELETE_WRONG_SOCIAL_ID = 11,
	// 12
	HEADER_GC_STUN = 13,
	HEADER_GC_DEAD = 14,

	HEADER_GC_MAIN_CHARACTER = 15,
	HEADER_GC_PLAYER_POINTS = 16,
	HEADER_GC_PLAYER_POINT_CHANGE = 17,
	HEADER_GC_CHANGE_SPEED = 18,
	HEADER_GC_CHARACTER_UPDATE = 19,
#if defined(GAIDEN)
	HEADER_GC_ITEM_DEL							= 20, // 아이템 창에 추가
	HEADER_GC_ITEM_SET							= 21, // 아이템 창에 추가
#else
	HEADER_GC_ITEM_SET = 20, // 아이템 창에 추가
	HEADER_GC_ITEM_SET2 = 21, // 아이템 창에 추가
#endif
	HEADER_GC_ITEM_USE = 22, // 아이템 사용 (주위 사람들에게 보여주기 위해)
	HEADER_GC_ITEM_DROP = 23, // 아이템 버리기
									 
	HEADER_GC_ITEM_UPDATE = 25, // 아이템 수치 업데이트
	HEADER_GC_ITEM_GROUND_ADD = 26, // 바닥에 아이템 추가
	HEADER_GC_ITEM_GROUND_DEL = 27, // 바닥에서 아이템 삭제
	HEADER_GC_QUICKSLOT_ADD = 28,
	HEADER_GC_QUICKSLOT_DEL = 29,
	HEADER_GC_QUICKSLOT_SWAP = 30,
	HEADER_GC_ITEM_OWNERSHIP = 31,
	HEADER_GC_LOGIN_SUCCESS4 = 32,
	HEADER_GC_ITEM_UNBIND_TIME = 33,
	HEADER_GC_WHISPER = 34,
	HEADER_GC_ALERT = 35,

	HEADER_GC_MOTION = 36,

	HEADER_GC_SHOP = 38,
	HEADER_GC_SHOP_SIGN = 39,

	// 39 ~ 41 Balnk
	HEADER_GC_DUEL_START = 40,
	HEADER_GC_PVP = 41,
	HEADER_GC_EXCHANGE = 42,
	HEADER_GC_CHARACTER_POSITION = 43,

	HEADER_GC_PING = 44,

	HEADER_GC_SCRIPT = 45,
	HEADER_GC_QUEST_CONFIRM = 46,

	HEADER_GC_MOUNT = 61,
	HEADER_GC_OWNERSHIP = 62,
	HEADER_GC_TARGET = 63,
	HEADER_GC_WARP = 65,
	HEADER_GC_ADD_FLY_TARGETING = 69,

	HEADER_GC_CREATE_FLY = 70,
	HEADER_GC_FLY_TARGETING = 71,
	HEADER_GC_SKILL_LEVEL = 72,
	HEADER_GC_SKILL_COOLTIME_END = 73,
	HEADER_GC_MESSENGER = 74,
	HEADER_GC_GUILD = 75,
	HEADER_GC_SKILL_LEVEL_NEW = 76,

	HEADER_GC_PARTY_INVITE = 77,
	HEADER_GC_PARTY_ADD = 78,
	HEADER_GC_PARTY_UPDATE = 79,
	HEADER_GC_PARTY_REMOVE = 80,

	HEADER_GC_QUEST_INFO = 81,
	HEADER_GC_REQUEST_MAKE_GUILD = 82,
	HEADER_GC_PARTY_PARAMETER = 83,

	HEADER_GC_SAFEBOX_MONEY_CHANGE = 84,
	HEADER_GC_SAFEBOX_SET = 85,
	HEADER_GC_SAFEBOX_DEL = 86,
	HEADER_GC_SAFEBOX_WRONG_PASSWORD = 87,
	HEADER_GC_SAFEBOX_SIZE = 88,

	HEADER_GC_FISHING = 89,

	HEADER_GC_EMPIRE = 90,

	HEADER_GC_PARTY_LINK = 91,
	HEADER_GC_PARTY_UNLINK = 92,

	HEADER_GC_REFINE_INFORMATION = 95,

	HEADER_GC_OBSERVER_ADD = 96,
	HEADER_GC_OBSERVER_REMOVE = 97,
	HEADER_GC_OBSERVER_MOVE = 98,
	HEADER_GC_VIEW_EQUIP = 99,

	HEADER_GC_MARK_BLOCK = 100,
	HEADER_GC_MARK_DIFF_DATA = 101,
	HEADER_GC_MARK_IDXLIST = 102,

	//HEADER_GC_SLOW_TIMER						= 105,
	HEADER_GC_TIME = 106,
	HEADER_GC_CHANGE_NAME = 107,

	HEADER_GC_DUNGEON = 110,
	HEADER_GC_WALK_MODE = 111,
	HEADER_GC_CHANGE_SKILL_GROUP = 112,

#if defined(GAIDEN)
	HEADER_GC_MAIN_CHARACTER					= 113,
	HEADER_GC_MAIN_CHARACTER3_BGM				= 137,
	HEADER_GC_MAIN_CHARACTER4_BGM_VOL			= 138,
#else
	// SUPPORT_BGM
	HEADER_GC_MAIN_CHARACTER2_EMPIRE = 113,
	// END_OF_SUPPORT_BGM
#endif

	HEADER_GC_SEPCIAL_EFFECT = 114,
	HEADER_GC_NPC_POSITION = 115,

	HEADER_GC_CHINA_MATRIX_CARD = 116,
	HEADER_GC_CHARACTER_UPDATE2 = 117,
	HEADER_GC_LOGIN_KEY = 118,
	HEADER_GC_REFINE_INFORMATION_NEW = 119,
	HEADER_GC_CHARACTER_ADD2 = 120,
	HEADER_GC_CHANNEL = 121,

	HEADER_GC_MALL_OPEN = 122,
	HEADER_GC_TARGET_UPDATE = 123,
	HEADER_GC_TARGET_DELETE = 124,
	HEADER_GC_TARGET_CREATE_NEW = 125,

	HEADER_GC_AFFECT_ADD = 126,
	HEADER_GC_AFFECT_REMOVE = 127,

	HEADER_GC_MALL_SET = 128,
	HEADER_GC_MALL_DEL = 129,
	HEADER_GC_LAND_LIST = 130,
	HEADER_GC_LOVER_INFO = 131,
	HEADER_GC_LOVE_POINT_UPDATE = 132,
	HEADER_GC_GUILD_SYMBOL_DATA = 133,
	HEADER_GC_DIG_MOTION = 134,

	HEADER_GC_DAMAGE_INFO = 135,
	HEADER_GC_CHAR_ADDITIONAL_INFO = 136,

	// SUPPORT_BGM
	HEADER_GC_MAIN_CHARACTER3_BGM = 137,
	HEADER_GC_MAIN_CHARACTER4_BGM_VOL = 138,
	// END_OF_SUPPORT_BGM

	HEADER_GC_AUTH_SUCCESS = 150,
	HEADER_GC_PANAMA_PACK = 151,

	//HYBRID CRYPT
	HEADER_GC_HYBRIDCRYPT_KEYS = 152,
	HEADER_GC_HYBRIDCRYPT_SDB = 153, // SDB means Supplmentary Data Blocks
	//HYBRID CRYPT

	HEADER_GC_AUTH_SUCCESS_OPENID = 154,
 
						  

	HEADER_GC_RUNUP_MATRIX_QUIZ = 201,
	HEADER_GC_NEWCIBN_PASSPOD_REQUEST = 202,
	HEADER_GC_NEWCIBN_PASSPOD_FAILURE = 203,
#if defined(GAIDEN)
	HEADER_GC_ONTIME							= 204,
	HEADER_GC_RESET_ONTIME						= 205,

	// AUTOBAN
	HEADER_GC_AUTOBAN_QUIZ						= 206,
	// END_OF_AUTOBAN

	HEADER_GC_HS_REQUEST						= 207,	// Origially it's 204 on devel branch
#else
	HEADER_GC_HS_REQUEST = 204,
	HEADER_GC_XTRAP_CS1_REQUEST = 205,
#endif

#ifdef __AUCTION__
	HEADER_GC_AUCTOIN_ITEM_LIST					= 206,
#endif 

	HEADER_GC_SPECIFIC_EFFECT = 208,
	HEADER_GC_DRAGON_SOUL_REFINE = 209,
	HEADER_GC_RESPOND_CHANNELSTATUS = 210,

	HEADER_GC_KEY_AGREEMENT_COMPLETED = 0xfa, // _IMPROVED_PACKET_ENCRYPTION_
	HEADER_GC_KEY_AGREEMENT = 0xfb, // _IMPROVED_PACKET_ENCRYPTION_
	HEADER_GC_HANDSHAKE_OK = 0xfc, // 252
	HEADER_GC_PHASE = 0xfd,	// 253
	HEADER_GC_BINDUDP = 0xfe, // 254
	HEADER_GC_HANDSHAKE = 0xff, // 255

	/////////////////////////////////////////////////
	// Client To Client for UDP
	/*
	HEADER_CC_STATE_WAITING						= 1,
	HEADER_CC_STATE_WALKING						= 2,
	HEADER_CC_STATE_GOING						= 3,
	HEADER_CC_EVENT_NORMAL_ATTACKING			= 4,
	HEADER_CC_EVENT_COMBO_ATTACKING				= 5,
	HEADER_CC_EVENT_HIT							= 6,
	*/
};

enum
{
	ID_MAX_NUM = 30,
	PASS_MAX_NUM = 16,
	HWID_MAX_NUM = 50,
	CHAT_MAX_NUM = 128,
	PATH_NODE_MAX_NUM = 64,
	SHOP_SIGN_MAX_LEN = 32,

	PLAYER_PER_ACCOUNT3 = 3,
	PLAYER_PER_ACCOUNT4 = 4,

	PLAYER_ITEM_SLOT_MAX_NUM = 20,		// ÇÃ·¡ÀÌ¾îÀÇ ½½·Ô´ç µé¾î°¡´Â °¹¼ö.

	QUICKSLOT_MAX_LINE = 4,
	QUICKSLOT_MAX_COUNT_PER_LINE = 8, // Å¬¶óÀÌ¾ðÆ® ÀÓÀÇ °áÁ¤°ª
	QUICKSLOT_MAX_COUNT = QUICKSLOT_MAX_LINE * QUICKSLOT_MAX_COUNT_PER_LINE,

	QUICKSLOT_MAX_NUM = 36, // ¼­¹ö¿Í ¸ÂÃçÁ® ÀÖ´Â °ª

	SHOP_HOST_ITEM_MAX_NUM = 40,

	METIN_SOCKET_COUNT = 6,

	PARTY_AFFECT_SLOT_MAX_NUM = 7,

	GUILD_GRADE_NAME_MAX_LEN = 8,
	GUILD_NAME_MAX_LEN = 12,
	GUILD_GRADE_COUNT = 15,
	GULID_COMMENT_MAX_LEN = 50,

	MARK_CRC_NUM = 8*8,
	MARK_DATA_SIZE = 16*12,
	SYMBOL_DATA_SIZE = 128*256,
	QUEST_INPUT_STRING_MAX_NUM = 64,

	PRIVATE_CODE_LENGTH = 8,

	REFINE_MATERIAL_MAX_NUM = 5,

	CHINA_MATRIX_ANSWER_MAX_LEN	= 8,

	RUNUP_MATRIX_QUIZ_MAX_LEN	= 8,
	RUNUP_MATRIX_ANSWER_MAX_LEN = 4,
	NEWCIBN_PASSPOD_ANSWER_MAX_LEN = 8,
	NEWCIBN_PASSPOD_FAILURE_MAX_LEN = 128,

	WEAR_MAX_NUM = 11,

	OPENID_AUTHKEY_LEN = 32,

	SHOP_TAB_NAME_MAX = 32,
	SHOP_TAB_COUNT_MAX = 3,
};

#pragma pack(push)
#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mark
typedef struct command_mark_login
{
    BYTE    header;
    DWORD   handle;
    DWORD   random_key;
} TPacketCGMarkLogin;

typedef struct command_mark_upload
{
    BYTE    header;
    DWORD   gid;
    BYTE    image[16*12*4];
} TPacketCGMarkUpload;

typedef struct command_mark_idxlist
{
    BYTE    header;
} TPacketCGMarkIDXList;

typedef struct command_mark_crclist
{
    BYTE    header;
    BYTE    imgIdx;
    DWORD   crclist[80];
} TPacketCGMarkCRCList;

typedef struct packet_mark_idxlist
{
    BYTE    header;
	DWORD	bufSize;
    WORD    count;
    //µÚ¿¡ size * (WORD + WORD)¸¸Å­ µ¥ÀÌÅÍ ºÙÀ½
} TPacketGCMarkIDXList;

typedef struct packet_mark_block
{
    BYTE    header;
    DWORD   bufSize;
	BYTE	imgIdx;
    DWORD   count;
    // µÚ¿¡ 64 x 48 x ÇÈ¼¿Å©±â(4¹ÙÀÌÆ®) = 12288¸¸Å­ µ¥ÀÌÅÍ ºÙÀ½
} TPacketGCMarkBlock;

typedef struct command_symbol_upload
{
	BYTE	header;
	WORD	size;
	DWORD	handle;
} TPacketCGSymbolUpload;

typedef struct command_symbol_crc
{
	BYTE	header;
	DWORD	dwGuildID;
	DWORD	dwCRC;
	DWORD	dwSize;
} TPacketCGSymbolCRC;

typedef struct packet_symbol_data
{
    BYTE header;
    WORD size;
    DWORD guild_id;
} TPacketGCGuildSymbolData;

//
//
//
typedef struct packet_observer_add
{
	BYTE	header;
	DWORD	vid;
	WORD	x;
	WORD	y;
} TPacketGCObserverAdd;

typedef struct packet_observer_move
{
	BYTE	header;
	DWORD	vid;
	WORD	x;
	WORD	y;
} TPacketGCObserverMove;


typedef struct packet_observer_remove
{
	BYTE	header;
	DWORD	vid;	
} TPacketGCObserverRemove;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// To Server

typedef struct command_checkin
{
	BYTE header;
	char name[ID_MAX_NUM+1];
	char pwd[PASS_MAX_NUM+1];
} TPacketCGCheckin;

typedef struct command_login
{
    BYTE header;
    char name[ID_MAX_NUM + 1];
    char pwd[PASS_MAX_NUM + 1];
	char Hwid[HWID_MAX_NUM + 1];
} TPacketCGLogin;

// start - ±ÇÇÑ ¼­¹ö Á¢¼ÓÀ» À§ÇÑ ÆÐÅ¶µé
typedef struct command_login2
{
	BYTE	header;
	char	name[ID_MAX_NUM + 1];
	DWORD	login_key;
    DWORD	adwClientKey[4];
} TPacketCGLogin2;

typedef struct command_login3
{
    BYTE	header;
    char	name[ID_MAX_NUM + 1];
    char	pwd[PASS_MAX_NUM + 1];
	char	Hwid[HWID_MAX_NUM + 1];
    DWORD	adwClientKey[4];
} TPacketCGLogin3;

typedef struct command_login5
{
    BYTE	header;
    char	authKey[OPENID_AUTHKEY_LEN + 1];
    DWORD	adwClientKey[4];
} TPacketCGLogin5;

// end - ±ÇÇÑ ¼­¹ö Á¢¼ÓÀ» À§ÇÑ ÆÐÅ¶µé

#ifdef NEW_PET_SYSTEM
typedef struct packet_RequestPetName
{
	BYTE byHeader;
	char petname[13];
} TPacketCGRequestPetName;
#endif


typedef struct command_direct_enter
{
    BYTE        bHeader;
    char        login[ID_MAX_NUM + 1];
    char        passwd[PASS_MAX_NUM + 1];
	char        Hwid[HWID_MAX_NUM + 1];
    BYTE        index;
} TPacketCGDirectEnter;

typedef struct command_player_select
{
	BYTE	header;
	BYTE	player_index;
} TPacketCGSelectCharacter;

typedef struct command_attack
{
	BYTE	header;
	BYTE	bType;			// °ø°Ý À¯Çü
	DWORD	dwVictimVID;	// Àû VID
	BYTE	bCRCMagicCubeProcPiece;
	BYTE	bCRCMagicCubeFilePiece;
} TPacketCGAttack;

typedef struct command_chat
{
	BYTE	header;
	WORD	length;
	BYTE	type;
} TPacketCGChat;

typedef struct command_whisper
{
    BYTE        bHeader;
    WORD        wSize;
    char        szNameTo[CHARACTER_NAME_MAX_LEN + 1];
} TPacketCGWhisper;

typedef struct command_sms
{
    BYTE        bHeader;
    WORD        wSize;
    char        szNameTo[CHARACTER_NAME_MAX_LEN + 1];
} TPacketCGSMS;

enum EBattleMode
{
	BATTLEMODE_ATTACK = 0,
	BATTLEMODE_DEFENSE = 1,
};

typedef struct command_EnterFrontGame
{
	BYTE header;
} TPacketCGEnterFrontGame;

typedef struct command_item_use
{
	BYTE header;
	TItemPos pos;
} TPacketCGItemUse;

typedef struct command_item_use_to_item
{
	BYTE header;
	TItemPos source_pos;
	TItemPos target_pos;
} TPacketCGItemUseToItem;

typedef struct command_item_drop
{
	BYTE  header;
	TItemPos pos;
	DWORD elk;
} TPacketCGItemDrop;

typedef struct command_item_drop2
{
    BYTE        header;
    TItemPos pos;
    DWORD       gold;
    BYTE        count;
} TPacketCGItemDrop2;

typedef struct command_item_destroy
{
	BYTE        header;
	TItemPos    pos;
} TPacketCGItemDestroy;

typedef struct command_item_move
{
	BYTE header;
	TItemPos pos;
	TItemPos change_pos;
	BYTE num;
} TPacketCGItemMove;

typedef struct command_item_pickup
{
	BYTE header;
	DWORD vid;
} TPacketCGItemPickUp;

typedef struct command_quickslot_add
{
    BYTE        header;
    BYTE        pos;
	TQuickSlot	slot;
}TPacketCGQuickSlotAdd;

typedef struct command_quickslot_del
{
    BYTE        header;
    BYTE        pos;
}TPacketCGQuickSlotDel;

typedef struct command_quickslot_swap
{
    BYTE        header;
    BYTE        pos;
    BYTE        change_pos;
}TPacketCGQuickSlotSwap;

typedef struct command_on_click
{
	BYTE		header;
	DWORD		vid;
} TPacketCGOnClick;


enum
{
    SHOP_SUBHEADER_CG_END,
	SHOP_SUBHEADER_CG_BUY,
	SHOP_SUBHEADER_CG_SELL,
	SHOP_SUBHEADER_CG_SELL2,
};

typedef struct command_shop
{
	BYTE        header;
	BYTE		subheader;
} TPacketCGShop;

enum
{
	EXCHANGE_SUBHEADER_CG_START,			// arg1 == vid of target character
	EXCHANGE_SUBHEADER_CG_ITEM_ADD,		// arg1 == position of item
	EXCHANGE_SUBHEADER_CG_ITEM_DEL,		// arg1 == position of item
	EXCHANGE_SUBHEADER_CG_ELK_ADD,			// arg1 == amount of elk
	EXCHANGE_SUBHEADER_CG_ACCEPT,			// arg1 == not used
	EXCHANGE_SUBHEADER_CG_CANCEL,			// arg1 == not used
	EXCHANGE_SUBHEADER_CG_ALREADY,			// arg1 == not used
	EXCHANGE_SUBHEADER_CG_LESS_ELK,		// arg1 == not used
#ifdef ENABLE_CHEQUE_SYSTEM
	EXCHANGE_SUBHEADER_CG_WON_ADD, // Système Won
#endif
};

typedef struct command_exchange
{
	BYTE		header;
	BYTE		subheader;
	long long		arg1;
	BYTE		arg2;
	TItemPos	Pos;
} TPacketCGExchange;

typedef struct command_position
{   
    BYTE        header;
    BYTE        position;
} TPacketCGPosition;

typedef struct command_script_answer
{
    BYTE        header;
	BYTE		answer;
} TPacketCGScriptAnswer;

typedef struct command_script_button
{
    BYTE        header;
	unsigned int			idx;
} TPacketCGScriptButton;

typedef struct command_target
{
    BYTE        header;
    DWORD       dwVID;
} TPacketCGTarget;

typedef struct command_move
{
	BYTE		bHeader;
	BYTE		bFunc;
	BYTE		bArg;
	BYTE		bRot;
	LONG		lX;
	LONG		lY;
	DWORD		dwTime;	
} TPacketCGMove;

typedef struct command_sync_position_element 
{ 
    DWORD       dwVID; 
    long        lX; 
    long        lY; 
} TPacketCGSyncPositionElement; 

typedef struct command_sync_position
{ 
    BYTE        bHeader;
	WORD		wSize;
} TPacketCGSyncPosition; 

typedef struct command_fly_targeting
{
	BYTE		bHeader;
	DWORD		dwTargetVID;
	long		lX;
	long		lY;
} TPacketCGFlyTargeting;

typedef struct packet_fly_targeting
{
    BYTE        bHeader;
	DWORD		dwShooterVID;
	DWORD		dwTargetVID;
	long		lX;
	long		lY;
} TPacketGCFlyTargeting;

typedef struct packet_shoot
{   
    BYTE		bHeader;                
    BYTE		bType;
} TPacketCGShoot;

typedef struct command_warp
{
	BYTE			bHeader;
} TPacketCGWarp;

enum
{
	MESSENGER_SUBHEADER_GC_LIST,
	MESSENGER_SUBHEADER_GC_LOGIN,
	MESSENGER_SUBHEADER_GC_LOGOUT,
	MESSENGER_SUBHEADER_GC_INVITE,
	MESSENGER_SUBHEADER_GC_MOBILE,
};

typedef struct packet_messenger
{
    BYTE header;
    WORD size;
    BYTE subheader;
} TPacketGCMessenger;

typedef struct packet_messenger_list_offline
{
    BYTE connected; // always 0
	BYTE length;
} TPacketGCMessengerListOffline;

enum
{
	MESSENGER_CONNECTED_STATE_OFFLINE,
	MESSENGER_CONNECTED_STATE_ONLINE,
	MESSENGER_CONNECTED_STATE_MOBILE,
};

typedef struct packet_messenger_list_online
{
    BYTE connected;
	BYTE length;
	//BYTE length_char_name;
} TPacketGCMessengerListOnline;

typedef struct packet_messenger_login
{
	//BYTE length_login;
	//BYTE length_char_name;
	BYTE length;
} TPacketGCMessengerLogin;

typedef struct packet_messenger_logout
{
	BYTE length;
} TPacketGCMessengerLogout;

enum
{
    MESSENGER_SUBHEADER_CG_ADD_BY_VID,
    MESSENGER_SUBHEADER_CG_ADD_BY_NAME,
    MESSENGER_SUBHEADER_CG_REMOVE,
};

typedef struct command_messenger
{
    BYTE header;
    BYTE subheader;
} TPacketCGMessenger;

typedef struct command_messenger_remove
{
	BYTE length;
} TPacketCGMessengerRemove;

enum
{
	SAFEBOX_MONEY_STATE_SAVE,
	SAFEBOX_MONEY_STATE_WITHDRAW,
};

typedef struct command_safebox_money
{
    BYTE        bHeader;
    BYTE        bState;
    DWORD       dwMoney;
} TPacketCGSafeboxMoney;

typedef struct command_safebox_checkout
{
    BYTE        bHeader;
    BYTE        bSafePos;
    TItemPos	ItemPos;
} TPacketCGSafeboxCheckout;

typedef struct command_safebox_checkin
{
    BYTE        bHeader;
    BYTE        bSafePos;
    TItemPos	ItemPos;
} TPacketCGSafeboxCheckin;

typedef struct command_mall_checkout
{
    BYTE        bHeader;
    BYTE        bMallPos;
    TItemPos	ItemPos;
} TPacketCGMallCheckout;

///////////////////////////////////////////////////////////////////////////////////
// Party

typedef struct command_use_skill
{
    BYTE                bHeader;
    DWORD               dwVnum;
	DWORD				dwTargetVID;
} TPacketCGUseSkill;

typedef struct command_party_invite
{
    BYTE header;
    DWORD vid;
} TPacketCGPartyInvite;

typedef struct command_party_invite_answer
{
    BYTE header;
    DWORD leader_pid;
    BYTE accept;
} TPacketCGPartyInviteAnswer;

typedef struct command_party_remove
{
    BYTE header;
    DWORD pid;
} TPacketCGPartyRemove;

typedef struct command_party_set_state
{
    BYTE byHeader;
    DWORD dwVID;
	BYTE byState;
    BYTE byFlag;
} TPacketCGPartySetState;

typedef struct packet_party_link
{
    BYTE header;
    DWORD pid;
    DWORD vid;
} TPacketGCPartyLink;

typedef struct packet_party_unlink
{
    BYTE header;
    DWORD pid;
	DWORD vid;
} TPacketGCPartyUnlink;

typedef struct command_party_use_skill
{
    BYTE byHeader;
	BYTE bySkillIndex;
    DWORD dwTargetVID;
} TPacketCGPartyUseSkill;

enum
{
	GUILD_SUBHEADER_CG_ADD_MEMBER,
	GUILD_SUBHEADER_CG_REMOVE_MEMBER,
	GUILD_SUBHEADER_CG_CHANGE_GRADE_NAME,
	GUILD_SUBHEADER_CG_CHANGE_GRADE_AUTHORITY,
	GUILD_SUBHEADER_CG_OFFER,
	GUILD_SUBHEADER_CG_POST_COMMENT,
	GUILD_SUBHEADER_CG_DELETE_COMMENT,
	GUILD_SUBHEADER_CG_REFRESH_COMMENT,
	GUILD_SUBHEADER_CG_CHANGE_MEMBER_GRADE,
	GUILD_SUBHEADER_CG_USE_SKILL,
	GUILD_SUBHEADER_CG_CHANGE_MEMBER_GENERAL,
	GUILD_SUBHEADER_CG_GUILD_INVITE_ANSWER,
	GUILD_SUBHEADER_CG_CHARGE_GSP,
	GUILD_SUBHEADER_CG_DEPOSIT_MONEY,
	GUILD_SUBHEADER_CG_WITHDRAW_MONEY,
};

typedef struct command_guild
{
    BYTE byHeader;
	BYTE bySubHeader;
} TPacketCGGuild;

typedef struct command_guild_answer_make_guild
{
	BYTE header;
	char guild_name[GUILD_NAME_MAX_LEN+1];
} TPacketCGAnswerMakeGuild; 

typedef struct command_give_item
{
	BYTE byHeader;
	DWORD dwTargetVID;
	TItemPos ItemPos;
	BYTE byItemCount;
} TPacketCGGiveItem;

typedef struct SPacketCGHack
{
    BYTE        bHeader;
    char        szBuf[255 + 1];
} TPacketCGHack;

typedef struct command_dungeon
{
	BYTE		bHeader;
	WORD		size;
} TPacketCGDungeon;

// Private Shop
typedef struct SShopItemTable
{
	DWORD		vnum;
	BYTE		count;

	TItemPos	pos;			// PC ???? ??
	long long		price;			// PC ???? ??
	BYTE		display_pos;	//	PC ???? ??, ?? ??.
	int			price_type;
#ifdef ENABLE_CHEQUE_SYSTEM
	int			won; // prix en won
#endif
} TShopItemTable;

typedef struct SPacketCGMyShop
{
	BYTE        bHeader;
	char        szSign[SHOP_SIGN_MAX_LEN + 1];
	BYTE        bCount;	// count of TShopItemTable, max 39
	int			days;

} TPacketCGMyShop;

typedef struct SPacketCGRefine
{
	BYTE		header;
	BYTE		pos;
	BYTE		type;
} TPacketCGRefine;

typedef struct SPacketCGChangeName
{
    BYTE header;
    BYTE index;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketCGChangeName;

typedef struct command_client_version
{
	BYTE header;
	char filename[32+1];
	char timestamp[32+1];
} TPacketCGClientVersion;

typedef struct command_client_version2
{
	BYTE header;
	char filename[32+1];
	char timestamp[32+1];
} TPacketCGClientVersion2;

typedef struct command_crc_report
{
	BYTE header;
	BYTE byPackMode;
	DWORD dwBinaryCRC32;
	DWORD dwProcessCRC32;
	DWORD dwRootPackCRC32;
} TPacketCGCRCReport;

typedef struct command_china_matrix_card
{
	BYTE	bHeader;
	char	szAnswer[CHINA_MATRIX_ANSWER_MAX_LEN + 1];
} TPacketCGChinaMatrixCard;

typedef struct command_runup_matrix_answer
{
	BYTE	bHeader;
	char	szAnswer[RUNUP_MATRIX_ANSWER_MAX_LEN + 1];
} TPacketCGRunupMatrixAnswer;

typedef struct command_newcibn_passpod_answer
{
	BYTE	bHeader;
	char	szAnswer[NEWCIBN_PASSPOD_ANSWER_MAX_LEN + 1];
} TPacketCGNEWCIBNPasspodAnswer;

enum EPartyExpDistributionType
{
    PARTY_EXP_DISTRIBUTION_NON_PARITY,
    PARTY_EXP_DISTRIBUTION_PARITY,
};

typedef struct command_party_parameter
{
    BYTE        bHeader;
    BYTE        bDistributeMode;
} TPacketCGPartyParameter;

typedef struct command_quest_input_string
{
    BYTE        bHeader;
    char		szString[QUEST_INPUT_STRING_MAX_NUM+1];
} TPacketCGQuestInputString;

typedef struct command_quest_confirm
{
    BYTE header;
    BYTE answer;
    DWORD requestPID;
} TPacketCGQuestConfirm;

typedef struct command_script_select_item
{
    BYTE header;
    DWORD selection;
} TPacketCGScriptSelectItem;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From Server
enum EPhase
{
    PHASE_CLOSE,				// ²÷±â´Â »óÅÂ (¶Ç´Â ²÷±â Àü »óÅÂ)
    PHASE_HANDSHAKE,			// ¾Ç¼ö..;;
    PHASE_LOGIN,				// ·Î±×ÀÎ Áß
    PHASE_SELECT,				// Ä³¸¯ÅÍ ¼±ÅÃ È­¸é
    PHASE_LOADING,				// ¼±ÅÃ ÈÄ ·Îµù È­¸é
    PHASE_GAME,					// °ÔÀÓ È­¸é
    PHASE_DEAD,					// Á×¾úÀ» ¶§.. (°ÔÀÓ ¾È¿¡ ÀÖ´Â °ÍÀÏ ¼öµµ..)

	PHASE_DBCLIENT_CONNECTING,	// ¼­¹ö¿ë
    PHASE_DBCLIENT,				// ¼­¹ö¿ë
    PHASE_P2P,					// ¼­¹ö¿ë
    PHASE_AUTH,					// ·Î±×ÀÎ ÀÎÁõ ¿ë
};

typedef struct packet_phase
{
    BYTE        header;
    BYTE        phase;
} TPacketGCPhase;

typedef struct packet_blank		// °ø¹éÆÐÅ¶.
{
	BYTE		header;
} TPacketGCBlank;

typedef struct packet_blank_dynamic
{
	BYTE		header;
	WORD		size;
} TPacketGCBlankDynamic;

typedef struct packet_header_handshake
{
	BYTE		header;
	DWORD		dwHandshake;
	DWORD		dwTime;
	LONG		lDelta;
} TPacketGCHandshake;

typedef struct packet_header_bindudp
{
	BYTE		header;
	DWORD		addr;
	WORD		port;
} TPacketGCBindUDP;

typedef struct packet_header_dynamic_size
{
	BYTE		header;
	WORD		size;
} TDynamicSizePacketHeader;

typedef struct SSimplePlayerInformation
{
    DWORD               dwID;
    char                szName[CHARACTER_NAME_MAX_LEN + 1];
    BYTE                byJob;
    DWORD                byLevel;
    DWORD               dwPlayMinutes;
    BYTE                byST, byHT, byDX, byIQ;
//	WORD				wParts[CRaceData::PART_MAX_NUM];
    WORD                wMainPart;
    BYTE                bChangeName;
	WORD				wHairPart;
	WORD				wAccePart;
    BYTE                bDummy[4];
	long				x, y;
	LONG				lAddr;
	WORD				wPort;
	BYTE				bySkillGroup;
	DWORD				Semeskill; // 7ème skill
	DWORD				Eemeskill; // 8ème skill
	DWORD				titre; // titre pvp
	DWORD				cheque; 
} TSimplePlayerInformation;

typedef struct packet_login_success3
{
	BYTE						header;
	TSimplePlayerInformation	akSimplePlayerInformation[PLAYER_PER_ACCOUNT3];
    DWORD						guild_id[PLAYER_PER_ACCOUNT3];
    char						guild_name[PLAYER_PER_ACCOUNT3][GUILD_NAME_MAX_LEN+1];
	DWORD handle;
	DWORD random_key;
} TPacketGCLoginSuccess3;

typedef struct packet_login_success4
{
	BYTE						header;
	TSimplePlayerInformation	akSimplePlayerInformation[PLAYER_PER_ACCOUNT4];
    DWORD						guild_id[PLAYER_PER_ACCOUNT4];
    char						guild_name[PLAYER_PER_ACCOUNT4][GUILD_NAME_MAX_LEN+1];
	DWORD handle;
	DWORD random_key;
} TPacketGCLoginSuccess4;


	
 
enum { LOGIN_STATUS_MAX_LEN = 8 };
  

typedef struct packet_login_failure
{
	BYTE	header;
	char	szStatus[LOGIN_STATUS_MAX_LEN + 1];
} TPacketGCLoginFailure;

typedef struct command_player_create
{
	BYTE        header;
	BYTE        index;
	char        name[CHARACTER_NAME_MAX_LEN + 1];
	WORD        job;
	BYTE		shape;
	BYTE		CON;
	BYTE		INT;
	BYTE		STR;
	BYTE		DEX;
} TPacketCGCreateCharacter;

typedef struct command_player_create_success
{
    BYTE						header;
    BYTE						bAccountCharacterSlot;
    TSimplePlayerInformation	kSimplePlayerInfomation;
} TPacketGCPlayerCreateSuccess;

typedef struct command_create_failure
{
	BYTE	header;
	BYTE	bType;
} TPacketGCCreateFailure;

typedef struct command_player_delete
{
	BYTE        header;
	BYTE        index;
	char		szPrivateCode[PRIVATE_CODE_LENGTH];
} TPacketCGDestroyCharacter;

typedef struct packet_player_delete_success
{
	BYTE        header;
	BYTE        account_index;
} TPacketGCDestroyCharacterSuccess;

enum
{
	ADD_CHARACTER_STATE_DEAD   = (1 << 0),
	ADD_CHARACTER_STATE_SPAWN  = (1 << 1),
	ADD_CHARACTER_STATE_GUNGON = (1 << 2),
	ADD_CHARACTER_STATE_KILLER = (1 << 3),
	ADD_CHARACTER_STATE_PARTY  = (1 << 4),
};

enum EPKModes
{
	PK_MODE_PEACE,
	PK_MODE_REVENGE,
	PK_MODE_FREE,
	PK_MODE_PROTECT,
	PK_MODE_GUILD,
	PK_MODE_MAX_NUM,
};

// 2004.11.20.myevan.CRaceData::PART_MAX_NUM »ç¿ë¾ÈÇÏ°Ô ¼öÁ¤ - ¼­¹ö¿¡¼­ »ç¿ëÇÏ´Â°Í°ú ÀÏÄ¡ÇÏÁö ¾ÊÀ½
enum ECharacterEquipmentPart
{
	CHR_EQUIPPART_ARMOR,
	CHR_EQUIPPART_WEAPON,
	CHR_EQUIPPART_HEAD,
	CHR_EQUIPPART_HAIR,
	CHR_EQUIPPART_ACCE,
	CHR_EQUIPPART_NUM,		
};

typedef struct packet_char_additional_info
{
	BYTE    header;
	DWORD   dwVID;
	char    name[CHARACTER_NAME_MAX_LEN + 1];
	WORD    awPart[CHR_EQUIPPART_NUM];
	BYTE	bEmpire;
	DWORD   dwGuildID;
	DWORD   dwLevel;
	//DWORD	dwTitle;
	DWORD	dw7emeSkill;
	DWORD	dw8emeSkill;
	short   sAlignment; //선악치
	BYTE    bPKMode;
	DWORD   dwMountVnum;
	/*char	dwTitreNom[CHARACTER_NAME_MAX_LEN + 1];
	char	dwTitreCouleur1[CHARACTER_NAME_MAX_LEN + 1];
	char	dwTitreCouleur2[CHARACTER_NAME_MAX_LEN + 1];
	char	dwTitreCouleur3[CHARACTER_NAME_MAX_LEN + 1];*/
	//char		dwScale[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCCharacterAdditionalInfo;

typedef struct packet_add_char
{
    BYTE        header;

    DWORD       dwVID;
	DWORD		dwLevel;
	DWORD		dwAIFlag;
	//DWORD	dwTitle;
	DWORD	dw7emeSkill;
	DWORD	dw8emeSkill;
	/*char	dwTitreNom[CHARACTER_NAME_MAX_LEN + 1];
	char	dwTitreCouleur1[CHARACTER_NAME_MAX_LEN + 1];
	char	dwTitreCouleur2[CHARACTER_NAME_MAX_LEN + 1];
	char	dwTitreCouleur3[CHARACTER_NAME_MAX_LEN + 1];*/
    //char        name[CHARACTER_NAME_MAX_LEN + 1];

    float       angle;
    long        x;
    long        y;
    long        z;

	BYTE		bType;
    WORD        wRaceNum;
    //WORD        awPart[CHR_EQUIPPART_NUM];
    BYTE        bMovingSpeed;
    BYTE        bAttackSpeed;

			
			   
										 
				   
				   

    BYTE        bStateFlag;
    DWORD       dwAffectFlag[2];        // ??
    //BYTE      bEmpire;
    //DWORD     dwGuild;
    //short     sAlignment;	
	//BYTE		bPKMode;
	//DWORD		dwMountVnum;
	//char		dwScale[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCCharacterAdd;

typedef struct packet_add_char2
{
    BYTE        header;

    DWORD       dwVID;

    char        name[CHARACTER_NAME_MAX_LEN + 1];

    float       angle;
    long        x;
    long        y;
    long        z;

	BYTE		bType;
    WORD        wRaceNum;
    WORD        awPart[CHR_EQUIPPART_NUM];
    BYTE        bMovingSpeed;
    BYTE        bAttackSpeed;

    BYTE        bStateFlag;
    DWORD       dwAffectFlag[2];        // ??
    BYTE        bEmpire;

    DWORD       dwGuild;
    short       sAlignment;
	BYTE		bPKMode;
	DWORD		dwMountVnum;
	/*char		dwTitreNom[CHARACTER_NAME_MAX_LEN + 1];
	char		dwTitreCouleur1[CHARACTER_NAME_MAX_LEN + 1];
	char		dwTitreCouleur2[CHARACTER_NAME_MAX_LEN + 1];
	char		dwTitreCouleur3[CHARACTER_NAME_MAX_LEN + 1];*/
	//char		dwScale[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCCharacterAdd2;

typedef struct packet_update_char
{
    BYTE        header;
    DWORD       dwVID;

    WORD        awPart[CHR_EQUIPPART_NUM];
    BYTE        bMovingSpeed;
	BYTE		bAttackSpeed;

    BYTE        bStateFlag;
    DWORD       dwAffectFlag[2];

	DWORD		dwGuildID;
    short       sAlignment;
#ifdef NEW_PET_SYSTEM
	DWORD		dwLevel;
#endif
	//DWORD		bTitle;
	DWORD		b7emeSkill;
	DWORD		b8emeSkill;
	/*char		bTitreNom[CHARACTER_NAME_MAX_LEN + 1];
	char		bTitreCouleur1[CHARACTER_NAME_MAX_LEN + 1];
	char		bTitreCouleur2[CHARACTER_NAME_MAX_LEN + 1];
	char		bTitreCouleur3[CHARACTER_NAME_MAX_LEN + 1];*/
	BYTE		bPKMode;
	DWORD		dwMountVnum;
	//char		dwScale[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCCharacterUpdate;

typedef struct packet_update_char2
{
    BYTE        header;
    DWORD       dwVID;

    WORD        awPart[CHR_EQUIPPART_NUM];
    BYTE        bMovingSpeed;
	BYTE		bAttackSpeed;

    BYTE        bStateFlag;
    DWORD       dwAffectFlag[2];

	DWORD		dwGuildID;
    short       sAlignment;
	BYTE		bPKMode;
	DWORD		dwMountVnum;
} TPacketGCCharacterUpdate2;

typedef struct packet_del_char
{
	BYTE	header;
    DWORD	dwVID;
} TPacketGCCharacterDelete;

typedef struct packet_GlobalTime
{
	BYTE	header;
	float	GlobalTime;
} TPacketGCGlobalTime;

enum EChatType
{
	CHAT_TYPE_TALKING,  /* ±×³É Ã¤ÆÃ */
	CHAT_TYPE_INFO,     /* Á¤º¸ (¾ÆÀÌÅÛÀ» Áý¾ú´Ù, °æÇèÄ¡¸¦ ¾ò¾ú´Ù. µî) */
	CHAT_TYPE_NOTICE,   /* °øÁö»çÇ× */
	CHAT_TYPE_PARTY,    /* ÆÄÆ¼¸» */
	CHAT_TYPE_GUILD,    /* ±æµå¸» */
	CHAT_TYPE_COMMAND,	/* ¸í·É */
	CHAT_TYPE_SHOUT,	/* ¿ÜÄ¡±â */
	CHAT_TYPE_WHISPER,	// ¼­¹ö¿Í´Â ¿¬µ¿µÇÁö ¾Ê´Â Only Client Enum
	CHAT_TYPE_BIG_NOTICE,
	CHAT_TYPE_MAX_NUM,
				  
};

typedef struct packet_chatting
{
	BYTE	header;
	WORD	size;
	BYTE	type;
	DWORD	dwVID;
	BYTE	bEmpire;
} TPacketGCChat;

typedef struct packet_whisper   // °¡º¯ ÆÐÅ¶    
{   
    BYTE        bHeader;                        
    WORD        wSize;
    BYTE        bType;
    char        szNameFrom[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCWhisper;

typedef struct packet_stun
{
	BYTE		header;
	DWORD		vid;
} TPacketGCStun;

typedef struct packet_dead
{
	BYTE		header;
	DWORD		vid;
} TPacketGCDead;

typedef struct packet_main_character
{
    BYTE        header;
    DWORD       dwVID;
	WORD		wRaceNum;
    char        szName[CHARACTER_NAME_MAX_LEN + 1];
    long        lX, lY, lZ;
	BYTE		bySkillGroup;
} TPacketGCMainCharacter;

// SUPPORT_BGM
typedef struct packet_main_character2_empire
{
    BYTE        header;
    DWORD       dwVID;
	WORD		wRaceNum;
    char        szName[CHARACTER_NAME_MAX_LEN + 1];
    long        lX, lY, lZ;
	BYTE		byEmpire;
	BYTE		bySkillGroup;
} TPacketGCMainCharacter2_EMPIRE;

typedef struct packet_main_character3_bgm
{
	enum
	{
		MUSIC_NAME_MAX_LEN = 24,
	};

    BYTE        header;
    DWORD       dwVID;
	WORD		wRaceNum;
    char        szUserName[CHARACTER_NAME_MAX_LEN + 1];
	char        szBGMName[MUSIC_NAME_MAX_LEN + 1];
    long        lX, lY, lZ;
	BYTE		byEmpire;
	BYTE		bySkillGroup;
} TPacketGCMainCharacter3_BGM;

typedef struct packet_main_character4_bgm_vol
{
	enum
	{
		MUSIC_NAME_MAX_LEN = 24,
	};

    BYTE        header;
    DWORD       dwVID;
	WORD		wRaceNum;
    char        szUserName[CHARACTER_NAME_MAX_LEN + 1];
	char        szBGMName[MUSIC_NAME_MAX_LEN + 1];
	float		fBGMVol;
    long        lX, lY, lZ;
	BYTE		byEmpire;
	BYTE		bySkillGroup;
} TPacketGCMainCharacter4_BGM_VOL;

// END_OF_SUPPORT_BGM

enum EPointTypes
{
	POINT_NONE,                 // 0
	POINT_LEVEL,                // 1
	POINT_VOICE,                // 2
	POINT_EXP,                  // 3
	POINT_NEXT_EXP,             // 4
	POINT_HP,                   // 5
	POINT_MAX_HP,               // 6
	POINT_SP,                   // 7
	POINT_MAX_SP,               // 8  
	POINT_STAMINA,              // 9  ½ºÅ×¹Ì³Ê
	POINT_MAX_STAMINA,          // 10 ÃÖ´ë ½ºÅ×¹Ì³Ê

	POINT_GOLD,                 // 11
	POINT_ST,                   // 12 ±Ù·Â
	POINT_HT,                   // 13 Ã¼·Â
	POINT_DX,                   // 14 ¹ÎÃ¸¼º
	POINT_IQ,                   // 15 Á¤½Å·Â
	POINT_ATT_POWER,            // 16 °ø°Ý·Â
	POINT_ATT_SPEED,            // 17 °ø°Ý¼Óµµ
	POINT_EVADE_RATE,           // 18 È¸ÇÇÀ²
	POINT_MOV_SPEED,            // 19 ÀÌµ¿¼Óµµ
	POINT_DEF_GRADE,            // 20 ¹æ¾îµî±Þ
	POINT_CASTING_SPEED,        // 21 ÁÖ¹®¼Óµµ (Äð´Ù¿îÅ¸ÀÓ*100) / (100 + ÀÌ°ª) = ÃÖÁ¾ Äð´Ù¿î Å¸ÀÓ
	POINT_MAGIC_ATT_GRADE,      // 22 ¸¶¹ý°ø°Ý·Â
	POINT_MAGIC_DEF_GRADE,      // 23 ¸¶¹ý¹æ¾î·Â
	POINT_EMPIRE_POINT,         // 24 Á¦±¹Á¡¼ö
	POINT_LEVEL_STEP,           // 25 ÇÑ ·¹º§¿¡¼­ÀÇ ´Ü°è.. (1 2 3 µÉ ¶§ º¸»ó, 4 µÇ¸é ·¹º§ ¾÷)
	POINT_STAT,                 // 26 ´É·ÂÄ¡ ¿Ã¸± ¼ö ÀÖ´Â °³¼ö
	POINT_SUB_SKILL,            // 27 º¸Á¶ ½ºÅ³ Æ÷ÀÎÆ®
	POINT_SKILL,                // 28 ¾×Æ¼ºê ½ºÅ³ Æ÷ÀÎÆ®
	//    POINT_SKILL_PASV,           // 27 ÆÐ½Ãºê ±â¼ú ¿Ã¸± ¼ö ÀÖ´Â °³¼ö
	//    POINT_SKILL_ACTIVE,         // 28 ¾×Æ¼ºê ½ºÅ³ Æ÷ÀÎÆ®
	POINT_MIN_ATK,				// 29 ÃÖ¼Ò ÆÄ±«·Â
	POINT_MAX_ATK,				// 30 ÃÖ´ë ÆÄ±«·Â
	POINT_PLAYTIME,             // 31 ÇÃ·¹ÀÌ½Ã°£
	POINT_HP_REGEN,             // 32 HP È¸º¹·ü
	POINT_SP_REGEN,             // 33 SP È¸º¹·ü

	POINT_BOW_DISTANCE,         // 34 È° »çÁ¤°Å¸® Áõ°¡Ä¡ (meter)

	POINT_HP_RECOVERY,          // 35 Ã¼·Â È¸º¹ Áõ°¡·®
	POINT_SP_RECOVERY,          // 36 Á¤½Å·Â È¸º¹ Áõ°¡·®

	POINT_POISON_PCT,           // 37 µ¶ È®·ü
	POINT_STUN_PCT,             // 38 ±âÀý È®·ü
	POINT_SLOW_PCT,             // 39 ½½·Î¿ì È®·ü
	POINT_CRITICAL_PCT,         // 40 Å©¸®Æ¼ÄÃ È®·ü
	POINT_PENETRATE_PCT,        // 41 °üÅëÅ¸°Ý È®·ü
	POINT_CURSE_PCT,            // 42 ÀúÁÖ È®·ü

	POINT_ATTBONUS_HUMAN,       // 43 ÀÎ°£¿¡°Ô °­ÇÔ
	POINT_ATTBONUS_ANIMAL,      // 44 µ¿¹°¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_ORC,         // 45 ¿õ±Í¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_MILGYO,      // 46 ¹Ð±³¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_UNDEAD,      // 47 ½ÃÃ¼¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_DEVIL,       // 48 ¸¶±Í(¾Ç¸¶)¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_INSECT,      // 49 ¹ú·¹Á·
	POINT_ATTBONUS_FIRE,        // 50 È­¿°Á·
	POINT_ATTBONUS_ICE,         // 51 ºù¼³Á·
	POINT_ATTBONUS_DESERT,      // 52 »ç¸·Á·
	POINT_ATTBONUS_MONSTER,     // 53 UNUSED0
	POINT_ATTBONUS_WARRIOR,     // 54 UNUSED1
	POINT_ATTBONUS_ASSASSIN,     // 55 UNUSED2
	POINT_ATTBONUS_SURA,     // 56 UNUSED3
	POINT_ATTBONUS_SHAMAN,     // 57 UNUSED4
	POINT_ATTBONUS_TREE,     // 58 UNUSED5
	POINT_RESIST_WARRIOR,     // 59 UNUSED6
	POINT_RESIST_ASSASSIN,     // 60 UNUSED7
	POINT_RESIST_SURA,     // 61 UNUSED8
	POINT_RESIST_SHAMAN,     // 62 UNUSED9

	POINT_STEAL_HP,             // 63 »ý¸í·Â Èí¼ö
	POINT_STEAL_SP,             // 64 Á¤½Å·Â Èí¼ö

	POINT_MANA_BURN_PCT,        // 65 ¸¶³ª ¹ø

	/// ÇÇÇØ½Ã º¸³Ê½º ///

	POINT_DAMAGE_SP_RECOVER,    // 66 °ø°Ý´çÇÒ ½Ã Á¤½Å·Â È¸º¹ È®·ü

	POINT_BLOCK,                // 67 ºí·°À²
	POINT_DODGE,                // 68 È¸ÇÇÀ²

	POINT_RESIST_SWORD,         // 69
	POINT_RESIST_TWOHAND,       // 70
	POINT_RESIST_DAGGER,        // 71
	POINT_RESIST_BELL,          // 72
	POINT_RESIST_FAN,           // 73
	POINT_RESIST_BOW,           // 74  È­»ì   ÀúÇ×   : ´ë¹ÌÁö °¨¼Ò
	POINT_RESIST_FIRE,          // 75  È­¿°   ÀúÇ×   : È­¿°°ø°Ý¿¡ ´ëÇÑ ´ë¹ÌÁö °¨¼Ò
	POINT_RESIST_ELEC,          // 76  Àü±â   ÀúÇ×   : Àü±â°ø°Ý¿¡ ´ëÇÑ ´ë¹ÌÁö °¨¼Ò
	POINT_RESIST_MAGIC,         // 77  ¼ú¹ý   ÀúÇ×   : ¸ðµç¼ú¹ý¿¡ ´ëÇÑ ´ë¹ÌÁö °¨¼Ò
	POINT_RESIST_WIND,          // 78  ¹Ù¶÷   ÀúÇ×   : ¹Ù¶÷°ø°Ý¿¡ ´ëÇÑ ´ë¹ÌÁö °¨¼Ò

	POINT_REFLECT_MELEE,        // 79 °ø°Ý ¹Ý»ç

	/// Æ¯¼ö ÇÇÇØ½Ã ///
	POINT_REFLECT_CURSE,        // 80 ÀúÁÖ ¹Ý»ç
	POINT_POISON_REDUCE,        // 81 µ¶µ¥¹ÌÁö °¨¼Ò

	/// Àû ¼Ò¸ê½Ã ///
	POINT_KILL_SP_RECOVER,      // 82 Àû ¼Ò¸ê½Ã MP È¸º¹
	POINT_EXP_DOUBLE_BONUS,     // 83
	POINT_GOLD_DOUBLE_BONUS,    // 84
	POINT_ITEM_DROP_BONUS,      // 85

	/// È¸º¹ °ü·Ã ///
	POINT_POTION_BONUS,         // 86
	POINT_KILL_HP_RECOVER,      // 87

	POINT_IMMUNE_STUN,          // 88
	POINT_IMMUNE_SLOW,          // 89
	POINT_IMMUNE_FALL,          // 90
	//////////////////

	POINT_PARTY_ATT_GRADE,      // 91
	POINT_PARTY_DEF_GRADE,      // 92

	POINT_ATT_BONUS,            // 93
	POINT_DEF_BONUS,            // 94

	POINT_ATT_GRADE_BONUS,			// 95
	POINT_DEF_GRADE_BONUS,			// 96
	POINT_MAGIC_ATT_GRADE_BONUS,	// 97
	POINT_MAGIC_DEF_GRADE_BONUS,	// 98

	POINT_RESIST_NORMAL_DAMAGE,		// 99

	POINT_STAT_RESET_COUNT = 112,
	POINT_HORSE_SKILL = 113,

	POINT_MALL_ATTBONUS,		// 114 °ø°Ý·Â +x%
	POINT_MALL_DEFBONUS,		// 115 ¹æ¾î·Â +x%
	POINT_MALL_EXPBONUS,		// 116 °æÇèÄ¡ +x%
	POINT_MALL_ITEMBONUS,		// 117 ¾ÆÀÌÅÛ µå·ÓÀ² x/10¹è
	POINT_MALL_GOLDBONUS,		// 118 µ· µå·ÓÀ² x/10¹è
	POINT_MAX_HP_PCT,			// 119 ÃÖ´ë»ý¸í·Â +x%
	POINT_MAX_SP_PCT,			// 120 ÃÖ´ëÁ¤½Å·Â +x%

	POINT_SKILL_DAMAGE_BONUS,       // 121 ½ºÅ³ µ¥¹ÌÁö *(100+x)%
	POINT_NORMAL_HIT_DAMAGE_BONUS,  // 122 ÆòÅ¸ µ¥¹ÌÁö *(100+x)%

	POINT_SKILL_DEFEND_BONUS,       // 123 ½ºÅ³ ¹æ¾î µ¥¹ÌÁö
	POINT_NORMAL_HIT_DEFEND_BONUS,  // 124 ÆòÅ¸ ¹æ¾î µ¥¹ÌÁö
	POINT_PC_BANG_EXP_BONUS,        // 125
	POINT_PC_BANG_DROP_BONUS,       // 126 PC¹æ Àü¿ë µå·Ó·ü º¸³Ê½º

	POINT_ENERGY = 128,				// 128 ±â·Â

	// ±â·Â ui ¿ë.
	// ÀÌ·¸°Ô ÇÏ°í ½ÍÁö ¾Ê¾ÒÁö¸¸, 
	// uiTaskBar¿¡¼­´Â affect¿¡ Á¢±ÙÇÒ ¼ö ¾ø°í,
	// ´õ±¸³ª Å¬¶ó¸®¾ðÆ®¿¡¼­´Â blend_affect´Â °ü¸®ÇÏÁö ¾Ê¾Æ,
	// ÀÓ½Ã·Î ÀÌ·¸°Ô µÐ´Ù.
	POINT_ENERGY_END_TIME = 129,	// 129 ±â·Â Á¾·á ½Ã°£
	POINT_COSTUME_ATTR_BONUS = 130,		// point_value = 130
	POINT_MAGIC_ATT_BONUS_PER = 131,		// point_value = 131
	POINT_MELEE_MAGIC_ATT_BONUS_PER = 132,// point_value = 132
	POINT_RESIST_ICE = 133,				// point_value = 133
	POINT_RESIST_EARTH = 134,				// point_value = 134
	POINT_RESIST_DARK = 135,				// point_value = 135
	POINT_RESIST_CRITICAL = 136,			// point_value = 136
	POINT_RESIST_PENETRATE = 137,			// point_value = 137
	POINT_ATTBONUS_WOLFMAN,			// point_value = 138
	POINT_RESIST_WOLFMAN,			// point_value = 139
	POINT_RESIST_CLAW,				// point_value = 140
	POINT_BLEEDING_PCT,				// point_value = 141
	POINT_BLEEDING_REDUCE,			// point_value = 142
	POINT_ACCE_ABSORB,		// point_value = 143
	POINT_RESIST_MAGIC_REDUCTION,	// point_value = 144
	POINT_TITLE, // point_value = 145
	POINT_7EMESKILL, // point_value = 146
	POINT_8EMESKILL, // point_value = 147
	POINT_CINEMATIQUE, // point_value = 148
	POINT_CHEQUE, // point_value = 149

	// Å¬¶óÀÌ¾ðÆ® Æ÷ÀÎÆ®
	POINT_MIN_WEP = 200,
	POINT_MAX_WEP,
	POINT_MIN_MAGIC_WEP,
	POINT_MAX_MAGIC_WEP,
	POINT_HIT_RATE,

    //POINT_MAX_NUM = 255,=>stdafx.h ·Î/
};

typedef struct packet_points
{
    int		header;
    long long		points[POINT_MAX_NUM];
} TPacketGCPoints;

typedef struct packet_point_change
{
    int         header;

	DWORD		dwVID;
	BYTE		Type;

	long long       amount; // ¹Ù²ï °ª
    long long       value;  // ÇöÀç °ª
} TPacketGCPointChange;

typedef struct packet_motion
{
	BYTE		header;
	DWORD		vid;
	DWORD		victim_vid;
	WORD		motion;
} TPacketGCMotion;

#if defined(GAIDEN)
struct TPacketGCItemDelDeprecate
{
    TPacketGCItemDelDeprecate() :
        header(HEADER_GC_ITEM_DEL),
        pos(0),
        vnum(0),
        count(0)
    {
        memset(&alSockets, 0, sizeof(alSockets));
        memset(&aAttr, 0, sizeof(aAttr));
    }

    BYTE    header;
    BYTE    pos;
    DWORD   vnum;
    BYTE    count;
    long    alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
};

typedef struct packet_set_item
{
	BYTE		header;
	BYTE		pos;
	DWORD		vnum;
	BYTE		count;
	DWORD		flags;	// ÇÃ·¡±× Ãß°¡
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TPacketGCItemSet;

typedef struct packet_item_del
{
    BYTE        header;
    BYTE        pos;
} TPacketGCItemDel;
#else
typedef struct packet_set_item
{
	BYTE		header;
	TItemPos	Cell;
	DWORD		vnum;
	BYTE		count;
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
	DWORD		dwVnum;
#endif
} TPacketGCItemSet;

typedef struct packet_set_item2
{
	BYTE		header;
	TItemPos	Cell;
	DWORD		vnum;
	BYTE		count;
	DWORD		flags;	// ÇÃ·¡±× Ãß°¡
	DWORD		anti_flags;	// ÇÃ·¡±× Ãß°¡
	bool		highlight;
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
	DWORD		dwVnum;
#endif
} TPacketGCItemSet2;
#endif

typedef struct packet_item_del
{
    BYTE        header;
    BYTE        pos;
} TPacketGCItemDel;

typedef struct packet_use_item
{
	BYTE		header;
	TItemPos	Cell;
	DWORD		ch_vid;
	DWORD		victim_vid;

	DWORD		vnum;
} TPacketGCItemUse;

typedef struct packet_update_item
{
	BYTE		header;
	TItemPos	Cell;
	BYTE		count;
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
	DWORD		dwVnum;
#endif
} TPacketGCItemUpdate;

typedef struct packet_ground_add_item
{
    BYTE        bHeader;
    long        lX;
	long		lY;
	long		lZ;

    DWORD       dwVID;
    DWORD       dwVnum;
} TPacketGCItemGroundAdd;

typedef struct packet_ground_del_item
{
	BYTE		header;
	DWORD		vid;
} TPacketGCItemGroundDel;

typedef struct packet_item_ownership
{
    BYTE        bHeader;
    DWORD       dwVID;
    char        szName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCItemOwnership;

typedef struct packet_quickslot_add
{
    BYTE        header;
    BYTE        pos;
	TQuickSlot	slot;
} TPacketGCQuickSlotAdd;

typedef struct packet_quickslot_del
{
    BYTE        header;
    BYTE        pos;
} TPacketGCQuickSlotDel;

typedef struct packet_quickslot_swap
{
    BYTE        header;
    BYTE        pos;
    BYTE        change_pos;
} TPacketGCQuickSlotSwap;

typedef struct packet_shop_start
{
	struct packet_shop_item		items[SHOP_HOST_ITEM_MAX_NUM];
} TPacketGCShopStart;

typedef struct packet_shop_start_ex // ??? TSubPacketShopTab* shop_tabs ? ???.
{
	typedef struct sub_packet_shop_tab
	{
		char name[SHOP_TAB_NAME_MAX];
		BYTE coin_type;
		packet_shop_item items[SHOP_HOST_ITEM_MAX_NUM];
	} TSubPacketShopTab;

	DWORD owner_vid;
	int shop_tab_count;
} TPacketGCShopStartEx;


typedef struct packet_shop_update_item
{
	BYTE						pos;
	struct packet_shop_item		item;
} TPacketGCShopUpdateItem;

typedef struct packet_shop_update_price
{
	long long iElkAmount;
} TPacketGCShopUpdatePrice;

enum EPacketShopSubHeaders
{
	SHOP_SUBHEADER_GC_START,
    SHOP_SUBHEADER_GC_END,
	SHOP_SUBHEADER_GC_UPDATE_ITEM,
	SHOP_SUBHEADER_GC_UPDATE_PRICE,
    SHOP_SUBHEADER_GC_OK,
    SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY,
    SHOP_SUBHEADER_GC_SOLDOUT,
    SHOP_SUBHEADER_GC_INVENTORY_FULL,
    SHOP_SUBHEADER_GC_INVALID_POS,
	SHOP_SUBHEADER_GC_SOLD_OUT,
	SHOP_SUBHEADER_GC_START_EX,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
	SHOP_SUBHEADER_GC_OWNER,
};

typedef struct packet_shop
{
	BYTE        header;
	WORD		size;
	BYTE        subheader;
} TPacketGCShop;

typedef struct packet_exchange
{
    BYTE        header;
    BYTE        subheader;
    BYTE        is_me;
    long long       arg1;
    TItemPos       arg2;
    DWORD       arg3;
	long		alValues[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
#ifdef ENABLE_CHANGE_LOOK_SYSTEM
	DWORD		dwLookVnum;
#endif
} TPacketGCExchange;

enum
{
    EXCHANGE_SUBHEADER_GC_START,			// arg1 == vid
    EXCHANGE_SUBHEADER_GC_ITEM_ADD,		// arg1 == vnum  arg2 == pos  arg3 == count
	EXCHANGE_SUBHEADER_GC_ITEM_DEL,		// arg1 == pos
    EXCHANGE_SUBHEADER_GC_ELK_ADD,			// arg1 == elk
    EXCHANGE_SUBHEADER_GC_ACCEPT,			// arg1 == accept
    EXCHANGE_SUBHEADER_GC_END,				// arg1 == not used
	EXCHANGE_SUBHEADER_GC_ALREADY,			// arg1 == not used
	EXCHANGE_SUBHEADER_GC_LESS_ELK,		// arg1 == not used
#ifdef ENABLE_CHEQUE_SYSTEM
	EXCHANGE_SUBHEADER_GC_WON_ADD, // Système Won
#endif
};

typedef struct packet_position
{
    BYTE        header;
	DWORD		vid;
    BYTE        position;
} TPacketGCPosition;

typedef struct packet_ping
{
	BYTE		header;
} TPacketGCPing;

typedef struct packet_pong
{
	BYTE		bHeader;
} TPacketCGPong;

typedef struct packet_script
{
    BYTE		header;
    WORD        size;
	BYTE		skin;
    WORD        src_size;
} TPacketGCScript;

typedef struct packet_target
{
    BYTE        header;
    DWORD       dwVID;
    BYTE        bHPPercent;
} TPacketGCTarget;

typedef struct packet_damage_info
{
	BYTE header;
	DWORD dwVID;
	BYTE flag;
	int  damage;
} TPacketGCDamageInfo;

typedef struct packet_mount
{
    BYTE        header;
    DWORD       vid;
    DWORD       mount_vid;
    BYTE        pos;
	DWORD		_x, _y;
} TPacketGCMount;

typedef struct packet_change_speed
{
	BYTE		header;
	DWORD		vid;
	WORD		moving_speed;
} TPacketGCChangeSpeed;

typedef struct packet_move
{	
	BYTE		bHeader;
	BYTE		bFunc;
	BYTE		bArg;
	BYTE		bRot;
	DWORD		dwVID;
	LONG		lX;
	LONG		lY;
	DWORD		dwTime;
	DWORD		dwDuration;
} TPacketGCMove;

enum
{
	QUEST_SEND_IS_BEGIN         = 1 << 0,
    QUEST_SEND_TITLE            = 1 << 1,  // 28ÀÚ ±îÁö
    QUEST_SEND_CLOCK_NAME       = 1 << 2,  // 16ÀÚ ±îÁö
    QUEST_SEND_CLOCK_VALUE      = 1 << 3,
    QUEST_SEND_COUNTER_NAME     = 1 << 4,  // 16ÀÚ ±îÁö
    QUEST_SEND_COUNTER_VALUE    = 1 << 5,
	QUEST_SEND_ICON_FILE		= 1 << 6,  // 24ÀÚ ±îÁö 
};

typedef struct packet_quest_info
{
	BYTE header;
	WORD size;
	WORD index;
	BYTE flag;
} TPacketGCQuestInfo;

typedef struct packet_quest_confirm
{
    BYTE header;
    char msg[64+1];
    long timeout;
    DWORD requestPID;
} TPacketGCQuestConfirm;

typedef struct packet_attack
{
    BYTE        header;
    DWORD       dwVID;
    DWORD       dwVictimVID;    // Àû VID
    BYTE        bType;          // °ø°Ý À¯Çü
} TPacketGCAttack;

typedef struct packet_c2c
{
	BYTE		header;
	WORD		wSize;
} TPacketGCC2C;

typedef struct packetd_sync_position_element 
{ 
    DWORD       dwVID; 
    long        lX; 
    long        lY; 
} TPacketGCSyncPositionElement; 

typedef struct packetd_sync_position
{ 
    BYTE        bHeader; 
    WORD		wSize;
} TPacketGCSyncPosition; 

typedef struct packet_ownership 
{ 
    BYTE                bHeader; 
    DWORD               dwOwnerVID; 
    DWORD               dwVictimVID; 
} TPacketGCOwnership; 

#define	SKILL_MAX_NUM 255

typedef struct packet_skill_level
{
    BYTE        bHeader;
    BYTE        abSkillLevels[SKILL_MAX_NUM];
} TPacketGCSkillLevel;

typedef struct SPlayerSkill
{
	BYTE bMasterType;
	BYTE bLevel;
	time_t tNextRead;
} TPlayerSkill;

typedef struct packet_skill_level_new
{
	BYTE bHeader;
	TPlayerSkill skills[SKILL_MAX_NUM];
} TPacketGCSkillLevelNew;

// fly
typedef struct packet_fly
{
    BYTE        bHeader;
    BYTE        bType;
    DWORD       dwStartVID;
    DWORD       dwEndVID;
} TPacketGCCreateFly;

enum EPVPModes
{
	PVP_MODE_NONE,
    PVP_MODE_AGREE,
    PVP_MODE_FIGHT,
    PVP_MODE_REVENGE,
};

typedef struct packet_duel_start
{
    BYTE	header ;
    WORD	wSize ;	// DWORD°¡ ¸î°³? °³¼ö = (wSize - sizeof(TPacketGCPVPList)) / 4
} TPacketGCDuelStart ;

typedef struct packet_pvp
{
	BYTE		header;
	DWORD		dwVIDSrc;
	DWORD		dwVIDDst;
	BYTE		bMode;
} TPacketGCPVP;

typedef struct packet_skill_cooltime_end
{
	BYTE		header;
	BYTE		bSkill;
} TPacketGCSkillCoolTimeEnd;

typedef struct packet_warp
{
	BYTE			bHeader;
	LONG			lX;
	LONG			lY;
	LONG			lAddr;
	WORD			wPort;
} TPacketGCWarp;

typedef struct packet_party_invite
{
    BYTE header;
    DWORD leader_pid;
} TPacketGCPartyInvite;

typedef struct packet_party_add
{
    BYTE header;
    DWORD pid;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketGCPartyAdd;

typedef struct packet_party_update
{
    BYTE header;
    DWORD pid;
    BYTE state;
    BYTE percent_hp;
    short affects[PARTY_AFFECT_SLOT_MAX_NUM];
} TPacketGCPartyUpdate;

typedef struct packet_party_remove
{
    BYTE header;
    DWORD pid;
} TPacketGCPartyRemove;

typedef TPacketCGSafeboxCheckout TPacketGCSafeboxCheckout;
typedef TPacketCGSafeboxCheckin TPacketGCSafeboxCheckin;

typedef struct packet_safebox_wrong_password
{
    BYTE        bHeader;
} TPacketGCSafeboxWrongPassword;

typedef struct packet_safebox_size
{
	BYTE bHeader;
	BYTE bSize;
} TPacketGCSafeboxSize; 

typedef struct packet_safebox_money_change
{
    BYTE bHeader;
    DWORD dwMoney;
} TPacketGCSafeboxMoneyChange;

typedef struct command_empire
{
    BYTE        bHeader;
    BYTE        bEmpire;
} TPacketCGEmpire;

typedef struct packet_empire
{
    BYTE        bHeader;
    BYTE        bEmpire;
} TPacketGCEmpire;

enum
{
	FISHING_SUBHEADER_GC_START,
	FISHING_SUBHEADER_GC_STOP,
	FISHING_SUBHEADER_GC_REACT,
	FISHING_SUBHEADER_GC_SUCCESS,
	FISHING_SUBHEADER_GC_FAIL,
    FISHING_SUBHEADER_GC_FISH,
};

typedef struct packet_fishing
{
    BYTE header;
    BYTE subheader;
    DWORD info;
    BYTE dir;
} TPacketGCFishing;

typedef struct paryt_parameter
{
    BYTE        bHeader;
    BYTE        bDistributeMode;
} TPacketGCPartyParameter;

//////////////////////////////////////////////////////////////////////////
// Guild

enum
{
    GUILD_SUBHEADER_GC_LOGIN,
	GUILD_SUBHEADER_GC_LOGOUT,
	GUILD_SUBHEADER_GC_LIST,
	GUILD_SUBHEADER_GC_GRADE,
	GUILD_SUBHEADER_GC_ADD,
	GUILD_SUBHEADER_GC_REMOVE,
	GUILD_SUBHEADER_GC_GRADE_NAME,
	GUILD_SUBHEADER_GC_GRADE_AUTH, 
	GUILD_SUBHEADER_GC_INFO,
	GUILD_SUBHEADER_GC_COMMENTS,
    GUILD_SUBHEADER_GC_CHANGE_EXP,
    GUILD_SUBHEADER_GC_CHANGE_MEMBER_GRADE,
	GUILD_SUBHEADER_GC_SKILL_INFO,
	GUILD_SUBHEADER_GC_CHANGE_MEMBER_GENERAL,
	GUILD_SUBHEADER_GC_GUILD_INVITE,
    GUILD_SUBHEADER_GC_WAR,
    GUILD_SUBHEADER_GC_GUILD_NAME,
    GUILD_SUBHEADER_GC_GUILD_WAR_LIST,
    GUILD_SUBHEADER_GC_GUILD_WAR_END_LIST,
    GUILD_SUBHEADER_GC_WAR_POINT,
	GUILD_SUBHEADER_GC_MONEY_CHANGE,
};

typedef struct packet_guild
{
    BYTE header;
    WORD size;
    BYTE subheader;
} TPacketGCGuild;

// SubHeader - Grade
enum
{
    GUILD_AUTH_ADD_MEMBER       = (1 << 0),
    GUILD_AUTH_REMOVE_MEMBER    = (1 << 1),
    GUILD_AUTH_NOTICE           = (1 << 2),
    GUILD_AUTH_SKILL            = (1 << 3),
};

typedef struct packet_guild_sub_grade
{
	char grade_name[GUILD_GRADE_NAME_MAX_LEN+1]; // 8+1 ±æµåÀå, ±æµå¿ø µîÀÇ ÀÌ¸§
	BYTE auth_flag;
} TPacketGCGuildSubGrade;

typedef struct packet_guild_sub_member
{
	DWORD pid;
	BYTE byGrade;
	BYTE byIsGeneral;
	BYTE byJob;
	BYTE byLevel;
	DWORD dwOffer;
	BYTE byNameFlag;
// if NameFlag is TRUE, name is sent from server.
//	char szName[CHARACTER_ME_MAX_LEN+1];
} TPacketGCGuildSubMember;

typedef struct packet_guild_sub_info
{
    WORD member_count;
    WORD max_member_count;
	DWORD guild_id;
    DWORD master_pid;
    DWORD exp;
    BYTE level;
    char name[GUILD_NAME_MAX_LEN+1];
	DWORD gold;
	BYTE hasLand;
} TPacketGCGuildInfo;

enum EGuildWarState
{
    GUILD_WAR_NONE,
    GUILD_WAR_SEND_DECLARE,
    GUILD_WAR_REFUSE,
    GUILD_WAR_RECV_DECLARE,
    GUILD_WAR_WAIT_START,
    GUILD_WAR_CANCEL,
    GUILD_WAR_ON_WAR,
    GUILD_WAR_END,

    GUILD_WAR_DURATION = 2*60*60, // 2½Ã°£
};

typedef struct packet_guild_war
{
    DWORD       dwGuildSelf;
    DWORD       dwGuildOpp;
    BYTE        bType;
    BYTE        bWarState;
} TPacketGCGuildWar;

typedef struct SPacketGuildWarPoint
{
    DWORD dwGainGuildID;
    DWORD dwOpponentGuildID;
    long lPoint;
} TPacketGuildWarPoint;

// SubHeader - Dungeon
enum
{
	DUNGEON_SUBHEADER_GC_TIME_ATTACK_START = 0,
	DUNGEON_SUBHEADER_GC_DESTINATION_POSITION = 1,
};

typedef struct packet_dungeon
{
	BYTE		bHeader;
    WORD		size;
    BYTE		subheader;
} TPacketGCDungeon;

// Private Shop
typedef struct SPacketGCShopSign
{
    BYTE        bHeader;
    DWORD       dwVID;
    char        szSign[SHOP_SIGN_MAX_LEN + 1];
} TPacketGCShopSign;

typedef struct SPacketGCTime
{
    BYTE        bHeader;
    time_t      time;
} TPacketGCTime;

enum
{
    WALKMODE_RUN,
    WALKMODE_WALK,
};

typedef struct SPacketGCWalkMode
{
    BYTE        header;
    DWORD       vid;
    BYTE        mode;
} TPacketGCWalkMode;

typedef struct SPacketGCChangeSkillGroup
{
    BYTE        header;
    BYTE        skill_group;
} TPacketGCChangeSkillGroup;

struct TMaterial
{
    DWORD vnum;
    DWORD count;
};

typedef struct SRefineTable
{
    DWORD src_vnum;
    DWORD result_vnum;
    BYTE material_count;
    int cost; // ¼Ò¿ä ºñ¿ë
    int prob; // È®·ü
    TMaterial materials[REFINE_MATERIAL_MAX_NUM];
} TRefineTable;

typedef struct SPacketGCRefineInformation
{
	BYTE			header;
	BYTE			pos;
	TRefineTable	refine_table;
} TPacketGCRefineInformation;

typedef struct SPacketGCRefineInformationNew
{
	BYTE			header;
	BYTE			type;
	BYTE			pos;
	TRefineTable	refine_table;
} TPacketGCRefineInformationNew;

enum SPECIAL_EFFECT
{
	SE_NONE,
	SE_HPUP_RED,
	SE_SPUP_BLUE,
	SE_SPEEDUP_GREEN,
	SE_DXUP_PURPLE,
	SE_CRITICAL,
	SE_PENETRATE,
	SE_BLOCK,
	SE_DODGE,
	SE_CHINA_FIREWORK,
	SE_SPIN_TOP,
	SE_SUCCESS,
	SE_FAIL,
	SE_FR_SUCCESS,    
    SE_LEVELUP_ON_14_FOR_GERMANY,	//·¹º§¾÷ 14ÀÏ¶§ ( µ¶ÀÏÀü¿ë )
    SE_LEVELUP_UNDER_15_FOR_GERMANY,//·¹º§¾÷ 15ÀÏ¶§ ( µ¶ÀÏÀü¿ë )
    SE_PERCENT_DAMAGE1,
    SE_PERCENT_DAMAGE2,
    SE_PERCENT_DAMAGE3,    
	SE_AUTO_HPUP,
	SE_AUTO_SPUP,
	SE_EQUIP_RAMADAN_RING,			// ÃÊ½Â´ÞÀÇ ¹ÝÁö¸¦ Âø¿ëÇÏ´Â ¼ø°£¿¡ ¹ßµ¿ÇÏ´Â ÀÌÆåÆ®
	SE_EQUIP_HALLOWEEN_CANDY,		// ÇÒ·ÎÀ© »çÅÁÀ» Âø¿ë(-_-;)ÇÑ ¼ø°£¿¡ ¹ßµ¿ÇÏ´Â ÀÌÆåÆ®
	SE_EQUIP_HAPPINESS_RING,		// Å©¸®½º¸¶½º Çàº¹ÀÇ ¹ÝÁö¸¦ Âø¿ëÇÏ´Â ¼ø°£¿¡ ¹ßµ¿ÇÏ´Â ÀÌÆåÆ®
	SE_EQUIP_LOVE_PENDANT,		// ¹ß·»Å¸ÀÎ »ç¶ûÀÇ ÆÒ´øÆ®(71145) Âø¿ëÇÒ ¶§ ÀÌÆåÆ® (¹ßµ¿ÀÌÆåÆ®ÀÓ, Áö¼ÓÀÌÆåÆ® ¾Æ´Ô)
	SE_ACCE_SUCCEDED_1,
	SE_EQUIP_ACCE_1,
	SE_EQUIP_ACCE_2,
	SE_EQUIP_ACCE_3,
	SE_EQUIP_ACCE_4,
};

typedef struct SPacketGCSpecialEffect
{
    BYTE header;
    BYTE type;
    DWORD vid;
} TPacketGCSpecialEffect;

typedef struct SPacketGCNPCPosition
{
    BYTE header;
	WORD size;
    WORD count;
} TPacketGCNPCPosition;

struct TNPCPosition
{
    BYTE bType;
    char name[CHARACTER_NAME_MAX_LEN+1];
    long x;
    long y;
};

typedef struct SPacketGCChangeName
{
    BYTE header;
    DWORD pid;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketGCChangeName;

enum EBlockAction
{
    BLOCK_EXCHANGE              = (1 << 0),
    BLOCK_PARTY_INVITE          = (1 << 1),
    BLOCK_GUILD_INVITE          = (1 << 2),
    BLOCK_WHISPER               = (1 << 3),
    BLOCK_MESSENGER_INVITE      = (1 << 4),
    BLOCK_PARTY_REQUEST         = (1 << 5),
};

typedef struct packet_china_matrixd_card
{
	BYTE	bHeader;
	DWORD	dwRows;
	DWORD	dwCols;
} TPacketGCChinaMatrixCard;

typedef struct packet_runup_matrixd_quiz
{
	BYTE	bHeader;
	char	szQuiz[RUNUP_MATRIX_QUIZ_MAX_LEN + 1];	
} TPacketGCRunupMatrixQuiz;

typedef struct packet_newcibn_passpod_request
{
	BYTE	bHeader;
} TPacketGCNEWCIBNPasspodRequest;

typedef struct packet_newcibn_passpod_failure
{
	BYTE	bHeader;
	char	szMessage[NEWCIBN_PASSPOD_FAILURE_MAX_LEN + 1];
} TPacketGCNEWCIBNPasspodFailure;

typedef struct packet_login_key
{
	BYTE	bHeader;
	DWORD	dwLoginKey;
} TPacketGCLoginKey;

typedef struct packet_auth_success
{
    BYTE        bHeader;
    DWORD       dwLoginKey;
    BYTE        bResult;
} TPacketGCAuthSuccess;

typedef struct packet_auth_success_openid
{
    BYTE        bHeader;
    DWORD       dwLoginKey;
    BYTE        bResult;
	char		login[ID_MAX_NUM + 1];
} TPacketGCAuthSuccessOpenID;

typedef struct packet_channel
{
    BYTE header;
    BYTE channel;
} TPacketGCChannel;

typedef struct SEquipmentItemSet
{
	DWORD   vnum;
	BYTE    count;
	long    alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TEquipmentItemSet;

typedef struct pakcet_view_equip
{
    BYTE header;
	DWORD dwVID;
	TEquipmentItemSet equips[WEAR_MAX_NUM];
} TPacketGCViewEquip;

typedef struct
{
    DWORD       dwID;
    long        x, y;
    long        width, height;
    DWORD       dwGuildID;
} TLandPacketElement;

typedef struct packet_land_list
{
    BYTE        header;
    WORD        size;
} TPacketGCLandList;

typedef struct
{
    BYTE        bHeader;
    long        lID;
    char        szTargetName[32+1];
} TPacketGCTargetCreate;

enum
{
	CREATE_TARGET_TYPE_NONE,
	CREATE_TARGET_TYPE_LOCATION,
	CREATE_TARGET_TYPE_CHARACTER,
};

typedef struct
{
	BYTE		bHeader;
	long		lID;
	char		szTargetName[32+1];
	DWORD		dwVID;
	BYTE		byType;
} TPacketGCTargetCreateNew;

typedef struct
{
    BYTE        bHeader;
    long        lID;
    long        lX, lY;
} TPacketGCTargetUpdate;

typedef struct
{
    BYTE        bHeader;
    long        lID;
} TPacketGCTargetDelete;

typedef struct
{
    DWORD       dwType;
    BYTE        bPointIdxApplyOn;
    long        lApplyValue;
    DWORD       dwFlag;
    long        lDuration;
    long        lSPCost;
} TPacketAffectElement;

typedef struct 
{
    BYTE bHeader;
    TPacketAffectElement elem;
} TPacketGCAffectAdd;

typedef struct
{
    BYTE bHeader;
    DWORD dwType;
    BYTE bApplyOn;
} TPacketGCAffectRemove;

typedef struct packet_mall_open
{
	BYTE bHeader;
	BYTE bSize;
} TPacketGCMallOpen;

typedef struct packet_lover_info
{
	BYTE bHeader;
	char szName[CHARACTER_NAME_MAX_LEN + 1];
	BYTE byLovePoint;
} TPacketGCLoverInfo;

typedef struct packet_love_point_update
{
	BYTE bHeader;
	BYTE byLovePoint;
} TPacketGCLovePointUpdate;

typedef struct packet_dig_motion
{
    BYTE header;
    DWORD vid;
    DWORD target_vid;
	BYTE count;
} TPacketGCDigMotion;

typedef struct SPacketGCOnTime
{
    BYTE header;
    int ontime;     // sec
} TPacketGCOnTime;

typedef struct SPacketGCResetOnTime
{
    BYTE header;
} TPacketGCResetOnTime;

typedef struct SPacketGCPanamaPack
{
    BYTE    bHeader;
    char    szPackName[256];
    BYTE    abIV[32];
} TPacketGCPanamaPack;

typedef struct SPacketGCHybridCryptKeys
{
private:
	SPacketGCHybridCryptKeys() : m_pStream(NULL) {}
  
  

public:
	SPacketGCHybridCryptKeys(int iStreamSize) : iKeyStreamLen(iStreamSize)
	{
		m_pStream = new BYTE[iStreamSize];
	}

	~SPacketGCHybridCryptKeys()
	{
		if( m_pStream )
		{
			delete[] m_pStream;
			m_pStream = NULL;
		}
	}

	static int GetFixedHeaderSize() 
	{
		return sizeof(BYTE)+sizeof(WORD)+sizeof(int);
	}

	BYTE	bHeader;
	WORD    wDynamicPacketSize;
	int		iKeyStreamLen;
	BYTE*	m_pStream;

			  
						 
				   
				 
} TPacketGCHybridCryptKeys;


typedef struct SPacketGCHybridSDB
{
private:
	SPacketGCHybridSDB() : m_pStream(NULL) {}
  
  

public:
	SPacketGCHybridSDB(int iStreamSize) : iSDBStreamLen(iStreamSize)
	{
		m_pStream = new BYTE[iStreamSize];
	}

	~SPacketGCHybridSDB()
	{
		delete[] m_pStream;
		m_pStream = NULL;
	}

	static int GetFixedHeaderSize()
	{
		return sizeof(BYTE)+sizeof(WORD)+sizeof(int);
	}

	BYTE	bHeader;
	WORD    wDynamicPacketSize;
	int		iSDBStreamLen;
	BYTE*	m_pStream;

			  
						 
				   
				 
} TPacketGCHybridSDB;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Client To Client

typedef struct packet_state
{
	BYTE			bHeader;
	BYTE			bFunc;
	BYTE			bArg;
	BYTE			bRot;
	DWORD			dwVID;
	DWORD			dwTime;
	TPixelPosition	kPPos;
} TPacketCCState;

typedef struct packet_hs_check_req
{
	BYTE	bHeader;
	AHNHS_TRANS_BUFFER	Req;
} TPacketHSCheck;

//NOTE : recv/send¿¡ °øÅëÀ¸·Î »ý±è, bPacketDataÀÇ ³»¿ë¸¸ ¹Ù²ï´Ù.
typedef struct packet_xtrap_verify
{
	BYTE	bHeader;
	BYTE	bPacketData[128];

} TPacketXTrapCSVerify;

// AUTOBAN
typedef struct packet_autoban_quiz
{
    BYTE bHeader;
	BYTE bDuration;
    BYTE bCaptcha[64*32];
    char szQuiz[256];
} TPacketGCAutoBanQuiz;

// END_OF_AUTOBAN

#ifdef _IMPROVED_PACKET_ENCRYPTION_
struct TPacketKeyAgreement
{
	static const int MAX_DATA_LEN = 256;
	BYTE bHeader;
	WORD wAgreedLength;
	WORD wDataLength;
	BYTE data[MAX_DATA_LEN];
};

struct TPacketKeyAgreementCompleted
{
	BYTE bHeader;
	BYTE data[3]; // dummy (not used)
};
#endif // _IMPROVED_PACKET_ENCRYPTION_


#ifdef __AUCTION__
// ArgumentÀÇ ¿ëµµ´Â cmd¿¡ µû¶ó ´Ù¸£´Ù.
typedef struct SPacketCGAuctionCmd
{
	BYTE bHeader;
	BYTE cmd;
	int arg1;
	int arg2;
	int arg3;
	int arg4;
} TPacketCGAuctionCmd;

typedef struct SPacketGCAuctionItemListPack
{
	BYTE bHeader;
	BYTE bNumbers;
} TPacketGCAuctionItemListPack;

#endif

typedef struct SPacketGCSpecificEffect
{
	BYTE header;
	DWORD vid;
	char effect_file[128];
} TPacketGCSpecificEffect;

// ¿ëÈ¥¼®
enum EDragonSoulRefineWindowRefineType
{
	DragonSoulRefineWindow_UPGRADE,
	DragonSoulRefineWindow_IMPROVEMENT,
	DragonSoulRefineWindow_REFINE,
};

enum EPacketCGDragonSoulSubHeaderType
{
	DS_SUB_HEADER_OPEN,
	DS_SUB_HEADER_CLOSE,
	DS_SUB_HEADER_DO_UPGRADE,
	DS_SUB_HEADER_DO_IMPROVEMENT,
	DS_SUB_HEADER_DO_REFINE,
	DS_SUB_HEADER_REFINE_FAIL,
	DS_SUB_HEADER_REFINE_FAIL_MAX_REFINE,
	DS_SUB_HEADER_REFINE_FAIL_INVALID_MATERIAL,
	DS_SUB_HEADER_REFINE_FAIL_NOT_ENOUGH_MONEY,
	DS_SUB_HEADER_REFINE_FAIL_NOT_ENOUGH_MATERIAL,
	DS_SUB_HEADER_REFINE_FAIL_TOO_MUCH_MATERIAL,
	DS_SUB_HEADER_REFINE_SUCCEED,
};

typedef struct SPacketCGDragonSoulRefine
{
	SPacketCGDragonSoulRefine() : header (HEADER_CG_DRAGON_SOUL_REFINE)
	{}
  

	BYTE header;
	BYTE bSubType;
	TItemPos ItemGrid[DS_REFINE_WINDOW_MAX_NUM];
} TPacketCGDragonSoulRefine;

typedef struct SPacketGCDragonSoulRefine
{
	SPacketGCDragonSoulRefine() : header(HEADER_GC_DRAGON_SOUL_REFINE)
	{}
  

	BYTE header;
	BYTE bSubType;
	TItemPos Pos;
} TPacketGCDragonSoulRefine;

typedef struct SChannelStatus
{
	short nPort;
	BYTE bStatus;
} TChannelStatus;

#pragma pack(pop)


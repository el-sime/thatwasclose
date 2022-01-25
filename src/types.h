// needed enums:

// Item types
// Bonuses types


typedef struct Managers {
	char name[50];
	char portrait[50]; // could be an enum, if there is a list of predefined portraits
} Manager;

typedef struct Properties {
	char name[50];
} Property;

typedef struct Bonuses {
	char description[100]
	int type;
	float value;
} Bonus;

typedef struct Items {
	char name[50];
	int type;
	char description[100];
	Bonus effect;
} Item;

typedef struct Agencies {
	char name[50];
	unsigned int level;
	float xp;
	float gold;
	float reputation;
	float bling;
	Property property;
	Item loot_inventory[100];
} Agency;

/**
 * calulate rates on the fly
 */

float gold_rate();

float xp_rate();

float reputation_rate();

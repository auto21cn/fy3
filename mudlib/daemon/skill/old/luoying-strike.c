// luoying-strike.c  落英神剑掌

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「落英缤纷」，双掌一合，左掌护胸，右掌击向$n的$l",
		"dodge":		20,
		"parry":		20,
		"force":		25,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「蝶舞花见」，右掌似攻实守，左掌化虚为实击向$n的$l",
		"dodge":		10,
		"parry":		30,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出「百花争艳」，身形突然消失了，结果却转至$n的背后，一掌拍下",
		"dodge":		50,
		"parry":		-20,
		"force":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N吐气扬声，使出「秋风瑟瑟」，双掌化作无数掌影同时向$n的全身攻击",
		"dodge":		-50,
		"parry":		30,
		"force":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N大喝一声，一招「热火骄阳」带起一阵令人窒息的热浪击向$n$l",
		"dodge":		-20,
		"parry":		40,
		"force":		60,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N突然使一招「神鬼莫知」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
		"dodge":		50,
		"parry":		-20,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N神色凝重，双掌缓缓地推出，使出「残花败叶」，瞬时天地为之一黯",
		"dodge":		-50,
		"parry":		-20,
		"force":		75,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
        object ob;

		if( (int)me->query_skill("suiyu-force", 1) < 20 )
			return notify_fail("你的碎玉神功火候不足，无法练落英神剑掌。\n");
		
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练落英神剑掌。\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练兰花拂穴手必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习落英神剑掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍落英神剑掌。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/luoying-strike/" + action;
}
 

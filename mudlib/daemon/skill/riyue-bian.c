// riyue-bian.c 日月鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N端坐不动，一招「裂石式」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
	"damage":	50,
	"damage_type":	"刺伤"
]),
([	"action":		"$N身形一转，一招「断川式」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
	"damage":	80,
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「破云式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"damage":	110,
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「分海式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"damage":	140,
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「裂空式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"damage":	170,
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「佛光普照」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"damage":	200,
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「金刚伏魔」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"damage":	220,
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「佛法无边」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"damage":	250,
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_force") < 100)
		return notify_fail("你的内力不足，没有办法练日月鞭法, 多练些内力再来吧。\n");

	if ((int)me->query_skill("sanyang-shengong",1)<50)
		return notify_fail("你的三阳神功火侯不够。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

	return 1;
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练日月鞭法。\n");
	me->receive_damage("kee",20);
	return 1;
}

string perform_action_file(string action)
{
		return __DIR__"riyue-bian/" + action;
}
int power_point()	{	return 1.5;	}
int hard_point()	{	return 2.5;	}


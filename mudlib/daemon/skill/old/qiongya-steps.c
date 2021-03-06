//【龙神身法】 dragonstep.c
// cglaem...12/19/96.

inherit SKILL;

string *dodge_msg = ({
	"但是$n身形一晃，从$N身边轻轻滑过。\n",
            "只见$n往后一退，隐入一团白雾中，$N这一招顿时没了目标。\n",
            "$n一转身，一团白雾冒起，隔断了$N的攻势。\n",
            "$n左脚轻轻在地上一点，缓缓升上半空，避开了$N的攻势。\n",
            "$n连续几个转身。眼前白光一闪，$n已出现在$N身后。\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if (me->query("gender") != "女性")
		return notify_fail("这种步法需要纯阴之质才能习练!\n");
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练琼崖身法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

// tianlong-force 天龙心法 by ksusan 08/09/97
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{

	if ((int)me->query_skill("force", 1) < 25)
		return notify_fail("你的基本内功火候还不够，无法领会天龙心法。\n");

	return 1;
}


int practice_skill(object me)
{
	if(me->query("kee")<20)
		return notify_fail("你的体力太低了。\n");
	if(me->query("force")<20)
		return notify_fail("你的内力不够天龙心法。\n");

	me->receive_damage("kee",10);
	me->add("force",-10);
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"tianlong-force/" + func;
}

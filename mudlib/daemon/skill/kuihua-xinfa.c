// kuihua-xinfa.c 葵花心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("葵花心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
return "/daemon/class/riyue/kuihua-xinfa/" + func;
}
int power_point()	{	return 1.75;	}
int hard_point()	{	return 2;	}



#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    if ((string)me->query("gender") != "女性" )
	return notify_fail(HIY"这种阴柔的内功只有女子才适合学。\n"NOR);
    return 1;
}

int practice_skill(object me)
{
return notify_fail("灵元心法只能用(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
return "/daemon/class/hengshan/lingyuan-xinfa/"+func;
}


//玄天步法
inherit SKILL;

string *dodge_msg = ({
		"$n一招「风起白云飞」轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「天涯任我行」早已避在七尺之外。\n",
		"$n使出「独步江湖路」，轻轻松松地闪过。\n",
		"$n左足一点，一招「踏雪渺无痕」腾空而起，避了开去。\n",
		"可是$n使一招「身飞轻如燕」，身子轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「落叶了无根」轻轻闪过。\n",
		"但是$n一招「游刃犹有余」使出，早已绕到$N身後！\n",
		"但是$n身形飘忽，轻轻一纵，一招「天高任鸟飞」，避开这一击。\n",
		"$n身形往上一拔，一招「海阔凭鱼跃」，一个转折落在数尺之外。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
		if( (int)me->query("kee") < 30)
			return notify_fail("你的气不够，不能练玄天步法。\n");
        me->receive_damage("kee", 30);
        return 1;
}

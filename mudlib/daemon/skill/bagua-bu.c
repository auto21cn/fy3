// bagua-step.c
// 九宫八卦步

inherit SKILL;

string *dodge_msg = ({
	"$n一招「瞬息千里」脚蹋乾位，轻轻松松地避开了$N的攻击。\n",
	"只见$n身形一转，一式「霸王卸甲」竟然蹋到了坤位，很自然的闪过了$N的攻击。\n",
	"可是$n使一招「扑朔迷离」向震位蹋去，$N眼前一花，已经不见了$n的踪影。\n",
	"$n身体急转一招「瑶池仙舞」，突然化作一团迷雾，$N定睛一看$n已经到了坎位。\n",
	"但是$n一招「鹏程万里」脚蹋离位，跃出了一大步，$N的招数连$n的衣角也没有碰到$n！\n",
	"只见$n一式「天南地北」，已经从$N的头顶跃到了艮位。\n",
	"$n一式「颠倒阴阳」蹋向兑位，天地为之色变，$N脸色一变，根本忘了进攻。\n",
	"只见$n突然使出一招「乾坤倒置」，在$N不知不觉中就到了墟位。\n",
});

int valid_enable(string usage) { return (usage == "dodge");}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<40)
		return notify_fail("你的体力太差了，无法练习九宫八卦步。\n");
		me->receive_damage("kee",30);
        return 1;
}


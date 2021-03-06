inherit SKILL;

string *dodge_msg = ({
	"$n一招「西风生翠萝」脚踏五行八卦，连跨几步避开了$N的攻击。\n",
	"$n使出「北风江上寒」身行贴地平平掠出，闪过了$N的攻击。\n",
	"「春风寄燕然」$n身化青风，在$N目瞪可呆中，已来到$N身后。\n",
	"$n身体急转一招「落叶秋风早」，身如旋风,扶转直上,轻轻落在几丈之外。\n",
	"但是$n一招「水寒风似刀」双脚不动，平平移开,$N这招落了空！\n",
	"只见$n平空跃出,脚在近处树干上一蹬,如箭般射过$N头顶,正是一招「长风几万里」。\n",
	"$n一式「东风细雨来」大袖一挥，平地风起，飞沙走石中$N连人影都看不到。\n",
	"$n使出「临风听暮蝉」，只手托颊,盘腿悠然坐下,$N愕然中走了空招。\n",
});

int valid_enable(string usage) { return (usage == "dodge");}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < random(40) )
		return notify_fail("你现在体力不济，无法练习天风旋。\n");
		me->receive_damage("gin",30);
        return 1;
}


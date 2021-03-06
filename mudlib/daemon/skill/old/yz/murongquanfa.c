// fonxansword.c

#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使一招「峰回路转」，$w画出一道弧线，慢悠悠的拍向$n的$l",
			"dodge":                30,
		"damage":               50,
		"parry":		50,
		"weapon":"右掌",
		"damage_type":"瘀伤",
        ]),
        ([      "action":               
"$N使出慕容拳法中的「空山鸟语」，$w击向$n的$l",
		"dodge":                40,
		"damage":               50,
		"parry":		40,
		"force":		40,
	"weapon":"双拳化掌",
	"damage_type":"瘀伤",
        ]),
        ([      "action":               
"$N一招「御风而行」，身形陡然滑出数尺，$w斩向$n的$l",
		"dodge":		40,
		"damage":               50,
		"parry":		40,
		"force":		40,
	"weapon":"拳掌交加",
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右拳中宫直进，一式「旭日东升」对准$n的$l猛击一拳",
		"dodge":		40,
		"parry":		60,
		"force":		30,
		"damage":		80,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N纵身一跃，一招「金光泻地」$w对准$n的$l斜斜劈下",
		"dodge":		40,
		"parry":		80,
		"force":		70,
		"damage":		90,
	"weapon":"拳化指、指变掌，",
		"damage_type":  "劈伤"
        ]),
        ([      "action":               
"$N的右手凭空一指，一招「童子引路」，$w如闪电般直扑$n的$l",
                "dodge":                20,
                "damage":               40,
		"parry":		60,
		"force":		90,
	"weapon":"拳至半路突变指，",
		"damage_type" : "戳伤"
        ]),
        ([      "action":               
"$N两拳向外一分，使一招「柳暗花明」反手对准$n$l一拳击去",
		"dodge":		50,
		"parry":		50,
		"force":		50,
                "damage":               20,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双拳护胸，身形一转使一招「空谷秋虹」，$w拍向$n的$l",
		"dodge":		40,
		"damage":               80,
		"parry":		50,
		"force":		40,
		"weapon":"由拳化掌",
		"damage_type":  "斩伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

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
notify_fail("你的内力或气不够，没有办法练习慕容拳法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
	write("你按著所学练了一遍慕容拳法。\n");
        return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("xiake")+"/murongquanfa/"+action;
}
void skill_improved(object me)
{
	if(me->query_skill("murongquanfa",1)==20)	
	tell_object(me,HIC"你领悟了「探云手」的手法！(tanyunshou)\n"NOR);
	if(me->query_skill("murongquanfa",1)==40)
	tell_object(me,HIC"你领悟了「参合指」的指法！(canhezhi)\n"NOR);
	if(me->query_skill("murongquanfa",1)==80)
	tell_object(me,HIC"你领悟了「斗转星移」神功！(douzhuan)\n"NOR);
}

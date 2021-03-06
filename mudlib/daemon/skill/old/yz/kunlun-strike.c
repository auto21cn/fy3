// kunlun-strike.c   昆仑掌法  by wangzc & ppl      2/9/97       copy form  五毒玄阴掌

inherit SKILL;

mapping *action = ({
    ([  "action":       "$N使出一招「混沌初开」，双掌开合间产生一股强大的气旋，$n身形一窒间$N的双掌已按上了$n的$l",
		"dodge":		30,
		"parry":		30,
		"force":		45,
		"damage":		120,
		"damage_type":	"瘀伤",
		"condition_param": 30,
	]),
    ([  "action":       "$N一招「雨打巴焦」，斗然间一声巨喝，双掌如狂风暴雨般攻向$n的胸膛",
		"dodge":		-20,
		"parry":		40,
		"force":		40,
		"damage":		150,
		"damage_type":	"瘀伤",
		"condition_param": 40,
	]),
    ([  "action":       "$N使出「金鹰搏兔」，一个筋斗直飞上天，随即头下脚上的直扑$n，在$n封架双掌的时$N的右脚已反踢至$n的后脑",
		"dodge":		40,
		"parry":		10,
		"force":		30,
		"damage":		180,
		"damage_type":	"瘀伤",
		"condition_param": 50,
	]),
      ([  "action":       "$N身形急转，一招「两仪乍开」，刹那间幻出千万个影子，双掌左右合击向$n",
		"dodge":		-50,
		"parry":		-30,
		"force":		90,
		"damage":		200,
		"damage_type":	"瘀伤",
		"condition_param": 60,
	]),

});

int valid_learn(object me)
{
        object ob;

         if( (int)me->query_skill("kunlun-xinfa", 1) < 20 )
            return notify_fail("你的昆仑心法火候不足，无法练昆仑掌法。\n");
		
        if( (int)me->query("max_force") < 50 )
                  return notify_fail("你的内力不够，没有办法练昆仑掌法。\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("练昆仑掌法必须空手。\n");
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
notify_fail("你的内力或气不够，没有办法练习昆仑掌法。\n");
        me->receive_damage("kee", 20);
        me->add("force", -3);
        write("你按著所学练了一遍昆仑掌法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/kunlun-strike/" + action;
}

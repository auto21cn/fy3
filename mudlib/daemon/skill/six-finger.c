//
// six-finger.c
// 六脉神剑
// 小岛编写(islet@wx.jsinfo.net)
// 1999年10月31日
//

inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$N双手大开大阖，拇指向外一捺，一招[少商剑],\n以石破天惊、风雨大至之势袭向$n！",
          "force" : 120,
        "damage_type" : "伤害",
          "damage" : 120,
]),
([      "action" : "$N食指疾伸，一招[商阳剑],嗤的一声，\n一股真气从指尖激射而出，轻灵迅速地向$n刺去！",
          "force" : 130,
        "damage_type" : "伤害",
          "damage" : 130,
]),
([      "action" : "$N中指戳出，一招[中冲剑],内劲自“中冲穴”激射而出，嗤嗤声响，刺向$n!",
          "force" : 140,
        "damage_type" : "伤害",
          "damage" : 140,
]),
([      "action" : "$N连起真气，无名指点处，一招[关冲剑],真气自‘关冲’穴中汹涌并发,直指$n！",
          "force" : 150,
        "damage_type" : "伤害",
          "damage" : 150,
]),
([      "action" : "$N向右斜行三步，一招[少冲剑],右手小指的内力自右向左的向$n斜攻过去!",
          "force" : 160,
        "damage_type" : "伤害",
          "damage" : 160,
]),
([      "action" : "$N向左斜行三步，一招[少泽剑],左手小指的内力自左向右的向$n斜攻过去！",
          "force" : 170,
        "damage_type" : "伤害",
          "damage" : 170,
]),
});

int valid_enable(string usage) 
{
        return (usage == "unarmed") || (usage == "parry");
}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("yiyang-zhi", 1) < 80)
                return notify_fail("你的[一阳指]火候太浅。\n");
        return 1;
}

mapping query_action(object me,object target)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (me->query_temp("weapon")||me->query_temp("second_weapon"))
                return notify_fail("空手才能练六脉神剑。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力不够练六脉神剑。\n");
        if ((int)me->query("force") < 30)
                return notify_fail("你的内力不够练六脉神剑。\n");
        me->receive_damage("kee", 30);
        me->add("force",-10);
        return 1;
}

string perform_action_file(string action)
{
        return "/daemon/class/dali/six-finger/" + action;

}

int power_point()       {       return 2;    }
int hard_point()        {       return 3;    }


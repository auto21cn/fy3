// thd:testsword.c
// 97.7.14 by Aug

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", "试剑亭");
	set("long", @LONG
这是座古色古香的亭子。两根石柱上悬挂这一幅对联(duilian) 。亭
口高悬着一块木匾，上面大书“试剑亭”三个篆字，字体遒劲有力，很有
魏晋书风，看来是黄岛主的手笔。整个亭子说不上雕梁划柱，除了那幅对
联就没有什么太特殊的装饰品了。但它和这片桃花竹影浑然联成一体，一
切看来都是那么的自然。到了这里人的一切私心杂念都消失的一干二净，
不由的被自然的魅力所陶醉。桃花岛的地势东高西低，试剑亭的东面就是
悬崖峭壁，之下就是波涛汹涌的大海。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/huang_yaoshi" :  1,
//	]));

	set("detail", ([ /* sizeof() == 1 */
		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
      ]));

      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"front_testsword",
	]));
      
	setup();
}

void init()
{
	add_action("do_lian", "lian");
	add_action("do_lian", "practice");
}

int do_lian(string arg)
{
	object me;
	string skillname;
	int skill, skill_basic;

	me=this_player();

	seteuid(getuid());
	
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( !arg ) return ("/cmds/std/enable")->main(me, arg);

	if( (skillname = me->skill_mapped(arg)) == arg )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	notify_fail("你的条件还不够练习这项技能。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
	
	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没「学会」这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	
	if( SKILL_D(skillname)->practice_skill(me) ) {
		if ( skill > skill_basic * 3 / 2 ) {
			write( HIB "你的" + to_chinese(skillname) + "象遇到了障碍似的，没领悟到任何新东西了！\n" NOR);
			return 1;
		}

		if(skillname=="luoying-sword")
			me->improve_skill(skillname, (skill_basic/5 +1)*2);		
		else
			me->improve_skill(skillname, skill_basic/5 +1);		

		write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
		return 1;
	}
	else return 0;
}






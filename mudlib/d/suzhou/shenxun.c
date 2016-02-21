// Room: /u/oldsix/room2/shenxun.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "审讯堂");
	set("long", @LONG
堂内灯火通明，亮如白昼。凡是关入开封府大牢的犯人，都得经此上堂后
才能获得释放。屋内除了正当中一把椅子外别无他物。椅上坐着一人，正冲你
冷笑不止。
LONG
	);
	set("objects",([
		__DIR__"npc/chanzheng" :1,
]));
	set("exits", ([ /* sizeof() == 1 */
	"up" :__DIR__"laomen",
	"north" :__DIR__"dalao1",
	"west" :__DIR__"dalao2",
	"south" :__DIR__"dalao3",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("no_steal",1);
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me,string dir)
{
	if(me->query("oldsix_flag/lao")==1&&dir=="up")	{
	return notify_fail(CYN"单正对你冷笑道：想出去？哪有这么容易的事！\n"NOR);
	}
	if(dir=="up")	{
		message_vision(CYN"单正对着$N语重心长的说道：出去后好好做人啊。\n"NOR,me);
	}
	return 1;
}

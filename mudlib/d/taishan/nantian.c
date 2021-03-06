// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "南天门");
	set("long", @LONG
走完了十八盘，这里便是泰山顶的入口处。从这里附视山下，
群山如龟伏地，河流如蚓缠绕，天地空阔，无可名状。从这里往东
北走可到一个市集，往西走便是月观峰，往北走则是到玉皇顶之路。
LONG );
	set("exits", ([
		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));
	set("objects",([
//		__DIR__"npc/jiang" : 1,
//		__DIR__"npc/wei-shi3" : 2,
		__DIR__"npc/jianchu":1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
}

int valid_leave(object me, string dir)
{
	string fam;
	object ob;

	fam=(string)me->query("family/family_name");
	ob=present("jianchu daoren",this_object());
	if(fam && fam!="泰山派" && (int)me->query("combat_exp")>10000
	&& objectp(ob) && dir=="northup")
	return notify_fail("建除道人喝道：本派掌门没空见你！\n");
	return ::valid_leave(me,dir);
}

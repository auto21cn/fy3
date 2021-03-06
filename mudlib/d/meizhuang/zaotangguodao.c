// Room: /d/suzhou/meizhuang/zaotangguodao.c

inherit ROOM;

void create()
{
	set("short", "澡堂过道");
	set("long", @LONG
过道内雾气迷漫，有些看不太清。由于梅庄近来招收女徒，所以刚刚
赶建了个为女弟子提供沐浴的场所。梅庄庄规极严，平时男女弟子很难碰
面，所以不少无聊男子有事没事就在此处转悠，成为梅庄很独特的风景。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east":__DIR__"nuzaotang",
	"west":__DIR__"nanzaotang",
  "south" : __DIR__"shibanlu2",
]));
	set("objects",([
		__DIR__"npc/wuliaodizi":2,
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me,string dir)
{
	if((me->query("gender")=="男性"&&dir=="east")||(me->query("gender")=="女性"&&dir=="west"))
	return notify_fail("哎！看清楚再走！！\n");
	if(dir=="south")	return ::valid_leave(me,dir);
	if(me->query("family/family_name")!="孤山梅庄")
	return notify_fail("本澡堂不接待其他门派弟子！\n");
	return ::valid_leave(me,dir);
}

//xiuxishi
  

inherit ROOM;

void create()
{
	set("short","公告室");
	set("long", @LONG
这儿是「铁血江湖」的最新公告室，凡是江湖上有些什么风吹草动
的变化，你都可以在此得到第一手的资料。
LONG
	);
	set("no_fight", 1);

	set("exits", ([
		"west":__DIR__"yinghaoup",
		
	]));

	setup();
	"/obj/board/gonggao"->foo();
}


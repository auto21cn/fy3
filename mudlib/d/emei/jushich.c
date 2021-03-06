// Room: /d/emei/jushich.c

inherit ROOM;

void create()
{
	set("short", "一山兆瑞");
	set("long", @LONG
沿着陡峭石阶向上,路边不远的古藤丛菽中,有一块巨石如斧所劈,
屹立在上山坡道的左侧,石上苔藓密布,巧妙地构成了'第一山'三字.字
呈赤色,随着雨晴变化,时隐时现.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xu.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/emei");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"uproad",
  "northup" : __DIR__"hongchun",
]));

	setup();
}

int valid_leave(object me,string dir)
{
        string fam;
        object npc;

        fam=(string)me->query("family/family_name");
	npc=present("jingxu shitai",environment(me));
        if( fam && fam!="峨嵋派" && objectp(npc) &&
                dir=="northup")
	return notify_fail("静虚师太左手轻挥，你只觉得心口烦闷动弹不得。\n");
        return ::valid_leave(me,dir);
}

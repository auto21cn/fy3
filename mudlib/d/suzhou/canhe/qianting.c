// Room: /d/suzhou/canhe/qianting.c

inherit ROOM;

void create()
{
	set("short", "前厅");
	set("long", @LONG
厅内布置简单的令你难以相信，除了桌子椅子这些必备的家俱之，整个厅内
竟无其它任何东西。你一走进这里，就觉的这儿实在安静的有些过份，忍不住就
想大叫几声。
LONG
	);
	set("objects",([
		__DIR__"npc/dengbai":1,
		__DIR__"npc/gongye" :1,
]));
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"canhe",
		"east" :__DIR__"dating",
]));
	set("item_desc",([
		"桌子" : "这张桌子(zhuozi)似乎没什么特别之处。\n",
		"zhuozi":"这张桌子似乎没什么特别之处。\n",
		"椅子" : "这张椅子(yizi)似乎没什么特别之处。\n",
		"yizi" : "这张椅子似乎没什么特别之处。\n",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

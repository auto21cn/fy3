// Room: /u/o/oldsix/room/road1.c

inherit ROOM;

void create()
{
	set("short", "�ľ�С·");
	set("long", @LONG
��ʯ���̳ɵ�С·��������ï�ܵ����֣�С·һֱ��ǰ�����ţ���֪Ҫ��
������δ����㲻��������������һ�¡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" :__DIR__"road2",
	"south" :__DIR__"road3",
	"east" :__DIR__"road3",
	"west" :__DIR__"road3",
]));
	set("no_clean_up", 0);
	set("outdoors","room");
	setup();
	replace_program(ROOM);
}
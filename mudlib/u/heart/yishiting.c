// Room: /u/viviran/yishiting.c

inherit ROOM;

void create()
{
	set("short", "议事厅");
	set("long", @LONG
这里是议事厅。铁血江湖的众幕僚日常商讨事情的
场所。相对“情缘阁”显得矮小。但又比寻常百姓家的
房屋高大许多。里面是清一色的红木家具。进门右边垒
有炕席，上有小床，此处可坐可卧。对面是一个类似单
人的坐椅左右两边有几个太师椅。房屋正中有一个长桌
旁边有一摞精装书画类的东西。案几上摆有文房四宝。
墙上有一幅康熙王的字画
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huihong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
